#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define HOME_PAGE_BACKGROUND ":/icon/background.png"
#define HOME_PAGE_BUS ":/icon/bus-bg.png"
#define HOME_ITEM_TEX1_NUM 8
#define HOME_ITEM_TEX2_NUM 8
#define HOME_ITEM_TEX3_NUM 1
#define HOME_ITEM_TEX_ALL_NUM 17


class Home_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Home_Page(QWidget *parent = nullptr);
    QImage image_car_bus;
    Show_text *show_item[HOME_ITEM_TEX_ALL_NUM];
    Show_text *show_data[HOME_ITEM_TEX_ALL_NUM];

    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
