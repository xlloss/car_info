#include "slave_sat_in_msg_page.h"
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

QString satin_msg_sub_text[4][8] = {
                            {"J6-01", "J6-05", "J6-09", "J6-13", "J6-17", "J7-04", "J8-01", "預留"},
                            {"J6-02", "J6-06", "J6-10", "J6-14", "J6-18", "J7-05", "J8-02", "預留"},
                            {"J6-03", "J6-07", "J6-11", "J6-15", "J7-02", "J7-06", "預留", "預留"},
                            {"J6-04", "J6-08", "J6-12", "J6-16", "J7-03", "J7-07", "預留", "預留"},
                            };

QString satin_msg_sub_text_msg = "開關無效";

int satin_msg_sub_text_xy[] = {
  SUB_TEXT_X,  SUB_TEXT_Y,
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 4),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 5),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 6),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 7),
};

int satin_msg_sub_text_x_offset[4] = {0, 200, 400, 600};
int satin_msg_sub_text_msg_off[4] = {80, 280, 480, 680};

SatInMsg_Page::SatInMsg_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("SatInMsg_Page");
    int i, j, k;

    backimg.load(":/icon/rpm_page_bg.png");
    tableimg.load(":/icon/slave_sat_table.png");

    for (i = 0; i < 4; i++) {
        j = 0;
        for (k = 0; k < 8; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(satin_msg_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(satin_msg_sub_text_xy[j] + satin_msg_sub_text_x_offset[i],
                                             satin_msg_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = 20;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    for (i = 0; i < 4; i++) {
        j = 0;
        for (k = 0; k < 8; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(satin_msg_sub_text_msg);
            show_sub_item[i][k]->setGeometry(satin_msg_sub_text_xy[j] + satin_msg_sub_text_msg_off[i],
                                             satin_msg_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = 20;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void SatInMsg_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(5, 20, tableimg, 0, 0, 788, 380);
}
