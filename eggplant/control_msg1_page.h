#ifndef CONTROL_MSG1_PAGE_H
#define CONTROL_MSG1_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define CONTROL1_OBJNAME "ControlMsg1_Page"
#define CONTROL1_BG_IMG ":/icon/rpm_page_bg.png"
#define CONTROL1_FM_IMG ":/icon/control_msg1.png"

#define CONTROL1_MSA_TEX_NUM 2
#define CONTROL1_SUB_TEX_COL_NUM 3
#define CONTROL1_SUB_TEX_ROW_NUM 6
#define CONTROL1_FONT_SIZE 20

class ControlMsg1_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit ControlMsg1_Page(QWidget *parent = nullptr);

    QPixmap tableimg;
    Show_text *show_master_item[CONTROL1_MSA_TEX_NUM];
    Show_text *show_sub_item[CONTROL1_SUB_TEX_COL_NUM][CONTROL1_SUB_TEX_ROW_NUM];
    Show_text *show_sub_item_info[CONTROL1_SUB_TEX_COL_NUM][CONTROL1_SUB_TEX_ROW_NUM];

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
