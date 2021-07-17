#include "temp_module_page.h"
#include <QPainter>

#define MASTER_TEXT_X 30
#define MASTER_TEXT_Y 20
#define MASTER_TEXT_W 200
#define MASTER_TEXT_H 50
#define MASTER_TEXT_GAP 50

#define SUB_TEXT_X 30
#define SUB_TEXT_Y 40
#define SUB_TEXT_W 200
#define SUB_TEXT_H 45
#define SUB_TEXT_GAP 45

QString tempmodule_sub_text[2][8] = {
                            {"主站模塊",  "從站模塊1", "從站模塊3", "從站模塊5", "從站模塊7", "胎壓模塊1", "胎壓模塊2", "胎壓模塊3"},
                            {"從站模塊0", "從站模塊2", "從站模塊4", "從站模塊6", "", "", "", "",},
						};

QString tempmodule_sub_text_msg[2][8] = {
                            {"00°C", "00°C" , "00°C" , "00°C"  , "00°C", "在線", "在線", "在線"},
                            {"00°C", "00°C" , "00°C" , "00°C"  , "",  "",  "",  ""},
                        };

int tempmodule_sub_text_xy[] = {
  SUB_TEXT_X,  SUB_TEXT_Y,
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 4),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 5),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 6),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 7),
};

int tempmodule_sub_text_x_offset[2] = {0,  400};
int tempmodule_sub_text_msg_off[2] = {210, 600};

TempModule_Page::TempModule_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("TempModule_Page");
    int i, j, k;

    backimg.load(":/icon/rpm_page_bg.png");
    tableimg.load(":/icon/temp_module.png");

    for (i = 0; i < 2; i++) {
        j = 0;
        for (k = 0; k < 8; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(tempmodule_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(tempmodule_sub_text_xy[j] + tempmodule_sub_text_x_offset[i],
                                             tempmodule_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    for (i = 0; i < 2; i++) {
        j = 0;
        for (k = 0; k < 8; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(tempmodule_sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(tempmodule_sub_text_xy[j] + tempmodule_sub_text_msg_off[i],
                                             tempmodule_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void TempModule_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(5, 20, tableimg, 0, 0, 788, 380);
}
