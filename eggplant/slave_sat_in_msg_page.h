#ifndef SLAVE_SAT_IN_MSG_PAGE_H
#define SLAVE_SAT_IN_MSG_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define SATIN_OBJNAME "SatInMsg_Page"
#define SATIN_BG_IMG ":/icon/rpm_page_bg.png"
#define SATIN_FM_IMG ":/icon/slave_sat_table.png"

#define SATIN_SUB_ITEM_COL_NUM 4
#define SATIN_SUB_ITEM_ROW_NUM 8
#define SATIN_SUB_ITEM_FONT_SIZE 20

class SatInMsg_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit SatInMsg_Page(QWidget *parent = nullptr);

    QPixmap tableimg;
    Show_text *show_sub_item[SATIN_SUB_ITEM_COL_NUM][SATIN_SUB_ITEM_ROW_NUM];
    Show_text *show_sub_item_info[SATIN_SUB_ITEM_COL_NUM][SATIN_SUB_ITEM_ROW_NUM];
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
    virtual void GetAckData(unsigned char *) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
