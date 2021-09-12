#include "fw_update_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

#define ITEM_TEXT "系統更新"
#define ITEM_CHILD_TEXT1 "更新設備"
#define ITEM_CHILD_TEXT2 "更新狀態"

FwUpdate_Page::FwUpdate_Page(QWidget *parent) : Frame_Page(parent)
{
    setObjectName(FWV_UPDATE_OBJNAME);
    bgimg.load(FWV_UPDATE_BG_IMG);

    show_item = new Show_text(this);
    show_item->set_text(ITEM_TEXT);
    show_item->setGeometry(25, 30, 100, 50);
    show_item->show();

    show_item_child1 = new Show_text(this);
    show_item_child1->set_text(ITEM_TEXT);
    show_item_child1->setGeometry(170, 100, 100, 50);
    show_item_child1->show();

    show_item_child1 = new Show_text(this);
    show_item_child1->set_text(ITEM_TEXT);
    show_item_child1->setGeometry(170, 200, 100, 50);
    show_item_child1->show();

}

void FwUpdate_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg,
                       GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
}


void FwUpdate_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    qDebug("FwUpdate_Page:%s\n", __func__);
}
