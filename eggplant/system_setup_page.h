#ifndef SYSTEM_SETUP_PAGE_H
#define SYSTEM_SETUP_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define SYSTEM_SETUP_BG_IMG ":/icon/system_setup.png"

#define TIME_ADJ_TEX_TITLE_NUM 6
#define TIME_ADJ_CHILD_TEX_TIME_NUM 5
#define SYSTEM_SETUP_FONT_SZ 18
#define SYSTEM_SHOWITEM_NUM 15
#define SYSTEM_SYSBTN_NUM 6

class SystemSetup_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit SystemSetup_Page(QWidget *parent = nullptr);

    Show_text *show_item[SYSTEM_SHOWITEM_NUM];
    Show_text *show_item_data[SYSTEM_SHOWITEM_NUM];
    Icon_btn *system_btn[SYSTEM_SYSBTN_NUM];
    void Enable_Icon_Light(int i);
    void Disable_Icon_Light(int i);
    QFont m_font;
    int m_btn_id;
    int m_msg_tit_id;

    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
protected:
    void paintEvent(QPaintEvent *);

private:
    QString Change_DigToStr(uint8_t digital);

signals:

};

#endif
