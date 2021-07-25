#include "battery_temp_info_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

QString battempinfo_master_text[BATTINFO_MAS_NUM] = {"電池溫度資訊"};

QString battempinfo_sub_text[BATTINFO_TEX_COL_NUM][BATTINFO_TEX_ROW_NUM] = {
                            {BATT_SUB_TEX_ID00, BATT_SUB_TEX_ID01, BATT_SUB_TEX_ID02, BATT_SUB_TEX_ID03},
                            {BATT_SUB_TEX_ID10, BATT_SUB_TEX_ID11, BATT_SUB_TEX_ID12, BATT_SUB_TEX_ID13},
                            {BATT_SUB_TEX_ID20, BATT_SUB_TEX_ID21, BATT_SUB_TEX_ID22, BATT_SUB_TEX_ID23},
                            {BATT_SUB_TEX_ID30, BATT_SUB_TEX_ID31, BATT_SUB_TEX_ID32, BATT_SUB_TEX_ID33},
                            {BATT_SUB_TEX_ID40, BATT_SUB_TEX_ID41, BATT_SUB_TEX_ID42, BATT_SUB_TEX_ID43},
                            {BATT_SUB_TEX_ID50, BATT_SUB_TEX_ID51, BATT_SUB_TEX_ID52, BATT_SUB_TEX_ID53},
						};

QString battempinfo_sub_text_msg[BATTINFO_TEX_COL_NUM][BATTINFO_TEX_ROW_NUM] = {
                            {BATT_MSG_TEX_ID00, BATT_MSG_TEX_ID01, BATT_MSG_TEX_ID02, BATT_MSG_TEX_ID03},
                            {BATT_MSG_TEX_ID10, BATT_MSG_TEX_ID11, BATT_MSG_TEX_ID12, BATT_MSG_TEX_ID13},
                            {BATT_MSG_TEX_ID20, BATT_MSG_TEX_ID21, BATT_MSG_TEX_ID22, BATT_MSG_TEX_ID23},
                            {BATT_MSG_TEX_ID30, BATT_MSG_TEX_ID31, BATT_MSG_TEX_ID32, BATT_MSG_TEX_ID33},
                            {BATT_MSG_TEX_ID40, BATT_MSG_TEX_ID41, BATT_MSG_TEX_ID42, BATT_MSG_TEX_ID43},
                            {BATT_MSG_TEX_ID50, BATT_MSG_TEX_ID51, BATT_MSG_TEX_ID52, BATT_MSG_TEX_ID53},
                        };


int battempinfo_master_text_xy[] = {
    BATTEMP_MASTER_TEXT_X,  BATTEMP_MASTER_TEXT_Y,
};

int battempinfo_sub_text_xy[] = {
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

int battempinfo_sub_text_x_offset[6] = {0,  0, 380, 380, 580, 580};
int battempinfo_sub_text_msg_off[6] = {160, 160, 470, 470, 670, 670};

BatTempInfo_Page::BatTempInfo_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(BATTINFO_OBJNAME);
    int i, j, k;

    backimg.load(BATTINFO_BG_IMG);
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
                                             battempinfo_sub_text_xy[j + 1], BATTEMP_SUB_TEXT_W, BATTEMP_SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = 20;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    j = 0;
    for (i = 0; i < BATTINFO_TEX_COL_NUM; i++) {
        for (k = 0; k < BATTINFO_TEX_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(battempinfo_sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(battempinfo_sub_text_xy[j] + battempinfo_sub_text_msg_off[i],
                                             battempinfo_sub_text_xy[j + 1], BATTEMP_SUB_TEXT_W, BATTEMP_SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = 20;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

}

void BatTempInfo_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    painter.drawPixmap(8, 20, tableimg, 0, 0, 788, 385);
}
