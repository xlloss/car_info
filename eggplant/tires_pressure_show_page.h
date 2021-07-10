#ifndef TIRES_PRESSURE_SHOW_PAGE_H
#define TIRES_PRESSURE_SHOW_PAGE_H

#include <QMainWindow>
#include <QPushButton>
#include <QImage>
#include "frame_page.h"
#include "icon_btn.h"
#include "show_text.h"

#define TIRES_BTN_X 576
#define TIRES_BTN_Y 96
#define TIRES_BTN_W 85
#define TIRES_BTN_H 51

#define TIRES_ID_1_BTN_OFF_X 0
#define TIRES_ID_1_BTN_OFF_Y 0

#define TIRES_ID_6_BTN_OFF_X 0
#define TIRES_ID_6_BTN_OFF_Y 180

#define TIRES_ID_2_BTN_OFF_X TIRES_ID_3_BTN_OFF_X
#define TIRES_ID_2_BTN_OFF_Y -38

#define TIRES_ID_3_BTN_OFF_X -264
#define TIRES_ID_3_BTN_OFF_Y TIRES_ID_1_BTN_OFF_Y

#define TIRES_ID_4_BTN_OFF_X TIRES_ID_3_BTN_OFF_X
#define TIRES_ID_4_BTN_OFF_Y TIRES_ID_6_BTN_OFF_Y

#define TIRES_ID_5_BTN_OFF_X TIRES_ID_3_BTN_OFF_X
#define TIRES_ID_5_BTN_OFF_Y 220


class TiresPressShow_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit TiresPressShow_Page(QWidget *parent = nullptr);

    Icon_btn *tires_btn[6];
    Icon_btn *back_btn;
    QPixmap back_img;
    QPixmap frame_img;
    Show_text *tires_text_air[6];
    Show_text *tires_text_temp[6];

    Show_text *tires_value_air[6];
    Show_text *tires_value_temp[6];

private slots:
    void Enable_Icon_Light(int i);
    void mousePressEvent(QMouseEvent *ev);

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
