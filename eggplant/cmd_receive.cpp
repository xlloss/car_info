#include "cmd_receive.h"
#include "barframe.h"
#include <QDebug>

#define REC_UART_PORT "/dev/ttyS1"
#define REC_UART_SPEED 921600
#define ENABLE_ACK 0

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

    return 0;
}

void WorkThread::run()
{
    QByteArray rdata, cmdbuf;

    QThread::msleep(100);
    while(1) {
        serialport->Serial_Port_Read(&rdata);
        if (rdata.size() <= 0)
            goto gotsleep;

        getcmd = new Cmd_Buf;
        getcmd->buf_sz = rdata.size();
        memcpy(getcmd->buf, rdata.data(), sizeof(uint8_t) * uint8_t(rdata.size()));
        cmd_list.append(getcmd);

        rdata.clear();
        rdata.resize(0);

gotsleep:
        msleep(10);
    }
}

PageCtl_Thread::PageCtl_Thread(QObject *parent, bool b) :
    QThread(parent), Stop(b)
{
    cmd_receive = static_cast<Cmd_Receive *>(parent);
    connect(this, SIGNAL(Triger_Page_Signal()), cmd_receive, SLOT(Triger_Page()));
}

void PageCtl_Thread::run()
{
    uint8_t data_sz;
    uint8_t *readbuf;
    int32_t buf_index;
    Cmd_Buf *getcmdlistbuf;
    int ret;
    int cmd_n;
    int cmd_index;

    QThread::msleep(100);

    while(1) {
        cmd_n = cmd_receive->mThread->cmd_list.size();
        if (!cmd_n)
            goto do_sleep;

        for (cmd_index = 0; cmd_index < cmd_n; cmd_index++) {
            getcmdlistbuf = cmd_receive->mThread->cmd_list.at(cmd_index);

            readbuf = new uint8_t [getcmdlistbuf->buf_sz + 1];
            memcpy(readbuf, getcmdlistbuf->buf, sizeof(uint8_t) * uint8_t(getcmdlistbuf->buf_sz));
            readbuf[getcmdlistbuf->buf_sz] = 0;

            buf_index = 0;
            while (buf_index < getcmdlistbuf->buf_sz) {
                if (readbuf[buf_index + HEAD1_OFF] == HEAD1 &&
                    readbuf[buf_index + HEAD2_OFF] == HEAD2 &&
                    readbuf[buf_index + ID_OFF] == PAGE_RQ) {
                    data_sz = uint8_t((readbuf[buf_index + LENH_OFF] << 8) | readbuf[buf_index + LENL_OFF]);

                    //compute checksun
                    ret = cmd_receive->mThread->do_checksum(static_cast<uint8_t *>(&readbuf[buf_index + HEAD1_OFF]),
                                    uint16_t(data_sz + HEAD_SIZE),
                                    readbuf[buf_index + PAGE_DATA_OFF + data_sz]);
                    if (ret)
                        qDebug("checksun fail\n");

                    //qDebug("m_carinfo_data.page_number %d\n", readbuf[PAGE_DATA_OFF + PAGE_NUM_OFF]);
                    //readbuf[PAGE_DATA_OFF + PAGE_NUM_OFF] = (4 + 1);
                    //5 = Page_Num + Meter[2] + Meter[1] + Meter[0]
                    m_carinfo_data.page_data_sz = data_sz - 4;
                    m_carinfo_data.page_number = readbuf[PAGE_DATA_OFF + PAGE_NUM_OFF];
                    memcpy(m_carinfo_data.meter_sat, &readbuf[PAGE_DATA_OFF + METER_SAT_OFF], 3);
                    memcpy(m_carinfo_data.page_data, &readbuf[PAGE_DATA_OFF + PAGE_DAT_OFF], m_carinfo_data.page_data_sz);
                    cmd_receive->pcarinfo_data = &m_carinfo_data;

                    /* qDebug("m_carinfo_data.page_number %d\n", m_carinfo_data.page_number); */
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
    }
}


Cmd_Receive::Cmd_Receive(QObject *parent) : QObject(parent)
{
    mThread = new WorkThread(this);
    mPage_ctl_thread = new PageCtl_Thread(this);

    mThread->start();
    mPage_ctl_thread->start();
    current_page = HOME_PAGE_OBJNAME;
}


void Cmd_Receive::Register(class Frame_Page *frameage)
{
    page_list.append(frameage);
    connect(this, SIGNAL(set_show_page()), frameage, SLOT(show()));
    connect(this, SIGNAL(set_close_page()), frameage, SLOT(close()));
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
    uint8_t get_ackdata[256];
    uint8_t get_ackdata_len;
    int i, j;

    i = Find_Frame(show_objname);
    if (i < 0) {
        qDebug() << "can't find any show frame page\n" << show_objname;
        return;
    }

    if (!show_objname.compare(BAR_FRAME_OBJNAME)) {
        bar_page = static_cast<BarFrame *>(page_list.at(i));
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
        show_framepage->GetMcuData(pcarinfo_data);
        show_framepage->update();
    }

#if ENABLE_ACK
    show_framepage->GetAckData(get_ackdata);
    get_ackdata_len = 5 + (get_ackdata[3] << 8 | get_ackdata[4]);
    mThread->serialport->Serial_Port_Write(get_ackdata, get_ackdata_len);
#endif

    current_page = show_objname;
}

void Cmd_Receive::Triger_Page()
{
    QString objname[] = {
        PAGE_00,
        PAGE_01,
        PAGE_02,
        PAGE_03,
        PAGE_04,
        PAGE_05,
        PAGE_06,
        PAGE_07,
        PAGE_08,
        PAGE_09,
        PAGE_10,
        PAGE_11,
        PAGE_12,
        PAGE_13,
        PAGE_14,
        PAGE_15,
        PAGE_16,
        PAGE_17};

    Frame_Page_Show(BAR_FRAME_OBJNAME);
    Frame_Page_Show(objname[pcarinfo_data->page_number - 1]);
}
