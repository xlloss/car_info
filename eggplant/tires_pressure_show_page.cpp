#include "tires_pressure_show_page.h"
#include <QPainter>
#include <QMouseEvent>

QString  tires_value_air_default = "000kPa";
#define TIRES_VAL_AIR_OFF_X 70
int tires_value_air_coord[]
{
    350 + TIRES_VAL_AIR_OFF_X, 55,
    350 + TIRES_VAL_AIR_OFF_X, 300,
    -20 + TIRES_VAL_AIR_OFF_X, 60,
    -20 + TIRES_VAL_AIR_OFF_X, 60 + (80 * 1),
    -20 + TIRES_VAL_AIR_OFF_X, 60 + (80 * 2),
    -20 + TIRES_VAL_AIR_OFF_X, 60 + (80 * 3),
};


QString tires_btn_str[6] = {"輪胎1", "輪胎6", "輪胎3", "輪胎4", "輪胎2", "輪胎5"};
QString tires_btn_objname[6] =
{
  "tires_id_1",
  "tires_id_6",
  "tires_id_3",
  "tires_id_4",
  "tires_id_2",
  "tires_id_5"
};

QString tires_text_air_str[] =
{
    "胎壓01:",
    "胎壓06:",
    "胎壓02:",
    "胎壓03:",
    "胎壓04:",
    "胎壓05:",
};

int tires_text_air_coord[]
{
    350, 55,
    350, 300,
    -20, 60,
    -20, 60 + (80 * 1),
    -20, 60 + (80 * 2),
    -20, 60 + (80 * 3),
};

QString tires_text_temp_str[] =
{
    "溫度01:",
    "溫度06:",
    "溫度02:",
    "溫度03:",
    "溫度04:",
    "溫度05:",
};

#define TEXT_TEMP_OFF_Y 30
int tires_text_temp_coord[]
{
    350, 55 + TEXT_TEMP_OFF_Y,
    350, 300 + TEXT_TEMP_OFF_Y,
    -20, 60 + TEXT_TEMP_OFF_Y,
    -20, 60 + (80 * 1) + TEXT_TEMP_OFF_Y,
    -20, 60 + (80 * 2) + TEXT_TEMP_OFF_Y,
    -20, 60 + (80 * 3) + TEXT_TEMP_OFF_Y,
};

QString  tires_value_temp_default = "000°C";
#define TIRES_VAL_TEMP_OFF_X 70
int tires_value_temp_coord[]
{
    350 + TIRES_VAL_TEMP_OFF_X, 55 + TEXT_TEMP_OFF_Y,
    350 + TIRES_VAL_TEMP_OFF_X, 300 + TEXT_TEMP_OFF_Y,
    -20 + TIRES_VAL_TEMP_OFF_X, 60 + TEXT_TEMP_OFF_Y,
    -20 + TIRES_VAL_TEMP_OFF_X, 60 + (80 * 1) + TEXT_TEMP_OFF_Y,
    -20 + TIRES_VAL_TEMP_OFF_X, 60 + (80 * 2) + TEXT_TEMP_OFF_Y,
    -20 + TIRES_VAL_TEMP_OFF_X, 60 + (80 * 3) + TEXT_TEMP_OFF_Y,
};


int tires_btn_coord[12] = {
        TIRES_BTN_X + TIRES_ID_1_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_1_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_6_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_6_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_3_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_3_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_4_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_4_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_2_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_2_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_5_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_5_BTN_OFF_Y,
    };

int tires_btn_text_coord[12] = {
        20, 30,
        20, 30,
        20, 30,
        20, 30,
        20, 30,
        20, 30,
};



TiresPressShow_Page::TiresPressShow_Page(QWidget *parent) : Frame_Page(parent)
{
    int i, j;
    QString tires_btn_name, back_btn_name;

    this->setObjectName("TiresPressShow_Page");

    back_img.load(":/icon/rpm_page_bg.png");
    frame_img.load(":/icon/tires_pressure_show.png");

    j = 0;
    for (i = 0; i < 6; i++) {
        tires_btn[i] = new Icon_btn(this);
        tires_btn[i]->setObjectName(tires_btn_objname[i]);
        tires_btn[i]->enable_scale = 0;
    
        tires_btn[i]->font.setPixelSize(18);
        tires_btn_name = tires_btn_str[i];
        tires_btn[i]->m_set_text_x = tires_btn_text_coord[j];
        tires_btn[i]->m_set_text_y = tires_btn_text_coord[j + 1];
        tires_btn[i]->set_text(tires_btn_name);
    
        tires_btn[i]->load_image_ft(":icon/tires_0.png", ":icon/tires_1.png");
        tires_btn[i]->setGeometry(tires_btn_coord[j], tires_btn_coord[j + 1],
            TIRES_BTN_W, TIRES_BTN_H);

        j = j + 2;
    }

    j = 0;
    for (i = 0; i < 6; i++) {
        tires_text_air[i] = new Show_text(this);
        tires_text_air[i]->set_text(tires_text_air_str[i]);
        tires_text_air[i]->m_text_x = 50;
        tires_text_air[i]->m_text_y = 25;
        tires_text_air[i]->font.setPixelSize(18);
        tires_text_air[i]->font.setBold(0);
        tires_text_air[i]->setGeometry(tires_text_air_coord[j], tires_text_air_coord[j + 1], 150, 50);
        tires_text_air[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 0; i < 6; i++) {
        tires_value_air[i] = new Show_text(this);
        tires_value_air[i]->set_text(tires_value_air_default);
        tires_value_air[i]->m_text_x = 50;
        tires_value_air[i]->m_text_y = 25;
        tires_value_air[i]->font.setPixelSize(18);
        tires_value_air[i]->font.setBold(0);
        tires_value_air[i]->setGeometry(tires_value_air_coord[j], tires_value_air_coord[j + 1], 150, 50);
        tires_value_air[i]->show();
        j = j + 2;
    }



    j = 0;
    for (i = 0; i < 6; i++) {
        tires_text_temp[i] = new Show_text(this);
        tires_text_temp[i]->set_text(tires_text_temp_str[i]);
        tires_text_temp[i]->m_text_x = 50;
        tires_text_temp[i]->m_text_y = 25;
        tires_text_temp[i]->font.setPixelSize(18);
        tires_text_temp[i]->font.setBold(0);
        tires_text_temp[i]->setGeometry(tires_text_temp_coord[j], tires_text_temp_coord[j + 1], 150, 50);
        tires_text_temp[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 0; i < 6; i++) {
        tires_value_temp[i] = new Show_text(this);
        tires_value_temp[i]->set_text(tires_value_temp_default);
        tires_value_temp[i]->m_text_x = 50;
        tires_value_temp[i]->m_text_y = 25;
        tires_value_temp[i]->font.setPixelSize(18);
        tires_value_temp[i]->font.setBold(0);
        tires_value_temp[i]->setGeometry(tires_value_temp_coord[j], tires_value_temp_coord[j + 1], 150, 50);
        tires_value_temp[i]->show();
        j = j + 2;
    }
}

void TiresPressShow_Page::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
//    btn[i]->ft_light_enable();
}

void TiresPressShow_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, back_img, 0, 55, 800, 480);
    painter.drawPixmap(2, 5, frame_img, 0, 0, 800, 418);
}

void TiresPressShow_Page::mousePressEvent(QMouseEvent *ev)
{
    qDebug("x=%d, y=%d", ev->x(), ev->y());
}
