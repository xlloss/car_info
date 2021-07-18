#include "home_page.h"
#include <QPainter>


Home_Page::Home_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("Home_Page");

    backimg.load(":/icon/background.png");

    if (image_car_bus.load(":/icon/bus-bg.png") == false) {
        qDebug("image_car_bus load fail");
        return;
    }

    this->setWindowState(Qt::WindowActive);
}

void Home_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawImage(190, 80, image_car_bus);
}
