#ifndef BCM_PAGE_H
#define BCM_PAGE_H

#include <QMainWindow>
#include <QPushButton>
#include <QImage>
#include "frame_page.h"
#include "icon_btn.h"

#define BCM_BTN_NUM 4
#define BCM_BTN_ID0_OBJNAME "bcm_btn_id_0"
#define BCM_BTN_ID1_OBJNAME "bcm_btn_id_1"
#define BCM_BTN_ID2_OBJNAME "bcm_btn_id_2"
#define BCM_BTN_ID3_OBJNAME "bcm_btn_id_3"
#define BCM_BTN_ID4_OBJNAME "bcm_btn_id_4"

class Bcm_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Bcm_Page(QWidget *parent = nullptr);

    Icon_btn *func_btn[BCM_BTN_NUM];
    Icon_btn *back_btn;
    QPixmap frame_img;
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
private slots:
    void Enable_Icon_Light(int i);

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
