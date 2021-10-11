#include "eai_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

static QString master_text[EAI_MAS_TEX_NUM] = {EAI_MAS_TEX_ID0,
    EAI_MAS_TEX_ID1, EAI_MAS_TEX_ID2};

static QString sub_text[EAI_MAS_TEX_NUM][EAI_SUB_TEX_NUM] = {
    {EAI_SUB_STR_ID00, EAI_SUB_STR_ID01,
     EAI_SUB_STR_ID02, EAI_SUB_STR_ID03,
     EAI_SUB_STR_ID04, EAI_SUB_STR_ID05, EAI_SUB_STR_ID06},

    {EAI_SUB_STR_ID10, EAI_SUB_STR_ID11,
     EAI_SUB_STR_ID12, EAI_SUB_STR_ID13,
     EAI_SUB_STR_ID14, EAI_SUB_STR_ID15, EAI_SUB_STR_ID16},

    {EAI_SUB_STR_ID20, EAI_SUB_STR_ID21,
     EAI_SUB_STR_ID22, EAI_SUB_STR_ID23,
     EAI_SUB_STR_ID24, EAI_SUB_STR_ID25, EAI_SUB_STR_ID26},
};

static QString sub_text_msg[EAI_MAS_TEX_NUM][EAI_SUB_TEX_NUM] = {
    {EAI_SUB_SAMPLE_STR_ID00, EAI_SUB_STR_ID01,
     EAI_SUB_SAMPLE_STR_ID02, EAI_SUB_STR_ID03,
     EAI_SUB_SAMPLE_STR_ID04, EAI_SUB_SAMPLE_STR_ID05, EAI_SUB_SAMPLE_STR_ID06},

    {EAI_SUB_SAMPLE_STR_ID10, EAI_SUB_STR_ID11,
     EAI_SUB_SAMPLE_STR_ID12, EAI_SUB_STR_ID13,
     EAI_SUB_SAMPLE_STR_ID14, EAI_SUB_SAMPLE_STR_ID15, EAI_SUB_SAMPLE_STR_ID16},

    {EAI_SUB_SAMPLE_STR_ID20, EAI_SUB_STR_ID21,
     EAI_SUB_SAMPLE_STR_ID22, EAI_SUB_STR_ID23,
     EAI_SUB_SAMPLE_STR_ID24, EAI_SUB_SAMPLE_STR_ID25, EAI_SUB_SAMPLE_STR_ID26},
};

static int master_text_xy[] = {
  EAI_MASTER_TEXT_X,  EAI_MASTER_TEXT_Y,
  EAI_MASTER_TEXT_X + (EAI_MASTER_TEXT_W + 70) * 1, EAI_MASTER_TEXT_Y,
  EAI_MASTER_TEXT_X + (EAI_MASTER_TEXT_W + 50) * 2, EAI_MASTER_TEXT_Y,
};

static int sub_text_xy[] = {
  EAI_SUB_TEXT_X,  EAI_SUB_TEXT_Y,
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 1),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 2),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 3),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 4),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 5),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 6),
};

static int sub_text_x_offset[EAI_MAS_TEX_NUM] = {0,  260, 510};
static int sub_text_msg_off[EAI_MAS_TEX_NUM] = {150, 400, 670};

EleAccInfo_Page::EleAccInfo_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(EAI_OBJNAME);
    int i, j, k;

    backimg.load(EAI_BG_IMG);
    tableimg.load(EAI_FM_IMG);

    /* master title */
    j = 0;
    for (i = 0; i < EAI_MAS_TEX_NUM; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(master_text[i]);
        show_master_item[i]->setGeometry(master_text_xy[j], master_text_xy[j + 1],
                EAI_MASTER_TEXT_W, EAI_MASTER_TEXT_H);
        show_master_item[i]->m_font_size = RAI_FONT_SIZE;
        j = j + 2;
    }

    /* sub title */
    for (i = 0; i < EAI_MAS_TEX_NUM; i++) {
        j = 0;
        for (k = 0; k < EAI_SUB_TEX_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(sub_text_xy[j] + sub_text_x_offset[i], sub_text_xy[j + 1],
                    EAI_SUB_TEXT_W, EAI_SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = RAI_FONT2_SIZE;
            show_sub_item[i][k]->show();

            show_sub_data[i][k] = new Show_text(this);
            show_sub_data[i][k]->set_text(sub_text_msg[i][k]);
            show_sub_data[i][k]->setGeometry(sub_text_xy[j] + sub_text_msg_off[i], sub_text_xy[j + 1],
                    EAI_SUB_TEXT_W, EAI_SUB_TEXT_H);
            show_sub_data[i][k]->m_font_size = RAI_FONT2_SIZE;
            show_sub_data[i][k]->show();
            j = j + 2;
        }
    }
}

void EleAccInfo_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawPixmap(8, 50, tableimg, 0, 0, 788, 360);
}

void EleAccInfo_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    uint8_t page_data[128];
    uint8_t u8_data_tmp;
    double d_data_tmp;
    QString str_tmp;

    memcpy(page_data, protolcol_data->page_data, sizeof(uint8_t) * protolcol_data->page_data_sz);

    /* for DATA I-1 */
    d_data_tmp = double(page_data[1] << 8 | page_data[0]);
    d_data_tmp = d_data_tmp * 0.125;
    if (d_data_tmp > 5000 )
        d_data_tmp = 5000.0; 
    else if (d_data_tmp < 0 )
        d_data_tmp = 0;

    str_tmp.sprintf("%d rpm", uint32_t(d_data_tmp));
    show_sub_data[ELEACC_INFO_ITEM_I][ELEACC_INFO_I1]->set_text(str_tmp);

    /* for DATA I-2 */
    d_data_tmp = double(page_data[3] << 8 | page_data[2]);
    d_data_tmp = d_data_tmp * 0.1;
    if (d_data_tmp > 1000 )
        d_data_tmp = 1000.0; 
    else if (d_data_tmp < 0 )
        d_data_tmp = 0;

    str_tmp.sprintf("%.1f V", d_data_tmp);
    show_sub_data[ELEACC_INFO_ITEM_I][ELEACC_INFO_I2]->set_text(str_tmp);

    /* for DATA I-3 */
    d_data_tmp = double(page_data[4]);
    d_data_tmp = d_data_tmp;
    if (d_data_tmp > 1000 )
        d_data_tmp = 1000; 
    else if (d_data_tmp < 0 )
        d_data_tmp = 0;

    str_tmp.sprintf("%d A", uint32_t(d_data_tmp));
    show_sub_data[ELEACC_INFO_ITEM_I][ELEACC_INFO_I3]->set_text(str_tmp);

    /* for DATA I-4 */
    d_data_tmp = double(page_data[5]);
    d_data_tmp = d_data_tmp - 40;
    if (d_data_tmp > 200 )
        d_data_tmp = 200; 
    else if (d_data_tmp < -40 )
        d_data_tmp = -40;

    str_tmp.sprintf("%i °C", int32_t(d_data_tmp));
    show_sub_data[ELEACC_INFO_ITEM_I][ELEACC_INFO_I4]->set_text(str_tmp);

    /* for DATA I-5 */
    u8_data_tmp = page_data[6];
    u8_data_tmp = u8_data_tmp & 0x0F;
    str_tmp.sprintf("%d", u8_data_tmp);
    show_sub_data[ELEACC_INFO_ITEM_I][ELEACC_INFO_I5]->set_text(str_tmp);

    /* for DATA I-6 */
    u8_data_tmp = page_data[6];
    u8_data_tmp = (u8_data_tmp & 0x03 << 4) >> 4;
    if (u8_data_tmp == 1)
        str_tmp.sprintf("%s", "作動");
    else
        str_tmp.sprintf("%s", "停止");

    show_sub_data[ELEACC_INFO_ITEM_I][ELEACC_INFO_I6]->set_text(str_tmp);

    /* for DATA I-7 */
    u8_data_tmp = page_data[6];
    u8_data_tmp = (u8_data_tmp & 0x01 << 6) >> 6;
    if (u8_data_tmp == 1)
        str_tmp.sprintf("%s", "完成");
    else
        str_tmp.sprintf("%s", "未完成");

    show_sub_data[ELEACC_INFO_ITEM_I][ELEACC_INFO_I7]->set_text(str_tmp);


    /* for DATA J-1 */
    d_data_tmp = double(page_data[8] << 8 | page_data[7]);
    d_data_tmp = d_data_tmp * 0.1;
    if (d_data_tmp > 1000 )
        d_data_tmp = 1000; 
    else if (d_data_tmp < 0 )
        d_data_tmp = 0;

    str_tmp.sprintf("%.1f V", d_data_tmp);
    show_sub_data[ELEACC_INFO_ITEM_J][ELEACC_INFO_J1]->set_text(str_tmp);


    /* for DATA J-2 */
    u8_data_tmp = page_data[9];
    str_tmp.sprintf("%d A", u8_data_tmp);
    show_sub_data[ELEACC_INFO_ITEM_J][ELEACC_INFO_J2]->set_text(str_tmp);

    /* for DATA J-3 */
    u8_data_tmp = page_data[10];
    str_tmp.sprintf("%d A", u8_data_tmp);
    show_sub_data[ELEACC_INFO_ITEM_J][ELEACC_INFO_J3]->set_text(str_tmp);


    /* for DATA J-4 */
    d_data_tmp = double(page_data[11]);
    d_data_tmp = d_data_tmp - 40;
    if (d_data_tmp > 210 )
        d_data_tmp = 210; 
    else if (d_data_tmp < -40 )
        d_data_tmp = -40;

    str_tmp.sprintf("%i °C", int32_t(d_data_tmp));
    show_sub_data[ELEACC_INFO_ITEM_J][ELEACC_INFO_J4]->set_text(str_tmp);


    /* for DATA J-5 */
    u8_data_tmp = page_data[12];
    u8_data_tmp = u8_data_tmp & 0x0F;
    str_tmp.sprintf("%d", u8_data_tmp);
    show_sub_data[ELEACC_INFO_ITEM_J][ELEACC_INFO_J5]->set_text(str_tmp);

    /* for DATA J-6 */
    u8_data_tmp = page_data[12];
    u8_data_tmp = ((u8_data_tmp >> 4) & 0x03);

    if (u8_data_tmp == 0)
        str_tmp.sprintf("%s", "停止");
    else if (u8_data_tmp == 1)
        str_tmp.sprintf("%s", "作動");
    else
        str_tmp.sprintf("%s", "異常");
    show_sub_data[ELEACC_INFO_ITEM_J][ELEACC_INFO_J6]->set_text(str_tmp);

    /* for DATA J-7 */
    u8_data_tmp = page_data[12];
    u8_data_tmp = (u8_data_tmp & (0x01 << 6)) >> 6;
    if (u8_data_tmp == 0)
        str_tmp.sprintf("%s", "未完成");
    else
        str_tmp.sprintf("%s", "完成");

    show_sub_data[ELEACC_INFO_ITEM_J][ELEACC_INFO_I7]->set_text(str_tmp);


    /* for DATA K-1 */
    d_data_tmp = double(page_data[14] << 8 | page_data[13]);
    d_data_tmp = d_data_tmp * 0.125;
    if (d_data_tmp > 5000 )
        d_data_tmp = 5000; 
    else if (d_data_tmp < 0 )
        d_data_tmp = 0;

    str_tmp.sprintf("%d rpm", uint32_t(d_data_tmp));
    show_sub_data[ELEACC_INFO_ITEM_K][ELEACC_INFO_K1]->set_text(str_tmp);

    /* for DATA K-2 */
    d_data_tmp = double(page_data[16] << 8 | page_data[15]);
    d_data_tmp = d_data_tmp * 0.1;
    if (d_data_tmp > 1000)
        d_data_tmp = 1000; 
    else if (d_data_tmp < 0 )
        d_data_tmp = 0;

    str_tmp.sprintf("%.1f V", d_data_tmp);
    show_sub_data[ELEACC_INFO_ITEM_K][ELEACC_INFO_K2]->set_text(str_tmp);

    /* for DATA K-3 */
    d_data_tmp = double(page_data[17]);

    if (d_data_tmp > 100 )
        d_data_tmp = 100; 
    else if (d_data_tmp < 0 )
        d_data_tmp = 0;

    str_tmp.sprintf("%d A", uint32_t(d_data_tmp));
    show_sub_data[ELEACC_INFO_ITEM_K][ELEACC_INFO_K3]->set_text(str_tmp);

    /* for DATA K-4 */
    d_data_tmp = double(page_data[18]);
    d_data_tmp = d_data_tmp - 40;
    if (d_data_tmp > 200 )
        d_data_tmp = 200; 
    else if (d_data_tmp < -40 )
        d_data_tmp = -40;

    str_tmp.sprintf("%i °C", int32_t(d_data_tmp));
    show_sub_data[ELEACC_INFO_ITEM_K][ELEACC_INFO_K4]->set_text(str_tmp);

    /* for DATA K-5 */
    u8_data_tmp = page_data[19];
    u8_data_tmp = u8_data_tmp & 0x0F;
    str_tmp.sprintf("%d", u8_data_tmp);
    show_sub_data[ELEACC_INFO_ITEM_K][ELEACC_INFO_K5]->set_text(str_tmp);


    /* for DATA K-6 */
    u8_data_tmp = page_data[19];
    u8_data_tmp = (u8_data_tmp >> 4) & 0x03;
    if (u8_data_tmp == 0)
        str_tmp.sprintf("%s", "停止");
    else if (u8_data_tmp == 1)
        str_tmp.sprintf("%s", "作動");
    else
        str_tmp.sprintf("%s", "異常");

    show_sub_data[ELEACC_INFO_ITEM_K][ELEACC_INFO_K6]->set_text(str_tmp);


    /* for DATA K-7 */
    u8_data_tmp = page_data[19];
    u8_data_tmp = (u8_data_tmp & (0x01 << 6)) >> 6;
    qDebug("page_data[19] 0x%x\n", page_data[19]);
    qDebug("u8_data_tmp 0x%x\n", u8_data_tmp);
    if (u8_data_tmp == 0)
        str_tmp.sprintf("%s", "未完成");
    else
        str_tmp.sprintf("%s", "完成");

    show_sub_data[ELEACC_INFO_ITEM_K][ELEACC_INFO_K7]->set_text(str_tmp);
    memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
}
