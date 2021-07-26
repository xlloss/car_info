#include "battery_volt_info_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

QString batvoltinfo_master_text[1] = {BATVOL_MAS_TEX_ID0};

QString batvoltinfo_sub_text[BATTVAL_TEX_COL_NUM][BATTVAL_TEX_ROW_NUM] = {
    {BATVOL_SUB_TEX_ID00, BATVOL_SUB_TEX_ID01, BATVOL_SUB_TEX_ID02, BATVOL_SUB_TEX_ID03},
    {BATVOL_SUB_TEX_ID10, BATVOL_SUB_TEX_ID11, BATVOL_SUB_TEX_ID12, BATVOL_SUB_TEX_ID13},
    {BATVOL_SUB_TEX_ID20, BATVOL_SUB_TEX_ID21, BATVOL_SUB_TEX_ID22, BATVOL_SUB_TEX_ID23},
    {BATVOL_SUB_TEX_ID30, BATVOL_SUB_TEX_ID31, BATVOL_SUB_TEX_ID32, BATVOL_SUB_TEX_ID33},
    {BATVOL_SUB_TEX_ID40, BATVOL_SUB_TEX_ID41, BATVOL_SUB_TEX_ID42, BATVOL_SUB_TEX_ID43},
    {BATVOL_SUB_TEX_ID50, BATVOL_SUB_TEX_ID51, BATVOL_SUB_TEX_ID52, BATVOL_SUB_TEX_ID53},
};


QString batvoltinfo_sub_text_msg[BATTVAL_TEX_COL_NUM][BATTVAL_TEX_ROW_NUM] = {
    {BATVOL_MSG_TEX_ID00, BATVOL_MSG_TEX_ID01, BATVOL_MSG_TEX_ID02, BATVOL_MSG_TEX_ID03},
    {BATVOL_MSG_TEX_ID10, BATVOL_MSG_TEX_ID11, BATVOL_MSG_TEX_ID12, BATVOL_MSG_TEX_ID13},
    {BATVOL_MSG_TEX_ID20, BATVOL_MSG_TEX_ID21, BATVOL_MSG_TEX_ID22, BATVOL_MSG_TEX_ID23},
    {BATVOL_MSG_TEX_ID30, BATVOL_MSG_TEX_ID31, BATVOL_MSG_TEX_ID32, BATVOL_MSG_TEX_ID33},
    {BATVOL_MSG_TEX_ID40, BATVOL_MSG_TEX_ID41, BATVOL_MSG_TEX_ID42, BATVOL_MSG_TEX_ID43},
    {BATVOL_MSG_TEX_ID50, BATVOL_MSG_TEX_ID51, BATVOL_MSG_TEX_ID52, BATVOL_MSG_TEX_ID53},
};


int batvoltinfo_master_text_xy[] = {
  BATVOL_MASTER_TEXT_X,  BATVOL_MASTER_TEXT_Y,
};

int batvoltinfo_sub_text_xy[] = {
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y                      ,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 1),
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 2),
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 3),
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 0) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 1) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 2) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 3) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y                      ,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 1),
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 2),
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 3),
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 0) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 1) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 2) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 3) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y                      ,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 1),
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 2),
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 3),
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 0) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 1) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 2) + 180,
   BATVOL_SUB_TEXT_X,  BATVOL_SUB_TEXT_Y + (BATVOL_SUB_TEXT_GAP  * 3) + 180,
};

int batvoltinfo_sub_text_x_offset[6] = {0,  0, 380, 380, 580, 580};
int batvoltinfo_sub_text_msg_off[6] = {160, 160, 470, 470, 670, 670};


BatVoltInfo_Page::BatVoltInfo_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(BATTVAL_OBJNAME);
    int i, j, k;

    bgimg.load(BATTVAL_BG_IMG);
    tableimg.load(BATTVAL_FM_IMG);

    j = 0;
    for (i = 0; i < BATTVAL_MAS_NUM; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(batvoltinfo_master_text[i]);
        show_master_item[i]->setGeometry(batvoltinfo_master_text_xy[j], batvoltinfo_master_text_xy[j + 1],
                BATVOL_MASTER_TEXT_W, BATVOL_MASTER_TEXT_H);

        show_master_item[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 0; i < BATTVAL_TEX_COL_NUM; i++) {
        for (k = 0; k < BATTVAL_TEX_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(batvoltinfo_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(batvoltinfo_sub_text_xy[j] + batvoltinfo_sub_text_x_offset[i],
                                             batvoltinfo_sub_text_xy[j + 1], BATVOL_SUB_TEXT_W, BATVOL_SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = BATTVAL_TEX_FONT_SIZE;
            show_sub_item[i][k]->show();
//            j = j + 2;
//        }
//    }
//
//    j = 0;
//    for (i = 0; i < BATTVAL_TEX_COL_NUM; i++) {
//        for (k = 0; k < BATTVAL_TEX_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(batvoltinfo_sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(batvoltinfo_sub_text_xy[j] + batvoltinfo_sub_text_msg_off[i],
                                             batvoltinfo_sub_text_xy[j + 1], BATVOL_SUB_TEXT_W, BATVOL_SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = BATTVAL_TEX_FONT_SIZE;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

}

void BatVoltInfo_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawPixmap(8, 20, tableimg, 0, 0, 788, 385);
}

void BatVoltInfo_Page::GetMcuData()
{
    qDebug("BatVoltInfo_Page:%s\n", __func__);
}
