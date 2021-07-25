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

    QPixmap backimg;
    QPixmap tableimg;
    Show_text *show_master_item[1];
    Show_text *show_sub_item[6][4];
    Show_text *show_sub_item_info[6][4];

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
