#include "sw_version_page.h"
#include <QPainter>

#define SUB_TEXT_X 35
#define SUB_TEXT_Y 22
#define SUB_TEXT_W 200
#define SUB_TEXT_H 45
#define SUB_TEXT_GAP 36

QString sw_version_sub_text[2][10] = {
                                    {"儀表", "主站", "從站0", "從站1", "從站2", "從站3", "從站4", "從站5", "從站6", "從站7"},
                                    {"DATE", "DATE", "DATE", "DATE", "DATE", "DATE", "DATE", "DATE", "DATE", "DATE"},
                            };

QString sw_version_sub_text_msg[2] = {"ZB2711K-A-CZN4.2.1K", "20210313"};

int sw_version_sub_text_xy[] = {
  SUB_TEXT_X,  SUB_TEXT_Y,
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 4),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 5),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 6),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 7),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 8),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 9),
};

int sw_version_sub_text_x_offset[2] = {0, 415};
int sw_version_sub_text_msg_off[2] = {120, 520};

SwVersion_Page::SwVersion_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("SwVersion_Page");
    int i, j, k;

    backimg.load(":/icon/rpm_page_bg.png");
    tableimg.load(":/icon/sw_version_table.png");

    for (i = 0; i < 2; i++) {
        j = 0;
        for (k = 0; k < 10; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(sw_version_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(sw_version_sub_text_xy[j] + sw_version_sub_text_x_offset[i],
                                             sw_version_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    for (i = 0; i < 2; i++) {
        j = 0;
        for (k = 0; k < 10; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(sw_version_sub_text_msg[i]);
            show_sub_item[i][k]->setGeometry(sw_version_sub_text_xy[j] + sw_version_sub_text_msg_off[i],
                                             sw_version_sub_text_xy[j + 1], SUB_TEXT_W + 50, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void SwVersion_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(5, 20, tableimg, 0, 0, 788, 380);
}
