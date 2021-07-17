#include "battery_volt_info_page.h"
#include <QPainter>

#define MASTER_TEXT_X 335
#define MASTER_TEXT_Y 30
#define MASTER_TEXT_W 200
#define MASTER_TEXT_H 50
#define MASTER_TEXT_GAP 50

#define SUB_TEXT_X 25
#define SUB_TEXT_Y 70
#define SUB_TEXT_W 200
#define SUB_TEXT_H 45
#define SUB_TEXT_GAP 40


QString batvoltinfo_master_text[1] = {"電池電壓資訊"};

QString batvoltinfo_sub_text[6][4] = {
                            {"單體第一高電壓:", "單體第一高電壓:", "單體第一高電壓:", "單體第一高電壓:"},
                            {"單體第一低電壓:", "單體第一低電壓:", "單體第一低電壓:", "單體第一低電壓:"},
                            {"位置(箱):", "位置(箱):", "位置(箱):", "位置(箱):"},
                            {"位置(箱):", "位置(箱):", "位置(箱):", "位置(箱):"},
                            {"位置(號):", "位置(號):", "位置(號):", "位置(號):"},
                            {"位置(號):", "位置(號):", "位置(號):", "位置(號):"},
						};

QString batvoltinfo_sub_text_msg[6][4] = {
                            {"003.32V", "003.32V" , "003.32V" , "003.32V"},
                            {"003.32V", "003.32V" , "003.32V" , "003.32V"},
                            {"001", "001", "001", "001"},
                            {"001", "001", "001", "001"},
                            {"001", "001", "001", "001"},
                            {"001", "001", "001", "001"},
                        };


int batvoltinfo_master_text_xy[] = {
  MASTER_TEXT_X,  MASTER_TEXT_Y,
};

int batvoltinfo_sub_text_xy[] = {
   SUB_TEXT_X,  SUB_TEXT_Y                      ,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),

   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 0) + 180,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 1) + 180,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 2) + 180,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 3) + 180,

   SUB_TEXT_X,  SUB_TEXT_Y                      ,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),

   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 0) + 180,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 1) + 180,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 2) + 180,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 3) + 180,

   SUB_TEXT_X,  SUB_TEXT_Y                      ,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),

   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 0) + 180,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 1) + 180,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 2) + 180,
   SUB_TEXT_X,  SUB_TEXT_Y + (SUB_TEXT_GAP  * 3) + 180,
};

int batvoltinfo_sub_text_x_offset[6] = {0,  0, 380, 380, 580, 580};
int batvoltinfo_sub_text_msg_off[6] = {160, 160, 470, 470, 670, 670};

BatVoltInfo_Page::BatVoltInfo_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("BatVoltInfo_Page");
    int i, j, k;

    backimg.load(":/icon/rpm_page_bg.png");
    tableimg.load(":/icon/battery-info.png");

    j = 0;
    for (i = 0; i < 1; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(batvoltinfo_master_text[i]);
        show_master_item[i]->setGeometry(batvoltinfo_master_text_xy[j], batvoltinfo_master_text_xy[j + 1],
                MASTER_TEXT_W, MASTER_TEXT_H);

        show_master_item[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 0; i < 6; i++) {
        for (k = 0; k < 4; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(batvoltinfo_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(batvoltinfo_sub_text_xy[j] + batvoltinfo_sub_text_x_offset[i],
                                             batvoltinfo_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    j = 0;
    for (i = 0; i < 6; i++) {
        for (k = 0; k < 4; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(batvoltinfo_sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(batvoltinfo_sub_text_xy[j] + batvoltinfo_sub_text_msg_off[i],
                                             batvoltinfo_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

}

void BatVoltInfo_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(8, 20, tableimg, 0, 0, 788, 385);
}
