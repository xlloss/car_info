#include "home_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

#define HOME_ITEM_TEX1_X 10
#define HOME_ITEM_TEX1_Y 80

#define HOME_ITEM_TEX2_X 630
#define HOME_ITEM_TEX2_Y 80

#define HOME_ITEM_TEX3_X 180
#define HOME_ITEM_TEX3_Y 450

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

void Home_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    qDebug("Home_Page:%s\n", __func__);
}
