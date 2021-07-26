#include "car_inout_temp_page.h"
#include <QPainter>
#include "string/string.h"

QString item_text[CAR_INOUT_TEX_NUM] = {CAR_INOUT_TEX_ID0, CAR_INOUT_TEX_ID1, CAR_INOUT_TEX_ID2};
QString item_text_child[CAR_INOUT_CHILD_TEX_NUM] =
{CAR_INOUT_TEX_SAMPLE, CAR_INOUT_TEX_SAMPLE, CAR_INOUT_TEX_SAMPLE};


int item_text_xy[CAR_INOUT_TEX_NUM * 2] = {
    CAR_INOUT_TEX_ID0_X , CAR_INOUT_TEX_ID0_Y,
    CAR_INOUT_TEX_ID1_X , CAR_INOUT_TEX_ID1_Y,
    CAR_INOUT_TEX_ID2_X , CAR_INOUT_TEX_ID2_Y,
};

int item_text_child_xy[CAR_INOUT_CHILD_TEX_NUM * 2] = {
    CAR_INOUT_CHILD_TEX_ID0_X, CAR_INOUT_CHILD_TEX_ID0_Y,
    CAR_INOUT_CHILD_TEX_ID1_X, CAR_INOUT_CHILD_TEX_ID1_Y,
    CAR_INOUT_CHILD_TEX_ID2_X, CAR_INOUT_CHILD_TEX_ID2_Y,
};

CarInOut_Page::CarInOut_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(CAR_INOUT_OBJ);
    int i, j;

    bgimg.load(CARINOUT_BG_IMG);
    image_table.load(CARINOUT_FM_IMG);
    if (image_car_bus.load(CARINOUT_FM2_IMG) == false) {
        qDebug("image_car_bus load fail");
        return;
    }

    j = 0;
    for (i = 0; i < CAR_INOUT_TEX_NUM; i++) {
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(item_text[i]);
        show_item[i]->setGeometry(item_text_xy[j], item_text_xy[j + 1], 150, 70);
        show_item[i]->show();
//        j = j + 2;
//    }
//
//    j = 0;
//    for (i = 0; i < CAR_INOUT_CHILD_TEX_NUM; i++) {
        show_item_child[i] = new Show_text(this);
        show_item_child[i]->set_text(item_text_child[i]);
        show_item_child[i]->setGeometry(item_text_child_xy[j], item_text_child_xy[j + 1], 100, 70);
        show_item_child[i]->show();
        j = j + 2;
    }
}

void CarInOut_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    painter.setBrush(QBrush(Qt::black));
    painter.drawImage(CAR_INOUT_BUS_IMG_X, CAR_INOUT_BUS_IMG_Y, image_car_bus);
    painter.drawImage(CAR_INOUT_TABLE_IMG_X, CAR_INOUT_TABLE_IMG_Y, image_table);
}

void CarInOut_Page::GetMcuData()
{
    qDebug("CarInOut_Page:%s\n", __func__);
}
