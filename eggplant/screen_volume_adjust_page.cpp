#include "screen_volume_adjust_page.h"
#include <QPainter>

#define VOL_BAR_X 220
#define VOL_BAR_Y 105
#define VOL_BAR_W 55
#define VOL_BAR_H 20
#define VOL_BAR_GAP 5

QString volume_text = "螢幕音量:";
QString volume_value = "15";

int volume_text_xy[2] = {40, 100};
int volume_value_xy[2] = {700, 100};


ScreenVolumeAdjust_Page::ScreenVolumeAdjust_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("ScreenVolumeAdjust_Page");

    backimg.load(":/icon/time_adjust.png");

    show_volume_text = new Show_text(this);
    show_volume_text->set_text(volume_text);
    show_volume_text->setGeometry(volume_text_xy[0], volume_text_xy[1], 150, 70);
    show_volume_text->show();

    show_volume_val = new Show_text(this);
    show_volume_val->set_text(volume_value);
    show_volume_val->setGeometry(volume_value_xy[0], volume_value_xy[1], 150, 70);
    show_volume_val->show();
}


void ScreenVolumeAdjust_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int i;

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);

    painter.setBrush(QBrush(QColor(0, 245, 245)));

    for (i = 0; i < 7; i++)
        painter.drawRect(VOL_BAR_X + (VOL_BAR_W + VOL_BAR_GAP) * i , 105, VOL_BAR_W, VOL_BAR_H);
}
