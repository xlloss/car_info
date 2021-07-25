#ifndef SW_VERSIOM_PAGE_H
#define SW_VERSIOM_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define SWVER_OBJNAME "SwVersion_Page"
#define SWVER_BG_IMG ":/icon/rpm_page_bg.png"
#define SWVER_FM_IMG ":/icon/sw_version_table.png"

#define SW_VER_SUB_TEX_MSG_NUM 2
#define SW_VER_SUB_TEX_COL_NUM 2
#define SW_VER_SUB_TEX_ROW_NUM 10

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
