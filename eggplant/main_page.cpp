#include "main_page.h"
#include <QPainter>
#include "string/main_string.h"

#define  BUTTON_STR(n) STR_ID##n

Main_Page::Main_Page(QWidget *parent) : Frame_Page(parent)
{
    int i;
    QString btn_name;

    this->setObjectName("Main_Page");

    for (i = 0; i < 5; i++) {
        btn[i] = new Icon_btn(this);
        btn[i]->setObjectName(main_page_str[i]);
        btn[i]->enable_scale = 0;
        btn_name = main_page_str[i];
        btn[i]->load_image_ft(":/icon/menu-button.png", ":/icon/menu-button-press.png");
        btn[i]->setGeometry(BTN_LEFT_X, BTN_LEFT_Y + ((BTN_OFF_Y + BTN_H) * i),
                            BTN_W, BTN_H);

        btn[i]->set_text(btn_name);
    }

    for (i = 0; i < 5; i++) {
        btn[i + 5] = new Icon_btn(this);
        btn[i + 5]->setObjectName(main_page_str[i]);
        btn[i + 5]->enable_scale = 0;
        btn_name = main_page_str[i + 5];
        btn[i + 5]->load_image_ft(":/icon/menu-button.png", ":/icon/menu-button-press.png");
        btn[i + 5]->setGeometry(BTN_RIGHT_X + BTN_W + BTN_OFF_X,
                                BTN_RIGHT_Y + ((BTN_OFF_Y + BTN_H) * i),
                                BTN_W, BTN_H);

        btn[i + 5]->set_text(btn_name);
    }

    backimg.load(":/icon/main_page_bg.png");

    this->setWindowState(Qt::WindowNoState);
}

void Main_Page::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
    btn[i]->ft_light_enable();
}

void Main_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    //painter.drawImage(190, 80, image_car_bus);
}
