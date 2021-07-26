#include <QPainter>
#include "barframe.h"
#include "ui_barframe.h"
#include <QDebug>
#include "string/string.h"

BarFrame::BarFrame(QWidget *parent) :
    Frame_Page(parent),
    ui(new Ui::BarFrame)
{
    ui->setupUi(this);

    int i;
    QString icon_name[CARGEAR_ICON_NUM][2] = {
            {CARGEAR_ID_0_0,  CARGEAR_ID_0_1},
            {CARGEAR_ID_1_0,  CARGEAR_ID_1_1},
            {CARGEAR_ID_2_0,  CARGEAR_ID_2_1},
            {CARGEAR_ID_3_0,  CARGEAR_ID_3_1},
            {CARGEAR_ID_4_0,  CARGEAR_ID_4_1},
            {CARGEAR_ID_5_0,  CARGEAR_ID_5_1},
            {CARGEAR_ID_6_0,  CARGEAR_ID_6_1},
            {CARGEAR_ID_7_0,  CARGEAR_ID_7_1},
            {CARGEAR_ID_8_0,  CARGEAR_ID_8_1},
            {CARGEAR_ID_9_0,  CARGEAR_ID_9_1},
            {CARGEAR_ID_10_0, CARGEAR_ID_10_1},
            {CARGEAR_ID_11_0, CARGEAR_ID_11_1},
            {CARGEAR_ID_12_0, CARGEAR_ID_12_1},
            {CARGEAR_ID_13_0, CARGEAR_ID_13_1},
            {CARGEAR_ID_14_0, CARGEAR_ID_14_1},
            };

    for (i = CARGEAR_ID_0; i < CARGEAR_ID_5; i++) {
        icon_id[i] = new Icon_btn(this);
        icon_id[i]->load_image_ft(icon_name[i][0], icon_name[i][1]);
        icon_id[i]->setGeometry(CARGEAR_ID_0_X + (CARGEAR_W * i + CARGEAR_ID_OFF),
                                CARGEAR_ID_0_Y, CARGEAR_W, CARGEAR_W);
        icon_id[i]->show();
    }

    for (i = CARGEAR_ID_5; i < CARGEAR_ID_11; i++) {
        icon_id[i] = new Icon_btn(this);
        icon_id[i]->load_image_ft(icon_name[i][0], icon_name[i][1]);
        icon_id[i]->setGeometry(CARGEAR_ID_5_STAR_X + (CARGEAR_W * (i - CARGEAR_ID_5) + CARGEAR_ID_OFF),
                                CARGEAR_ID_0_Y, CARGEAR_W, CARGEAR_W);
        icon_id[i]->show();
    }

    for (i = CARGEAR_ID_11; i < CARGEAR_ID_15; i++) {
        icon_id[i] = new Icon_btn(this);

        icon_id[i]->l_scale_sz_w = 30;
        icon_id[i]->l_scale_sz_h = 30;
        icon_id[i]->d_scale_sz_w = 30;
        icon_id[i]->d_scale_sz_h = 30;

        icon_id[i]->load_image_ft(icon_name[i][0], icon_name[i][1]);
        icon_id[i]->setGeometry(CARGEAR_ID_11_STAR_X + (CARGEAR_W * (i - CARGEAR_ID_11) + 5), 15, CARGEAR_W, CARGEAR_H);
        icon_id[i]->show();
    }

    this->setGeometry(0, 0, CARGEAR_BAR_FRAME_W, CARGEAR_BAR_FRAME_H);
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

void BarFrame::GetMcuData()
{
    qDebug("BarFrame:%s\n", __func__);
}
