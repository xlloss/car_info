#include "main_page.h"
#include <QPainter>

#define BTN_LEFT_X 100
#define BTN_LEFT_Y 70

#define BTN_RIGHT_X 100
#define BTN_RIGHT_Y BTN_LEFT_Y

#define BTN_OFF_X 10
#define BTN_OFF_Y 10


#define BTN_W 200
#define BTN_H 50


Main_Page::Main_Page(QWidget *parent) : Frame_Page(parent)
{
    int i;

    for (i = 0; i < 5; i++) {
        btn[i] = new QPushButton(this);
        btn[i]->setGeometry(BTN_LEFT_X, BTN_LEFT_Y + ((BTN_OFF_Y + BTN_H) * i),
                            BTN_W, BTN_H);
    }

    for (i = 0; i < 5; i++) {
        btn[i + 5] = new QPushButton(this);
        btn[i + 5]->setGeometry(BTN_RIGHT_X + BTN_W + BTN_OFF_X + 200,
                                BTN_RIGHT_Y + ((BTN_OFF_Y + BTN_H) * i),
                                BTN_W, BTN_H);
    }

    this->setWindowState(Qt::WindowMinimized);
}
