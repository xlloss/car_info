#include "system_setup_page.h"
#include <QPainter>
#include "string/string.h"

QString time_text[TIME_ADJ_TEX_TITLE_NUM] = {
    TIME_ADJ_TEX_TIME,
    TIME_ADJ_TEX_WEEK,
    TIME_ADJ_TEX_DATE,
    TIME_ADJ_TEX_YEAR,
    TIME_ADJ_TEX_MONTH,
    TIME_ADJ_TEX_DAY
};

QString time_text_child[TIME_ADJ_CHILD_TEX_TIME_NUM] =
{   TIME_ADJ_CHILD_TEX_TIME_SAMPLE,
    TIME_ADJ_CHILD_TEX_WEEK_SAMPLE,
    TIME_ADJ_CHILD_TEX_YEAR_SAMPLE,
    TIME_ADJ_CHILD_TEX_MONTH_SAMPLE,
    TIME_ADJ_CHILD_TEX_DAY_SAMPLE
};

int time_text_xy[TIME_ADJ_TEX_TITLE_NUM * 2] = {
    TIME_ADJ_TEX_TITLE_ID0_X, TIME_ADJ_TEX_TITLE_ID0_Y,
    TIME_ADJ_TEX_TITLE_ID1_X, TIME_ADJ_TEX_TITLE_ID1_Y,
    TIME_ADJ_TEX_TITLE_ID2_X, TIME_ADJ_TEX_TITLE_ID2_Y,
};

int time_text2_xy[TIME_ADJ_TEX_TITLE_NUM] = {
    TIME_ADJ_TEX_TITLE_ID3_X, TIME_ADJ_TEX_TITLE_ID3_Y,
    TIME_ADJ_TEX_TITLE_ID4_X, TIME_ADJ_TEX_TITLE_ID4_Y,
    TIME_ADJ_TEX_TITLE_ID5_X, TIME_ADJ_TEX_TITLE_ID5_Y,
};

int time_text_child_xy[TIME_ADJ_CHILD_TEX_TIME_NUM * 2] = {
    TIME_ADJ_CHILD_TEX_ID0_X, TIME_ADJ_CHILD_TEX_ID0_Y,
    TIME_ADJ_CHILD_TEX_ID1_X, TIME_ADJ_CHILD_TEX_ID1_Y,
    TIME_ADJ_CHILD_TEX_ID2_X, TIME_ADJ_CHILD_TEX_ID2_Y,
    TIME_ADJ_CHILD_TEX_ID3_X, TIME_ADJ_CHILD_TEX_ID3_Y,
    TIME_ADJ_CHILD_TEX_ID4_X, TIME_ADJ_CHILD_TEX_ID4_Y,
};

#define SYSTEM_BTN ":/icon/system_setup_btn.png"
QString sys_btn_txt[6] =
{
    "里程單位",
    "警示音",
    "按鍵音",
    "日期時間",
    "亮度",
    "出廠設定",
};

QString sys_msg_tit[8] =
{
    "里程單位:",
    "警示音:",
    "按鍵音:",
    "時間:",
    "星期:",
    "日期:",
    "亮度:",
    "出廠設定:",
};

int sys_btn_txt_x[6] = {25, 35, 35, 25, 45, 25};
int sys_btn_txt_y[6] = {30, 30, 30, 30, 30, 30};
enum {
  SYS_BTN_ID0_MILEAGE = 0,
  SYS_BTN_ID1_ALARM,
  SYS_BTN_ID2_BTNVOLUM,
  SYS_BTN_ID3_DATETIME,
  SYS_BTN_ID4_LIGHT,
  SYS_BTN_ID4_FACTORY,
  SYS_BTN_END,
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
    int i, j;

    this->setObjectName(SYSTEM_SETUP_OBJNAME);
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

    //j = 0;
    //for (i = 0; i < TIME_ADJ_TEX_TITLE_NUM / 2; i++) {
    //    show_item[i] = new Show_text(this);
    //    show_item[i]->set_text(time_text[i]);
    //    show_item[i]->setGeometry(time_text_xy[j], time_text_xy[j + 1], 150, 70);
    //    show_item[i]->show();
    //    j = j + 2;
    //}
    //
    //j = 0;
    //for (i = 3; i < TIME_ADJ_TEX_TITLE_NUM / 2; i++) {
    //    show_item[i] = new Show_text(this);
    //    show_item[i]->set_text(time_text[i]);
    //    show_item[i]->setGeometry(time_text2_xy[j], time_text2_xy[j + 1], 150, 50);
    //    show_item[i]->show();
    //    j = j + 2;
    //}
    //
    //j = 0;
    //for (i = 0; i < TIME_ADJ_CHILD_TEX_TIME_NUM; i++) {
    //    show_item_child[i] = new Show_text(this);
    //    show_item_child[i]->set_text(time_text_child[i]);
    //    show_item_child[i]->text_color.setRgb(0, 245, 245);
    //    show_item_child[i]->setGeometry(time_text_child_xy[j], time_text_child_xy[j + 1], 120, 70);
    //    show_item_child[i]->show();
    //    j = j + 2;
    //}
}

void SystemSetup_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont usefont(m_font.family(), m_font.pointSize(), m_font.weight(), m_font.bold());

    painter.drawPixmap(0, 0, bgimg,
                       GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.setFont(usefont);
    painter.setPen(QColor(Qt::white));

    if (m_btn_id == SYS_BTN_ID3_DATETIME) {
        painter.drawText(170, 65, sys_msg_tit[SYS_BTN_ID3_DATETIME]);
        painter.drawText(170, 125, sys_msg_tit[SYS_BTN_ID3_DATETIME + 1]);
        painter.drawText(170, 185, sys_msg_tit[SYS_BTN_ID3_DATETIME + 2]);
    } else {
        painter.drawText(170, 120, sys_msg_tit[m_msg_tit_id]);
    }

}

void SystemSetup_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{

}
