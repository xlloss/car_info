#include "control_msg1_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

QString control1_master_text[CONTROL1_MSA_TEX_NUM] = {CONTROL1_MAS_TEX_ID0, CONTROL1_MAS_TEX_ID1};

QString control1_sub_text[CONTROL1_SUB_TEX_COL_NUM][CONTROL1_SUB_TEX_ROW_NUM] = {
    {CONTROL1_SUB_TEX_ID00, CONTROL1_SUB_TEX_ID01, CONTROL1_SUB_TEX_ID02,
     CONTROL1_SUB_TEX_ID03, CONTROL1_SUB_TEX_ID04, CONTROL1_SUB_TEX_ID05},

    {CONTROL1_SUB_TEX_ID10, CONTROL1_SUB_TEX_ID11, CONTROL1_SUB_TEX_ID12,
     CONTROL1_SUB_TEX_ID13, CONTROL1_SUB_TEX_ID14, CONTROL1_SUB_TEX_ID15},

    {CONTROL1_SUB_TEX_ID20, CONTROL1_SUB_TEX_ID21, CONTROL1_SUB_TEX_ID22,
     CONTROL1_SUB_TEX_ID23, CONTROL1_SUB_TEX_ID24, CONTROL1_SUB_TEX_ID25},
    };

QString control1_sub_text_msg[CONTROL1_SUB_TEX_COL_NUM][CONTROL1_SUB_TEX_ROW_NUM] = {
    {CONTROL1_SUB_MSG_ID00, CONTROL1_SUB_MSG_ID01, CONTROL1_SUB_MSG_ID02,
     CONTROL1_SUB_MSG_ID03, CONTROL1_SUB_MSG_ID04, CONTROL1_SUB_MSG_ID05},

    {CONTROL1_SUB_MSG_ID10, CONTROL1_SUB_MSG_ID11, CONTROL1_SUB_MSG_ID12,
     CONTROL1_SUB_MSG_ID13, CONTROL1_SUB_MSG_ID14, CONTROL1_SUB_MSG_ID15},

    {CONTROL1_SUB_MSG_ID20, CONTROL1_SUB_MSG_ID21, CONTROL1_SUB_MSG_ID22,
     CONTROL1_SUB_MSG_ID23, CONTROL1_SUB_MSG_ID24, CONTROL1_SUB_MSG_ID25},

};


int control1_master_text_xy[] = {
  CONTROL1_MAS_TEX_X,  CONTROL1_MAS_TEX_Y,
  CONTROL1_MAS_TEX_X + (CONTROL1_MAS_TEX_W + 200), CONTROL1_MAS_TEX_Y,
};

int control1_sub_text_xy[] = {
  CONTROL1_SUB_TEX_X,  CONTROL1_SUB_TEX_Y,
  CONTROL1_SUB_TEX_X , CONTROL1_SUB_TEX_Y + (CONTROL1_SUB_TEX_GAP  * 1),
  CONTROL1_SUB_TEX_X , CONTROL1_SUB_TEX_Y + (CONTROL1_SUB_TEX_GAP  * 2),
  CONTROL1_SUB_TEX_X , CONTROL1_SUB_TEX_Y + (CONTROL1_SUB_TEX_GAP  * 3),
  CONTROL1_SUB_TEX_X , CONTROL1_SUB_TEX_Y + (CONTROL1_SUB_TEX_GAP  * 4),
  CONTROL1_SUB_TEX_X , CONTROL1_SUB_TEX_Y + (CONTROL1_SUB_TEX_GAP  * 5),
};

int control1_sub_text_x_offset[3] = {0,  250, 510};
int control1_sub_text_msg_off[3] = {150, 400, 670};

ControlMsg1_Page::ControlMsg1_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(CONTROL1_OBJNAME);
    int i, j, k;

    bgimg.load(CONTROL1_BG_IMG);
    tableimg.load(CONTROL1_FM_IMG);

    j = 0;
    for (i = 0; i < CONTROL1_MSA_TEX_NUM; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(control1_master_text[i]);
        show_master_item[i]->setGeometry(control1_master_text_xy[j], control1_master_text_xy[j + 1],
                CONTROL1_MAS_TEX_W, CONTROL1_MAS_TEX_H);

        show_master_item[i]->show();
        j = j + 2;
    }

    for (i = 0; i < CONTROL1_SUB_TEX_COL_NUM; i++) {
        j = 0;
        for (k = 0; k < CONTROL1_SUB_TEX_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(control1_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(control1_sub_text_xy[j] + control1_sub_text_x_offset[i],
                                             control1_sub_text_xy[j + 1], CONTROL1_SUB_TEX_W, CONTROL1_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = CONTROL1_FONT_SIZE;
            show_sub_item[i][k]->show();

            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(control1_sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(control1_sub_text_xy[j] + control1_sub_text_msg_off[i],
                                             control1_sub_text_xy[j + 1], CONTROL1_SUB_TEX_W, CONTROL1_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = CONTROL1_FONT_SIZE;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void ControlMsg1_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    painter.drawPixmap(8, 30, tableimg, 0, 0, 788, 360);
}

void ControlMsg1_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
   qDebug("SatInMsg_Page:%s page_number %d\n", __func__, protolcol_data->page_number);
}
