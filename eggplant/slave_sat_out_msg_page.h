#ifndef SLAVE_SAT_OUT_MSG_PAGE_H
#define SLAVE_SAT_OUT_MSG_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

class SatOutMsg_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit SatOutMsg_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    QPixmap tableimg;
    Show_text *show_master_item[2];
    Show_text *show_sub_item[3][6];
    Show_text *show_sub_item_info[3][6];

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
