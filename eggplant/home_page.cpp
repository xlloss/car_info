#include "home_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"


QString item1_text[HOME_ITEM_TEX1_NUM] = {
    HOME_ITEM_TEX_DATE_TIME,
    HOME_ITEM_TEX_SLOPE,
    HOME_ITEM_TEX_GEAR_SAT,
    HOME_ITEM_TEX_BATT_SAT,
    HOME_ITEM_TEX_IMM_PWR_CONSUMP,
    HOME_ITEM_TEX_TOTAL_MILEAGE,
    HOME_ITEM_TEX_PRE_MILEAGE,
    HOME_ITEM_TEX_AVAILABLE_MILE
};

QString item2_text[HOME_ITEM_TEX2_NUM] = {
    HOME_ITEM_TEX_MOTO_TEMP,
    HOME_ITEM_TEX_BATT_PACK,
    HOME_ITEM_TEX_SMALL_VOLAT,
    HOME_ITEM_TEX_TOTAL_VOLT,
    HOME_ITEM_TEX_TOTAL_CURREN,
    HOME_ITEM_TEX_BATT_SOC,
    HOME_ITEM_TEX_FRONT_AIR_PRESSURE,
    HOME_ITEM_TEX_BEHIND_AIR_PRESSURE
};

Home_Page::Home_Page(QWidget *parent) : Frame_Page(parent)
{
    int i;

    this->setObjectName(HOME_PAGE_OBJNAME);

    bgimg.load(HOME_PAGE_BACKGROUND);
    if (image_car_bus.load(HOME_PAGE_BUS) == false) {
        qDebug("image_car_bus load fail");
        return;
    }

    image_car_bus = image_car_bus.scaled(294, 175);

    for (i = 0; i < HOME_ITEM_TEX1_NUM; i++) {
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(item1_text[i]);
        show_item[i]->m_font_size = 12;
        show_item[i]->setGeometry(HOME_ITEM_TEX1_X,
            HOME_ITEM_TEX1_Y + HOME_ITEM_TEX1_Y_OFF * i,
            HOME_ITEM_TEX1_W, HOME_ITEM_TEX1_H);

        show_item[i]->show();

        show_item[i + 8] = new Show_text(this);
        show_item[i + 8]->set_text(item2_text[i]);
        show_item[i + 8]->m_font_size = 12;
        show_item[i + 8]->setGeometry(HOME_ITEM_TEX2_X,
            HOME_ITEM_TEX2_Y + HOME_ITEM_TEX2_Y_OFF * i,
            HOME_ITEM_TEX1_W, HOME_ITEM_TEX2_H);

        show_item[i + 8]->show();
    }


    show_item[HOME_ITEM_TEX_ALL_NUM - 1] = new Show_text(this);
    show_item[HOME_ITEM_TEX_ALL_NUM - 1]->set_text(HOME_ITEM_TEX_ALARM_MSG);
    show_item[HOME_ITEM_TEX_ALL_NUM - 1]->m_font_size = 12;
    show_item[HOME_ITEM_TEX_ALL_NUM - 1]->setGeometry(HOME_ITEM_TEX3_X, HOME_ITEM_TEX3_Y,
        HOME_ITEM_TEX3_W, HOME_ITEM_TEX3_H);

    show_item[HOME_ITEM_TEX_ALL_NUM - 1]->show();

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
