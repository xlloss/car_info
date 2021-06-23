#include "barframe.h"
#include "ui_barframe.h"

BarFrame::BarFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::BarFrame)
{
    ui->setupUi(this);


    QString icon_name[ICON_NUM][2] = {{APPLE_1, APPLE_2},
                                      {BANANA_1, BANANA_2}
                                     };

    int i;

    for (i = 0; i < ICON_NUM; i++) {
        icon_id[i] = new Icon_btn(this);
        icon_id[i]->load_image_ft(icon_name[i][0], icon_name[i][1]);
        icon_id[i]->setGeometry(ICON_ID_X + (ICON_W * i + ICON_ID_OFF),
                                ICON_ID_Y, ICON_W, ICON_H);
        icon_id[i]->show();
    }
}

BarFrame::~BarFrame()
{
    delete ui;
}
