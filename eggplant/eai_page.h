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

class EleAccInfo_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit EleAccInfo_Page(QWidget *parent = nullptr);

    QPixmap backimg;
    QPixmap tableimg;
    Show_text *show_master_item[EAI_MAS_TEX_NUM];
    Show_text *show_sub_item[EAI_MAS_TEX_NUM][EAI_SUB_TEX_NUM];
    Show_text *show_sub_item_info[EAI_MAS_TEX_NUM][EAI_SUB_TEX_NUM];
    virtual void GetMcuData() override;
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
