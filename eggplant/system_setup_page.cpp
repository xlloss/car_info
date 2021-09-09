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

static QString sys_btn_txt[6] =
{
    "里程單位",
    "警示音",
    "按鍵音",
    "日期時間",
    "亮度",
    "出廠設定",
};

static QString sys_msg_tit[13] =
{
    "里程單位:",//0
    "警示音:",//1
    "按鍵音:",//2
    "時間:", ":", ":", //3, 4, 5
    "星期:",//7
    "日期:", "年", "月", "日", //8, 9, 10
    "亮度:",//11
    "出廠設定:",//12
};

static QString sys_msg_data[15] =
{
    "KM",
    "1",
    "OFF",
    "12",
    "00",
    "00",
    "星期一",
    "2021",
    "05",
    "05",
    "9",
    "否",
};

static int sys_btn_txt_x[6] = {25, 35, 35, 25, 45, 25};
static int sys_btn_txt_y[6] = {30, 30, 30, 30, 30, 30};
//                                 0    1    2    3    4    5    7    8    9    10   11   12
static int sys_data_title_x[13] = {170, 170, 170, 170, 300, 430, 170, 170, 300, 430, 170, 170};
static int sys_data_title_y[13] = {120, 120, 120, 65,  65,  65 , 125, 185, 120, 120, 120, 120};

enum {
  SYS_BTN_ID0_MILEAGE = 0,
  SYS_BTN_ID1_ALARM,
  SYS_BTN_ID2_BTNVOLUM,
  SYS_BTN_ID3_DATETIME,
  SYS_BTN_ID4_LIGHT,
  SYS_BTN_ID4_FACTORY,
  SYS_BTN_END,
};

enum {
  SYS_DATA_ID0_MILEAGE = 0,
  SYS_DATA_ID1_ALARM,
  SYS_DATA_ID2_BTNVOLUM,
  SYS_DATA_ID3_TIME_H,
  SYS_DATA_ID3_TIME_M,
  SYS_DATA_ID3_TIME_S,
  SYS_DATA_ID4_WEEK,
  SYS_DATA_ID4_YEAR,
  SYS_DATA_ID4_MONTH,
  SYS_DATA_ID5_DAY,
  SYS_DATA_ID6_LIGHT,
  SYS_DATA_ID7_FACTORY,
  SYS_DATA_END,
};

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

    for (i = SYS_DATA_ID0_MILEAGE; i < 6; i++) {
        str_len_title = sys_msg_tit[i].length() * 20;

        show_item[i] = new Show_text(this);
        show_item[i]->set_text(sys_msg_tit[i]);
        show_item[i]->setGeometry(sys_data_title_x[i], sys_data_title_y[i], str_len_title, 50);

        show_item[i]->hide();

    }


 // str_len_data = sys_msg_data[i].length() * 20;
 // show_item_data[i] = new Show_text(this);
 // show_item_data[i]->set_text(sys_msg_data[i]);
 // show_item_data[i]->setGeometry(sys_data_title_x[i] + str_len_title, sys_data_title_y[i], str_len_data, 50);
 // show_item_data[i]->hide();

    show_item[3]->show();
    show_item[4]->show();
    show_item[5]->show();
//    show_item_data[6]->show();


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
    int i;

    memcpy(page_data, protolcol_data->page_data, sizeof(uint8_t) * protolcol_data->page_data_sz);

    u8_data_tmp  = page_data[0] > 6 ? 6 : page_data[0];
    m_btn_id = u8_data_tmp - 1;
    if (u8_data_tmp == 0) {
        for (i = 0; i < 6; i++)
            Disable_Icon_Light(i);
    } else {
        Enable_Icon_Light(m_btn_id);
    }

//    /* current setting content check */
//    switch (page_data[2]) {
//    case 0:
//        break
//    case 4:
//
//
//
//
//
//
//        break;
//
//    default:
//        break;
//    }
//
//    if (page_data[2] == 0) {
//        for (i = 0; i < 6; i++) {
//            show_item_data[i]->text_color = Qt::white;
//            show_item_data[i]->hide();
//        }
//    } else ()
//
//
//
//
//    else {
//        u8_child_item = page_data[2] - 1;
//        u8_child_item_color = page_data[3];
//        if (u8_child_item_color == 1)
//            show_item_data[u8_child_item]->text_color = QColor(0, 204, 240);
//        else
//            show_item_data[u8_child_item]->text_color = Qt::white;
//    }




}
