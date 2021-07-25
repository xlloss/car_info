#include "control_msg2_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"


QString control2_master_text[CONTROL2_MSA_TEX_NUM] = {CONTROL2_MAS_TEX_ID0};

QString control2_sub_text[CONTROL2_SUB_TEX_COL_NUM][CONTROL2_SUB_TEX_ROW_NUM] = {
    {CONTROL2_SUB_TEX_ID00, CONTROL2_SUB_TEX_ID01, CONTROL2_SUB_TEX_ID02,
     CONTROL2_SUB_TEX_ID03, CONTROL2_SUB_TEX_ID04, CONTROL2_SUB_TEX_ID05, CONTROL2_SUB_TEX_ID06},

    {CONTROL2_SUB_TEX_ID10, CONTROL2_SUB_TEX_ID11, CONTROL2_SUB_TEX_ID12,
     CONTROL2_SUB_TEX_ID13, CONTROL2_SUB_TEX_ID14, CONTROL2_SUB_TEX_ID15, CONTROL2_SUB_TEX_ID16},
};

QString control2_sub_text_msg[CONTROL2_SUB_TEX_COL_NUM][CONTROL2_SUB_TEX_ROW_NUM] = {
    {CONTROL2_SUB_MSG_ID00, CONTROL2_SUB_MSG_ID01, CONTROL2_SUB_MSG_ID02,
     CONTROL2_SUB_MSG_ID03, CONTROL2_SUB_MSG_ID04, CONTROL2_SUB_MSG_ID05, CONTROL2_SUB_TEX_ID06},

    {CONTROL2_SUB_MSG_ID10, CONTROL2_SUB_MSG_ID11, CONTROL2_SUB_MSG_ID12,
     CONTROL2_SUB_MSG_ID13, CONTROL2_SUB_MSG_ID14, CONTROL2_SUB_MSG_ID15, CONTROL2_SUB_MSG_ID16},
};


int control2_master_text_xy[] = {
  CONTROL2_MAS_TEX_X,  CONTROL2_MAS_TEX_Y,
};

int control2_sub_text_xy[] = {
  CONTROL2_SUB_TEX_X,  CONTROL2_SUB_TEX_Y,
  CONTROL2_SUB_TEX_X , CONTROL2_SUB_TEX_Y + (CONTROL2_SUB_TEX_GAP  * 1),
  CONTROL2_SUB_TEX_X , CONTROL2_SUB_TEX_Y + (CONTROL2_SUB_TEX_GAP  * 2),
  CONTROL2_SUB_TEX_X , CONTROL2_SUB_TEX_Y + (CONTROL2_SUB_TEX_GAP  * 3),
  CONTROL2_SUB_TEX_X , CONTROL2_SUB_TEX_Y + (CONTROL2_SUB_TEX_GAP  * 4),
  CONTROL2_SUB_TEX_X , CONTROL2_SUB_TEX_Y + (CONTROL2_SUB_TEX_GAP  * 5),
  CONTROL2_SUB_TEX_X , CONTROL2_SUB_TEX_Y + (CONTROL2_SUB_TEX_GAP  * 6),
};

int control2_sub_text_x_offset[2] = {0,  390};
int control2_sub_text_msg_off[2] = {160, 550};


ControlMsg2_Page::ControlMsg2_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(CONTROL2_OBJNAME);
    int i, j, k;

    backimg.load(CONTROL2_BG_IMG);
    tableimg.load(CONTROL2_FM_IMG);

    j = 0;
    for (i = 0; i < CONTROL2_MSA_TEX_NUM; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(control2_master_text[i]);
        show_master_item[i]->setGeometry(control2_master_text_xy[j], control2_master_text_xy[j + 1],
                CONTROL2_MAS_TEX_W, CONTROL2_MAS_TEX_H);

        show_master_item[i]->show();
        j = j + 2;
    }

    for (i = 0; i < CONTROL2_SUB_TEX_COL_NUM; i++) {
        j = 0;
        for (k = 0; k < CONTROL2_SUB_TEX_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(control2_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(control2_sub_text_xy[j] + control2_sub_text_x_offset[i],
                                             control2_sub_text_xy[j + 1], CONTROL2_SUB_TEX_W, CONTROL2_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = 20;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    for (i = 0; i < CONTROL2_SUB_TEX_COL_NUM; i++) {
        j = 0;
        for (k = 0; k < CONTROL2_SUB_TEX_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(control2_sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(control2_sub_text_xy[j] + control2_sub_text_msg_off[i],
                                             control2_sub_text_xy[j + 1], CONTROL2_SUB_TEX_W, CONTROL2_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = 20;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void ControlMsg2_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    painter.drawPixmap(8, 30, tableimg, 0, 0, 788, 360);
}
