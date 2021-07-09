#ifndef CONTROL_MSG2_PAGE_H
#define CONTROL_MSG2_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

class ControlMsg2_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit ControlMsg2_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    QPixmap tableimg;
    Show_text *show_master_item[1];
    Show_text *show_sub_item[2][7];
    Show_text *show_sub_item_info[2][7];

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
