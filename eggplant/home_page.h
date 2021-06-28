#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"


class Home_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Home_Page(QWidget *parent = nullptr);

    QImage image_car_bus;
    QPixmap backimg;

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
