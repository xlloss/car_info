#ifndef BARFRAME_H
#define BARFRAME_H

#include <QFrame>
#include <QPaintEvent>
#include "icon_btn.h"
#include "frame_page.h"
#include "string/string.h"

#define CARGEAR_ICON_NUM 15

#define CARGEAR_ID_0_0 ":/icon/ID-0-0.png"
#define CARGEAR_ID_0_1 ":/icon/ID-0-1.png"
#define CARGEAR_ID_1_0 ":/icon/ID-1-0.png"
#define CARGEAR_ID_1_1 ":/icon/ID-1-1.png"
#define CARGEAR_ID_2_0 ":/icon/ID-2-0.png"
#define CARGEAR_ID_2_1 ":/icon/ID-2-1.png"
#define CARGEAR_ID_3_0 ":/icon/ID-3-0.png"
#define CARGEAR_ID_3_1 ":/icon/ID-3-1.png"
#define CARGEAR_ID_4_0 ":/icon/ID-4-0.png"
#define CARGEAR_ID_4_1 ":/icon/ID-4-1.png"
#define CARGEAR_ID_5_0 ":/icon/ID-5-0.png"
#define CARGEAR_ID_5_1 ":/icon/ID-5-1.png"
#define CARGEAR_ID_6_0 ":/icon/ID-6-0.png"
#define CARGEAR_ID_6_1 ":/icon/ID-6-1.png"
#define CARGEAR_ID_7_0 ":/icon/ID-7-0.png"
#define CARGEAR_ID_7_1 ":/icon/ID-7-1.png"
#define CARGEAR_ID_8_0 ":/icon/ID-8-0.png"
#define CARGEAR_ID_8_1 ":/icon/ID-8-1.png"
#define CARGEAR_ID_9_0 ":/icon/ID-9-0.png"
#define CARGEAR_ID_9_1 ":/icon/ID-9-1.png"
#define CARGEAR_ID_10_0 ":/icon/ID-10-0.png"
#define CARGEAR_ID_10_1 ":/icon/ID-10-1.png"

#define CARGEAR_ID_11_0 ":/icon/ID-11-0.png"
#define CARGEAR_ID_11_1 ":/icon/ID-11-1.png"
#define CARGEAR_ID_12_0 ":/icon/ID-12-0.png"
#define CARGEAR_ID_12_1 ":/icon/ID-12-1.png"
#define CARGEAR_ID_13_0 ":/icon/ID-13-0.png"
#define CARGEAR_ID_13_1 ":/icon/ID-13-1.png"
#define CARGEAR_ID_14_0 ":/icon/ID-14-0.png"
#define CARGEAR_ID_14_1 ":/icon/ID-14-1.png"

namespace Ui {
class BarFrame;
}

class BarFrame : public Frame_Page
{
    Q_OBJECT

public:
    explicit BarFrame(QWidget *parent = nullptr);
    ~BarFrame();
    Icon_btn *icon_id[CARGEAR_ICON_NUM];
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;

private slots:
        void Enable_Icon_Light(int i);

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::BarFrame *ui;
};

#endif // BARFRAME_H
