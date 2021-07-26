#include "eai_page.h"
#include <QPainter>
#include "coordinate.h"
#include "string/string.h"

QString master_text[EAI_MAS_TEX_NUM] = {EAI_MAS_TEX_ID0, EAI_MAS_TEX_ID1, EAI_MAS_TEX_ID2};

QString sub_text[EAI_MAS_TEX_NUM][EAI_SUB_TEX_NUM] = {
    {EAI_SUB_STR_ID00, EAI_SUB_STR_ID01,
     EAI_SUB_STR_ID02, EAI_SUB_STR_ID03, EAI_SUB_STR_ID04, EAI_SUB_STR_ID05, EAI_SUB_STR_ID06},

    {EAI_SUB_STR_ID10, EAI_SUB_STR_ID11,
     EAI_SUB_STR_ID12, EAI_SUB_STR_ID13, EAI_SUB_STR_ID14, EAI_SUB_STR_ID15, EAI_SUB_STR_ID16},

    {EAI_SUB_STR_ID20, EAI_SUB_STR_ID21,
     EAI_SUB_STR_ID22, EAI_SUB_STR_ID23, EAI_SUB_STR_ID24, EAI_SUB_STR_ID25, EAI_SUB_STR_ID26},
};

QString sub_text_msg[EAI_MAS_TEX_NUM][EAI_SUB_TEX_NUM] = {
    {EAI_SUB_SAMPLE_STR_ID00, EAI_SUB_STR_ID01,
     EAI_SUB_SAMPLE_STR_ID02, EAI_SUB_STR_ID03,
     EAI_SUB_SAMPLE_STR_ID04, EAI_SUB_SAMPLE_STR_ID05, EAI_SUB_SAMPLE_STR_ID06},

    {EAI_SUB_SAMPLE_STR_ID10, EAI_SUB_STR_ID11,
     EAI_SUB_SAMPLE_STR_ID12, EAI_SUB_STR_ID13,
     EAI_SUB_SAMPLE_STR_ID14, EAI_SUB_SAMPLE_STR_ID15, EAI_SUB_SAMPLE_STR_ID16},

    {EAI_SUB_SAMPLE_STR_ID20, EAI_SUB_STR_ID21,
     EAI_SUB_SAMPLE_STR_ID22, EAI_SUB_STR_ID23,
     EAI_SUB_SAMPLE_STR_ID24, EAI_SUB_SAMPLE_STR_ID25, EAI_SUB_SAMPLE_STR_ID26},
};

int master_text_xy[] = {
  EAI_MASTER_TEXT_X,  EAI_MASTER_TEXT_Y,
  EAI_MASTER_TEXT_X + (EAI_MASTER_TEXT_W + 70) * 1, EAI_MASTER_TEXT_Y,
  EAI_MASTER_TEXT_X + (EAI_MASTER_TEXT_W + 50) * 2, EAI_MASTER_TEXT_Y,
};

int sub_text_xy[] = {
  EAI_SUB_TEXT_X,  EAI_SUB_TEXT_Y,
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 1),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 2),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 3),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 4),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 5),
  EAI_SUB_TEXT_X , EAI_SUB_TEXT_Y + (EAI_SUB_TEXT_GAP  * 6),
};

int sub_text_x_offset[EAI_MAS_TEX_NUM] = {0,  260, 510};
int sub_text_msg_off[EAI_MAS_TEX_NUM] = {150, 400, 670};

EleAccInfo_Page::EleAccInfo_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName(EAI_OBJNAME);
    int i, j, k;

    backimg.load(EAI_BG_IMG);
    tableimg.load(EAI_FM_IMG);

    /* master title */
    j = 0;
    for (i = 0; i < EAI_MAS_TEX_NUM; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(master_text[i]);
        show_master_item[i]->setGeometry(master_text_xy[j], master_text_xy[j + 1],
                EAI_MASTER_TEXT_W, EAI_MASTER_TEXT_H);
        show_master_item[i]->m_font_size = RAI_FONT_SIZE;
        j = j + 2;
    }

    /* sub title */
    for (i = 0; i < EAI_MAS_TEX_NUM; i++) {
        j = 0;
        for (k = 0; k < EAI_SUB_TEX_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(sub_text_xy[j] + sub_text_x_offset[i], sub_text_xy[j + 1],
                    EAI_SUB_TEXT_W, EAI_SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = RAI_FONT2_SIZE;
            show_sub_item[i][k]->show();
//            j = j + 2;
//        }
//    }
//
//    /* content value */
//    for (i = 0; i < EAI_MAS_TEX_NUM; i++) {
//        j = 0;
//        for (k = 0; k < EAI_SUB_TEX_NUM; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(sub_text_xy[j] + sub_text_msg_off[i], sub_text_xy[j + 1],
                    EAI_SUB_TEXT_W, EAI_SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = RAI_FONT2_SIZE;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void EleAccInfo_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    painter.drawPixmap(8, 50, tableimg, 0, 0, 788, 360);
}

void EleAccInfo_Page::GetMcuData()
{
    qDebug("EleAccInfo_Page:%s\n", __func__);
}
