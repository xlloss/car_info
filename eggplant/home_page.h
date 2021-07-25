#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"

#define HOME_PAGE_OBJNAME "Home_Page"
#define HOME_PAGE_BACKGROUND ":/icon/background.png"
#define HOME_PAGE_BUS ":/icon/bus-bg.png"


class Home_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Home_Page(QWidget *parent = nullptr);
    QImage image_car_bus;

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
