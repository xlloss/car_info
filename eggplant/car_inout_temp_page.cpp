#include "car_inout_temp_page.h"
#include <QPainter>

CarInOut_Page::CarInOut_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("CarInOut_Page");

    backimg.load(":/icon/background.png");

    if (image_car_bus.load(":/icon/bus-bg.png") == false) {
        qDebug("image_car_bus load fail");
        return;
    }

    this->setWindowState(Qt::WindowActive);
}

void CarInOut_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawImage(190, 80, image_car_bus);
}
