#ifndef CONTROL_MSG2_PAGE_H
#define CONTROL_MSG2_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define CONTROL2_OBJNAME "ControlMsg2_Page"
#define CONTROL2_BG_IMG ":/icon/rpm_page_bg.png"
#define CONTROL2_FM_IMG ":/icon/control_msg2.png"

#define CONTROL2_MSA_TEX_NUM 1
#define CONTROL2_SUB_TEX_COL_NUM 2
#define CONTROL2_SUB_TEX_ROW_NUM 7

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
