#include "main_page.h"
#include <QPainter>
#include <QTextCodec>
#include "string/string.h"
#include "coordinate.h"

Main_Page::Main_Page(QWidget *parent) : Frame_Page(parent)
{
    int i;
    QString btn_name;
    QPalette palette;
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
    backimg.load(MAIN_PAGE_BACKGROUND);
    this->setGeometry(GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                      GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    for (i = 0; i < 5; i++) {
        btn[i] = new Icon_btn(this);
        btn[i]->setObjectName(main_page_string[i]);
        btn[i]->enable_scale = 0;
        btn_name = main_page_string[i];
        btn[i]->load_image_ft(":/icon/menu-button.png", ":/icon/menu-button-press.png");
        btn[i]->setGeometry(BTN_LEFT_X, BTN_LEFT_Y + ((BTN_OFF_Y + BTN_H) * i),
                            BTN_W, BTN_H);

        btn[i]->set_text(btn_name);


        btn[i + 5] = new Icon_btn(this);
        btn[i + 5]->setObjectName(main_page_string[i]);
        btn[i + 5]->enable_scale = 0;
        btn_name = main_page_string[i + 5];
        btn[i + 5]->load_image_ft(":/icon/menu-button.png", ":/icon/menu-button-press.png");
        btn[i + 5]->setGeometry(BTN_RIGHT_X + BTN_W + BTN_OFF_X,
                                BTN_RIGHT_Y + ((BTN_OFF_Y + BTN_H) * i),
                                BTN_W, BTN_H);

        btn[i + 5]->set_text(btn_name);
    }
    m_load_background_img = 0;
}

void Main_Page::LoadBackground()
{
    backimg.load(":/icon/main_page_bg.png");

    QPalette palette;
    palette.setColor(QPalette::Background, Qt::black);
    m_load_background_img = 1;
}


void Main_Page::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
    btn[i]->ft_light_enable();
}

void Main_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont font("DroidSans", 22);
    painter.setFont(font);
    painter.drawPixmap(0, 0, backimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
}
