#include "sw_version_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

QString sw_version_sub_text[SW_VER_SUB_TEX_COL_NUM][SW_VER_SUB_TEX_ROW_NUM] = {
    {SWVER_SUB_TEX_ID00, SWVER_SUB_TEX_ID01, SWVER_SUB_TEX_ID02, SWVER_SUB_TEX_ID03, SWVER_SUB_TEX_ID04,
     SWVER_SUB_TEX_ID05, SWVER_SUB_TEX_ID06, SWVER_SUB_TEX_ID07, SWVER_SUB_TEX_ID08, SWVER_SUB_TEX_ID09},

    {SWVER_SUB_TEX_ID10, SWVER_SUB_TEX_ID11, SWVER_SUB_TEX_ID12, SWVER_SUB_TEX_ID13, SWVER_SUB_TEX_ID14,
     SWVER_SUB_TEX_ID15, SWVER_SUB_TEX_ID16, SWVER_SUB_TEX_ID17, SWVER_SUB_TEX_ID18, SWVER_SUB_TEX_ID19},
};


QString sw_version_sub_text_msg[SW_VER_SUB_TEX_MSG_NUM] = {SATIN_MSG_SUB_TEX_MSG_ID0, SATIN_MSG_SUB_TEX_MSG_ID1};

int sw_version_sub_text_xy[] = {
  SWVER_SUB_TEX_X,  SWVER_SUB_TEX_Y,
  SWVER_SUB_TEX_X , SWVER_SUB_TEX_Y + (SWVER_SUB_TEX_GAP  * 1),
  SWVER_SUB_TEX_X , SWVER_SUB_TEX_Y + (SWVER_SUB_TEX_GAP  * 2),
  SWVER_SUB_TEX_X , SWVER_SUB_TEX_Y + (SWVER_SUB_TEX_GAP  * 3),
  SWVER_SUB_TEX_X , SWVER_SUB_TEX_Y + (SWVER_SUB_TEX_GAP  * 4),
  SWVER_SUB_TEX_X , SWVER_SUB_TEX_Y + (SWVER_SUB_TEX_GAP  * 5),
  SWVER_SUB_TEX_X , SWVER_SUB_TEX_Y + (SWVER_SUB_TEX_GAP  * 6),
  SWVER_SUB_TEX_X , SWVER_SUB_TEX_Y + (SWVER_SUB_TEX_GAP  * 7),
  SWVER_SUB_TEX_X , SWVER_SUB_TEX_Y + (SWVER_SUB_TEX_GAP  * 8),
  SWVER_SUB_TEX_X , SWVER_SUB_TEX_Y + (SWVER_SUB_TEX_GAP  * 9),
};

int sw_version_sub_text_x_offset[2] = {0, 415};
int sw_version_sub_text_msg_off[2] = {120, 520};


SwVersion_Page::SwVersion_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(SWVER_OBJNAME);
    int i, j, k;

    bgimg.load(SWVER_BG_IMG);
    tableimg.load(SWVER_FM_IMG);

    for (i = 0; i < SW_VER_SUB_TEX_COL_NUM; i++) {
        j = 0;
        for (k = 0; k < SW_VER_SUB_TEX_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(sw_version_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(sw_version_sub_text_xy[j] + sw_version_sub_text_x_offset[i],
                                             sw_version_sub_text_xy[j + 1], SWVER_SUB_TEX_W, SWVER_SUB_TEX_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();

            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(sw_version_sub_text_msg[i]);
            show_sub_item[i][k]->setGeometry(sw_version_sub_text_xy[j] + sw_version_sub_text_msg_off[i],
                                             sw_version_sub_text_xy[j + 1], SWVER_SUB_TEX_W + 50, SWVER_SUB_TEX_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void SwVersion_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawPixmap(5, 20, tableimg, 0, 0, 788, 380);
}

void SwVersion_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    qDebug("SatInMsg_Page:%s page_number %d\n", __func__, protolcol_data->page_number);
}
