#ifndef SLAVE_SAT_OUT_MSG_PAGE_H
#define SLAVE_SAT_OUT_MSG_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"
#include "protocol_fmt.h"

#define SATOUT_MSATER_ITEM_NUM 2
#define SATOUT_MSG_COL_NUM 4
#define SATOUT_MSG_ROW_NUM 8
#define SATOUT_FONT_SIZE 20

#define SATOUT_BOJNAME "SatOutMsg_Page"
#define SATOUT_BG_IMG ":/icon/rpm_page_bg.png"
#define SATOUT_FM_IMG ":/icon/slave_sat_table.png"

class SatOutMsg_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit SatOutMsg_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    QPixmap tableimg;
    Show_text *show_master_item[SATOUT_MSATER_ITEM_NUM];
    Show_text *show_sub_item[SATOUT_MSG_COL_NUM][SATOUT_MSG_ROW_NUM];
    Show_text *show_sub_item_inf4[SATOUT_MSG_COL_NUM][SATOUT_MSG_ROW_NUM];
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
    virtual void GetAckData(unsigned char *) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
