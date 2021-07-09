#ifndef SLAVE_SAT_MAIN_PAGE_H
#define SLAVE_SAT_MAIN_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "icon_btn.h"
#include <QPushButton>

#define BTN_SAT_MSG_X 100
#define BTN_SAT_MSG_Y 30
#define BTN_SAT_OFF_X 170
#define BTN_SAT_OFF_Y 8
#define BTN_SAT_W 260
#define BTN_SAT_H 36

#define BTN_BACK_LEVEL_X 460
#define BTN_BACK_LEVEL_Y 30
#define BTN_BACK_LEVEL_W 240
#define BTN_BACK_LEVEL_H 135

#define BTN_BACK_MAIN_X 460
#define BTN_BACK_MAIN_Y 185
#define BTN_BACK_MAIN_W 240
#define BTN_BACK_MAIN_H 192

class SlaveSatMsg_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit SlaveSatMsg_Page(QWidget *parent = nullptr);

    Icon_btn *sat_msg_btn[8];
    Icon_btn *back_level_btn;
    Icon_btn *back_main_btn;
    QPixmap backimg;
    QPixmap frameimg;
    QString sat_msg_str[10];

private slots:
    void Enable_Icon_Light(int i);

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
