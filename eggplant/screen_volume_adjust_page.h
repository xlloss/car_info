#ifndef SCREEN_VOLUME_ADJUST_PAGE_H
#define SCREEN_VOLUME_ADJUST_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define VOL_TEX_NUM 2
#define VOL_LV_NUM 7
#define VOL_ADJ_OBJNAME "ScreenVolumeAdjust_Page"
#define VOL_ADJ_BG_IMG ":/icon/time_adjust.png"

class ScreenVolumeAdjust_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit ScreenVolumeAdjust_Page(QWidget *parent = nullptr);

    Show_text *show_volume_text;
    Show_text *show_volume_val;
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
    virtual void GetAckData(unsigned char *) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
