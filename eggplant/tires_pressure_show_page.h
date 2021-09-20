#ifndef TIRES_PRESSURE_SHOW_PAGE_H
#define TIRES_PRESSURE_SHOW_PAGE_H

#include <QMainWindow>
#include <QPushButton>
#include <QImage>
#include "frame_page.h"
#include "icon_btn.h"
#include "show_text.h"

#define TIRES_IMG_0 ":icon/tires_0.png"
#define TIRES_IMG_1 ":icon/tires_1.png"
#define TIRES_OBJNAME "TiresPressShow_Page"
#define TIRES_BG_IMG ":/icon/rpm_page_bg.png"
#define TIRES_FM_IMG ":/icon/tires_pressure_show.png"
#define TIRES_FONT_SIZE 18
#define TIRES_BTN_NUM 6
#define TIRES_TEXT_DEF_X 50
#define TIRES_TEXT_DEF_W 200
#define TIRES_TEXT_DEF_H 50

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
    void Enable_Icon_Light(int i);
    void Disable_Icon_Light(int i);

    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
private slots:

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
