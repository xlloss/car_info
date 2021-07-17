#ifndef SLAVE_SAT_IN_MSG_PAGE_H
#define SLAVE_SAT_IN_MSG_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

class SatInMsg_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit SatInMsg_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    QPixmap tableimg;

    Show_text *show_sub_item[4][8];
    Show_text *show_sub_item_info[4][8];

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
