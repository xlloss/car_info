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
        btn[i] = new QPushButton(this);
        btn_name = main_page_str[i];
        btn[i]->setText(btn_name);
        btn[i]->setGeometry(BTN_LEFT_X, BTN_LEFT_Y + ((BTN_OFF_Y + BTN_H) * i),
                            BTN_W, BTN_H);
    }

    for (i = 0; i < 5; i++) {
        btn[i + 5] = new QPushButton(this);
        btn_name = main_page_str[i + 5];
        btn[i + 5]->setText(btn_name);
        btn[i + 5]->setGeometry(BTN_RIGHT_X + BTN_W + BTN_OFF_X + 200,
                                BTN_RIGHT_Y + ((BTN_OFF_Y + BTN_H) * i),
                                BTN_W, BTN_H);
    }

    this->setWindowState(Qt::WindowNoState);
}
