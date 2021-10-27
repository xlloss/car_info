#include "battery_temp_info_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

static QString battempinfo_master_text[BATTINFO_MAS_NUM] = {"電池溫度資訊"};

static QString battempinfo_sub_text[BATTINFO_TEX_COL_NUM][BATTINFO_TEX_ROW_NUM] = {
                            {BATT_SUB_TEX_ID00, BATT_SUB_TEX_ID01, BATT_SUB_TEX_ID02, BATT_SUB_TEX_ID03},//class 1 -> battery HI Temp
                            {BATT_SUB_TEX_ID10, BATT_SUB_TEX_ID11, BATT_SUB_TEX_ID12, BATT_SUB_TEX_ID13},//class 2 -> battery LO Temp
                            {BATT_SUB_TEX_ID20, BATT_SUB_TEX_ID21, BATT_SUB_TEX_ID22, BATT_SUB_TEX_ID23},//class 3 -> Locate (box H )
                            {BATT_SUB_TEX_ID30, BATT_SUB_TEX_ID31, BATT_SUB_TEX_ID32, BATT_SUB_TEX_ID33},//class 4 -> Locate (box L )
                            {BATT_SUB_TEX_ID40, BATT_SUB_TEX_ID41, BATT_SUB_TEX_ID42, BATT_SUB_TEX_ID43},//class 5 -> Locate (num H )
                            {BATT_SUB_TEX_ID50, BATT_SUB_TEX_ID51, BATT_SUB_TEX_ID52, BATT_SUB_TEX_ID53},//class 6 -> Locate (num H )
                        };

static QString battempinfo_sub_text_msg[BATTINFO_TEX_COL_NUM][BATTINFO_TEX_ROW_NUM] = {
                            {BATT_MSG_TEX_ID00, BATT_MSG_TEX_ID01, BATT_MSG_TEX_ID02, BATT_MSG_TEX_ID03},//class 1
                            {BATT_MSG_TEX_ID10, BATT_MSG_TEX_ID11, BATT_MSG_TEX_ID12, BATT_MSG_TEX_ID13},//class 2
                            {BATT_MSG_TEX_ID20, BATT_MSG_TEX_ID21, BATT_MSG_TEX_ID22, BATT_MSG_TEX_ID23},//class 3
                            {BATT_MSG_TEX_ID30, BATT_MSG_TEX_ID31, BATT_MSG_TEX_ID32, BATT_MSG_TEX_ID33},//class 4
                            {BATT_MSG_TEX_ID40, BATT_MSG_TEX_ID41, BATT_MSG_TEX_ID42, BATT_MSG_TEX_ID43},//class 5
                            {BATT_MSG_TEX_ID50, BATT_MSG_TEX_ID51, BATT_MSG_TEX_ID52, BATT_MSG_TEX_ID53},//class 6
                        };


static int battempinfo_master_text_xy[] = {
    BATTEMP_MASTER_TEXT_X,  BATTEMP_MASTER_TEXT_Y,
};

static int battempinfo_sub_text_xy[] = {
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y                      ,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 1),
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 2),
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 3),
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 0) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 1) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 2) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 3) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y                      ,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 1),
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 2),
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 3),
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 0) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 1) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 2) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 3) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y                      ,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 1),
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 2),
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 3),
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 0) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 1) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 2) + 180,
   BATTEMP_SUB_TEXT_X,  BATTEMP_SUB_TEXT_Y + (BATTEMP_SUB_TEXT_GAP  * 3) + 180,
};

static int battempinfo_sub_text_x_offset[6] = {0,  0, 380, 380, 580, 580};
static int battempinfo_sub_text_msg_off[6] = {160, 160, 470, 470, 670, 670};


enum {
    BATT_CLASS_0_TMP_HI = 0,
    BATT_CLASS_1_TMP_LO,
    BATT_CLASS_2_LOC_BOX_TMP_H,
    BATT_CLASS_3_LOC_BOX_TMP_L,
    BATT_CLASS_4_LOC_NUM_TMP_H,
    BATT_CLASS_5_LOC_NUM_TMP_L,
    BATT_CLASS_END,
};

enum {
    BATT_DATA_0 = 0,
    BATT_DATA_1,
    BATT_DATA_2,
    BATT_DATA_3,
    BATT_DATA_END,
};


enum {
    BATT_HI_TEMP_0 = 0,
    BATT_HI_TEMP_1,
    BATT_HI_TEMP_2,
    BATT_HI_TEMP_3,
    BATT_LO_TEMP_0,
    BATT_LO_TEMP_1,
    BATT_LO_TEMP_2,
    BATT_LO_TEMP_3,
    BATT_LO_TEMP_END,
};

enum {
    BATT_BOX_HI_TEMP_0 = 0,
    BATT_BOX_HI_TEMP_1,
    BATT_BOX_HI_TEMP_2,
    BATT_BOX_HI_TEMP_3,
    BATT_BOX_LO_TEMP_0,
    BATT_BOX_LO_TEMP_1,
    BATT_BOX_LO_TEMP_2,
    BATT_BOX_LO_TEMP_3,
    BATT_BOX_LO_TEMP_END,
};

enum {
    BATT_NUM_HI_TEMP_0 = 0,
    BATT_NUM_HI_TEMP_1,
    BATT_NUM_HI_TEMP_2,
    BATT_NUM_HI_TEMP_3,
    BATT_NUM_LO_TEMP_0,
    BATT_NUM_LO_TEMP_1,
    BATT_NUM_LO_TEMP_2,
    BATT_NUM_LO_TEMP_3,
    BATT_NUM_LO_TEMP_END,
};

BatTempInfo_Page::BatTempInfo_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(BATTINFO_OBJNAME);
    int i, j, k;

    bgimg.load(BATTINFO_BG_IMG);
    tableimg.load(BATTINFO_FM_IMG);

    j = 0;
    for (i = 0; i < BATTINFO_MAS_NUM; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(battempinfo_master_text[i]);
        show_master_item[i]->setGeometry(battempinfo_master_text_xy[j], battempinfo_master_text_xy[j + 1],
                BATTEMP_MASTER_TEXT_W, BATTEMP_MASTER_TEXT_H);

        show_master_item[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 0; i < BATTINFO_TEX_COL_NUM; i++) {
        for (k = 0; k < BATTINFO_TEX_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(battempinfo_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(battempinfo_sub_text_xy[j] + battempinfo_sub_text_x_offset[i],
                                             battempinfo_sub_text_xy[j + 1],
                                             BATTEMP_SUB_TEXT_W, BATTEMP_SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = 20;
            show_sub_item[i][k]->show();

            show_sub_item_info[i][k] = new Show_text(this);
            show_sub_item_info[i][k]->set_text(battempinfo_sub_text_msg[i][k]);
            show_sub_item_info[i][k]->setGeometry(battempinfo_sub_text_xy[j] + battempinfo_sub_text_msg_off[i],
                                             battempinfo_sub_text_xy[j + 1],
                                             BATTEMP_SUB_TEXT_W, BATTEMP_SUB_TEXT_H);
            show_sub_item_info[i][k]->m_font_size = 20;
            show_sub_item_info[i][k]->show();
            j = j + 2;
        }
    }

}

void BatTempInfo_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    painter.drawPixmap(8, 20, tableimg, 0, 0, 788, 385);
}

void BatTempInfo_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    uint8_t page_data[BUFFER_SIZE];
    uint8_t u8_data_tmp;
    double d_data_tmp;
    QString str_tmp;
    int i, j;

    memcpy(page_data, protolcol_data->page_data, sizeof(uint8_t) * protolcol_data->page_data_sz);

    j = 0;
    /* temperature */
    for (i = BATT_DATA_0; i < BATT_DATA_END; i++) {
        /* HI temperature */
        d_data_tmp = double(page_data[j + 1] << 8 | page_data[j]);
        d_data_tmp = (d_data_tmp * 0.1) - 40;
        if (d_data_tmp < -40 )
            d_data_tmp = -40;

        str_tmp.sprintf("%.1f °C", d_data_tmp);
        show_sub_item_info[BATT_CLASS_0_TMP_HI][i]->set_text(str_tmp);

        /* LO temperature */
        d_data_tmp = double(page_data[j + 16 + 1] << 8 | page_data[j + 16]);
        d_data_tmp = (d_data_tmp * 0.001);
        if (d_data_tmp < 0 )
            d_data_tmp = 0;

        str_tmp.sprintf("%.1f °C", d_data_tmp);
        show_sub_item_info[BATT_CLASS_1_TMP_LO][i]->set_text(str_tmp);

        j = j + 2;
    }

    j = 0;
    /* Box */
    for (i = BATT_DATA_0; i < BATT_DATA_END; i++) {
        /* HI Temp */
        u8_data_tmp = page_data[j + 8];
        str_tmp.sprintf("%d", u8_data_tmp);
        show_sub_item_info[BATT_CLASS_2_LOC_BOX_TMP_H][i]->set_text(str_tmp);

        /* LO Temp */
        u8_data_tmp = page_data[j + 24];
        str_tmp.sprintf("%d", u8_data_tmp);
        show_sub_item_info[BATT_CLASS_3_LOC_BOX_TMP_L][i]->set_text(str_tmp);

        j = j + 1;
    }

    j = 0;
    /* Number */
    for (i = BATT_DATA_0; i < BATT_DATA_END; i++) {
        /* HI Temp */
        u8_data_tmp = page_data[j + 12];
        str_tmp.sprintf("%d", u8_data_tmp);
        show_sub_item_info[BATT_CLASS_4_LOC_NUM_TMP_H][i]->set_text(str_tmp);

        /* LO Temp */
        u8_data_tmp = page_data[j + 28];
        str_tmp.sprintf("%d", u8_data_tmp);
        show_sub_item_info[BATT_CLASS_5_LOC_NUM_TMP_L][i]->set_text(str_tmp);

        j = j + 1;
    }

    memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
}
