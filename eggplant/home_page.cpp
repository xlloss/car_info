#include "home_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

Home_Page::Home_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(HOME_PAGE_OBJNAME);

    //backimg.load(HOME_PAGE_BACKGROUND);
    bgimg.load(HOME_PAGE_BACKGROUND);
    if (image_car_bus.load(HOME_PAGE_BUS) == false) {
        qDebug("image_car_bus load fail");
        return;
    }
}

void Home_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg,
                       GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawImage(HOME_CARBUS_IMG_X, HOME_CARBUS_IMG_Y, image_car_bus);
}
