#include "home_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

#define VERSION "R2021-10-12.1"

static QString door_name[F_DOOR_NAME_NUM][F_DOOR_TYPE_NUM] = {
        {F_DOOR_TYPE0,  F_DOOR_TYPE1},
        {M_DOOR_TYPE0,  M_DOOR_TYPE1},
        {R_DOOR_TYPE0,  R_DOOR_TYPE1},
};

static int door_coord_xy[CARBUS_TYPE_NUM][2] = {
        //{HOME_FDOOR_IMG_X,  HOME_FDOOR_IMG_Y},
        //{HOME_MDOOR_IMG_X,  HOME_MDOOR_IMG_Y},
        //{HOME_RDOOR_IMG_X,  HOME_RDOOR_IMG_Y},
        {150,  80},
        {170,  80},
        {185,  80},
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

static QString strgear[GEAR_STR_NUM] = {
    GEAR_STR_ID0,
    GEAR_STR_ID1,
    GEAR_STR_ID2,
    GEAR_STR_ID3,
    GEAR_STR_ID4,
    GEAR_STR_ID5,
    GEAR_STR_ID6,
    GEAR_STR_ID7,
    GEAR_STR_ID8,
    GEAR_STR_ID9,
    GEAR_STR_ID10,
    GEAR_STR_ID11,
};

static QString strbatt [BATT_SAT_STR_NUM] = {
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
    int i, item_num;

    this->setObjectName(HOME_PAGE_OBJNAME);

    if (image_car_bus.load(HOME_PAGE_BUS) == false ||
        bgimg.load(HOME_PAGE_BACKGROUND) == false) {
        qDebug("image load fail");
        return;
    }

    image_car_bus = image_car_bus.scaled(HOME_CARBUS_SCALE_X, HOME_CARBUS_SCALE_Y);

    item_num = HOME_ITEM_ID_RDOOR - HOME_ITEM_ID_FDOOR + 1;
    for (i = 0; i < item_num; i++) {
        icon_door[i] = new Icon_btn(this);
        icon_door[i]->enable_scale = 0;
        icon_door[i]->load_image_ft(door_name[i][0], door_name[i][1]);
        icon_door[i]->setGeometry(door_coord_xy[i][0],
            door_coord_xy[i][1], 420, 250);
    }

    item_num = HOME_ITEM_ID_AVAILABLE_MILE - HOME_ITEM_ID_DATE_TIME + 1;
    for (i = 0; i < item_num; i++) {
        /* item 1 title */
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(item1_text[i]);
        show_item[i]->m_font_size = HOME_ITEM_FONT_DEFAULT;
        show_item[i]->setGeometry(HOME_ITEM_TEX1_X,
            HOME_ITEM_TEX1_Y + HOME_ITEM_TEX1_Y_OFF * i,
            HOME_ITEM_TEX1_W, HOME_ITEM_TEX1_H);

        /* item 1 data */
        show_item_data[i] = new Show_text(this);
        show_item_data[i]->set_text("--");
        show_item_data[i]->m_font_size = HOME_ITEM_FONT_DEFAULT;
        show_item_data[i]->m_text_x = 0;
        show_item_data[i]->m_text_y = 50;

        show_item_data[i]->setGeometry(HOME_ITEM_TEX1_DATA_X + 100,
            HOME_ITEM_TEX1_DATA_Y + HOME_ITEM_TEX1_Y_OFF * i,
            HOME_ITEM_TEX1_W, HOME_ITEM_TEX1_H);

        /* item 2 title */
        show_item[i + HOME_ITEM_ID_MOTO_TEMP] = new Show_text(this);
        show_item[i + HOME_ITEM_ID_MOTO_TEMP]->set_text(item2_text[i]);
        show_item[i + HOME_ITEM_ID_MOTO_TEMP]->m_font_size =
            HOME_ITEM_FONT_DEFAULT;

        show_item[i + HOME_ITEM_ID_MOTO_TEMP]->setGeometry(HOME_ITEM_TEX2_X,
            HOME_ITEM_TEX2_Y + HOME_ITEM_TEX2_Y_OFF * i,
            HOME_ITEM_TEX2_W, HOME_ITEM_TEX2_H);


        /* item 2 data */
        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP] = new Show_text(this);
        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->set_text("--");
        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->m_font_size =
            HOME_ITEM_FONT_DEFAULT;

        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->m_text_x = 0;
        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->m_text_y = 50;

        show_item_data[i + HOME_ITEM_ID_MOTO_TEMP]->setGeometry(HOME_ITEM_TEX2_DATA_X + 100,
            HOME_ITEM_TEX2_DATA_Y + HOME_ITEM_TEX2_Y_OFF * i,
            HOME_ITEM_TEX2_W, HOME_ITEM_TEX2_H);
    }

    show_item[HOME_ITEM_ID_ALARM_MSG] = new Show_text(this);
    show_item[HOME_ITEM_ID_ALARM_MSG]->set_text(HOME_ITEM_TEX_ALARM_MSG);
    show_item[HOME_ITEM_ID_ALARM_MSG]->m_font_size = HOME_ITEM_FONT_DEFAULT;
    show_item[HOME_ITEM_ID_ALARM_MSG]->setGeometry(HOME_ITEM_TEX3_X, HOME_ITEM_TEX3_Y,
        HOME_ITEM_TEX3_W, HOME_ITEM_TEX3_H);

    for (i = 0; i < HOME_ITEM_TOTAL_NUM - 1; i++)
        show_item[i]->show();

    item_num = HOME_ITEM_DOOR_NUM - HOME_ITEM_ID_FDOOR;

    for (i = 0; i < item_num; i++)
        icon_door[i]->hide();

    show_version = new Show_text(this);
    show_version->set_text(VERSION);
    show_version->m_font_size = 8;
    show_version->setGeometry(10, 350, 100, 50);
    show_version->show();
}

void Home_Page::Door_Sat_Change(uint8_t door_type, uint8_t status)
{
    if (door_type == DOOR_TYPE_ID_R) {
        if (status == DOOR_STAUS_TYPE_DISABLE)
            icon_door[door_type]->hide();
        else {
            icon_door[door_type]->ft_dark_enable();
            icon_door[door_type]->show();
        }
        return;
    }

    if (status == DOOR_STAUS_TYPE_DISABLE) {
        icon_door[door_type]->hide();
    }
    else if (status == DOOR_STAUS_TYPE_NOR_EN) {
        icon_door[door_type]->show();
        icon_door[door_type]->ft_light_enable();
    }
    else {
        icon_door[door_type]->show();
        icon_door[door_type]->ft_dark_enable();
    }
}

void Home_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg,
                       GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawImage(HOME_CARBUS_IMG_X, HOME_CARBUS_IMG_Y, image_car_bus);
    painter.drawText(100, 150, "2021-10-02");
}

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
    int16_t mototemp_data;
    signed char battpack_data;
    double smallvolt_data;
    double totalvolt_data;
    double totalkilo_data;
    double totalcurr_data;
    double currkilo_data;
    double battsoc_data;
    double frontair_data;
    double behind_data;

    #define DOOR_DATA_TYPE_FM_MASK 0x03
    #define DOOR_DATA_TYPE_R_MASK 0x01
    #define TIME_DATA_SIZE 6
    #define BATTSAT_DATA_MASK 0x03
    #define DATA_GEAR_MASK 0x0F

    memcpy(page_data, protolcol_data->page_data, sizeof(uint8_t) * protolcol_data->page_data_sz);

    /* Door */
    door_sat = (page_data[0] >> DOOR_TYPE_F_SHIF) & DOOR_DATA_TYPE_FM_MASK;
    Door_Sat_Change(DOOR_TYPE_ID_F, door_sat);

    door_sat = (page_data[0] >> DOOR_TYPE_M_SHIF) & DOOR_DATA_TYPE_FM_MASK;
    Door_Sat_Change(DOOR_TYPE_ID_M, door_sat);

    door_sat = (page_data[0] >> DOOR_TYPE_R_SHIF) & DOOR_DATA_TYPE_R_MASK;
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
    gear_data = (page_data[HOME_PGE_DATA_GEAR] >> 4) & DATA_GEAR_MASK;
    show_item_data[HOME_ITEM_ID_GEAR_SAT]->set_text(strgear[gear_data]);

    /* Battery status */
    batt_data = uint16_t(page_data[HOME_PGE_DATA_BATT_SAT_H] << 8 |
        page_data[HOME_PGE_DATA_BATT_SAT_L]);

    batt_data = batt_data & BATTSAT_DATA_MASK;
    show_item_data[HOME_ITEM_ID_BATT_SAT]->set_text(strbatt[batt_data]);

    /* Instant battery consumption */
    battconsum_data = uint16_t(page_data[HOME_PGE_DATA_BATT_CSUM_H] << 8 |
        page_data[HOME_PGE_DATA_BATT_CSUM_L]);

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
    str_temp.sprintf("%.1f km", totalkilo_data);
    show_item_data[HOME_ITEM_ID_TOTAL_MILEAGE]->set_text(str_temp);

    /* current kilo */
    currkilo_data = double(page_data[HOME_PGE_DATA_CUR_KM_BIT3] << 24 |
                           page_data[HOME_PGE_DATA_CUR_KM_BIT2] << 16 |
                           page_data[HOME_PGE_DATA_CUR_KM_BIT1] << 8 |
                           page_data[HOME_PGE_DATA_CUR_KM_BIT0]);
    currkilo_data = currkilo_data * 0.005;
    if (currkilo_data < 0)
        currkilo_data = 0;
    str_temp.sprintf("%.1f km", currkilo_data);
    show_item_data[HOME_ITEM_ID_PRE_MILEAGE]->set_text(str_temp);

    /* available kilo */
    availkilo_data = uint16_t(page_data[HOME_PGE_DATA_AVAI_KILO_H] << 8 |
        page_data[HOME_PGE_DATA_AVAI_KILO_L]);

    str_temp.sprintf("%u km", availkilo_data);
    show_item_data[HOME_ITEM_ID_AVAILABLE_MILE]->set_text(str_temp);

    /* moto temp */
    mototemp_data = int16_t(page_data[22]);
    mototemp_data = mototemp_data - 40;
    if (mototemp_data < -40)
        mototemp_data = -40;
    if (mototemp_data > 210)
        mototemp_data = -40;

    str_temp.sprintf("%i °C", mototemp_data);
    show_item_data[HOME_ITEM_ID_MOTO_TEMP]->set_text(str_temp);

    /* battery pack */
    battpack_data = int8_t(page_data[23]);
    battpack_data = battpack_data - 40;
    if (battpack_data < -40)
        battpack_data = -40;
    if (battpack_data > 100)
        battpack_data = 100;

    str_temp.sprintf("%i °C", battpack_data);
    show_item_data[HOME_ITEM_ID_BATT_PACK]->set_text(str_temp);

    /* small volt */
    smallvolt_data = page_data[24];
    smallvolt_data = smallvolt_data * 0.2;
    if (smallvolt_data < 0)
        smallvolt_data = 0;

    str_temp.sprintf("%.1f V", smallvolt_data);
    show_item_data[HOME_ITEM_ID_SMALL_VOLAT]->set_text(str_temp);

    /* total volt */
    totalvolt_data = page_data[26] << 8 | page_data[25];
    totalvolt_data = totalvolt_data * 0.1;
    if (totalvolt_data < 0)
        totalvolt_data = 0;

    str_temp.sprintf("%.1f V", totalvolt_data);
    show_item_data[HOME_ITEM_ID_TOTAL_VOLT]->set_text(str_temp);

    /* total curr */
    totalcurr_data = page_data[28] << 8 | page_data[27];
    totalcurr_data = totalcurr_data * 0.1 - 1000;
    if (totalcurr_data < 0)
        totalcurr_data = 0;

    str_temp.sprintf("%.1f A", totalcurr_data);
    show_item_data[HOME_ITEM_ID_TOTAL_CURREN]->set_text(str_temp);


    /* battery soc */
    battsoc_data = page_data[30] << 8 | page_data[29];
    battsoc_data = battsoc_data * 0.4;
    if (battsoc_data < 0)
        battsoc_data = 0;

    str_temp.sprintf("%.1f  %c", battsoc_data, 0x25);
    show_item_data[HOME_ITEM_ID_BATT_SOC]->set_text(str_temp);


    /* front air */
    frontair_data = page_data[31];
    frontair_data = frontair_data * 0.01;
    if (frontair_data < 0)
        frontair_data = 0;

    str_temp.sprintf("%.2f Mpa", frontair_data);
    show_item_data[HOME_ITEM_ID_FRONT_AIR_PRESSURE]->set_text(str_temp);


    /* behind air */
    behind_data = page_data[32];
    behind_data = behind_data * 0.01;
    if (behind_data < 0)
        behind_data = 0;

    str_temp.sprintf("%.2f Mpa", behind_data);
    show_item_data[HOME_ITEM_ID_BEHIND_AIR_PRESSURE]->set_text(str_temp);
    memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
}
