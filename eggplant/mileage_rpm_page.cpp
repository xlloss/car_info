#include "home_page.h"
#include <QPainter>
#include <mileage_rpm_page.h>

Mile_Page::Mile_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("Rpm_Page");

    lable_title[0] = new QLabel(this);
    lable_title[0]->setText("里程資訊");
    lable_title[0]->setFrameStyle(QFrame::NoFrame);
    lable_title[0]->setGeometry(250, 100, 100, 50);
    lable_title[0]->show();

    lable_title[1] = new QLabel(this);
    lable_title[1]->setText("轉速資訊");
    lable_title[1]->setFrameStyle(QFrame::Panel);
    lable_title[1]->setGeometry(350, 100, 100, 50);

    this->setWindowState(Qt::WindowNoState);
}

void Mile_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //QTransform trans;
    //painter.drawPixmap(0, 0, bg_img);

    //qDebug("Mile_Page:paintEvent");
    //trans.translate(bg_img.width()/2, bg_img.height()/2);
    //trans.rotate(rot_cnt);
    //trans.translate(-(bg_img.width()/2), -(bg_img.width()/2));
    //painter.setTransform(trans);
    //painter.drawImage(250, 50, image_car_bus);
}
