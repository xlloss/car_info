#include "bcm_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

QString bcm_func_btn_str[BCM_BTN_NUM] = {BCM_BTN_STR_ID0, BCM_BTN_STR_ID1, BCM_BTN_STR_ID2, BCM_BTN_STR_ID3};
QString back_btn_str = BCM_BACKPREV_BTN_NAME;

QString func_btn_objname[BCM_BTN_NUM] = {BCM_BTN_ID0_OBJNAME, BCM_BTN_ID1_OBJNAME, BCM_BTN_ID2_OBJNAME, BCM_BTN_ID3_OBJNAME};
QString back_btn_objname = BCM_BTN_ID4_OBJNAME;


int func_btn_coord[BCM_BTN_NUM * 2] = {
    BCM_FUNC_BTN_X,  BCM_FUNC_BTN_Y,
    BCM_FUNC_BTN_X,  BCM_FUNC_BTN_Y +    BCM_FUNC_BTN_OFF_Y,
    BCM_FUNC_BTN_X + BCM_FUNC_BTN_OFF_X, BCM_FUNC_BTN_Y,
    BCM_FUNC_BTN_X + BCM_FUNC_BTN_OFF_X, BCM_FUNC_BTN_Y + BCM_FUNC_BTN_OFF_Y,
};

int func_btn_text_coord[BCM_BTN_NUM * 2] = {
    BCM_BTN_TEX_ID0_X, BCM_BTN_TEX_ID0_Y,
    BCM_BTN_TEX_ID1_X, BCM_BTN_TEX_ID1_Y,
    BCM_BTN_TEX_ID2_X, BCM_BTN_TEX_ID2_Y,
    BCM_BTN_TEX_ID3_X, BCM_BTN_TEX_ID3_Y,
};

int back_btn_coord[2] = {BCM_BACK_BTN_X, BCM_BACK_BTN_Y};
int back_btn_text_coord[2] = {BCM_BACK_TEX_X, BCM_BACK_TEX_Y};

Bcm_Page::Bcm_Page(QWidget *parent) : Frame_Page(parent)
{
    int i, j;
    QString func_btn_name, back_btn_name;

    this->setObjectName("Bcm_Page");

    bgimg.load(":/icon/rpm_page_bg.png");
    frame_img.load(":/icon/slave_msg_frame.png");

    j = 0;
    for (i = 0; i < BCM_BTN_NUM; i++) {
        func_btn[i] = new Icon_btn(this);
        func_btn[i]->setObjectName(func_btn_objname[i]);
        func_btn[i]->enable_scale = 0;

        func_btn_name = bcm_func_btn_str[i];
        func_btn[i]->m_set_text_x = func_btn_text_coord[j];
        func_btn[i]->m_set_text_y = func_btn_text_coord[j + 1];
        func_btn[i]->set_text(func_btn_name);

        func_btn[i]->load_image_ft(":icon/bus_sys_sat_btn_0.png", ":icon/bus_sys_sat_btn_1.png");
        func_btn[i]->setGeometry(func_btn_coord[j], func_btn_coord[j + 1], BCM_FUNC_BTN_W, BCM_FUNC_BTN_H);

        j = j + 2;
    }

    back_btn = new Icon_btn(this);
    back_btn->setObjectName(back_btn_objname);
    back_btn->enable_scale = 0;

    back_btn->m_set_text_x = back_btn_text_coord[0];
    back_btn->m_set_text_y = back_btn_text_coord[1];
    back_btn->set_text(back_btn_str);

    back_btn->load_image_ft(":icon/bus_sys_back_btn_0.png", ":icon/bus_sys_back_btn_1.png");
    back_btn->setGeometry(back_btn_coord[0], back_btn_coord[1], BCM_BACK_BTN_W, BCM_BACK_BTN_H);

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

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawPixmap(5, 20, frame_img, 0, 0, 788, 369);
}
