#include "system_setup_page.h"
#include <QPainter>
#include "string/string.h"

static QString time_text[TIME_ADJ_TEX_TITLE_NUM] = {
    TIME_ADJ_TEX_TIME,
    TIME_ADJ_TEX_WEEK,
    TIME_ADJ_TEX_DATE,
    TIME_ADJ_TEX_YEAR,
    TIME_ADJ_TEX_MONTH,
    TIME_ADJ_TEX_DAY
};

static QString time_text_child[TIME_ADJ_CHILD_TEX_TIME_NUM] =
{   TIME_ADJ_CHILD_TEX_TIME_SAMPLE,
    TIME_ADJ_CHILD_TEX_WEEK_SAMPLE,
    TIME_ADJ_CHILD_TEX_YEAR_SAMPLE,
    TIME_ADJ_CHILD_TEX_MONTH_SAMPLE,
    TIME_ADJ_CHILD_TEX_DAY_SAMPLE
};

static int time_text_xy[TIME_ADJ_TEX_TITLE_NUM * 2] = {
    TIME_ADJ_TEX_TITLE_ID0_X, TIME_ADJ_TEX_TITLE_ID0_Y,
    TIME_ADJ_TEX_TITLE_ID1_X, TIME_ADJ_TEX_TITLE_ID1_Y,
    TIME_ADJ_TEX_TITLE_ID2_X, TIME_ADJ_TEX_TITLE_ID2_Y,
};

static int time_text2_xy[TIME_ADJ_TEX_TITLE_NUM] = {
    TIME_ADJ_TEX_TITLE_ID3_X, TIME_ADJ_TEX_TITLE_ID3_Y,
    TIME_ADJ_TEX_TITLE_ID4_X, TIME_ADJ_TEX_TITLE_ID4_Y,
    TIME_ADJ_TEX_TITLE_ID5_X, TIME_ADJ_TEX_TITLE_ID5_Y,
};

static int time_text_child_xy[TIME_ADJ_CHILD_TEX_TIME_NUM * 2] = {
    TIME_ADJ_CHILD_TEX_ID0_X, TIME_ADJ_CHILD_TEX_ID0_Y,
    TIME_ADJ_CHILD_TEX_ID1_X, TIME_ADJ_CHILD_TEX_ID1_Y,
    TIME_ADJ_CHILD_TEX_ID2_X, TIME_ADJ_CHILD_TEX_ID2_Y,
    TIME_ADJ_CHILD_TEX_ID3_X, TIME_ADJ_CHILD_TEX_ID3_Y,
    TIME_ADJ_CHILD_TEX_ID4_X, TIME_ADJ_CHILD_TEX_ID4_Y,
};

#define SYSTEM_BTN ":/icon/system_setup_btn.png"

enum {
  SYS_BTN_ID0_MILEAGE = 0,
  SYS_BTN_ID1_ALARM,
  SYS_BTN_ID2_BTNVOLUM,
  SYS_BTN_ID3_DATETIME,
  SYS_BTN_ID4_LIGHT,
  SYS_BTN_ID4_FACTORY,
  SYS_BTN_END,
};

static QString sys_btn_txt[6] =
{
    "里程單位",
    "警示音",
    "按鍵音",
    "日期時間",
    "亮度",
    "出廠設定",
};

enum {
  SYS_DATA_ITEM_MILEAGE = 0,
  SYS_DATA_ITEM_ALARM,
  SYS_DATA_ITEM_BTNVOLUM,
  SYS_DATA_ITEM_TIME,
  SYS_DATA_ITEM_TIME_SP1,
  SYS_DATA_ITEM_TIME_SP2,
  SYS_DATA_ITEM_WEEK,
  SYS_DATA_ITEM_DATE,
  SYS_DATA_ITEM_YEAR,
  SYS_DATA_ITEM_MONTH,
  SYS_DATA_ITEM_DAY,
  SYS_DATA_ITEM_LIGHT,
  SYS_DATA_ITEM_FACTORY,
  SYS_DATA_ITEM_END,
};

static QString sys_msg_tit[13] =
{
    "里程單位:",//0
    "警示音:",//1
    "按鍵音:",//2
    "時間:", ":", ":", //3, 4, 5
    "星期:",//6
    "日期:", "年", "月", "日", //7, 8, 9, 10
    "亮度:",//11
    "出廠設定:",//12
};

enum {
  SYS_DATA_MSG_MILEAGE = 0,
  SYS_DATA_MSG_ALARM,
  SYS_DATA_MSG_BTNVOLUM,
  SYS_DATA_MSG_TIME_H,
  SYS_DATA_MSG_TIME_M,
  SYS_DATA_MSG_TIME_S,
  SYS_DATA_MSG_WEEK,
  SYS_DATA_MSG_YEAR,
  SYS_DATA_MSG_MONTH,
  SYS_DATA_MSG_DAY,
  SYS_DATA_MSG_LIGHT,
  SYS_DATA_MSG_FACTORY,
  SYS_DATA_MSG_END,
};

static QString sys_msg_data[12] =
{
    "KM",//0
    "OFF",//1
    "1",//2
    "12",//3
    "00",//4
    "00",//5
    "一",//6
    "2021",//7
    "05",//8
    "05",//9
    "9",//10
    "否",//11
};

static int sys_btn_txt_x[6] = {25, 35, 35, 25, 45, 25};
static int sys_btn_txt_y[6] = {30, 30, 30, 30, 30, 30};

//                                 0    1    2    3    4    5    6    7    8    9    10   11   12
static int sys_data_title_x[15] = {170, 170, 170, 170, 245, 285, 170, 170, 270, 330, 390, 170, 170};
static int sys_data_title_y[15] = {100, 100, 100, 55,  55,  55 , 95,  135, 135, 135, 135, 100, 100};

//                               0    1    2    3    4    5    6    7    8    9    10   11
static int sys_data_msg_x[15] = {160, 240, 170, 220, 260, 300, 220, 220, 300, 360, 220, 260};
static int sys_data_msg_y[15] = {100, 100, 100, 55,  55,  55 , 95,  135, 135, 135, 100, 100};

void SystemSetup_Page::Enable_Icon_Light(int i)
{
    system_btn[i]->m_texcolor = QColor(0, 204, 240);
}

void SystemSetup_Page::Disable_Icon_Light(int i)
{
    system_btn[i]->m_texcolor = Qt::white;
}

SystemSetup_Page::SystemSetup_Page(QWidget *parent) : Frame_Page(parent)
{
    int i;
    int str_len_title;
    int str_len_data;

    setObjectName(SYSTEM_SETUP_OBJNAME);
    m_btn_id = SYS_BTN_ID3_DATETIME;

    m_font.setBold(0);
    m_font.setPointSize(20);
    m_font.setFamily("DroidSans");

    bgimg.load(SYSTEM_SETUP_BG_IMG);

    for (i = SYS_BTN_ID0_MILEAGE; i < SYS_BTN_END; i++) {
        system_btn[i] = new Icon_btn(this);
        system_btn[i]->font.setPointSize(20);
        system_btn[i]->m_set_text_x = sys_btn_txt_x[i];
        system_btn[i]->m_set_text_y = sys_btn_txt_y[i];
        system_btn[i]->m_texcolor = Qt::white;
        system_btn[i]->enable_scale = 0;
        system_btn[i]->load_image_ft(SYSTEM_BTN, SYSTEM_BTN);
        system_btn[i]->set_text(sys_btn_txt[i]);
        system_btn[i]->setGeometry(10, 30 + (60 * i), 135, 50);
        system_btn[i]->show();
    }

    for (i = SYS_DATA_ITEM_MILEAGE; i < SYS_DATA_ITEM_END; i++) {
        str_len_title = sys_msg_tit[i].length() * 20;
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(sys_msg_tit[i]);
        show_item[i]->setGeometry(sys_data_title_x[i], sys_data_title_y[i], str_len_title, 50);
        show_item[i]->hide();
    }

    for (i = SYS_DATA_MSG_MILEAGE; i < SYS_DATA_MSG_END; i++) {
        str_len_data = sys_msg_data[i].length() * 20;
        show_item_data[i] = new Show_text(this);
        show_item_data[i]->set_text(sys_msg_data[i]);
        show_item_data[i]->setGeometry(sys_data_msg_x[i], sys_data_msg_y[i], str_len_data, 50);
        show_item_data[i]->hide();
    }

//    show_item[1]->show();
//    show_item_data[1]->show();


//    show_item[SYS_DATA_ITEM_TIME]->show();
//    show_item[SYS_DATA_ITEM_TIME_SP1]->show();
//    show_item[SYS_DATA_ITEM_TIME_SP2]->show();
//    show_item_data[SYS_DATA_MSG_TIME_H]->show();
//    show_item_data[SYS_DATA_MSG_TIME_M]->show();
//    show_item_data[SYS_DATA_MSG_TIME_S]->show();
//
//    show_item[SYS_DATA_ITEM_WEEK]->show();
//    show_item[SYS_DATA_ITEM_DATE]->show();
//    show_item[SYS_DATA_ITEM_YEAR]->show();
//    show_item[SYS_DATA_ITEM_MONTH]->show();
//    show_item[SYS_DATA_ITEM_DAY]->show();
//
//    show_item_data[SYS_DATA_MSG_WEEK]->show();
//    show_item_data[SYS_DATA_MSG_YEAR]->show();
//    show_item_data[SYS_DATA_MSG_MONTH]->show();
//    show_item_data[SYS_DATA_MSG_DAY]->show();

//    show_item[SYS_DATA_ITEM_LIGHT]->show();
//    show_item_data[SYS_DATA_MSG_LIGHT]->show();

//    show_item[SYS_DATA_ITEM_FACTORY]->show();
//    show_item_data[SYS_DATA_MSG_FACTORY]->show();

}

void SystemSetup_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
//    QFont usefont(m_font.family(), m_font.pointSize(), m_font.weight(), m_font.bold());

    painter.drawPixmap(0, 0, bgimg,
                       GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

//    painter.setFont(usefont);
//    painter.setPen(QColor(Qt::white));
//
//    if (m_btn_id == SYS_BTN_ID3_DATETIME) {
//        painter.drawText(170, 65, sys_msg_tit[SYS_BTN_ID3_DATETIME]);
//        painter.drawText(170, 125, sys_msg_tit[SYS_BTN_ID3_DATETIME + 1]);
//        painter.drawText(170, 185, sys_msg_tit[SYS_BTN_ID3_DATETIME + 2]);
//    } else {
//        painter.drawText(170, 120, sys_msg_tit[m_msg_tit_id]);
//    }

}

void SystemSetup_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    uint8_t page_data[128];
    uint8_t u8_data_tmp;
    uint8_t u8_child_item, u8_child_item_color;
    QString str_tmp;
    int i, data_index;
    #define PROTOCOL_OFF_ID0_ALL_WHITE 0
    #define PROTOCOL_OFF_ID1_DATE_MILEAGE 1
    #define PROTOCOL_OFF_ID2_DATE_ALARM 2
    #define PROTOCOL_OFF_ID3_DATE_BTNVOLUM 3
    #define PROTOCOL_OFF_ID4_DATE_TIME 4
    #define PROTOCOL_OFF_ID5_DATE_LIGHT 5
    #define PROTOCOL_OFF_ID6_DATE_FACTORY 6

    memcpy(page_data, protolcol_data->page_data, sizeof(uint8_t) * protolcol_data->page_data_sz);

    u8_data_tmp  = page_data[0] > 6 ? 6 : page_data[0];

    if (u8_data_tmp != PROTOCOL_OFF_ID0_ALL_WHITE)
        m_btn_id = u8_data_tmp - 1;

    /* Left Side Button */
    if (u8_data_tmp == PROTOCOL_OFF_ID0_ALL_WHITE) {
        for (i = SYS_BTN_ID0_MILEAGE; i < SYS_BTN_END; i++)
            Disable_Icon_Light(i);
    } else {
        Enable_Icon_Light(m_btn_id);
    }

    /* Left Right Data Content */

    if (u8_data_tmp == PROTOCOL_OFF_ID0_ALL_WHITE) {
        for (i = SYS_DATA_MSG_MILEAGE; i < SYS_DATA_MSG_END; i++)
            show_item_data[i]->hide();

        return;
    }

    if (u8_data_tmp == PROTOCOL_OFF_ID4_DATE_TIME) {
        if (page_data[2] == 0) {
            for (i = SYS_DATA_MSG_TIME_H; i < SYS_DATA_MSG_DAY + 1; i++)
                show_item_data[i]->text_color = Qt::white;
        } else {
            //(SYS_DATA_MSG_TIME_H ~ SYS_DATA_MSG_DAY)= page_data[2] + 2
            show_item_data[page_data[2] + 2]->text_color = QColor(0, 204, 240);
        }
    } else if (u8_data_tmp != PROTOCOL_OFF_ID0_ALL_WHITE) {
        switch (u8_data_tmp) {
        case PROTOCOL_OFF_ID1_DATE_MILEAGE:
            data_index = SYS_DATA_MSG_MILEAGE;
            break;
        case PROTOCOL_OFF_ID2_DATE_ALARM:
            data_index = SYS_DATA_MSG_ALARM;
            break;
        case PROTOCOL_OFF_ID3_DATE_BTNVOLUM:
            data_index = SYS_DATA_MSG_BTNVOLUM;
            break;
        case PROTOCOL_OFF_ID5_DATE_LIGHT:
            data_index = SYS_DATA_MSG_LIGHT;
            break;
        case PROTOCOL_OFF_ID6_DATE_FACTORY:
            data_index = SYS_DATA_MSG_FACTORY;
            break;
        default:
            data_index = SYS_DATA_MSG_MILEAGE;
            break;
        }

        if (page_data[2] == 1)
            show_item_data[data_index]->text_color = QColor(0, 204, 240);
        else
            show_item_data[data_index]->text_color = Qt::white;
    }

    //Data for Mile
    u8_data_tmp = page_data[3] & 0x03;
    if (u8_data_tmp)
        str_tmp.sprintf("MP/H");
    else
        str_tmp.sprintf("MP/H");

    show_item_data[SYS_DATA_MSG_MILEAGE]->set_text(str_tmp);

    //Data for Alarm
    u8_data_tmp = (page_data[3] & (0x0F << 2)) >> 2;
    if (u8_data_tmp == 0)
        str_tmp.sprintf("1");
    else if (u8_data_tmp == 1)
        str_tmp.sprintf("2");
    else
        str_tmp.sprintf("3");

    show_item_data[SYS_DATA_MSG_ALARM]->set_text(str_tmp);

    //Data for Btn Volume
    u8_data_tmp = (page_data[3] & (0x01 << 3)) >> 3;
    if (u8_data_tmp == 0)
        str_tmp.sprintf("OFF");
    else
        str_tmp.sprintf("ON");

    show_item_data[SYS_DATA_MSG_BTNVOLUM]->set_text(str_tmp);


    //Data for Year
    u8_data_tmp = page_data[9];
    str_tmp.sprintf("%d", u8_data_tmp);
    show_item_data[SYS_DATA_MSG_YEAR]->set_text(str_tmp);

    //Data for Month
    u8_data_tmp = page_data[8];
    str_tmp.sprintf("%d", u8_data_tmp);
    show_item_data[SYS_DATA_MSG_MONTH]->set_text(str_tmp);

    //Data for Day
    u8_data_tmp = page_data[7];
    str_tmp.sprintf("%d", u8_data_tmp);
    show_item_data[SYS_DATA_MSG_DAY]->set_text(str_tmp);

    //Data for Time-H
    u8_data_tmp = page_data[6];
    str_tmp.sprintf("%d", u8_data_tmp);
    show_item_data[SYS_DATA_MSG_TIME_H]->set_text(str_tmp);

    //Data for Time-M
    u8_data_tmp = page_data[5];
    str_tmp.sprintf("%d", u8_data_tmp);
    show_item_data[SYS_DATA_MSG_TIME_M]->set_text(str_tmp);

    //Data for Time-S
    u8_data_tmp = page_data[4];
    str_tmp.sprintf("%d", u8_data_tmp);
    show_item_data[SYS_DATA_MSG_TIME_S]->set_text(str_tmp);

    //Data for Week
    u8_data_tmp = page_data[10];
    str_tmp.sprintf("%d", u8_data_tmp);
    show_item_data[SYS_DATA_MSG_WEEK]->set_text(str_tmp);

    //Data for Light
    u8_data_tmp = page_data[11];
    str_tmp.sprintf("%d", u8_data_tmp);
    show_item_data[SYS_DATA_MSG_LIGHT]->set_text(str_tmp);

    //Data for Factory
    u8_data_tmp = page_data[12];
    str_tmp.sprintf("%d", u8_data_tmp);
    show_item_data[SYS_DATA_MSG_FACTORY]->set_text(str_tmp);
}
