#include "time_adjust_page.h"
#include <QPainter>

QString time_text[6] = {"時間:", "星期:", "日期:", "年", "月", "日"};
QString time_text_child[5] = {"13:00:00", "星期三", "2021", "05", "13"};


int time_text_xy[12] = {
    40, 60,
    40, 110,
    40, 160,
};

int time_text2_xy[6] = {
    230, 160,
    340, 160,
    450, 160,
};

int time_text_child_xy[10] = {
    140 , 60,
    140, 110,

    140, 160,
    280, 160,
    400, 160,
};

TimeAdjust_Page::TimeAdjust_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("TimeAdjust_Page");
    int i, j;

    backimg.load(":/icon/time_adjust.png");

    j = 0;
    for (i = 0; i < 3; i++) {
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(time_text[i]);
        show_item[i]->setGeometry(time_text_xy[j], time_text_xy[j + 1], 150, 70);
        show_item[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 3; i < 6; i++) {
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(time_text[i]);
        show_item[i]->setGeometry(time_text2_xy[j], time_text2_xy[j + 1], 150, 50);
        show_item[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 0; i < 5; i++) {
        show_item_child[i] = new Show_text(this);
        show_item_child[i]->set_text(time_text_child[i]);
        show_item_child[i]->text_color.setRgb(0, 245, 245);
        show_item_child[i]->setGeometry(time_text_child_xy[j], time_text_child_xy[j + 1], 120, 70);
        show_item_child[i]->show();
        j = j + 2;
    }

    this->setWindowState(Qt::WindowActive);
}

void TimeAdjust_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
}
