#include "home_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"


static QString door_name[3][2] = {
        {F_DOOR_TYPE0,  F_DOOR_TYPE1},
        {M_DOOR_TYPE0,  M_DOOR_TYPE1},
        {R_DOOR_TYPE0,  R_DOOR_TYPE1},
};

static int door_coord_xy[3][2] = {
        {HOME_CARBUS_IMG_X,  HOME_CARBUS_IMG_Y},
        {HOME_CARBUS_IMG_X,  HOME_CARBUS_IMG_Y},
        {HOME_CARBUS_IMG_X,  HOME_CARBUS_IMG_Y},
};

static QString item1_text[HOME_ITEM_TEX1_NUM] = {
    HOME_ITEM_TEX_DATE_TIME,
    HOME_ITEM_TEX_SLOPE,
    HOME_ITEM_TEX_GEAR_SAT,
    HOME_ITEM_TEX_BATT_SAT,
    HOME_ITEM_TEX_IMM_PWR_CONSUMP,
    HOME_ITEM_TEX_TOTAL_MILEAGE,
    HOME_ITEM_TEX_PRE_MILEAGE,
    HOME_ITEM_TEX_AVAILABLE_MILE
};

static QString item2_text[HOME_ITEM_TEX2_NUM] = {
    HOME_ITEM_TEX_MOTO_TEMP,
    HOME_ITEM_TEX_BATT_PACK,
    HOME_ITEM_TEX_SMALL_VOLAT,
    HOME_ITEM_TEX_TOTAL_VOLT,
    HOME_ITEM_TEX_TOTAL_CURREN,
    HOME_ITEM_TEX_BATT_SOC,
    HOME_ITEM_TEX_FRONT_AIR_PRESSURE,
    HOME_ITEM_TEX_BEHIND_AIR_PRESSURE
};

static QString strgear[10] = {
    GEAR_STR_ID0,
    GEAR_STR_ID1,
    GEAR_STR_ID2,
    GEAR_STR_ID3,
    GEAR_STR_ID4,
    GEAR_STR_ID5,
    GEAR_STR_ID6,
    GEAR_STR_ID7,
    GEAR_STR_ID8,
    GEAR_STR_ID9
};

static QString strbatt [4] = {
    BATT_SAT_STR_ID0,
    BATT_SAT_STR_ID1,
    BATT_SAT_STR_ID2,
    BATT_SAT_STR_ID3
};

enum HOME_ITEAM_ID {
    HOME_ITEM_ID_DATE_TIME = 0,
    HOME_ITEM_ID_SLOPE,
    HOME_ITEM_ID_GEAR_SAT,
    HOME_ITEM_ID_BATT_SAT,
    HOME_ITEM_ID_IMM_PWR_CONSUMP,
    HOME_ITEM_ID_TOTAL_MILEAGE,
    HOME_ITEM_ID_PRE_MILEAGE,
    HOME_ITEM_ID_AVAILABLE_MILE,
    HOME_ITEM_ID_MOTO_TEMP,
    HOME_ITEM_ID_BATT_PACK,
    HOME_ITEM_ID_SMALL_VOLAT,
    HOME_ITEM_ID_TOTAL_VOLT,
    HOME_ITEM_ID_TOTAL_CURREN,
    HOME_ITEM_ID_BATT_SOC,
    HOME_ITEM_ID_FRONT_AIR_PRESSURE,
    HOME_ITEM_ID_BEHIND_AIR_PRESSURE,
    HOME_ITEM_ID_ALARM_MSG,
    HOME_ITEM_TOTAL_NUM,
    HOME_ITEM_ID_FDOOR,
    HOME_ITEM_ID_MDOOR,
    HOME_ITEM_ID_RDOOR,
    HOME_ITEM_DOOR_NUM,
};

Home_Page::Home_Page(QWidget *parent) : Frame_Page(parent)
{
    int i, item_num, item_str_start;

    this->setObjectName(HOME_PAGE_OBJNAME);

    if (image_car_bus.load(HOME_PAGE_BUS) == false ||
        bgimg.load(HOME_PAGE_BACKGROUND) == false) {
        qDebug("image load fail");
        return;
    }

    item_num = HOME_ITEM_ID_RDOOR - HOME_ITEM_ID_FDOOR + 1;
    for (i = 0; i < item_num; i++) {
        icon_door[i] = new Icon_btn(this);
        icon_door[i]->enable_scale = 0;
        icon_door[i]->load_image_ft(door_name[i][0], door_name[i][1]);
        icon_door[i]->setGeometry(door_coord_xy[i][0], door_coord_xy[i][1], 420, 250);
    }


    //image_car_bus = image_car_bus.scaled(294, 175);

    item_num = HOME_ITEM_ID_AVAILABLE_MILE - HOME_ITEM_ID_DATE_TIME + 1;
    for (i = 0; i < item_num; i++) {
        /* item 1 title */
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(item1_text[i]);
        show_item[i]->m_font_size = 12;
        show_item[i]->setGeometry(HOME_ITEM_TEX1_X,
            HOME_ITEM_TEX1_Y + HOME_ITEM_TEX1_Y_OFF * i,
            HOME_ITEM_TEX1_W, HOME_ITEM_TEX1_H);

        /* item 1 data */
        show_item_data[i] = new Show_text(this);
        show_item_data[i]->set_text("--");
        show_item_data[i]->m_font_size = 12;
        show_item_data[i]->m_text_x = 0;
        show_item_data[i]->m_text_y = 0;

        item_str_start = item1_text[i].size() * show_item_data[i]->m_font_size + HOME_ITEM1_DATA_OFF;
        show_item_data[i]->setGeometry(HOME_ITEM_TEX1_DATA_X + item_str_start,
            HOME_ITEM_TEX1_DATA_Y + HOME_ITEM_TEX1_Y_OFF * i,
            HOME_ITEM_TEX1_W, HOME_ITEM_TEX1_H);

        /* item 2 title */
        show_item[i + HOME_ITEM_ID_MOTO_TEMP] = new Show_text(this);
        show_item[i + HOME_ITEM_ID_MOTO_TEMP]->set_text(item2_text[i]);
        show_item[i + HOME_ITEM_ID_MOTO_TEMP]->m_font_size = 12;
        show_item[i + HOME_ITEM_ID_MOTO_TEMP]->setGeometry(HOME_ITEM_TEX2_X,
            HOME_ITEM_TEX2_Y + HOME_ITEM_TEX2_Y_OFF * i,
            HOME_ITEM_TEX1_W, HOME_ITEM_TEX2_H);


        /* item 2 data */
        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP] = new Show_text(this);
        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->set_text("--");
        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->m_font_size = 12;
        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->m_text_x = 0;
        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->m_text_y = 0;

        item_str_start = item2_text[i].size() * \
                show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->m_font_size + HOME_ITEM2_DATA_OFF;

        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->setGeometry(HOME_ITEM_TEX2_DATA_X + item_str_start,
            HOME_ITEM_TEX2_DATA_Y + HOME_ITEM_TEX2_Y_OFF * i,
            HOME_ITEM_TEX2_W, HOME_ITEM_TEX2_H);
    }

    show_item[HOME_ITEM_ID_ALARM_MSG] = new Show_text(this);
    show_item[HOME_ITEM_ID_ALARM_MSG]->set_text(HOME_ITEM_TEX_ALARM_MSG);
    show_item[HOME_ITEM_ID_ALARM_MSG]->m_font_size = 12;
    show_item[HOME_ITEM_ID_ALARM_MSG]->setGeometry(HOME_ITEM_TEX3_X, HOME_ITEM_TEX3_Y,
        HOME_ITEM_TEX3_W, HOME_ITEM_TEX3_H);



//    /* Dat Time */
//    show_time_str = new Show_text(this);
//    show_time_str->set_text("00 時 00 分 00 秒");
//    show_time_str->m_font_size = 12;
//    show_time_str->setGeometry(80, 60, 100, 70);
//
//    /* Slop */
//    show_slope_str = new Show_text(this);
//    show_slope_str->set_text("00 %");
//    show_slope_str->m_font_size = 12;
//    show_slope_str->setGeometry(80, 90, 50, 70);
//
//    /* Gear */
//    show_gear_str = new Show_text(this);
//    show_gear_str->set_text("前進檔");
//    show_gear_str->m_font_size = 12;
//    show_gear_str->setGeometry(80, 120, 50, 70);
//
//    /* Battery status */
//    show_batt_str = new Show_text(this);
//    show_batt_str->set_text("閒置");
//    show_batt_str->m_font_size = 12;
//    show_batt_str->setGeometry(80, 150, 50, 70);
//
//    /* Instant battery consumption */
//    show_battconsum_str = new Show_text(this);
//    show_battconsum_str->set_text("0 kw/100km");
//    show_battconsum_str->m_font_size = 12;
//    show_battconsum_str->setGeometry(80, 180, 50, 70);
//
//    /* total kilo */
//    show_totalkilo_str = new Show_text(this);
//    show_totalkilo_str->set_text("0 km");
//    show_totalkilo_str->m_font_size = 12;
//    show_totalkilo_str->setGeometry(80, 210, 100, 70);
//
//    /* total kilo */
//    show_currkilo_str = new Show_text(this);
//    show_currkilo_str->set_text("0 km");
//    show_currkilo_str->m_font_size = 12;
//    show_currkilo_str->setGeometry(80, 240, 100, 70);
//
//    /* avail kilo */
//    show_availkilo_str = new Show_text(this);
//    show_availkilo_str->set_text("0 km");
//    show_availkilo_str->m_font_size = 12;
//    show_availkilo_str->setGeometry(100, 270, 100, 70);
//
//    /* moto temp */
//    show_mototemp_str = new Show_text(this);
//    show_mototemp_str->set_text("0 °C");
//    show_mototemp_str->m_font_size = 12;
//    show_mototemp_str->setGeometry(700, 60, 100, 70);
//
//    /* battery pack */
//    show_battpack_str = new Show_text(this);
//    show_battpack_str->set_text("0 %");
//    show_battpack_str->m_font_size = 12;
//    show_battpack_str->setGeometry(700, 90, 100, 70);
//
//    /* small volt */
//    show_smallvolt_str = new Show_text(this);
//    show_smallvolt_str->set_text("0 V");
//    show_smallvolt_str->m_font_size = 12;
//    show_smallvolt_str->setGeometry(700, 120, 100, 70);
//
//    /* total volt */
//    show_totalvolt_str = new Show_text(this);
//    show_totalvolt_str->set_text("0 V");
//    show_totalvolt_str->m_font_size = 12;
//    show_totalvolt_str->setGeometry(700, 150, 100, 70);
//
//    /* total current */
//    show_totalcurr_str = new Show_text(this);
//    show_totalcurr_str->set_text("0 A");
//    show_totalcurr_str->m_font_size = 12;
//    show_totalcurr_str->setGeometry(700, 180, 100, 70);
//
//    /* battery SOC */
//    show_battsoc_str = new Show_text(this);
//    show_battsoc_str->set_text("0 %");
//    show_battsoc_str->m_font_size = 12;
//    show_battsoc_str->setGeometry(700, 210, 100, 70);
//
//    /* front air */
//    show_frontair_str = new Show_text(this);
//    show_frontair_str->set_text("0 Mpa");
//    show_frontair_str->m_font_size = 12;
//    show_frontair_str->setGeometry(720, 240, 100, 70);
//
//    /* behind air */
//    show_behindair_str = new Show_text(this);
//    show_behindair_str->set_text("0 Mpa");
//    show_behindair_str->m_font_size = 12;
//    show_behindair_str->setGeometry(720, 270, 100, 70);

    for (i = 0; i < HOME_ITEM_TOTAL_NUM - 1; i++)
        show_item[i]->show();

    item_num = HOME_ITEM_DOOR_NUM - HOME_ITEM_ID_FDOOR;
    for (i = 0; i < item_num; i++)
        icon_door[i]->show();

}

void Home_Page::Door_Sat_Change(uint8_t door_type, uint8_t status)
{
    if (door_type == DOOR_TYPE_ID_R) {
        if (status == DOOR_STAUS_TYPE_DISABLE)
            icon_door[door_type]->ft_light_enable();
        else
            icon_door[door_type]->ft_dark_enable();
        return;
    }

    if (status == DOOR_STAUS_TYPE_DISABLE)
        icon_door[door_type]->hide();
    else if (status == DOOR_STAUS_TYPE_NOR_EN)
        icon_door[door_type]->ft_light_enable();
    else
        icon_door[door_type]->ft_dark_enable();


}

void Home_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg,
                       GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawImage(HOME_CARBUS_IMG_X, HOME_CARBUS_IMG_Y, image_car_bus);
}


/*
enum HOME_ITEAM_ID {
    HOME_ITEM_ID_DATE_TIME = 0,
    HOME_ITEM_ID_SLOPE,
    HOME_ITEM_ID_GEAR_SAT,
    HOME_ITEM_ID_BATT_SAT,
    HOME_ITEM_ID_IMM_PWR_CONSUMP,
    HOME_ITEM_ID_TOTAL_MILEAGE,
    HOME_ITEM_ID_PRE_MILEAGE,
    HOME_ITEM_ID_AVAILABLE_MILE,
    HOME_ITEM_ID_MOTO_TEMP,
    HOME_ITEM_ID_BATT_PACK,
    HOME_ITEM_ID_SMALL_VOLAT,
    HOME_ITEM_ID_TOTAL_VOLT,
    HOME_ITEM_ID_TOTAL_CURREN,
    HOME_ITEM_ID_BATT_SOC,
    HOME_ITEM_ID_FRONT_AIR_PRESSURE,
    HOME_ITEM_ID_BEHIND_AIR_PRESSURE,
    HOME_ITEM_ID_ALARM_MSG,
    HOME_ITEM_TOTAL_NUM,
    HOME_ITEM_ID_FDOOR,
    HOME_ITEM_ID_MDOOR,
    HOME_ITEM_ID_RDOOR,
    HOME_ITEM_DOOR_NUM,
};
*/

void Home_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    uint8_t page_data[128];
    uint8_t door_sat;
    uint8_t date_time[6];
    uint8_t gear_data;
    uint16_t batt_data;
    uint16_t battconsum_data;
    uint16_t availkilo_data;
    QString str_temp;
    int time_hr, time_min, time_sec;
    signed char slope_data;
    signed char mototemp_data;
    signed char battpack_data;
    double smallvolt_data;
    double totalvolt_data;
    double totalkilo_data;
    double totalcurr_data;
    double currkilo_data;
    double battsoc_data;
    double frontair_data;
    double behind_data;
    #define DOOR_DATA_MASK 0x03
    #define TIME_DATA_SIZE 6
    #define BATTSAT_DATA_MASK 0x03

    memcpy(page_data, protolcol_data->page_data, sizeof(uint8_t) * protolcol_data->page_data_sz);

    /* Door */
    door_sat = (page_data[0] >> DOOR_TYPE_F_SHIF) & DOOR_DATA_MASK;
    Door_Sat_Change(DOOR_TYPE_ID_F, door_sat);

    door_sat = (page_data[0] >> DOOR_TYPE_M_SHIF) & DOOR_DATA_MASK;
    Door_Sat_Change(DOOR_TYPE_ID_M, door_sat);

    door_sat = (page_data[0] >> DOOR_TYPE_R_SHIF) & DOOR_DATA_MASK;
    Door_Sat_Change(DOOR_TYPE_ID_R, door_sat);

    /* Date Time */
    memcpy(date_time, &page_data[1], sizeof(uint8_t) * TIME_DATA_SIZE);
    time_hr = date_time[HOME_PGE_DATA_TIME_H];
    time_min = date_time[HOME_PGE_DATA_TIME_M];
    time_sec = date_time[HOME_PGE_DATA_TIME_S];
    str_temp.sprintf("%d 時 %d 分 %d 秒", time_hr, time_min, time_sec);
    show_item_data[HOME_ITEM_ID_DATE_TIME]->set_text(str_temp);

   /* slope data */
    slope_data = int8_t(page_data[HOME_PGE_DATA_SLOPE]);
    str_temp.sprintf("%i %c", slope_data, 0x25); /* ASCII 0x25 => % */
    show_item_data[HOME_ITEM_ID_SLOPE]->set_text(str_temp);

    /* Gear_Data */
    gear_data = (page_data[HOME_PGE_DATA_GEAR] >> 4) & 0x0F;
    show_item_data[HOME_ITEM_ID_GEAR_SAT]->set_text(strgear[gear_data]);

    /* Battery status */
    batt_data = uint16_t(page_data[HOME_PGE_DATA_BATT_SAT_H] << 8 | page_data[HOME_PGE_DATA_BATT_SAT_L]);
    batt_data = batt_data & BATTSAT_DATA_MASK;
    show_item_data[HOME_ITEM_ID_BATT_SAT]->set_text(strbatt[batt_data]);


    /* Instant battery consumption */
    battconsum_data = uint16_t(page_data[HOME_PGE_DATA_BATT_CSUM_H] << 8 | page_data[HOME_PGE_DATA_BATT_CSUM_L]);
    str_temp.sprintf("%d kw/100km", battconsum_data);
    show_item_data[HOME_ITEM_ID_IMM_PWR_CONSUMP]->set_text(str_temp);

    /* total kilo */
    totalkilo_data = double(page_data[HOME_PGE_DATA_TOT_KM_BIT3] << 24 |
                            page_data[HOME_PGE_DATA_TOT_KM_BIT2] << 16 |
                            page_data[HOME_PGE_DATA_TOT_KM_BIT1] << 8 |
                            page_data[HOME_PGE_DATA_TOT_KM_BIT0]);
    totalkilo_data = totalkilo_data * 0.005;
    if (totalkilo_data < 0)
        totalkilo_data = 0;
    str_temp.sprintf("%f km", totalkilo_data * 0.005);
    show_item_data[HOME_ITEM_ID_TOTAL_MILEAGE]->set_text(str_temp);

    /* current kilo */

    currkilo_data = double(page_data[HOME_PGE_DATA_CUR_KM_BIT3] << 24 |
                           page_data[HOME_PGE_DATA_CUR_KM_BIT2] << 16 |
                           page_data[HOME_PGE_DATA_CUR_KM_BIT1] << 8 |
                           page_data[HOME_PGE_DATA_CUR_KM_BIT0]);
    currkilo_data = currkilo_data * 0.005;
    if (currkilo_data < 0)
        currkilo_data = 0;
    str_temp.sprintf("%f km", currkilo_data);
    show_item_data[HOME_ITEM_ID_PRE_MILEAGE]->set_text(str_temp);

    /* available kilo */
    availkilo_data = uint16_t(page_data[21] << 8 | page_data[20]);
    str_temp.sprintf("%u km", availkilo_data);
    show_item_data[HOME_ITEM_ID_AVAILABLE_MILE]->set_text(str_temp);

    /* moto temp */
    mototemp_data = int8_t(page_data[22]);
    mototemp_data = mototemp_data - 40;
    if (mototemp_data < 0)
        mototemp_data = 0;

    str_temp.sprintf("%i °C", mototemp_data - 40);
    show_item_data[HOME_ITEM_ID_MOTO_TEMP]->set_text(str_temp);

    /* battery pack */
    battpack_data = int8_t(page_data[23]);
    battpack_data = battpack_data - 40;
    if (battpack_data < 40)
        battpack_data = 0;

    str_temp.sprintf("%i °C", battpack_data);
    show_item_data[HOME_ITEM_ID_BATT_PACK]->set_text(str_temp);


    /* small volt */
    smallvolt_data = page_data[24];
    smallvolt_data = smallvolt_data * 0.2;
    if (smallvolt_data < 0)
        smallvolt_data = 0;

    str_temp.sprintf("%f V", smallvolt_data);
    show_item_data[HOME_ITEM_ID_SMALL_VOLAT]->set_text(str_temp);

    /* total volt */
    totalvolt_data = page_data[26] << 8 | page_data[25];
    totalvolt_data = totalvolt_data * 0.1;
    if (totalvolt_data < 0)
        totalvolt_data = 0;

    str_temp.sprintf("%f V", totalvolt_data);
    show_item_data[HOME_ITEM_ID_TOTAL_VOLT]->set_text(str_temp);

    /* total curr */
    totalcurr_data = page_data[28] << 8 | page_data[27];
    totalcurr_data = totalcurr_data * 0.1 - 1000;
    if (totalcurr_data < 0)
        totalcurr_data = 0;

    str_temp.sprintf("%f A", totalcurr_data);
    show_item_data[HOME_ITEM_ID_TOTAL_CURREN]->set_text(str_temp);


    /* battery soc */
    battsoc_data = page_data[30] << 8 | page_data[29];
    battsoc_data = battsoc_data * 0.1;
    if (battsoc_data < 0)
        battsoc_data = 0;

    str_temp.sprintf("%f  %c", battsoc_data, 0x25);
    show_item_data[HOME_ITEM_ID_BATT_SOC]->set_text(str_temp);


    /* front air */
    frontair_data = page_data[31];
    frontair_data = frontair_data * 0.01;
    if (frontair_data < 0)
        frontair_data = 0;

    str_temp.sprintf("%f Mpa", frontair_data);
    show_item_data[HOME_ITEM_ID_FRONT_AIR_PRESSURE]->set_text(str_temp);


    /* behind air */
    behind_data = page_data[32];
    behind_data = behind_data * 0.01;
    if (behind_data < 0)
        behind_data = 0;

    str_temp.sprintf("%f Mpa", behind_data);
    show_item_data[HOME_ITEM_ID_BEHIND_AIR_PRESSURE]->set_text(str_temp);
}
