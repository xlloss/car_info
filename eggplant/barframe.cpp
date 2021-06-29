#include <QPainter>
#include "barframe.h"
#include "ui_barframe.h"
#include <QDebug>
BarFrame::BarFrame(QWidget *parent) :
    Frame_Page(parent),
    ui(new Ui::BarFrame)
{
    ui->setupUi(this);

    int i;
    QString icon_name[ICON_NUM][2] = {{ID_0_0, ID_0_1},
                                       {ID_1_0, ID_1_1},
                                       {ID_2_0, ID_2_1},
                                       {ID_3_0, ID_3_1},
                                       {ID_4_0, ID_4_1},
                                       {ID_5_0, ID_5_1},
                                       {ID_6_0, ID_6_1},
                                       {ID_7_0, ID_7_1},
                                       {ID_8_0, ID_8_1},
                                       {ID_9_0, ID_9_1},
                                       {ID_10_0,ID_10_1},
                                       {ID_11_0, ID_11_1},
                                       {ID_12_0, ID_12_1},
                                       {ID_13_0, ID_13_1},
                                       {ID_14_0, ID_14_1},
                                     };

    for (i = 0; i < 5; i++) {
        icon_id[i] = new Icon_btn(this);
        icon_id[i]->load_image_ft(icon_name[i][0], icon_name[i][1]);
        icon_id[i]->setGeometry(10 + (ICON_W * i + ICON_ID_OFF),
                                ICON_ID_Y, ICON_W, ICON_H);
        icon_id[i]->show();
    }

    for (i = 5; i < 5 + 6; i++) {
        icon_id[i] = new Icon_btn(this);
        icon_id[i]->load_image_ft(icon_name[i][0], icon_name[i][1]);
        icon_id[i]->setGeometry(460 + (ICON_W * (i - 5) + ICON_ID_OFF),
                                ICON_ID_Y, ICON_W, ICON_H);
        icon_id[i]->show();
    }

    for (i = 11; i < 15; i++) {
        icon_id[i] = new Icon_btn(this);

        icon_id[i]->l_scale_sz_w = 30;
        icon_id[i]->l_scale_sz_h = 30;
        icon_id[i]->d_scale_sz_w = 30;
        icon_id[i]->d_scale_sz_h = 30;

        icon_id[i]->load_image_ft(icon_name[i][0], icon_name[i][1]);
        icon_id[i]->setGeometry(285 + (ICON_W * (i - 11) + 5),
                                15, ICON_W, ICON_H);
        icon_id[i]->show();
    }

    this->setGeometry(500, 115, BAR_FRAME_W, BAR_FRAME_H);
    this->setObjectName("BarFrame");

}

BarFrame::~BarFrame()
{
    delete ui;
}

void BarFrame::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(0, 0, this->width(), this->height());
}


void BarFrame::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
    icon_id[i]->ft_light_enable();
}
