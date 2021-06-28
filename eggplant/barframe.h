#ifndef BARFRAME_H
#define BARFRAME_H

#include <QFrame>
#include <QPaintEvent>
#include "icon_btn.h"

#define ICON_NUM 15

#define ID_0_0 ":/icon/ID-0-0.png"
#define ID_0_1 ":/icon/ID-0-1.png"
#define ID_1_0 ":/icon/ID-1-0.png"
#define ID_1_1 ":/icon/ID-1-1.png"
#define ID_2_0 ":/icon/ID-2-0.png"
#define ID_2_1 ":/icon/ID-2-1.png"
#define ID_3_0 ":/icon/ID-3-0.png"
#define ID_3_1 ":/icon/ID-3-1.png"
#define ID_4_0 ":/icon/ID-4-0.png"
#define ID_4_1 ":/icon/ID-4-1.png"
#define ID_5_0 ":/icon/ID-5-0.png"
#define ID_5_1 ":/icon/ID-5-1.png"
#define ID_6_0 ":/icon/ID-6-0.png"
#define ID_6_1 ":/icon/ID-6-1.png"
#define ID_7_0 ":/icon/ID-7-0.png"
#define ID_7_1 ":/icon/ID-7-1.png"
#define ID_8_0 ":/icon/ID-8-0.png"
#define ID_8_1 ":/icon/ID-8-1.png"
#define ID_9_0 ":/icon/ID-9-0.png"
#define ID_9_1 ":/icon/ID-9-1.png"
#define ID_10_0 ":/icon/ID-10-0.png"
#define ID_10_1 ":/icon/ID-10-1.png"

#define ID_11_0 ":/icon/ID-11-0.png"
#define ID_11_1 ":/icon/ID-11-1.png"
#define ID_12_0 ":/icon/ID-12-0.png"
#define ID_12_1 ":/icon/ID-12-1.png"
#define ID_13_0 ":/icon/ID-13-0.png"
#define ID_13_1 ":/icon/ID-13-1.png"
#define ID_14_0 ":/icon/ID-14-0.png"
#define ID_14_1 ":/icon/ID-14-1.png"


#define BAR_FRAME_X 0
#define BAR_FRAME_Y 0
#define BAR_FRAME_W 800
#define BAR_FRAME_H 55

#define ICON_W ICON_SCALE_SIZ_W
#define ICON_H ICON_SCALE_SIZ_H

#define ICON_ID_X 10
#define ICON_ID_Y 0
#define ICON_ID_OFF 20

namespace Ui {
class BarFrame;
}

class BarFrame : public QFrame
{
    Q_OBJECT

public:
    explicit BarFrame(QWidget *parent = nullptr);
    ~BarFrame();

    Icon_btn *icon_id[ICON_NUM];
    QPixmap green_line[2];
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::BarFrame *ui;
};

#endif // BARFRAME_H
