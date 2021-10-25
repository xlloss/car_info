#include "home_page.h"
#include <QPainter>
#include <mileage_rpm_page.h>
#include "coordinate.h"
#include "string/string.h"

QString str_img_id[RPM_STR_IMG_COL_NUM] = {
    {ID_STR_IMG_0},
    {ID_STR_IMG_1},
    {ID_STR_IMG_2},
    {ID_STR_IMG_3},
    {ID_STR_IMG_4},
    {ID_STR_IMG_5},
    {ID_STR_IMG_6},
    {ID_STR_IMG_7},
};

int str_img_xy[RPM_STR_IMG_COL_NUM][RPM_STR_IMG_ROW_NUM] = {
    {RPM_STR_IMG_ID_0_X, RPM_STR_IMG_ID_0_Y, },    //ID_STR_IMG_0
    {RPM_STR_IMG_ID_1_X, RPM_STR_IMG_ID_1_Y, },    //ID_STR_IMG_1
    {RPM_STR_IMG_ID_2_X, RPM_STR_IMG_ID_2_Y, },    //ID_STR_IMG_2
    {RPM_STR_IMG_ID_3_X, RPM_STR_IMG_ID_3_Y, },    //ID_STR_IMG_3

    {RPM_STR_IMG_ID_4_X, RPM_STR_IMG_ID_4_Y,},    //ID_STR_IMG_4
    {RPM_STR_IMG_ID_5_X, RPM_STR_IMG_ID_5_Y,},    //ID_STR_IMG_5
    {RPM_STR_IMG_ID_6_X, RPM_STR_IMG_ID_6_Y,},    //ID_STR_IMG_6
    {RPM_STR_IMG_ID_7_X, RPM_STR_IMG_ID_7_Y,},    //ID_STR_IMG_7
};

int btn_img_xy[RPM_BTN_NUM][2] = {
    {RPM_BTN_IMG_ID0_X, RPM_BTN_IMG_ID0_Y},
    {RPM_BTN_IMG_ID1_X, RPM_BTN_IMG_ID1_Y},
    {RPM_BTN_IMG_ID2_X, RPM_BTN_IMG_ID2_Y},
    {RPM_BTN_IMG_ID3_X, RPM_BTN_IMG_ID3_Y},
};

static int item_xy[8][2] = {
    {150, 40},
    {40, 100},
    {40, 175},
    {40, 275},

    {150 + 400 , 40},
    {40  + 400, 100},
    {40  + 400, 175},
    {40  + 400, 275},
};


static int show_data_xy[6][2] = {
    {RPM_DATA_ID0_X, RPM_DATA_ID0_Y},
    {RPM_DATA_ID1_X, RPM_DATA_ID1_Y},
    {RPM_DATA_ID2_X, RPM_DATA_ID2_Y},

    {RPM_DATA_ID3_X, RPM_DATA_ID3_Y},
    {RPM_DATA_ID4_X, RPM_DATA_ID4_Y},
    {RPM_DATA_ID5_X, RPM_DATA_ID5_Y},
};

static QString show_text_default[RPM_STR_NUM] = {
    RPM_DATA_DEF_STR_ID0,
    RPM_DATA_DEF_STR_ID1,
    RPM_DATA_DEF_STR_ID2,
    RPM_DATA_DEF_STR_ID3,
    RPM_DATA_DEF_STR_ID4,
    RPM_DATA_DEF_STR_ID5,
};

static QString rpm_page_btn_objname[RPM_BTN_NUM] = {
    RPM_SAMPLE_BTN_OBJ_ID0
    RPM_SAMPLE_BTN_OBJ_ID1
    RPM_SAMPLE_BTN_OBJ_ID2
    RPM_SAMPLE_BTN_OBJ_ID3
};

static QString item1_text[] = {
    "累計資訊",
    "總里程:",
    "短里程 A:",
    "短里程 B:",
    "轉速資訊",
    "累計總轉速:",
    "總轉累計時間 A:",
    "總轉累計時間 B:"
};

#define MILE_ITEM 8
#define BTN_NUM 4

enum {
    MILE_PAGE_TOTAL_KM_DATA = 0,
    MILE_PAGE_SHORT_KM_A_DATA,
    MILE_PAGE_SHORT_KM_B_DATA,
    MILE_PAGE_TOTAL_RPM_DATA,
    MILE_PAGE_RPM_TIME_A_DATA,
    MILE_PAGE_RPM_TIME_B_DATA,
};


Mile_Page::Mile_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(RPM_OBJNAME);
    int i;

    bgimg.load(RPM_BG_IMG);
    backimg2.load(RPM_FM_IMG);

    for (i = 0; i < MILE_ITEM; i++) {
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(item1_text[i]);
        show_item[i]->m_font_size = 20;
        show_item[i]->setGeometry(item_xy[i][0], item_xy[i][1], 150, 40);
    }

    for (i = 0; i < 6; i++) {
        show_data[i] = new Show_text(this);
        show_data[i]->set_text(show_text_default[i]);
        show_data[i]->setGeometry(show_data_xy[i][0], show_data_xy[i][1], 200, 70);
        show_data[i]->show();
    }

    for (i = 0; i < RPM_BTN_NUM; i++) {
        zero_btn[i] = new Icon_btn(this);
        zero_btn[i]->setObjectName(rpm_page_btn_objname[i]);
        zero_btn[i]->enable_scale = 0;

        zero_btn[i]->load_image_ft(":/icon/rpm_btn.png", ":/icon/rpm_btn_press.png");
        zero_btn[i]->setGeometry(btn_img_xy[i][0], btn_img_xy[i][1], 120, 40);

        zero_btn[i]->set_text(RPM_PAGE_BTN_NAME);
        zero_btn[i]->m_set_text_y = RPM_FONT_SIZE;
    }
}

void Mile_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawPixmap(8, 30, backimg2, MILERPM_BACKIMAGE_X, MILERPM_BACKIMAGE_Y,
                       MILERPM_BACKIMAGE_W, MILERPM_BACKIMAGE_H);
}

void Mile_Page::Enable_Icon_Light(int i)
{
    zero_btn[i]->ft_light_enable();
}

void Mile_Page::Disable_Icon_Light(int i)
{
    zero_btn[i]->ft_dark_enable();
}

void Mile_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    uint8_t page_data[256];
    double total_km, total_rpm;
    double short_km_a, short_km_b;
    uint8_t rpm_time_a_h, rpm_time_a_m, rpm_time_a_s;
    uint8_t rpm_time_b_h, rpm_time_b_m, rpm_time_b_s;
    uint8_t i, ret;
    QString str_temp;
    QString rpm_time_a_h_str, rpm_time_a_m_str, rpm_time_a_s_str;
    QString rpm_time_b_h_str, rpm_time_b_m_str, rpm_time_b_s_str;

    memcpy(page_data, protolcol_data->page_data,
        sizeof(uint8_t) * protolcol_data->page_data_sz);

    total_km = double(page_data[3] << 24 |
            page_data[2] << 16 |
            page_data[1] << 8 |
            page_data[0]);
    total_km = total_km * 0.005;
    str_temp.sprintf("%.1f km", total_km);
    show_data[MILE_PAGE_TOTAL_KM_DATA]->set_text(str_temp);

    short_km_a = double(page_data[7] << 24 |
        page_data[6] << 16 |
        page_data[5] << 8 |
        page_data[4]);
    short_km_a = short_km_a * 0.005;
    str_temp.sprintf("%.1f km", short_km_a);
    show_data[MILE_PAGE_SHORT_KM_A_DATA]->set_text(str_temp);

    short_km_b = double(page_data[11] << 24 |
        page_data[10] << 16 |
        page_data[9] << 8 |
        page_data[8]);
    short_km_b = short_km_b * 0.005;
    str_temp.sprintf("%.1f km", short_km_b);
    show_data[MILE_PAGE_SHORT_KM_B_DATA]->set_text(str_temp);

    total_rpm = double(page_data[13] << 8 |  page_data[12]);
    str_temp.sprintf("%.1f rpm", total_rpm - 12000);
    show_data[MILE_PAGE_TOTAL_RPM_DATA]->set_text(str_temp);

    rpm_time_a_h = page_data[16];
    rpm_time_a_m = page_data[15];
    rpm_time_a_s = page_data[14];

    rpm_time_a_h_str.sprintf("%d", rpm_time_a_h);
    if (rpm_time_a_h < 10)
        rpm_time_a_h_str.sprintf("0%d", rpm_time_a_h);

    rpm_time_a_m_str.sprintf("%d", rpm_time_a_m);
    if (rpm_time_a_m < 10)
        rpm_time_a_m_str.sprintf("0%d", rpm_time_a_m);

    rpm_time_a_s_str.sprintf("%d", rpm_time_a_s);
    if (rpm_time_a_s < 10)
        rpm_time_a_s_str.sprintf("0%d", rpm_time_a_s);

    str_temp.sprintf("%s : %s : %s",
                     rpm_time_a_h_str.toUtf8().data(),
                     rpm_time_a_m_str.toUtf8().data(),
                     rpm_time_a_s_str.toUtf8().data());
    show_data[MILE_PAGE_RPM_TIME_A_DATA]->set_text(str_temp);

    rpm_time_b_h = page_data[19];
    rpm_time_b_m = page_data[18];
    rpm_time_b_s = page_data[17];

    rpm_time_b_h_str.sprintf("%d", rpm_time_b_h);
    if (rpm_time_b_h < 10)
        rpm_time_b_h_str.sprintf("0%d", rpm_time_b_h);

    rpm_time_b_m_str.sprintf("%d", rpm_time_b_m);
    if (rpm_time_b_m < 10)
        rpm_time_b_m_str.sprintf("0%d", rpm_time_b_m);

    rpm_time_b_s_str.sprintf("%d", rpm_time_b_s);
    if (rpm_time_b_s < 10)
        rpm_time_b_s_str.sprintf("0%d", rpm_time_b_s);


    str_temp.sprintf("%s : %s : %s",
                     rpm_time_b_h_str.toUtf8().data(),
                     rpm_time_b_m_str.toUtf8().data(),
                     rpm_time_b_s_str.toUtf8().data());
    show_data[MILE_PAGE_RPM_TIME_B_DATA]->set_text(str_temp);

    i = 0;
    while (i < BTN_NUM) {
        ret = (page_data[20] >> i) & 0x01;
        if (ret)
            Enable_Icon_Light(i);
        else
            Disable_Icon_Light(i);
        i++;
    }

    memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
}
