#include "slave_sat_msg_page.h"
#include <QPainter>


SlaveSatMsg_Page::SlaveSatMsg_Page(QWidget *parent) : Frame_Page(parent)
{
    int i;
    QString btn_name;

    this->setObjectName("SlaveSatMsg_Page");

    backimg.load(":/icon/rpm_page_bg.png");
    frameimg.load(":/icon/slave_msg_frame.png");

    for (i = 0; i < 8; i++) {
        sat_msg_btn[i] = new Icon_btn(this);
        sat_msg_str[i].append("從站訊息");
        sat_msg_btn[i]->setObjectName(sat_msg_str[i]);
        sat_msg_btn[i]->enable_scale = 0;
        btn_name = sat_msg_str[i];
        sat_msg_btn[i]->load_image_ft(":/icon/slve_msg_btn0.png", ":/icon/slve_msg_btn1.png");
        sat_msg_btn[i]->m_set_text_y = 28;
        sat_msg_btn[i]->font.setPixelSize(25);
        sat_msg_btn[i]->set_text(btn_name);
        sat_msg_btn[i]->setGeometry(BTN_SAT_MSG_X, BTN_SAT_MSG_Y + ((BTN_SAT_OFF_Y + BTN_SAT_H) * i),
                            BTN_SAT_W, BTN_SAT_H);
    }

    back_level_btn = new Icon_btn(this);
    back_level_btn->setObjectName("slave_sat_msg_back_level");
    back_level_btn->enable_scale = 0;
    btn_name = "返回上一層";
    back_level_btn->load_image_ft(":/icon/slave_back_level.png", ":/icon/slave_back_level.png");
    back_level_btn->m_set_text_x = 55;
    back_level_btn->m_set_text_y = 75;
    back_level_btn->set_text(btn_name);
    back_level_btn->setGeometry(BTN_BACK_LEVEL_X, BTN_BACK_LEVEL_Y, BTN_BACK_LEVEL_W, BTN_BACK_LEVEL_H);


    back_main_btn = new Icon_btn(this);
    back_main_btn->setObjectName("slave_sat_msg_back_main");
    back_main_btn->enable_scale = 0;
    btn_name = "返回主頁";
    back_main_btn->load_image_ft(":/icon/slave_back_main.png", ":/icon/slave_back_main.png");
    back_main_btn->m_set_text_x = 55;
    back_main_btn->m_set_text_y = 90;
    back_main_btn->set_text(btn_name);
    back_main_btn->setGeometry(BTN_BACK_MAIN_X, BTN_BACK_MAIN_Y, BTN_BACK_MAIN_W, BTN_BACK_MAIN_H);
}

void SlaveSatMsg_Page::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
    //btn[i]->ft_light_enable();
}

void SlaveSatMsg_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(5, 20, frameimg, 0, 0, 788, 369);
}
