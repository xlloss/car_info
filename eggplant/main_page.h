#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QMainWindow>
#include <QImage>
#include <QPushButton>
#include "frame_page.h"
#include "icon_btn.h"


#define MAIN_PAGE_OBJNAME "Main_Page"
#define MAIN_PAGE_BACKGROUND ":/icon/main_page_bg.png"
#define MAIN_PAGE_BUS ":/icon/bus-bg.png"

#define BTN_LEFT_X 100
#define BTN_LEFT_Y 35

#define BTN_RIGHT_X 10
#define BTN_RIGHT_Y BTN_LEFT_Y

#define BTN_OFF_X 170
#define BTN_OFF_Y 10

#define BTN_W 260
#define BTN_H 66


class Main_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Main_Page(QWidget *parent = nullptr);

    //QPushButton *btn[10];
    Icon_btn *btn[10];
    QPixmap backimg;
    void LoadBackground();
    int m_load_background_img;
private slots:
    void Enable_Icon_Light(int i);

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
