#include "main_page.h"
#include <QPainter>
#include <QTextCodec>
#include "string/string.h"
#include "coordinate.h"

Main_Page::Main_Page(QWidget *parent) : Frame_Page(parent)
{
    int i, item_num;
    QString btn_name;

    QString main_page_string[MAIN_STR_NUM] = {
        {MAIN_STR_ID0},
        {MAIN_STR_ID1},
        {MAIN_STR_ID2},
        {MAIN_STR_ID3},
        {MAIN_STR_ID4},
        {MAIN_STR_ID5},
        {MAIN_STR_ID6},
        {MAIN_STR_ID7},
        {MAIN_STR_ID8},
        {MAIN_STR_ID9}
    };

    this->setObjectName(MAIN_PAGE_OBJNAME);
    bgimg.load(MAIN_PAGE_BACKGROUND);

    item_num = MAIN_PAG_TOTAL_NUM / 2;
    for (i = 0; i < item_num; i++) {
        btn[i] = new Icon_btn(this);
        btn[i]->setObjectName(main_page_string[i]);
        btn[i]->enable_scale = 0;
        btn_name = main_page_string[i];
        btn[i]->load_image_ft(MAIN_PAGE_BTN, MAIN_PAGE_BTN_PRESS);
        btn[i]->setGeometry(MAIN_BTN_LEFT_X,
            MAIN_BTN_LEFT_Y + ((MAIN_BTN_OFF_Y + MAIN_BTN_H) * i),
            MAIN_BTN_W, MAIN_BTN_H);

        btn[i]->set_text(btn_name);


        btn[i + MAIN_PAG_ID_CTRL_MSG] = new Icon_btn(this);
        btn[i + MAIN_PAG_ID_CTRL_MSG]->setObjectName(main_page_string[i]);
        btn[i + MAIN_PAG_ID_CTRL_MSG]->enable_scale = 0;

        btn_name = main_page_string[i + MAIN_PAG_ID_CTRL_MSG];
        btn[i + MAIN_PAG_ID_CTRL_MSG]->load_image_ft(MAIN_PAGE_BTN, MAIN_PAGE_BTN_PRESS);
        btn[i + MAIN_PAG_ID_CTRL_MSG]->setGeometry(
            MAIN_BTN_RIGHT_X + MAIN_BTN_W + MAIN_BTN_OFF_X,
            MAIN_BTN_RIGHT_Y + ((MAIN_BTN_OFF_Y + MAIN_BTN_H) * i),
            MAIN_BTN_W, MAIN_BTN_H);

        btn[i + MAIN_PAG_ID_CTRL_MSG]->set_text(btn_name);
    }

    this->setGeometry(GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                      GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

}

void Main_Page::Enable_Icon_Light(int i)
{
    btn[i]->ft_light_enable();
}

void Main_Page::Disable_Icon_Light(int i)
{
    btn[i]->ft_dark_enable();
}

void Main_Page::LoadBackground()
{
    QPalette palette;

    bgimg.load(MAIN_PAGE_BACKGROUND);
    palette.setColor(QPalette::Background, Qt::black);
}

void Main_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont font(MAIN_PAG_FONT_TYPE, MAIN_PAG_FONT_SIZE);

    painter.setFont(font);
    painter.drawPixmap(0, 0,
        bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
        GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
}

void Main_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    uint8_t page_data[BUFFER_SIZE];
    int i, item_num, ret;

    CopyAckToData(protolcol_data, page_data);
    item_num = (MAIN_PAG_ID_BUS_SYS_SAT + 1);
    i = MAIN_PAG_ID_MILE_RPM;
    while (i < item_num) {
        ret = (page_data[0] >> i) & 0x01;
        if (ret)
            Enable_Icon_Light(i);
        else
            Disable_Icon_Light(i);
        i++;
    }

    item_num = MAIN_PAG_TOTAL_NUM;
    i = MAIN_PAG_ID_TIRE_PRESS;
    while (i < item_num) {
        ret = (page_data[1] >> (i - MAIN_PAG_ID_TIRE_PRESS)) & 0x01;
        if (ret)
            Enable_Icon_Light(i);
        else
            Disable_Icon_Light(i);
        i++;
    }

    CopyDataToAck(protolcol_data);
}
