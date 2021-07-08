#ifndef CAR_INOUT_TEMP_PAGE_H
#define CAR_INOUT_TEMP_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

class CarInOut_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit CarInOut_Page(QWidget *parent = nullptr);

    QImage image_car_bus;
    QImage image_table;
    QPixmap backimg;
    Show_text *show_item[3];
    Show_text *show_item_child[3];

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
