#ifndef BARFRAME_H
#define BARFRAME_H

#include <QFrame>
#include "icon_btn.h"

#define ICON_NUM 2

#define APPLE_1 ":/icon/apple-1.png"
#define APPLE_2 ":/icon/apple-2.png"

#define BANANA_1 ":/icon/banana-1.png"
#define BANANA_2 ":/icon/banana-2.png"

#define BAR_FRAME_X 0
#define BAR_FRAME_Y 10
#define BAR_FRAME_W 800
#define BAR_FRAME_H 100

#define ICON_W ICON_SCALE_SIZ_W
#define ICON_H ICON_SCALE_SIZ_H

#define ICON_ID_X 10
#define ICON_ID_Y 0
#define ICON_ID_OFF 10

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

private:
    Ui::BarFrame *ui;
};

#endif // BARFRAME_H
