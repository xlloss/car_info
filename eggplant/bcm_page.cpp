#include "bcm_page.h"
#include <QPainter>


QString func_btn_str[4] = {"從站輸入狀態", "從站故障檢測", "模塊溫度", "程式序號版本"};
QString back_btn_str = "返回上級菜單";

QString func_btn_objname[4] = {"bcm_btn_id_0", "bcm_btn_id_1", "bcm_btn_id_2", "bcm_btn_id_3"};
QString back_btn_objname = "bcm_btn_id_4";

int func_btn_coord[8] = {
        FUNC_BTN_X, FUNC_BTN_Y,
        FUNC_BTN_X, FUNC_BTN_Y + FUNC_BTN_OFF_Y,
        FUNC_BTN_X + FUNC_BTN_OFF_X, FUNC_BTN_Y,
        FUNC_BTN_X + FUNC_BTN_OFF_X, FUNC_BTN_Y + FUNC_BTN_OFF_Y,
    };

int func_btn_text_coord[8] = {
        15, 70,
        15, 70,
        45, 70,
        15, 70,
};

int back_btn_coord[2] = {BACK_BTN_X, BACK_BTN_Y};
int back_btn_text_coord[2] = {15, 130};

Bcm_Page::Bcm_Page(QWidget *parent) : Frame_Page(parent)
{
    int i, j;
    QString func_btn_name, back_btn_name;

    this->setObjectName("Bcm_Page");

    back_img.load(":/icon/rpm_page_bg.png");
    frame_img.load(":/icon/slave_msg_frame.png");

    j = 0;
    for (i = 0; i < 4; i++) {
        func_btn[i] = new Icon_btn(this);
        func_btn[i]->setObjectName(func_btn_objname[i]);
        func_btn[i]->enable_scale = 0;

        func_btn_name = func_btn_str[i];
        func_btn[i]->m_set_text_x = func_btn_text_coord[j];
        func_btn[i]->m_set_text_y = func_btn_text_coord[j + 1];
        func_btn[i]->set_text(func_btn_name);

        func_btn[i]->load_image_ft(":icon/bus_sys_sat_btn_0.png", ":icon/bus_sys_sat_btn_1.png");
        func_btn[i]->setGeometry(func_btn_coord[j], func_btn_coord[j + 1], FUNC_BTN_W, FUNC_BTN_H);

        j = j + 2;
    }

    back_btn = new Icon_btn(this);
    back_btn->setObjectName(back_btn_objname);
    back_btn->enable_scale = 0;

    back_btn->m_set_text_x = back_btn_text_coord[0];
    back_btn->m_set_text_y = back_btn_text_coord[1];
    back_btn->set_text(back_btn_str);

    back_btn->load_image_ft(":icon/bus_sys_back_btn_0.png", ":icon/bus_sys_back_btn_1.png");
    back_btn->setGeometry(back_btn_coord[0], back_btn_coord[1], BACK_BTN_W, BACK_BTN_H);

    this->setWindowState(Qt::WindowNoState);
}

void Bcm_Page::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
//    btn[i]->ft_light_enable();
}

void Bcm_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, back_img, 0, 55, 800, 480);
    painter.drawPixmap(5, 20, frame_img, 0, 0, 788, 369);
}
