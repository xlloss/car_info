#ifndef CAR_INOUT_TEMP_PAGE_H
#define CAR_INOUT_TEMP_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"


class CarInOut_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit CarInOut_Page(QWidget *parent = nullptr);

    QImage image_car_bus;
    QPixmap backimg;

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
