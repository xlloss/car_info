#ifndef TIME_ADJUST_PAGE_H
#define TIME_ADJUST_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

class TimeAdjust_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit TimeAdjust_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    Show_text *show_item[6];
    Show_text *show_item_child[5];

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
