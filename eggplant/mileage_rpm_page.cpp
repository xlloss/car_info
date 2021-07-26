#include "home_page.h"
#include <QPainter>
#include <mileage_rpm_page.h>
#include "coordinate.h"
#include "string/string.h"

QString str_img_id[RPM_STR_IMG_COL_NUM] = {
    {ID_STR_IMG_0},
    {ID_STR_IMG_1},
    {ID_STR_IMG_2},
    {ID_STR_IMG_3},
    {ID_STR_IMG_4},
    {ID_STR_IMG_5},
    {ID_STR_IMG_6},
    {ID_STR_IMG_7},
};

int str_img_xy[RPM_STR_IMG_COL_NUM][RPM_STR_IMG_ROW_NUM] = {
    {RPM_STR_IMG_ID_0_X, RPM_STR_IMG_ID_0_Y, },    //ID_STR_IMG_0
    {RPM_STR_IMG_ID_1_X, RPM_STR_IMG_ID_1_Y, },    //ID_STR_IMG_1
    {RPM_STR_IMG_ID_2_X, RPM_STR_IMG_ID_2_Y, },    //ID_STR_IMG_2
    {RPM_STR_IMG_ID_3_X, RPM_STR_IMG_ID_3_Y, },    //ID_STR_IMG_3

    {RPM_STR_IMG_ID_4_X, RPM_STR_IMG_ID_4_Y,},    //ID_STR_IMG_4
    {RPM_STR_IMG_ID_5_X, RPM_STR_IMG_ID_5_Y,},    //ID_STR_IMG_5
    {RPM_STR_IMG_ID_6_X, RPM_STR_IMG_ID_6_Y,},    //ID_STR_IMG_6
    {RPM_STR_IMG_ID_7_X, RPM_STR_IMG_ID_7_Y,},    //ID_STR_IMG_7
};

int btn_img_xy[RPM_BTN_NUM * 2] = {
    RPM_BTN_IMG_ID0_X, RPM_BTN_IMG_ID0_Y,
    RPM_BTN_IMG_ID1_X, RPM_BTN_IMG_ID1_Y,
    RPM_BTN_IMG_ID2_X, RPM_BTN_IMG_ID2_Y,
    RPM_BTN_IMG_ID3_X, RPM_BTN_IMG_ID3_Y,
};

int show_text_xy[RPM_STR_NUM * 2] = {
    RPM_TEX_ID0_X, RPM_TEX_ID0_Y,
    RPM_TEX_ID1_X, RPM_TEX_ID1_Y,
    RPM_TEX_ID2_X, RPM_TEX_ID2_Y,

    RPM_TEX_ID3_X, RPM_TEX_ID3_Y,
    RPM_TEX_ID4_X, RPM_TEX_ID4_Y,
    RPM_TEX_ID5_X, RPM_TEX_ID5_Y,
};



QString show_text_default[RPM_STR_NUM] = {
    RPM_DAMPLE_STR_ID0,
    RPM_DAMPLE_STR_ID1,
    RPM_DAMPLE_STR_ID2,
    RPM_DAMPLE_STR_ID3,
    RPM_DAMPLE_STR_ID4,
    RPM_DAMPLE_STR_ID5,
};

QString rpm_page_btn_objname[RPM_BTN_NUM] = {
    RPM_SAMPLE_BTN_OBJ_ID0
    RPM_SAMPLE_BTN_OBJ_ID1
    RPM_SAMPLE_BTN_OBJ_ID2
    RPM_SAMPLE_BTN_OBJ_ID3
};

Mile_Page::Mile_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(RPM_OBJNAME);
    int i, j;

    bgimg.load(RPM_BG_IMG);
    backimg2.load(RPM_FM_IMG);

    for (i = 0; i < RPM_STR_IMG_COL_NUM; i++)
        str_img[i].load(str_img_id[i]);


    j = 0;
    for (i = 0; i < RPM_BTN_NUM; i++) {
        btn[i] = new Icon_btn(this);
        btn[i]->setObjectName(rpm_page_btn_objname[i]);
        btn[i]->enable_scale = 0;

        btn[i]->load_image_ft(":/icon/rpm_btn.png", ":/icon/rpm_btn_press.png");
        btn[i]->setGeometry(btn_img_xy[j], btn_img_xy[j + 1], 120, 40);

        btn[i]->set_text(RPM_PAGE_BTN_NAME);
        btn[i]->m_set_text_y = RPM_FONT_SIZE;

        show_string[i] = new Show_text(this);
        show_string[i]->set_text(show_text_default[i]);
        show_string[i]->setGeometry(show_text_xy[j], show_text_xy[j + 1], 200, 70);
        show_string[i]->show();
        j = j + 2;
    }
}

void Mile_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int i;

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawPixmap(8, 30, backimg2, MILERPM_BACKIMAGE_X, MILERPM_BACKIMAGE_Y,
                       MILERPM_BACKIMAGE_W, MILERPM_BACKIMAGE_H);

    for (i = 0; i < RPM_STR_IMG_NUM; i++)
        painter.drawImage(str_img_xy[i][0], str_img_xy[i][1], str_img[i]);
}

void Mile_Page::GetMcuData()
{
    qDebug("Mile_Page:%s\n", __func__);
}
