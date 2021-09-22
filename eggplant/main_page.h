#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QMainWindow>
#include <QImage>
#include <QPushButton>
#include "frame_page.h"
#include "icon_btn.h"
#include "coordinate.h"


#define MAIN_PAGE_BACKGROUND ":/icon/main_page_bg.png"
#define MAIN_PAGE_BUS ":/icon/bus-bg.png"
#define MAIN_PAG_FONT_TYPE "DroidSans"
#define MAIN_PAG_FONT_SIZE 22
#define MAIN_PAGE_BTN ":/icon/menu-button.png"
#define MAIN_PAGE_BTN_PRESS ":/icon/menu-button-press.png"

enum main_page_id {
    MAIN_PAG_ID_MILE_RPM = 0,
    MAIN_PAG_ID_CAR_INOUT_TEMP,
    MAIN_PAG_ID_TIME_ADJ,
    MAIN_PAG_ID_SPEAK_SET,
    MAIN_PAG_ID_EMESG,
    MAIN_PAG_ID_CTRL_MSG,
    MAIN_PAG_ID_BATT_SAT,
    MAIN_PAG_ID_BUS_SYS_SAT,
    MAIN_PAG_ID_TIRE_PRESS,
    MAIN_PAG_ID_RETURN_MAIN,
    MAIN_PAG_TOTAL_NUM
};

class Main_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Main_Page(QWidget *parent = nullptr);

    Icon_btn *btn[MAIN_PAG_TOTAL_NUM];
    void LoadBackground();
    int m_load_background_img;
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;

private slots:
    void Enable_Icon_Light(int i);
    void Disable_Icon_Light(int i);

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
