#ifndef BATTERY_TEMP_INFO_PAGE_H
#define BATTERY_TEMP_INFO_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

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
