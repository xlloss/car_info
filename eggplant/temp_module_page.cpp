#include "temp_module_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

QString tempmodule_sub_text[TEMP_SUB_ITEM_COL_NUM][TEMP_SUB_ITEM_ROW_NUM] = {
    {TEMP_SUB_TEX_ID00, TEMP_SUB_TEX_ID01, TEMP_SUB_TEX_ID02, TEMP_SUB_TEX_ID03,
     TEMP_SUB_TEX_ID00, TEMP_SUB_TEX_ID01, TEMP_SUB_TEX_ID02, TEMP_SUB_TEX_ID03},

    {TEMP_SUB_TEX_ID10, TEMP_SUB_TEX_ID11, TEMP_SUB_TEX_ID12, TEMP_SUB_TEX_ID13,
     TEMP_SUB_TEX_ID10, TEMP_SUB_TEX_ID11, TEMP_SUB_TEX_ID12, TEMP_SUB_TEX_ID13},
};


QString tempmodule_sub_text_msg[TEMP_SUB_ITEM_COL_NUM][TEMP_SUB_ITEM_ROW_NUM] = {
    {TEMP_MSG_TEX_ID00, TEMP_MSG_TEX_ID01, TEMP_MSG_TEX_ID02, TEMP_MSG_TEX_ID03,
     TEMP_MSG_TEX_ID04, TEMP_MSG_TEX_ID05, TEMP_MSG_TEX_ID06, TEMP_MSG_TEX_ID07,
    },

    {TEMP_MSG_TEX_ID10, TEMP_MSG_TEX_ID11, TEMP_MSG_TEX_ID12, TEMP_MSG_TEX_ID13,
     TEMP_MSG_TEX_ID14, TEMP_MSG_TEX_ID15, TEMP_MSG_TEX_ID16, TEMP_MSG_TEX_ID17,
    },
};

int tempmodule_sub_text_xy[] = {
  TEMP_SUB_TEX_X,  TEMP_SUB_TEX_Y,
  TEMP_SUB_TEX_X , TEMP_SUB_TEX_Y + (TEMP_SUB_TEX_GAP  * 1),
  TEMP_SUB_TEX_X , TEMP_SUB_TEX_Y + (TEMP_SUB_TEX_GAP  * 2),
  TEMP_SUB_TEX_X , TEMP_SUB_TEX_Y + (TEMP_SUB_TEX_GAP  * 3),
  TEMP_SUB_TEX_X , TEMP_SUB_TEX_Y + (TEMP_SUB_TEX_GAP  * 4),
  TEMP_SUB_TEX_X , TEMP_SUB_TEX_Y + (TEMP_SUB_TEX_GAP  * 5),
  TEMP_SUB_TEX_X , TEMP_SUB_TEX_Y + (TEMP_SUB_TEX_GAP  * 6),
  TEMP_SUB_TEX_X , TEMP_SUB_TEX_Y + (TEMP_SUB_TEX_GAP  * 7),
};

int tempmodule_sub_text_x_offset[2] = {0,  400};
int tempmodule_sub_text_msg_off[2] = {210, 600};


TempModule_Page::TempModule_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(TEMP_MOD_OBJNAME);
    int i, j, k;

    bgimg.load(TEMP_MOD_BG_IMG);
    tableimg.load(TEMP_MOD_FM_IMG);

    for (i = 0; i < TEMP_MAS_ITEM_NUM; i++) {
        j = 0;
        for (k = 0; k < TEMP_SUB_ITEM_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(tempmodule_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(tempmodule_sub_text_xy[j] + tempmodule_sub_text_x_offset[i],
                                             tempmodule_sub_text_xy[j + 1], TEMP_SUB_TEX_W, TEMP_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = TEMP_FONT_SIZE;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    for (i = 0; i < TEMP_SUB_ITEM_COL_NUM; i++) {
        j = 0;
        for (k = 0; k < TEMP_SUB_ITEM_ROW_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(tempmodule_sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(tempmodule_sub_text_xy[j] + tempmodule_sub_text_msg_off[i],
                                             tempmodule_sub_text_xy[j + 1], TEMP_SUB_TEX_W, TEMP_SUB_TEX_H);
            show_sub_item[i][k]->m_font_size = TEMP_FONT_SIZE;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void TempModule_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawPixmap(5, 20, tableimg, 0, 0, 788, 380);
}

void TempModule_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    qDebug("TempModule_Page:%s\n", __func__);
}
