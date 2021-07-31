#ifndef CAR_INOUT_TEMP_PAGE_H
#define CAR_INOUT_TEMP_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define CAR_INOUT_TEX_NUM 3
#define CAR_INOUT_CHILD_TEX_NUM 3
#define CARINOUT_BG_IMG ":/icon/rpm_page_bg.png"
#define CARINOUT_FM_IMG ":/icon/cat_inout_table.png"
#define CARINOUT_FM2_IMG ":/icon/car_inout_temp.png"

class CarInOut_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit CarInOut_Page(QWidget *parent = nullptr);

    QImage image_car_bus;
    QImage image_table;
    Show_text *show_item[CAR_INOUT_TEX_NUM];
    Show_text *show_item_child[CAR_INOUT_CHILD_TEX_NUM];
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
