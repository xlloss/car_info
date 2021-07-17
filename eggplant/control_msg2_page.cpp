#include "control_msg2_page.h"
#include <QPainter>

#define MASTER_TEXT_X 335
#define MASTER_TEXT_Y 40
#define MASTER_TEXT_W 250
#define MASTER_TEXT_H 50
#define MASTER_TEXT_GAP 50

#define SUB_TEXT_X 25
#define SUB_TEXT_Y 85
#define SUB_TEXT_W 200
#define SUB_TEXT_H 45
#define SUB_TEXT_GAP 45


QString control2_master_text[2] = {"高壓配電工作狀態"};

QString control2_sub_text[2][7] = {
                            {"K1預充電:", "K2主電機:", "K3電附件:", "K4電空調:", "K5電除霜:" , "K6電池充電:", "K6電池組內部:"},
                            {"S1高壓急斷:", "B正極絕緣電阻:", "B負極絕緣電阻:", "S正極絕緣電阻:", "S負極絕緣電阻:", ""},
						};

QString control2_sub_text_msg[2][7] = {
                            {"斷開", "斷開" , "斷開" , "斷開" , "斷開",  "斷開", "斷開"},
                            {"斷開", "00000KΩ", "00000KΩ" , "00000KΩ" , "00000KΩ"  , "",  ""},
                        };


int control2_master_text_xy[] = {
  MASTER_TEXT_X,  MASTER_TEXT_Y,
};

int control2_sub_text_xy[] = {
  SUB_TEXT_X,  SUB_TEXT_Y,
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 4),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 5),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 6),
};

int control2_sub_text_x_offset[2] = {0,  390};
int control2_sub_text_msg_off[2] = {160, 550};

ControlMsg2_Page::ControlMsg2_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("ControlMsg2_Page");
    int i, j, k;

    backimg.load(":/icon/rpm_page_bg.png");
    tableimg.load(":/icon/control_msg2.png");

    j = 0;
    for (i = 0; i < 1; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(control2_master_text[i]);
        show_master_item[i]->setGeometry(control2_master_text_xy[j], control2_master_text_xy[j + 1],
                MASTER_TEXT_W, MASTER_TEXT_H);

        show_master_item[i]->show();
        j = j + 2;
    }

    for (i = 0; i < 2; i++) {
        j = 0;
        for (k = 0; k < 7; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(control2_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(control2_sub_text_xy[j] + control2_sub_text_x_offset[i],
                                             control2_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    for (i = 0; i < 2; i++) {
        j = 0;
        for (k = 0; k < 7; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(control2_sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(control2_sub_text_xy[j] + control2_sub_text_msg_off[i],
                                             control2_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void ControlMsg2_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(8, 30, tableimg, 0, 0, 788, 360);
}
