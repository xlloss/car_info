#include "time_adjust_page.h"
#include <QPainter>
#include "string/string.h"

QString time_text[TIME_ADJ_TEX_TITLE_NUM] = {
    TIME_ADJ_TEX_TIME,
    TIME_ADJ_TEX_WEEK,
    TIME_ADJ_TEX_DATE,
    TIME_ADJ_TEX_YEAR,
    TIME_ADJ_TEX_MONTH,
    TIME_ADJ_TEX_DAY
};

QString time_text_child[TIME_ADJ_CHILD_TEX_TIME_NUM] =
{   TIME_ADJ_CHILD_TEX_TIME_SAMPLE,
    TIME_ADJ_CHILD_TEX_WEEK_SAMPLE,
    TIME_ADJ_CHILD_TEX_YEAR_SAMPLE,
    TIME_ADJ_CHILD_TEX_MONTH_SAMPLE,
    TIME_ADJ_CHILD_TEX_DAY_SAMPLE
};

int time_text_xy[TIME_ADJ_TEX_TITLE_NUM * 2] = {
    TIME_ADJ_TEX_TITLE_ID0_X, TIME_ADJ_TEX_TITLE_ID0_Y,
    TIME_ADJ_TEX_TITLE_ID1_X, TIME_ADJ_TEX_TITLE_ID1_Y,
    TIME_ADJ_TEX_TITLE_ID2_X, TIME_ADJ_TEX_TITLE_ID2_Y,
};

int time_text2_xy[TIME_ADJ_TEX_TITLE_NUM] = {
    TIME_ADJ_TEX_TITLE_ID3_X, TIME_ADJ_TEX_TITLE_ID3_Y,
    TIME_ADJ_TEX_TITLE_ID4_X, TIME_ADJ_TEX_TITLE_ID4_Y,
    TIME_ADJ_TEX_TITLE_ID5_X, TIME_ADJ_TEX_TITLE_ID5_Y,
};

int time_text_child_xy[TIME_ADJ_CHILD_TEX_TIME_NUM * 2] = {
    TIME_ADJ_CHILD_TEX_ID0_X, TIME_ADJ_CHILD_TEX_ID0_Y,
    TIME_ADJ_CHILD_TEX_ID1_X, TIME_ADJ_CHILD_TEX_ID1_Y,
    TIME_ADJ_CHILD_TEX_ID2_X, TIME_ADJ_CHILD_TEX_ID2_Y,
    TIME_ADJ_CHILD_TEX_ID3_X, TIME_ADJ_CHILD_TEX_ID3_Y,
    TIME_ADJ_CHILD_TEX_ID4_X, TIME_ADJ_CHILD_TEX_ID4_Y,
};

TimeAdjust_Page::TimeAdjust_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(TIME_ADJ_OBJNAME);
    int i, j;

    bgimg.load(TIME_ADJ_BG_IMG);

    j = 0;
    for (i = 0; i < TIME_ADJ_TEX_TITLE_NUM / 2; i++) {
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(time_text[i]);
        show_item[i]->setGeometry(time_text_xy[j], time_text_xy[j + 1], 150, 70);
        show_item[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 3; i < TIME_ADJ_TEX_TITLE_NUM / 2; i++) {
        show_item[i] = new Show_text(this);
        show_item[i]->set_text(time_text[i]);
        show_item[i]->setGeometry(time_text2_xy[j], time_text2_xy[j + 1], 150, 50);
        show_item[i]->show();
        j = j + 2;
    }

    j = 0;
    for (i = 0; i < TIME_ADJ_CHILD_TEX_TIME_NUM; i++) {
        show_item_child[i] = new Show_text(this);
        show_item_child[i]->set_text(time_text_child[i]);
        show_item_child[i]->text_color.setRgb(0, 245, 245);
        show_item_child[i]->setGeometry(time_text_child_xy[j], time_text_child_xy[j + 1], 120, 70);
        show_item_child[i]->show();
        j = j + 2;
    }
}

void TimeAdjust_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg,
                       GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
}

void TimeAdjust_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    qDebug("TimeAdjust_Page:%s\n", __func__);
}
