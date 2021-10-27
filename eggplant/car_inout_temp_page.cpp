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

enum {
    CAR_IN_TEMP = 0,
    CAR_OUT_TEMP,
    CAR_METER_TEMP,
};

CarInOut_Page::CarInOut_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(CAR_INOUT_OBJ);
    int i, j;

    bgimg.load(CARINOUT_BG_IMG);
    image_table.load(CARINOUT_FM_IMG);
    ramp_board.load(CARINOUT_RAMPBOARD_IMG);
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

        show_item_data[i] = new Show_text(this);
        show_item_data[i]->set_text(item_text_child[i]);
        show_item_data[i]->setGeometry(item_text_child_xy[j], item_text_child_xy[j + 1], 100, 70);
        show_item_data[i]->show();
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
    painter.drawImage(180, 50, ramp_board);
}

void CarInOut_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    uint8_t page_data[BUFFER_SIZE];
    int8_t car_in_temp;
    int8_t car_out_temp;
    int8_t car_meter_temp;
    QString str_temp;

    memcpy(page_data, protolcol_data->page_data, sizeof(uint8_t) * protolcol_data->page_data_sz);

    car_in_temp = int8_t((page_data[0] >> 1) - 30);
    if (car_in_temp < -40)
        car_in_temp = -40;

    if (car_in_temp > 97)
        car_in_temp = 97;

    str_temp.sprintf("%i °C", car_in_temp);
    show_item_data[CAR_IN_TEMP]->set_text(str_temp);


    car_out_temp = int8_t((page_data[1] >> 1) - 30);
    if (car_out_temp < -40)
        car_out_temp = -40;

    if (car_out_temp > 97)
        car_out_temp = 97;

    str_temp.sprintf("%i °C", car_out_temp);
    show_item_data[CAR_OUT_TEMP]->set_text(str_temp);

    car_meter_temp = int8_t(page_data[2] - 40);
    if (car_meter_temp < -40)
        car_meter_temp = -40;

    if (car_meter_temp > 97)
        car_meter_temp = 97;

    str_temp.sprintf("%i °C", car_meter_temp);
    show_item_data[CAR_METER_TEMP]->set_text(str_temp);
    memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
}
