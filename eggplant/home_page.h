#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "icon_btn.h"
#include "frame_page.h"
#include "show_text.h"

#define HOME_PAGE_BACKGROUND ":/icon/background.png"
#define HOME_PAGE_BUS ":/icon/bus-bg.png"
#define HOME_ITEM_TEX1_NUM 8
#define HOME_ITEM_TEX2_NUM 8
#define HOME_ITEM_TEX3_NUM 1
#define HOME_ITEM_TEX_ALL_NUM 17


#define DOOR_ID_0
#define DOOR_ID_1
#define DOOR_ID_2

#define F_DOOR_TYPE0 ":/icon/FDoorType0.png"
#define F_DOOR_TYPE1 ":/icon/FDoorType1.png"
#define M_DOOR_TYPE0 ":/icon/MDoorType0.png"
#define M_DOOR_TYPE1 ":/icon/MDoorType1.png"
#define R_DOOR_TYPE0 ":/icon/RDoorType0.png"
#define R_DOOR_TYPE1 ":/icon/RDoorType1.png"


class Home_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Home_Page(QWidget *parent = nullptr);
    QImage image_car_bus;
    Show_text *show_item[HOME_ITEM_TEX_ALL_NUM];
    Show_text *show_data[HOME_ITEM_TEX_ALL_NUM];
    Icon_btn *icon_door[3];

    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
