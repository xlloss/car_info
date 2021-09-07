#ifndef SYSTEM_SETUP_PAGE_H
#define SYSTEM_SETUP_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define SYSTEM_SETUP_OBJNAME "SystemSetup_Page"
#define SYSTEM_SETUP_BG_IMG ":/icon/system_setup.png"

#define TIME_ADJ_TEX_TITLE_NUM 6
#define TIME_ADJ_CHILD_TEX_TIME_NUM 5



class SystemSetup_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit SystemSetup_Page(QWidget *parent = nullptr);

    Show_text *show_item[TIME_ADJ_TEX_TITLE_NUM];
    Show_text *show_item_child[TIME_ADJ_CHILD_TEX_TIME_NUM];
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
