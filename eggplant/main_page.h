#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include <QPushButton>

#define BTN_LEFT_X 100
#define BTN_LEFT_Y 70

#define BTN_RIGHT_X 100
#define BTN_RIGHT_Y BTN_LEFT_Y

#define BTN_OFF_X 10
#define BTN_OFF_Y 10

#define BTN_W 200
#define BTN_H 50


class Main_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Main_Page(QWidget *parent = nullptr);

    QPushButton *btn[10];

signals:

};

#endif
