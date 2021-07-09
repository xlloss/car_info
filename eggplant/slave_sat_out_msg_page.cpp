#include "slave_sat_out_msg_page.h"
#include <QPainter>

#define MASTER_TEXT_X 30
#define MASTER_TEXT_Y 20
#define MASTER_TEXT_W 200
#define MASTER_TEXT_H 50
#define MASTER_TEXT_GAP 50

#define SUB_TEXT_X 30
#define SUB_TEXT_Y 30
#define SUB_TEXT_W 200
#define SUB_TEXT_H 45
#define SUB_TEXT_GAP 45

QString satout_msg_sub_text[4][8] = {
                            {"J1-01", "J1-05", "J2-04", "J3-06", "J3-10", "J3-14", "J3-21", "J3-25"},
                            {"J1-02", "J1-06", "J2-05", "J3-07", "J3-11", "J3-15", "J3-22", "預留"},
                            {"J1-03", "J1-07", "J2-06", "J3-08", "J3-12", "J3-16", "J3-23", "預留"},
                            {"J1-04", "J2-03", "J3-05", "J3-09", "J3-13", "J3-17", "J3-24", "預留"},
                            };

QString satout_msg_sub_text_msg = "正常";

int satout_msg_sub_text_xy[] = {
  SUB_TEXT_X,  SUB_TEXT_Y,
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 4),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 5),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 6),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 7),
};

int satout_msg_sub_text_x_offset[4] = {0, 200, 400, 600};
int satout_msg_sub_text_msg_off[4] = {80, 280, 480, 680};

SatOutMsg_Page::SatOutMsg_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("SatOutMsg_Page");
    int i, j, k;

    backimg.load(":/icon/rpm_page_bg.png");
    tableimg.load(":/icon/slave_sat_table.png");

    for (i = 0; i < 4; i++) {
        j = 0;
        for (k = 0; k < 8; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(satout_msg_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(satout_msg_sub_text_xy[j] + satout_msg_sub_text_x_offset[i],
                                             satout_msg_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    for (i = 0; i < 4; i++) {
        j = 0;
        for (k = 0; k < 8; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(satout_msg_sub_text_msg);
            show_sub_item[i][k]->setGeometry(satout_msg_sub_text_xy[j] + satout_msg_sub_text_msg_off[i],
                                             satout_msg_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    this->setWindowState(Qt::WindowActive);
}

void SatOutMsg_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(5, 20, tableimg, 0, 0, 788, 380);
}
