#include "slave_sat_out_msg_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

QString satout_msg_sub_text[SATOUT_MSG_COL_NUM][SATOUT_MSG_ROW_NUM] = {
    {SATOUT_SUB_TEX_ID00, SATOUT_SUB_TEX_ID01, SATOUT_SUB_TEX_ID02, SATOUT_SUB_TEX_ID03,
     SATOUT_SUB_TEX_ID04, SATOUT_SUB_TEX_ID05, SATOUT_SUB_TEX_ID06, SATOUT_SUB_TEX_ID07},
    {SATOUT_SUB_TEX_ID10, SATOUT_SUB_TEX_ID11, SATOUT_SUB_TEX_ID12, SATOUT_SUB_TEX_ID13,
     SATOUT_SUB_TEX_ID14, SATOUT_SUB_TEX_ID15, SATOUT_SUB_TEX_ID16, SATOUT_SUB_TEX_ID17},
    {SATOUT_SUB_TEX_ID20, SATOUT_SUB_TEX_ID21, SATOUT_SUB_TEX_ID22, SATOUT_SUB_TEX_ID23,
     SATOUT_SUB_TEX_ID24, SATOUT_SUB_TEX_ID25, SATOUT_SUB_TEX_ID26, SATOUT_SUB_TEX_ID27},
    {SATOUT_SUB_TEX_ID30, SATOUT_SUB_TEX_ID31, SATOUT_SUB_TEX_ID32, SATOUT_SUB_TEX_ID33,
     SATOUT_SUB_TEX_ID34, SATOUT_SUB_TEX_ID35, SATOUT_SUB_TEX_ID36, SATOUT_SUB_TEX_ID37},
};

int satout_msg_sub_text_xy[] = {
  SATOUT_SUB_TEX_X,  SATOUT_SUB_TEX_Y,
  SATOUT_SUB_TEX_X , SATOUT_SUB_TEX_Y + (SATOUT_SUB_TEX_GAP  * 1),
  SATOUT_SUB_TEX_X , SATOUT_SUB_TEX_Y + (SATOUT_SUB_TEX_GAP  * 2),
  SATOUT_SUB_TEX_X , SATOUT_SUB_TEX_Y + (SATOUT_SUB_TEX_GAP  * 3),
  SATOUT_SUB_TEX_X , SATOUT_SUB_TEX_Y + (SATOUT_SUB_TEX_GAP  * 4),
  SATOUT_SUB_TEX_X , SATOUT_SUB_TEX_Y + (SATOUT_SUB_TEX_GAP  * 5),
  SATOUT_SUB_TEX_X , SATOUT_SUB_TEX_Y + (SATOUT_SUB_TEX_GAP  * 6),
  SATOUT_SUB_TEX_X , SATOUT_SUB_TEX_Y + (SATOUT_SUB_TEX_GAP  * 7),
};

int satout_msg_sub_text_x_offset[4] = {0, 200, 400, 600};
int satout_msg_sub_text_msg_off[4] = {80, 280, 480, 680};


SatOutMsg_Page::SatOutMsg_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(SATOUT_BOJNAME);
    int i, j, k;

    backimg.load(SATOUT_BG_IMG);
    tableimg.load(SATOUT_FM_IMG);

    for (i = 0; i < SATOUT_MSG_COL_NUM; i++) {
        j = 0;
        for (k = 0; k < SATOUT_MSG_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(satout_msg_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(satout_msg_sub_text_xy[j] + satout_msg_sub_text_x_offset[i],
                                             satout_msg_sub_text_xy[j + 1], SATOUT_SUB_TEX_W, SATOUT_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = SATOUT_FONT_SIZE;
            show_sub_item[i][k]->show();

            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(SATOUT_MSG_SUB_TEX_MSG);
            show_sub_item[i][k]->setGeometry(satout_msg_sub_text_xy[j] + satout_msg_sub_text_msg_off[i],
                                             satout_msg_sub_text_xy[j + 1], SATOUT_SUB_TEX_W, SATOUT_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = SATOUT_FONT_SIZE;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void SatOutMsg_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    painter.drawPixmap(5, 20, tableimg, 0, 0, 788, 380);
}

void SatOutMsg_Page::GetMcuData()
{
    qDebug("SatOutMsg_Page:%s\n", __func__);
}
