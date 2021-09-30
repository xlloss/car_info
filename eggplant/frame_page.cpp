#include "frame_page.h"
#include "ui_frame_page.h"
#include <QDebug>
#include <QPainter>
#include "coordinate.h"

Frame_Page::Frame_Page(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame_Page)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->close();
    this->setGeometry(GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                      GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    this->setWindowState(Qt::WindowNoState);
}

Frame_Page::~Frame_Page()
{
    delete ui;
}

uint8_t Frame_Page::do_checksum(uint8_t *data, uint16_t data_len)
{
    uint8_t ret = 0;
    uint32_t len = 0;

    do {
        ret = ret ^ data[len];
        len++;
    } while (len < data_len);

    return ret;
}

void Frame_Page::Load_Background(QString image)
{
    if (image.isNull())
        return;
}

void Frame_Page::Enable_Icon_Light(int i)
{
    if (i < 0)
        return;
}

void Frame_Page::GetAckData(uint8_t *get_ackdata)
{
    #define HEAD1 0x5A
    #define HEAD2 0x87
    #define PAGE_RQ 0x0C
    uint8_t get_checksum;
    uint16_t tot_data_len;

    return;

    if (!get_ackdata)
        return;

    //   0        1      2       3       4         5        6          7          8            9    ...            TotalLen - 1
    //--------------------------------------------------------------------------------------------------------------------
    // HEAD1  | HEAD2 | CMD  | LEN-H | LEN-L | Page_Num | Meter[2] | Meter[1] | Meter[0] | Data [N] ... Data[N-1] | CKSUM |
    //--------------------------------------------------------------------------------------------------------------------
    //  LEN-H | LEN-L = Page_Num(1) + Meter0-2(3) + Page_Data_Len(N)
    //  Total Len     = HEAD1(1) + HEAD2(1) + CMD(1) + LEN-H(1) + LEN-L(1) + Data_Len (Page_Num + Meter0-2 + Page_Data) + CheckSum(1)

    get_ackdata[0] = HEAD1;
    get_ackdata[1] = HEAD2;
    get_ackdata[2] = PAGE_RQ;

    get_ackdata[3] = ((m_protolcol_data.page_data_sz + 4) & 0xFF00) >> 8;
    get_ackdata[4] = (m_protolcol_data.page_data_sz + 4) & 0x00FF;

    get_ackdata[5] = m_protolcol_data.page_number;

    memcpy(&get_ackdata[6], m_protolcol_data.meter_sat, 3);

    memcpy(&get_ackdata[9], &m_protolcol_data.page_data, m_protolcol_data.page_data_sz);

    tot_data_len = uint16_t((get_ackdata[3] << 8 | get_ackdata[4]) + 6);
    get_checksum = do_checksum(get_ackdata, tot_data_len - 1);
    get_ackdata[tot_data_len - 1] = get_checksum;
}
