#ifndef EAI_PAGE_H
#define EAI_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

class EleAccInfo_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit EleAccInfo_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    QPixmap tableimg;
    Show_text *show_master_item[3];
    Show_text *show_sub_item[3][7];
    Show_text *show_sub_item_info[3][7];

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
