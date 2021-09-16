#ifndef EAI_PAGE_H
#define EAI_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define EAI_MAS_TEX_NUM 3
#define EAI_SUB_TEX_NUM 7

#define EAI_OBJNAME "EleAccInfo_Page"
#define EAI_BG_IMG ":/icon/rpm_page_bg.png"
#define EAI_FM_IMG ":/icon/electrical_accessories_information.png"
#define RAI_FONT_SIZE 20
#define RAI_FONT2_SIZE 16

enum {
    ELEACC_INFO_ITEM_I = 0,
    ELEACC_INFO_ITEM_J,
    ELEACC_INFO_ITEM_K,
};

enum {
    ELEACC_INFO_I1 = 0,
    ELEACC_INFO_I2,
    ELEACC_INFO_I3,
    ELEACC_INFO_I4,
    ELEACC_INFO_I5,
    ELEACC_INFO_I6,
    ELEACC_INFO_I7,

    ELEACC_INFO_J1 = 0,
    ELEACC_INFO_J2,
    ELEACC_INFO_J3,
    ELEACC_INFO_J4,
    ELEACC_INFO_J5,
    ELEACC_INFO_J6,
    ELEACC_INFO_J7,

    ELEACC_INFO_K1 = 0,
    ELEACC_INFO_K2,
    ELEACC_INFO_K3,
    ELEACC_INFO_K4,
    ELEACC_INFO_K5,
    ELEACC_INFO_K6,
    ELEACC_INFO_K7,
};

class EleAccInfo_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit EleAccInfo_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    QPixmap tableimg;
    Show_text *show_master_item[EAI_MAS_TEX_NUM];
    Show_text *show_sub_item[EAI_MAS_TEX_NUM][EAI_SUB_TEX_NUM];
    Show_text *show_sub_data[EAI_MAS_TEX_NUM][EAI_SUB_TEX_NUM];
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
