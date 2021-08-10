#include "cmd_receive.h"
#include "barframe.h"
#include <QDebug>

#define HEAD1 0x11
#define HEAD2 0x22
#define HEAD3 0x33
#define HEAD4 0x44
#define REC_UART_PORT "/dev/ttyS1"
#define REC_UART_SPEED 9600

WorkThread::WorkThread(QObject *parent, bool b) :
    QThread(parent), Stop(b)
{
    int ret;

    serialport = new Serial_Port();
    ret = serialport->Serial_Port_Open(REC_UART_PORT, REC_UART_SPEED);
    if (ret)
        qDebug("Serial_Port_Open fail\n");

}

int WorkThread::do_checksum(uint8_t *data, uint16_t data_len, uint8_t check)
{
    int ret = -1;
    uint8_t len = 0;

    do {
        ret = ret ^ data[len];
        len++;
    } while (len < data_len);

    if (ret != check)
        ret = -1;

    return ret;
}

void WorkThread::run()
{
    QByteArray rdata, cmdbuf;
    Cmd_Buf *getcmd;

    while(1) {

        serialport->Serial_Port_Read(&rdata);
        if (rdata.size() != 0) {
            qDebug("Serial Buf is come in %s %d\n", __func__, __LINE__);
            //qDebug("Serial Buf is %s %d rdata %s\n", __func__, __LINE__, rdata.data());
            //qDebug("Serial Buf have data %s %d\n", __func__, __LINE__);
            getcmd = new Cmd_Buf;
            getcmd->buf_sz = rdata.size();
            memcpy(getcmd->buf, rdata.data(), rdata.size());
            cmd_list.append(getcmd);

            rdata.clear();
            rdata.resize(0);
        }
        //else {
        //    qDebug("Serial Buf is empy %s %d\n", __func__, __LINE__);
        //}

        msleep(10);
    };
}

PageCtl_Thread::PageCtl_Thread(QObject *parent, bool b) :
    QThread(parent), Stop(b)
{
    cmd_receive = (Cmd_Receive *)parent;
    connect(this, SIGNAL(Triger_Page_Signal(CarInfo_Data *)), cmd_receive, SLOT(Triger_Page(CarInfo_Data *)));
}

void PageCtl_Thread::run()
{
    uint32_t cmd_n, i;
    Cmd_Buf *getcmdlistbuf;
    CarInfo_Data cmd_carinfo;
    uint8_t cmd_data_n, get_headinfo;
    uint8_t temp_buf[128] = {0};
    uint8_t *readbuf;
    uint8_t cmd_id, cmd_buf_ck;
    uint16_t data_buf_sz;
    int ret;

    cmd_data_n = 0;
    get_headinfo = 0;
    while(1) {
        cmd_n = cmd_receive->mThread->cmd_list.size();
        if (cmd_n > 0) {
            for (i = 0; i < cmd_n; i++) {
                getcmdlistbuf = cmd_receive->mThread->cmd_list.at(i);

                readbuf = new uint8_t [getcmdlistbuf->buf_sz + 1];
                memcpy(readbuf, getcmdlistbuf->buf, getcmdlistbuf->buf_sz);
                readbuf[getcmdlistbuf->buf_sz] = 0;
                qDebug("getcmdlistbuf->buf_sz -> %d\n", getcmdlistbuf->buf_sz);

                if (!get_headinfo && readbuf[0] == 0x5A && readbuf[1] == 0x87) {
                    cmd_id = readbuf[2];
                    data_buf_sz = (readbuf[3] << 8) | readbuf[4];

                    //compute checksun
                    ret = do_checksum(&readbuf[5], cmd_buf_sz, readbuf[5 + cmd_buf_sz])
                    if (ret < 0)
                        continue;

                    if (cmd_buf_sz > 128)
                        qDebug("data buffer[%d] over temp_buf size\n", cmd_buf_sz);

                    memcpy((uint8_t *)&temp_buf, &readbuf[5], cmd_buf_sz - 1);
                    get_headinfo = 1;
                    memcpy((uint8_t *)&cmd_carinfo, temp_buf, cmd_buf_sz - 1);
                    emit Triger_Page_Signal(&cmd_carinfo);
                    get_headinfo = 0;
                }

                //if (!get_headinfo && readbuf[0] == HEAD1 && readbuf[1] == HEAD2
                //        && readbuf[2] == HEAD3 && readbuf[3] == HEAD4) {
                //    qDebug("-->Get Head\n");
                //    if (getcmdlistbuf->buf_sz - 4 >= 32) {
                //        qDebug("SLASH TEST\n");
                //        memcpy((uint8_t *)&temp_buf, &readbuf[4], 32);
                //        cmd_data_n = 32;
                //    } else {
                //        memcpy((uint8_t *)&temp_buf, &readbuf[4], getcmdlistbuf->buf_sz);
                //        cmd_data_n = cmd_data_n + getcmdlistbuf->buf_sz;
                //    }
                //    get_headinfo = 1;
                //} else if (get_headinfo) {
                //    if (32 - cmd_data_n > getcmdlistbuf->buf_sz) {
                //        memcpy((uint8_t *)&temp_buf[cmd_data_n], readbuf, getcmdlistbuf->buf_sz);
                //        cmd_data_n = cmd_data_n + getcmdlistbuf->buf_sz;
                //    } else {
                //        memcpy((uint8_t *)&temp_buf[cmd_data_n], readbuf, 32 - cmd_data_n);
                //        cmd_data_n = cmd_data_n + 32 - cmd_data_n;
                //    }
                //}
                //
                //if (cmd_data_n >= 32) {
                //    cmd_data_n = 0;
                //    get_headinfo = 0;
                //    memcpy((uint8_t *)&cmd_carinfo, temp_buf, 32);
                //    emit Triger_Page_Signal(&cmd_carinfo);
                //    //qDebug("cmd_carinfo.page_number %d\n", cmd_carinfo.page_number);
                //    //qDebug("cmd_carinfo.widge_id %d\n", cmd_carinfo.widge_id);
                //    //int i;
                //    //for (i = 0; i < 25; i++)
                //    //    qDebug("cmd_carinfo.widge_data[%d] %d\n", i, cmd_carinfo.widge_data[i]);
                //}

                delete readbuf;
                cmd_receive->mThread->cmd_list.removeAt(i);
                delete getcmdlistbuf;
            }
        }
        QThread::msleep(5);
    };
}


Cmd_Receive::Cmd_Receive(QObject *parent) : QObject(parent)
{
    mThread = new WorkThread(this);
    mPage_ctl_thread = new PageCtl_Thread(this);

    mThread->start();
    mPage_ctl_thread->start();
    current_page = "Home_Page";
}


void Cmd_Receive::Register(class Frame_Page *frameage)
{
    page_list.append(frameage);
    this->connect(this, SIGNAL(set_show_page()), frameage, SLOT(show()));
    this->connect(this, SIGNAL(set_close_page()), frameage, SLOT(close()));
}

int Cmd_Receive::Find_Frame(QString objname)
{
    int i, ret, list_cnt;
    class Frame_Page *frameage;

    if (page_list.empty())
        return -1;

    list_cnt = page_list.count();
    for (i = 0; i < list_cnt; i++) {
        frameage = page_list.at(i);
        ret = objname.compare(frameage->objectName());
        //qDebug() << "find frameage->objectName()" << frameage->objectName();
        if (!ret)
            break;
    }

    if (i >= list_cnt)
        return -1;

    return i;
}

void Cmd_Receive::Frame_Page_Show(QString show_objname)
{
    class Frame_Page *show_framepage;
    class Frame_Page *close_framepage;
    class BarFrame *bar_page;
    int i, j, k;

    i = Find_Frame(show_objname);
    if (i < 0) {
        qDebug() << "can't find any show frame page\n" << show_objname;
        return;
    }

    if (!show_objname.compare(BAR_FRAME_OBJNAME)) {
        bar_page = (BarFrame *)page_list.at(i);
        bar_page->GetMcuData(pcarinfo_data);
        bar_page->update();
        return;
    }


    show_framepage = page_list.at(i);
    qDebug() << "show frameage objname=" <<show_framepage->objectName();

    j = Find_Frame(current_page);
    if (j < 0) {
        qDebug("can't find any current page\n");
        return;
    }
    close_framepage = page_list.at(j);
    qDebug() << "close frame page objname=" <<close_framepage->objectName();

    if (current_page.compare(show_objname) != 0) {
        show_framepage->GetMcuData(pcarinfo_data);
        show_framepage->setWindowFlags(Qt::WindowStaysOnTopHint);
        show_framepage->setGeometry(0, 0, GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
        show_framepage->show();
        close_framepage->close();
    } else {
        show_framepage->update();
    }

    current_page = show_objname;
}

void Cmd_Receive::Triger_Page(CarInfo_Data *carinfo_data)
{
    pcarinfo_data = carinfo_data;
    qDebug("page_number %d", pcarinfo_data->page_number);
    QString objname[] = {HOME_PAGE_OBJNAME, MAIN_PAGE_OBJNAME, RPM_OBJNAME, "CarInOut_Page",
                        "TimeAdjust_Page", "ScreenVolumeAdjust_Page", "EleAccInfo_Page",
                        "ControlMsg1_Page", "ControlMsg2_Page", "BatTempInfo_Page", "BatVoltInfo_Page",
                        "TempModule_Page", "SatOutMsg_Page", "SatInMsg_Page", "SwVersion_Page",
                        "SlaveSatMsg_Page", "Bcm_Page", "TiresPressShow_Page",BAR_FRAME_OBJNAME,
                        };

    Frame_Page_Show(objname[pcarinfo_data->page_number]);

}
