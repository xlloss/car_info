#include "slave_sat_in_msg_page.h"
#include <QPainter>
#include "string/string.h"
#include "coordinate.h"

QString satin_msg_sub_text[4][8] = {
    {SATIN_SUB_TEX_ID00, SATIN_SUB_TEX_ID01, SATIN_SUB_TEX_ID02, SATIN_SUB_TEX_ID03,
     SATIN_SUB_TEX_ID04, SATIN_SUB_TEX_ID05, SATIN_SUB_TEX_ID06, SATIN_SUB_TEX_ID07},
    {SATIN_SUB_TEX_ID10, SATIN_SUB_TEX_ID11, SATIN_SUB_TEX_ID12, SATIN_SUB_TEX_ID13,
     SATIN_SUB_TEX_ID14, SATIN_SUB_TEX_ID15, SATIN_SUB_TEX_ID16, SATIN_SUB_TEX_ID17},
    {SATIN_SUB_TEX_ID20, SATIN_SUB_TEX_ID21, SATIN_SUB_TEX_ID22, SATIN_SUB_TEX_ID23,
     SATIN_SUB_TEX_ID24, SATIN_SUB_TEX_ID25, SATIN_SUB_TEX_ID26, SATIN_SUB_TEX_ID27},
    {SATIN_SUB_TEX_ID30, SATIN_SUB_TEX_ID31, SATIN_SUB_TEX_ID32, SATIN_SUB_TEX_ID33,
     SATIN_SUB_TEX_ID34, SATIN_SUB_TEX_ID35, SATIN_SUB_TEX_ID36, SATIN_SUB_TEX_ID37},
};

int satin_msg_sub_text_xy[] = {
  SATIN_SUB_TEX_X, SATIN_SUB_TEX_Y,
  SATIN_SUB_TEX_X, SATIN_SUB_TEX_Y + (SATIN_SUB_TEX_GAP  * 1),
  SATIN_SUB_TEX_X, SATIN_SUB_TEX_Y + (SATIN_SUB_TEX_GAP  * 2),
  SATIN_SUB_TEX_X, SATIN_SUB_TEX_Y + (SATIN_SUB_TEX_GAP  * 3),
  SATIN_SUB_TEX_X, SATIN_SUB_TEX_Y + (SATIN_SUB_TEX_GAP  * 4),
  SATIN_SUB_TEX_X, SATIN_SUB_TEX_Y + (SATIN_SUB_TEX_GAP  * 5),
  SATIN_SUB_TEX_X, SATIN_SUB_TEX_Y + (SATIN_SUB_TEX_GAP  * 6),
  SATIN_SUB_TEX_X, SATIN_SUB_TEX_Y + (SATIN_SUB_TEX_GAP  * 7),
};

int satin_msg_sub_text_x_offset[4] = {0, 200, 400, 600};
int satin_msg_sub_text_msg_off[4] = {80, 280, 480, 680};


SatInMsg_Page::SatInMsg_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(SATIN_OBJNAME);
    int i, j, k;

    bgimg.load(SATIN_BG_IMG);
    tableimg.load(SATIN_FM_IMG);

    for (i = 0; i < SATIN_SUB_ITEM_COL_NUM; i++) {
        j = 0;
        for (k = 0; k < SATIN_SUB_ITEM_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(satin_msg_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(satin_msg_sub_text_xy[j] + satin_msg_sub_text_x_offset[i],
                                             satin_msg_sub_text_xy[j + 1], SATIN_SUB_TEX_W, SATIN_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = SATIN_SUB_ITEM_FONT_SIZE;
            show_sub_item[i][k]->show();

            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(SATIN_MSG_SUB_TEX_MSG);
            show_sub_item[i][k]->setGeometry(satin_msg_sub_text_xy[j] + satin_msg_sub_text_msg_off[i],
                                             satin_msg_sub_text_xy[j + 1], SATIN_SUB_TEX_W, SATIN_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = SATIN_SUB_ITEM_FONT_SIZE;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void SatInMsg_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawPixmap(5, 20, tableimg, 0, 0, 788, 380);
}
