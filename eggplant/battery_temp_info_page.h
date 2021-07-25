#ifndef BATTERY_TEMP_INFO_PAGE_H
#define BATTERY_TEMP_INFO_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define BATTINFO_OBJNAME "BatTempInfo_Page"
#define BATTINFO_BG_IMG ":/icon/rpm_page_bg.png"
#define BATTINFO_FM_IMG ":/icon/battery-info.png"

#define BATTINFO_MAS_NUM 1
#define BATTINFO_TEX_COL_NUM 6
#define BATTINFO_TEX_ROW_NUM 4
#define BATTINFO_TEX_FONT_SIZE 20

class BatTempInfo_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit BatTempInfo_Page(QWidget *parent = nullptr);

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
