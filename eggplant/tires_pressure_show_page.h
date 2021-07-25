#ifndef TIRES_PRESSURE_SHOW_PAGE_H
#define TIRES_PRESSURE_SHOW_PAGE_H

#include <QMainWindow>
#include <QPushButton>
#include <QImage>
#include "frame_page.h"
#include "icon_btn.h"
#include "show_text.h"

#define TIRES_OBJNAME "TiresPressShow_Page"
#define TIRES_BG_IMG ":/icon/rpm_page_bg.png"
#define TIRES_FM_IMG ":/icon/tires_pressure_show.png"
#define TIRES_FONT_SIZE 18
#define TIRES_BTN_NUM 6

class TiresPressShow_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit TiresPressShow_Page(QWidget *parent = nullptr);

    Icon_btn *tires_btn[TIRES_BTN_NUM];
    Icon_btn *back_btn;
    QPixmap backimg;
    QPixmap frame_img;
    Show_text *tires_text_air[TIRES_BTN_NUM];
    Show_text *tires_text_temp[TIRES_BTN_NUM];
    Show_text *tires_value_air[TIRES_BTN_NUM];
    Show_text *tires_value_temp[TIRES_BTN_NUM];

private slots:
    void Enable_Icon_Light(int i);
    void mousePressEvent(QMouseEvent *ev);

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
