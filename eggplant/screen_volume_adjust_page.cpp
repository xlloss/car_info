#include "screen_volume_adjust_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

int volume_text_xy[VOL_TEX_NUM] = {VOL_TEX_X, VOL_TEX_Y};
int volume_value_xy[VOL_TEX_NUM] = {VOL_TEX_VAL_X, VOL_TEX_VAL_Y};

ScreenVolumeAdjust_Page::ScreenVolumeAdjust_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(VOL_ADJ_OBJNAME);

    backimg.load(VOL_ADJ_BG_IMG);

    show_volume_text = new Show_text(this);
    show_volume_text->set_text(VOLUME_TEXT);
    show_volume_text->setGeometry(volume_text_xy[0], volume_text_xy[1], 150, 70);
    show_volume_text->show();

    show_volume_val = new Show_text(this);
    show_volume_val->set_text(VOLUME_TEXT_SAMPLE_VAL);
    show_volume_val->setGeometry(volume_value_xy[0], volume_value_xy[1], 150, 70);
    show_volume_val->show();
}


void ScreenVolumeAdjust_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int i;

    painter.drawPixmap(0, 0, backimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.setBrush(QBrush(QColor(0, 245, 245)));

    for (i = 0; i < VOL_LV_NUM; i++)
        painter.drawRect(VOL_BAR_X + (VOL_BAR_W + VOL_BAR_GAP) * i , 105, VOL_BAR_W, VOL_BAR_H);
}
