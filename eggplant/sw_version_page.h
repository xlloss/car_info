#ifndef SW_VERSIOM_PAGE_H
#define SW_VERSIOM_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

class SwVersion_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit SwVersion_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    QPixmap tableimg;
    Show_text *show_sub_item[2][10];
    Show_text *show_sub_item_info[2][10];

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
