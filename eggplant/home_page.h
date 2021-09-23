#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "icon_btn.h"
#include "frame_page.h"
#include "show_text.h"

#define HOME_PAGE_BACKGROUND ":/icon/background.png"
#define HOME_PAGE_BUS ":/icon/bus-bg.png"
#define HOME_ITEM_FONT_DEFAULT 12
#define HOME_ITEM_TEX1_NUM 8
#define HOME_ITEM_TEX2_NUM 8
#define HOME_ITEM_TEX3_NUM 1
#define HOME_ITEM_TEX_ALL_NUM 17

#define HOME_PGE_DATA_TIME_H 3
#define HOME_PGE_DATA_TIME_M 4
#define HOME_PGE_DATA_TIME_S 5
#define HOME_PGE_DATA_SLOPE 7
#define HOME_PGE_DATA_GEAR 33
#define HOME_PGE_DATA_BATT_SAT_H 9
#define HOME_PGE_DATA_BATT_SAT_L 8
#define HOME_PGE_DATA_BATT_CSUM_H 11
#define HOME_PGE_DATA_BATT_CSUM_L 10
#define HOME_PGE_DATA_TOT_KM_BIT3 15
#define HOME_PGE_DATA_TOT_KM_BIT2 14
#define HOME_PGE_DATA_TOT_KM_BIT1 13
#define HOME_PGE_DATA_TOT_KM_BIT0 12
#define HOME_PGE_DATA_CUR_KM_BIT3 19
#define HOME_PGE_DATA_CUR_KM_BIT2 18
#define HOME_PGE_DATA_CUR_KM_BIT1 17
#define HOME_PGE_DATA_CUR_KM_BIT0 16

#define HOME_PGE_DATA_AVAI_KILO_H 21
#define HOME_PGE_DATA_AVAI_KILO_L 20


#define DOOR_TYPE_ID_F 0
#define DOOR_TYPE_ID_M 1
#define DOOR_TYPE_ID_R 2

#define F_DOOR_NAME_NUM 3
#define F_DOOR_TYPE_NUM 2

#define F_DOOR_TYPE0 ":/icon/FDoorType0.png"
#define F_DOOR_TYPE1 ":/icon/FDoorType1.png"
#define M_DOOR_TYPE0 ":/icon/MDoorType0.png"
#define M_DOOR_TYPE1 ":/icon/MDoorType1.png"
#define R_DOOR_TYPE0 ":/icon/RDoorType0.png"
#define R_DOOR_TYPE1 ":/icon/RDoorType1.png"

#define DOOR_STAUS_TYPE_DISABLE 0
#define DOOR_STAUS_TYPE_NOR_EN 1
#define DOOR_STAUS_TYPE_FOC_EN 2

#define DOOR_TYPE_F_SHIF 0
#define DOOR_TYPE_M_SHIF 2
#define DOOR_TYPE_R_SHIF 4

#define GEAR_FORW 0x01
#define GEAR_BACK 0x02
#define GEAR_EMPY 0x04
#define GEAR_PARK 0x08
#define GEAR_FORW_1 0x03
#define GEAR_FORW_2 0x05
#define GEAR_FORW_3 0x06
#define GEAR_FORW_4 0x09
#define GEAR_FORW_5 0x0A
#define GEAR_FORW_6 0x0B

#define BATT_SAT0 0
#define BATT_SAT1 1
#define BATT_SAT2 2
#define BATT_SAT3 3

class Home_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Home_Page(QWidget *parent = nullptr);
    QImage image_car_bus;
    Show_text *show_item[HOME_ITEM_TEX_ALL_NUM];
    Show_text *show_item_data[HOME_ITEM_TEX_ALL_NUM];

    Icon_btn *icon_door[3];
    void Door_Sat_Change(uint8_t door_type, uint8_t status);

    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
