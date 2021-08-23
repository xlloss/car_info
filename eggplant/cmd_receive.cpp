#include "cmd_receive.h"
#include "barframe.h"
#include <QDebug>

#define HEAD1 0x5A
#define HEAD2 0x87
#define PAGE_RQ 0x0B

#define HEAD1_OFF 0
#define HEAD2_OFF 1
#define ID_OFF 2
#define LENH_OFF 3
#define LENL_OFF 4
#define PAGE_DATA_OFF 5

#define HEAD_SIZE 5
#define PAGE_NUM_OFF 0
#define METER_SAT_OFF 1
#define PAGE_DAT_OFF 4


#define REC_UART_PORT "/dev/ttyS1"
#define REC_UART_SPEED 921600

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
    int ret = 0;
    uint32_t len = 0;

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
        if (rdata.size() <= 0)
            continue;

        //qDebug("Serial Buf is come in %s %d\n", __func__, __LINE__);
        //qDebug("Serial Buf is %s %d rdata %d\n", __func__, __LINE__, rdata.size());
        //qDebug("Serial Buf have data %s %d 0x%x\n", __func__, __LINE__, rdata.at(0));
        getcmd = new Cmd_Buf;
        getcmd->buf_sz = rdata.size();
        memcpy(getcmd->buf, rdata.data(), rdata.size());
        cmd_list.append(getcmd);

        rdata.clear();
        rdata.resize(0);

        msleep(10);
    };
}

PageCtl_Thread::PageCtl_Thread(QObject *parent, bool b) :
    QThread(parent), Stop(b)
{
    cmd_receive = (Cmd_Receive *)parent;
    connect(this, SIGNAL(Triger_Page_Signal()), cmd_receive, SLOT(Triger_Page()));
}

void PageCtl_Thread::run()
{
    int32_t buf_index;
    uint32_t cmd_n, cmd_index;
    Cmd_Buf *getcmdlistbuf;
    uint8_t cmd_data_n, get_headinfo;
    uint8_t temp_buf[128] = {0};
    uint8_t *readbuf;
    uint8_t cmd_id, cmd_buf_ck;
    uint16_t pagedata_sz;
    int ret;

    cmd_data_n = 0;
    get_headinfo = 0;

    while(1) {
        cmd_n = cmd_receive->mThread->cmd_list.size();
        if (!cmd_n)
            goto do_sleep;

        for (cmd_index = 0; cmd_index < cmd_n; cmd_index++) {
            getcmdlistbuf = cmd_receive->mThread->cmd_list.at(cmd_index);

            readbuf = new uint8_t [getcmdlistbuf->buf_sz + 1];
            memcpy(readbuf, getcmdlistbuf->buf, getcmdlistbuf->buf_sz);
            readbuf[getcmdlistbuf->buf_sz] = 0;
            //qDebug("getcmdlistbuf->buf_sz -> %d\n", getcmdlistbuf->buf_sz);

            buf_index = 0;
            while (buf_index < getcmdlistbuf->buf_sz) {

                if (readbuf[buf_index + HEAD1_OFF] == HEAD1 && readbuf[buf_index + HEAD2_OFF] == HEAD2) {
                    //qDebug("Get Head\n");
                    cmd_id = readbuf[buf_index + ID_OFF];
                    pagedata_sz = (readbuf[buf_index + LENH_OFF] << 8) | readbuf[buf_index + LENL_OFF];

                    //compute checksun
                    ret = cmd_receive->mThread->do_checksum(&readbuf[buf_index + HEAD1_OFF], pagedata_sz + HEAD_SIZE,
                                      readbuf[buf_index + PAGE_DATA_OFF + pagedata_sz]);
                    //if (ret < 0) {
                    //    qDebug("check sum fail\n");
                    //    goto do_sleep;
                    //} else
                    //    qDebug("check sum ok\n");

                    m_carinfo_data.page_number = readbuf[PAGE_DATA_OFF + PAGE_NUM_OFF];
                    memcpy(m_carinfo_data.meter_sat, &readbuf[PAGE_DATA_OFF + METER_SAT_OFF], 3);
                    memcpy(m_carinfo_data.widge_data, &readbuf[PAGE_DATA_OFF + PAGE_DAT_OFF], pagedata_sz - 4);
                    cmd_receive->pcarinfo_data = &m_carinfo_data;
                    emit Triger_Page_Signal();
                }
                buf_index++;
            }

            delete readbuf;
            cmd_receive->mThread->cmd_list.removeAt(cmd_index);
            delete getcmdlistbuf;
        }

do_sleep:
        QThread::msleep(10);
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
    //qDebug() << "show frameage objname=" <<show_framepage->objectName();

    j = Find_Frame(current_page);
    if (j < 0) {
        qDebug("can't find any current page\n");
        return;
    }
    close_framepage = page_list.at(j);
    //qDebug() << "close frame page objname=" <<close_framepage->objectName();

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

//void Cmd_Receive::Triger_Page(CarInfo_Data *carinfo_data)
void Cmd_Receive::Triger_Page()
{
    //pcarinfo_data = carinfo_data;
    //qDebug("page_number %d", pcarinfo_data->page_number);
    QString objname[] = {HOME_PAGE_OBJNAME, MAIN_PAGE_OBJNAME, RPM_OBJNAME, "CarInOut_Page",
                        "TimeAdjust_Page", "ScreenVolumeAdjust_Page", "EleAccInfo_Page",
                        "ControlMsg1_Page", "ControlMsg2_Page", "BatTempInfo_Page", "BatVoltInfo_Page",
                        "TempModule_Page", "SatOutMsg_Page", "SatInMsg_Page", "SwVersion_Page",
                        "SlaveSatMsg_Page", "Bcm_Page", "TiresPressShow_Page",BAR_FRAME_OBJNAME,
                        };

    Frame_Page_Show(BAR_FRAME_OBJNAME);
    Frame_Page_Show(objname[pcarinfo_data->page_number - 1]);

}
