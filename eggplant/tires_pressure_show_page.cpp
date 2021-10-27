#include "tires_pressure_show_page.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPainter>
#include "string/string.h"
#include "coordinate.h"

static int tires_value_air_coord[]
{
    TIRES_VAL_AIR_ID0_X, TIRES_VAL_AIR_ID0_Y,
    TIRES_VAL_AIR_ID1_X, TIRES_VAL_AIR_ID1_Y,
    TIRES_VAL_AIR_ID2_X, TIRES_VAL_AIR_ID2_Y,
    TIRES_VAL_AIR_ID3_X, TIRES_VAL_AIR_ID3_Y,
    TIRES_VAL_AIR_ID4_X, TIRES_VAL_AIR_ID4_Y,
    TIRES_VAL_AIR_ID5_X, TIRES_VAL_AIR_ID5_Y,
};

static QString tires_btn_str[TIRES_BTN_NUM] = {TIRES_BTN_STR_ID0, TIRES_BTN_STR_ID1, TIRES_BTN_STR_ID2,
                            TIRES_BTN_STR_ID3, TIRES_BTN_STR_ID4, TIRES_BTN_STR_ID5};
static QString tires_btn_objname[TIRES_BTN_NUM] =
{
    TIRES_ID0_OBJNAME,
    TIRES_ID1_OBJNAME,
    TIRES_ID2_OBJNAME,
    TIRES_ID3_OBJNAME,
    TIRES_ID4_OBJNAME,
    TIRES_ID5_OBJNAME,
};

static QString tires_text_air_str[] =
{
    TIRES_AIR_TEX_ID0, TIRES_AIR_TEX_ID1, TIRES_AIR_TEX_ID2,
    TIRES_AIR_TEX_ID3, TIRES_AIR_TEX_ID4, TIRES_AIR_TEX_ID5
};

static int tires_text_air_coord[]
{
    TIRE_AIT_TEX_ID0_X, TIRE_AIT_TEX_ID0_Y,
    TIRE_AIT_TEX_ID1_X, TIRE_AIT_TEX_ID1_Y,
    TIRE_AIT_TEX_ID2_X, TIRE_AIT_TEX_ID2_Y,
    TIRE_AIT_TEX_ID3_X, TIRE_AIT_TEX_ID3_Y,
    TIRE_AIT_TEX_ID4_X, TIRE_AIT_TEX_ID4_Y,
    TIRE_AIT_TEX_ID5_X, TIRE_AIT_TEX_ID5_Y,
};

static QString tires_text_temp_str[] =
{
    TIRES_TEMP_TEX_ID0,
    TIRES_TEMP_TEX_ID1,
    TIRES_TEMP_TEX_ID2,
    TIRES_TEMP_TEX_ID3,
    TIRES_TEMP_TEX_ID4,
    TIRES_TEMP_TEX_ID5,
};

static int tires_text_temp_coord[]
{
    TIRES_TEMP_TEX_ID0_X, TIRES_TEMP_TEX_ID0_Y,
    TIRES_TEMP_TEX_ID1_X, TIRES_TEMP_TEX_ID1_Y,
    TIRES_TEMP_TEX_ID2_X, TIRES_TEMP_TEX_ID2_Y,
    TIRES_TEMP_TEX_ID3_X, TIRES_TEMP_TEX_ID3_Y,
    TIRES_TEMP_TEX_ID4_X, TIRES_TEMP_TEX_ID4_Y,
    TIRES_TEMP_TEX_ID5_X, TIRES_TEMP_TEX_ID5_Y,
};

static int tires_value_temp_coord[]
{
    TIRES_TMEPVAL_ID0_X, TIRES_TMEPVAL_ID0_Y,
    TIRES_TMEPVAL_ID1_X, TIRES_TMEPVAL_ID1_Y,
    TIRES_TMEPVAL_ID2_X, TIRES_TMEPVAL_ID2_Y,
    TIRES_TMEPVAL_ID3_X, TIRES_TMEPVAL_ID3_Y,
    TIRES_TMEPVAL_ID4_X, TIRES_TMEPVAL_ID4_Y,
    TIRES_TMEPVAL_ID5_X, TIRES_TMEPVAL_ID5_Y,
};

static int tires_btn_coord[TIRES_BTN_NUM * 2] = {
        TIRES_BTN_X + TIRES_ID_1_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_1_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_6_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_6_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_3_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_3_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_4_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_4_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_2_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_2_BTN_OFF_Y,
        TIRES_BTN_X + TIRES_ID_5_BTN_OFF_X, TIRES_BTN_Y + TIRES_ID_5_BTN_OFF_Y,
};

static int tires_btn_text_coord[TIRES_BTN_NUM * 2] = {
    TIRES_BTN_TEX_ID0_X, TIRES_BTN_TEX_ID0_Y,
    TIRES_BTN_TEX_ID1_X, TIRES_BTN_TEX_ID1_Y,
    TIRES_BTN_TEX_ID2_X, TIRES_BTN_TEX_ID2_Y,
    TIRES_BTN_TEX_ID3_X, TIRES_BTN_TEX_ID3_Y,
    TIRES_BTN_TEX_ID4_X, TIRES_BTN_TEX_ID4_Y,
    TIRES_BTN_TEX_ID5_X, TIRES_BTN_TEX_ID5_Y,
};

TiresPressShow_Page::TiresPressShow_Page(QWidget *parent) : Frame_Page(parent)
{
    int i, j;
    QString tires_btn_name, back_btn_name;

    this->setObjectName(TIRES_OBJNAME);

    backimg.load(TIRES_BG_IMG);
    frame_img.load(TIRES_FM_IMG);

    j = 0;
    for (i = 0; i < TIRES_BTN_NUM; i++) {
        tires_btn[i] = new Icon_btn(this);
        tires_btn[i]->setObjectName(tires_btn_objname[i]);
        tires_btn[i]->enable_scale = 0;

        tires_btn[i]->font.setPixelSize(TIRES_FONT_SIZE);
        tires_btn_name = tires_btn_str[i];
        tires_btn[i]->m_set_text_x = tires_btn_text_coord[j];
        tires_btn[i]->m_set_text_y = tires_btn_text_coord[j + 1];
        tires_btn[i]->set_text(tires_btn_name);

        tires_btn[i]->load_image_ft(TIRES_IMG_0, TIRES_IMG_1);
        tires_btn[i]->setGeometry(tires_btn_coord[j], tires_btn_coord[j + 1],
            TIRES_BTN_W, TIRES_BTN_H);

        tires_text_air[i] = new Show_text(this);
        tires_text_air[i]->set_text(tires_text_air_str[i]);
        tires_text_air[i]->m_text_x = TIRES_TEXT_DEF_X;
        tires_text_air[i]->m_font_size = TIRES_FONT_SIZE;
        tires_text_air[i]->font.setBold(0);
        tires_text_air[i]->setGeometry(tires_text_air_coord[j],
            tires_text_air_coord[j + 1],
            TIRES_TEXT_DEF_W, TIRES_TEXT_DEF_H);

        tires_text_air[i]->show();

        tires_value_air[i] = new Show_text(this);
        tires_value_air[i]->set_text(TIRES_AIR_VAL_DEF);
        tires_value_air[i]->m_font_size = TIRES_FONT_SIZE;
        tires_value_air[i]->m_text_x = TIRES_TEXT_DEF_X;
        tires_value_air[i]->font.setBold(0);
        tires_value_air[i]->setGeometry(tires_value_air_coord[j],
            tires_value_air_coord[j + 1],
            TIRES_TEXT_DEF_W, TIRES_TEXT_DEF_H);
        tires_value_air[i]->show();

        tires_text_temp[i] = new Show_text(this);
        tires_text_temp[i]->set_text(tires_text_temp_str[i]);
        tires_text_temp[i]->m_text_x = TIRES_TEXT_DEF_X;
        tires_text_temp[i]->m_font_size = TIRES_FONT_SIZE;;
        tires_text_temp[i]->font.setBold(0);
        tires_text_temp[i]->setGeometry(tires_text_temp_coord[j],
            tires_text_temp_coord[j + 1],
            TIRES_TEXT_DEF_W, TIRES_TEXT_DEF_H);
        tires_text_temp[i]->show();

        tires_value_temp[i] = new Show_text(this);
        tires_value_temp[i]->set_text(TIRES_TEMPVAL_DEF);
        tires_value_temp[i]->m_text_x = TIRES_TEXT_DEF_X;
        tires_value_temp[i]->m_font_size = TIRES_FONT_SIZE;;
        tires_value_temp[i]->font.setBold(0);
        tires_value_temp[i]->setGeometry(tires_value_temp_coord[j],
            tires_value_temp_coord[j + 1], TIRES_TEXT_DEF_W, TIRES_TEXT_DEF_H);
        tires_value_temp[i]->show();
        j = j + 2;
    }
}

void TiresPressShow_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg,
            GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
            GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);


    painter.drawPixmap(FRAME_IMG_WIN_X, FRAME_IMG_WIN_Y,
        frame_img,
        FRAME_IMG_X, FRAME_IMG_Y,
        FRAME_IMG_W, FRAME_IMG_H);
}

void TiresPressShow_Page::Enable_Icon_Light(int i)
{
    tires_btn[i]->ft_light_enable();
}

void TiresPressShow_Page::Disable_Icon_Light(int i)
{
    tires_btn[i]->ft_dark_enable();
}

void TiresPressShow_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    uint8_t page_data[BUFFER_SIZE];
    uint8_t u8_data_tmp;
    int8_t i8_data_temp;
    QString str_tmp;
    uint8_t tires_order[6] = {0, 2, 3, 4, 5, 1};
    uint8_t tiresbtn_order[6] = {0, 2, 3, 4, 5, 1};
    uint8_t tiresbtn_order2[2] = {5, 1};
    int i, j;

    //tires_btn[0] map tire number 1
    //tires_btn[1] map tire number 6
    //tires_btn[2] map tire number 2
    //tires_btn[3] map tire number 3
    //tires_btn[4] map tire number 4
    //tires_btn[5] map tire number 5

    memcpy(page_data, protolcol_data->page_data,
        sizeof(uint8_t) * protolcol_data->page_data_sz);

    j = 0;
    for (i = 0; i < 7; i = i + 2) {
        u8_data_tmp = (page_data[0] & (0x03 << i)) >> i;
        if (u8_data_tmp > 0) {
            Enable_Icon_Light(tiresbtn_order[j]);
        }
        else {
            Disable_Icon_Light(tiresbtn_order[j]);
        }
        j++;
    }

    j = 0;
    for (i = 0; i < 4; i = i + 2) {
        u8_data_tmp = (page_data[1] & (0x03 << i)) >> i;
        qDebug("u8_data_tmp=%d j=%d tiresbtn_order2[%d] %d\n", u8_data_tmp, j, j, tiresbtn_order2[j]);
        if (u8_data_tmp > 0)
            Enable_Icon_Light(tiresbtn_order2[j]);
        else
            Disable_Icon_Light(tiresbtn_order2[j]);

        j++;
    }

    j = 0;
    for (i = 2; i < 8; i++) {
        u8_data_tmp = page_data[i];
        str_tmp.sprintf("%d kPa", u8_data_tmp);
        tires_value_air[tires_order[j]]->set_text(str_tmp);
        j++;
    }

    j = 0;
    for (i = 8; i < 14; i++) {
        i8_data_temp = int8_t(page_data[i]);
        str_tmp.sprintf("%i °C", i8_data_temp - 40);
        tires_value_temp[tires_order[j]]->set_text(str_tmp);
        j++;
    }

    memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
}
