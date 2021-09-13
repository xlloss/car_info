#ifndef TEMP_MODULE_PAGE_H
#define TEMP_MODULE_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define TEMP_MOD_OBJNAME "TempModule_Page"
#define TEMP_MOD_BG_IMG ":/icon/rpm_page_bg.png"
#define TEMP_MOD_FM_IMG ":/icon/temp_module.png"


#define TEMP_MAS_ITEM_NUM 2
#define TEMP_SUB_ITEM_COL_NUM 2
#define TEMP_SUB_ITEM_ROW_NUM 8

#define TEMP_SUB_INFO_COL_NUM 3
#define TEMP_SUB_INFO_ROW_NUM 6

#define TEMP_FONT_SIZE 20


class TempModule_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit TempModule_Page(QWidget *parent = nullptr);

    QPixmap tableimg;
    Show_text *show_master_item[TEMP_MAS_ITEM_NUM];
    Show_text *show_sub_item[TEMP_SUB_ITEM_COL_NUM][TEMP_SUB_ITEM_ROW_NUM];
    Show_text *show_sub_item_info[TEMP_SUB_INFO_COL_NUM][TEMP_SUB_INFO_ROW_NUM];
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
    virtual void GetAckData(unsigned char *) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
