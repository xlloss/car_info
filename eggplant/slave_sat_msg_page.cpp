#include "slave_sat_msg_page.h"
#include <QPainter>
#include "string/string.h"
#include "coordinate.h"


SlaveSatMsg_Page::SlaveSatMsg_Page(QWidget *parent) : Frame_Page(parent)
{
    int i;
    QString btn_name;

    this->setObjectName("SlaveSatMsg_Page");

    bgimg.load(":/icon/rpm_page_bg.png");
    frameimg.load(":/icon/slave_msg_frame.png");

    for (i = 0; i < 8; i++) {
        sat_msg_btn[i] = new Icon_btn(this);
        sat_msg_str[i].append(SLASAT_MSG_BTN_NAME);
        sat_msg_btn[i]->setObjectName(sat_msg_str[i]);
        sat_msg_btn[i]->enable_scale = 0;
        btn_name = sat_msg_str[i];
        sat_msg_btn[i]->load_image_ft(":/icon/slve_msg_btn0.png", ":/icon/slve_msg_btn1.png");
        sat_msg_btn[i]->m_set_text_y = 28;
        sat_msg_btn[i]->font.setPixelSize(25);
        sat_msg_btn[i]->set_text(btn_name);
        sat_msg_btn[i]->setGeometry(SLASAT_MSG_BTN_X, SLASAT_MSG_BTN_Y + ((SLASAT_MSG_BTN_OFF_Y + SLASAT_MSG_BTN_H) * i),
                            SLASAT_MSG_BTN_W, SLASAT_MSG_BTN_H);
    }

    back_level_btn = new Icon_btn(this);
    back_level_btn->setObjectName("slave_sat_msg_back_level");
    back_level_btn->enable_scale = 0;
    btn_name = SLASAT_BACKPREV_BTN_NAME;
    back_level_btn->load_image_ft(":/icon/slave_back_level.png", ":/icon/slave_back_level.png");
    back_level_btn->m_set_text_x = 55;
    back_level_btn->m_set_text_y = 75;
    back_level_btn->set_text(btn_name);
    back_level_btn->setGeometry(SLASAT_BACK_LV_BTN_X, SLASAT_BACK_LV_BTN_Y,
                                SLASAT_BACK_LV_BTN_W, SLASAT_BACK_LV_BTN_H);


    back_main_btn = new Icon_btn(this);
    back_main_btn->setObjectName("slave_sat_msg_back_main");
    back_main_btn->enable_scale = 0;
    btn_name = SLASAT_BACKMAIN_BTN_NAME;
    back_main_btn->load_image_ft(":/icon/slave_back_main.png", ":/icon/slave_back_main.png");
    back_main_btn->m_set_text_x = 55;
    back_main_btn->m_set_text_y = 90;
    back_main_btn->set_text(btn_name);
    back_main_btn->setGeometry(SLASAT_BACK_MAIN_BTN_X, SLASAT_BACK_MAIN_BTN_Y,
                               SLASAT_BACK_MAIN_BTN_W, SLASAT_BACK_MAIN_BTN_H);
}

void SlaveSatMsg_Page::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
    //btn[i]->ft_light_enable();
}

void SlaveSatMsg_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    painter.drawPixmap(5, 20, frameimg, 0, 0, 788, 369);
}

void SlaveSatMsg_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    qDebug("SatInMsg_Page:%s page_number %d\n", __func__, protolcol_data->page_number);
}
