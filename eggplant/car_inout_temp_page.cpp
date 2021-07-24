#include "car_inout_temp_page.h"
#include <QPainter>
#include "string/string.h"

QString item_text[3] = {CAR_INOUT_TEX_ID0, CAR_INOUT_TEX_ID1, CAR_INOUT_TEX_ID2};
QString item_text_child[3] = {CAR_INOUT_TEX_SAMPLE, CAR_INOUT_TEX_SAMPLE, CAR_INOUT_TEX_SAMPLE};


int item_text_xy[6] = {
    CAR_INOUT_TEX_ID0_X , CAR_INOUT_TEX_ID0_Y,
    CAR_INOUT_TEX_ID1_X , CAR_INOUT_TEX_ID1_Y,
    CAR_INOUT_TEX_ID2_X , CAR_INOUT_TEX_ID2_Y,
};

int item_text_child_xy[6] = {
    CAR_INOUT_CHILD_TEX_ID0_X, CAR_INOUT_CHILD_TEX_ID0_Y,
    CAR_INOUT_CHILD_TEX_ID1_X, CAR_INOUT_CHILD_TEX_ID1_Y,
    CAR_INOUT_CHILD_TEX_ID2_X, CAR_INOUT_CHILD_TEX_ID2_Y,
};

CarInOut_Page::CarInOut_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("CarInOut_Page");
    int i, j;

    backimg.load(":/icon/rpm_page_bg.png");
    image_table.load(":/icon/cat_inout_table.png");
    if (image_car_bus.load(":/icon/car_inout_temp.png") == false) {
        qDebug("image_car_bus load fail");
        return;
    }

    j = 0;
    for (i = 0; i < 3; i++) {
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(item_text[i]);
        show_item[i]->setGeometry(item_text_xy[j], item_text_xy[j + 1], 150, 70);
        show_item[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 0; i < 3; i++) {
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

    painter.drawPixmap(0, 0, backimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    painter.setBrush(QBrush(Qt::black));
    painter.drawImage(0, 60, image_car_bus);
    painter.drawImage(5, 270, image_table);
}
