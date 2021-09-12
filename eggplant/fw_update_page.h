#ifndef FW_UPDATE_PAGE_H
#define FW_UPDATE_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define FWV_UPDATE_OBJNAME "FwUpdate_Page"
#define FWV_UPDATE_BG_IMG ":/icon/system_setup.png"

class FwUpdate_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit FwUpdate_Page(QWidget *parent = nullptr);

    Show_text *show_item;
    Show_text *show_item_child1;
    Show_text *show_item_child2;

    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
