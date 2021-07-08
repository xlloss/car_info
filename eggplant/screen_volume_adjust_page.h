#ifndef SCREEN_VOLUME_ADJUST_PAGE_H
#define SCREEN_VOLUME_ADJUST_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

class ScreenVolumeAdjust_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit ScreenVolumeAdjust_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    Show_text *show_volume_text;
    Show_text *show_volume_val;

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
