#ifndef BATTERY_VOLT_INFO_PAGE_H
#define BATTERY_VOLT_INFO_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define BATTVAL_OBJNAME "BatVoltInfo_Page"
#define BATTVAL_BG_IMG ":/icon/rpm_page_bg.png"
#define BATTVAL_FM_IMG ":/icon/battery-info.png"

#define BATTVAL_MAS_NUM 1
#define BATTVAL_TEX_COL_NUM 6
#define BATTVAL_TEX_ROW_NUM 4
#define BATTVAL_TEX_FONT_SIZE 20

class BatVoltInfo_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit BatVoltInfo_Page(QWidget *parent = nullptr);

    QPixmap tableimg;
    Show_text *show_master_item[BATTVAL_MAS_NUM];
    Show_text *show_sub_item[BATTVAL_TEX_COL_NUM][BATTVAL_TEX_ROW_NUM];
    Show_text *show_sub_item_info[BATTVAL_TEX_COL_NUM][BATTVAL_TEX_ROW_NUM];
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
