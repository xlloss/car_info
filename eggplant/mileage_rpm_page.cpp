#include "home_page.h"
#include <QPainter>
#include <mileage_rpm_page.h>

QString str_img_id[8] = {
    {ID_STR_IMG_0},
    {ID_STR_IMG_1},
    {ID_STR_IMG_2},
    {ID_STR_IMG_3},
    {ID_STR_IMG_4},
    {ID_STR_IMG_5},
    {ID_STR_IMG_6},
    {ID_STR_IMG_7},
};

int str_img_xy[8][2] = {
    {150, 45, },    //ID_STR_IMG_0
    {20, 110, },    //ID_STR_IMG_1
    {30, 170, },    //ID_STR_IMG_2
    {25, 270, },    //ID_STR_IMG_3

    {550, 45,},    //ID_STR_IMG_4
    {430, 110,},    //ID_STR_IMG_5
    {430, 170,},    //ID_STR_IMG_6
    {430, 270,},    //ID_STR_IMG_7
};

int btn_img_xy[8] = {
    230, 200,
    230, 300,
    650, 200,
    650, 300,
};

int show_text_xy[12] = {
    140, 115,
    40, 215,
    40, 315,

    580, 115,
    430, 215,
    430, 315,
};

QString show_text_default[6] = {
    "012345678Km",
    "0000.2Km",
    "0204.9Km",
    "000002040Kr",
    "000000002h",
    "100000002h"
};

QString rpm_page_btn_objname[4] = {
    "set_zero_0",
    "set_zero_0",
    "set_zero_1",
    "set_zero_2",
};

QString rpm_page_btn_name = "歸零";

Mile_Page::Mile_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("Rpm_Page");
    int i, j;

    backimg.load(":/icon/rpm_page_bg.png");
    backimg2.load(":/icon/rpm_page_bg_2.png");

    for (i = 0; i < 8; i++) {
        str_img[i].load(str_img_id[i]);
    }

    j = 0;
    for (i = 0; i < 4; i++) {
        btn[i] = new Icon_btn(this);
        btn[i]->setObjectName(rpm_page_btn_objname[i]);
        btn[i]->enable_scale = 0;

        btn[i]->load_image_ft(":/icon/rpm_btn.png", ":/icon/rpm_btn_press.png");
        btn[i]->setGeometry(btn_img_xy[j], btn_img_xy[j + 1], 120, 40);

        btn[i]->set_text(rpm_page_btn_name);
        btn[i]->m_set_text_y = 30;
        j = j + 2;
    }

    j = 0;
    for (i = 0; i < 6; i++) {
        show_string[i] = new Show_text(this);
        show_string[i]->set_text(show_text_default[i]);
        show_string[i]->setGeometry(show_text_xy[j], show_text_xy[j + 1], 200, 70);
        show_string[i]->show();
        j = j + 2;
    }
    this->setWindowState(Qt::WindowNoState);
}

void Mile_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int i;

    painter.setBrush(QBrush(Qt::black));
    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(8, 30, backimg2, 0, 0, 788, 360);

    for (i = 0; i < 8; i++)
        painter.drawImage(str_img_xy[i][0], str_img_xy[i][1], str_img[i]);
}
