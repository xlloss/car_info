#include "home_page.h"
#include <QPainter>

Home_Page::Home_Page(QWidget *parent) : Frame_Page(parent)
{
    if (image_car_bus.load(":/icon/bus.png") == false) {
        qDebug("image_car_bus load fail");
        return;
    }

    image_car_bus = image_car_bus.scaled(300, 400);
    this->setWindowState(Qt::WindowMinimized);
}

void Home_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //QTransform trans;
    //painter.drawPixmap(0, 0, bg_img);

    qDebug("Home_Page:paintEvent");
    //trans.translate(bg_img.width()/2, bg_img.height()/2);
    //trans.rotate(rot_cnt);
    //trans.translate(-(bg_img.width()/2), -(bg_img.width()/2));
    //painter.setTransform(trans);
    painter.drawImage(250, 50, image_car_bus);
}
