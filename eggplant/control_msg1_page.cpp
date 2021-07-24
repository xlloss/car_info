#include "control_msg1_page.h"
#include <QPainter>

#define MASTER_TEXT_X 50
#define MASTER_TEXT_Y 40
#define MASTER_TEXT_W 200
#define MASTER_TEXT_H 50
#define MASTER_TEXT_GAP 50

#define SUB_TEXT_X 30
#define SUB_TEXT_Y 85
#define SUB_TEXT_W 200
#define SUB_TEXT_H 45
#define SUB_TEXT_GAP 45


QString control1_master_text[2] = {"系統工作狀態", "系統信息狀態"};

QString control1_sub_text[3][6] = {
                            {"電控:"    , "電機:"     , "轉向:"      , "氣磊:"      , "DCDC:"        , ""           },
                            {"電控心跳:", "電機心跳:"  , "電池心跳:"   , "轉向心跳:" , "加速踏板開度:"  , "制動踏板開度:"},
                            {"氣磊心跳:", "DCDC心跳:"  , "絕緣B心跳:" , "絕緣S心跳:"  , ""             , ""},
						};

QString control1_sub_text_msg[3][6] = {
                            {"正常", "準備好" , "停止" , "停止" , "停止",  ""},
                            {"000"  , "000" , "000" , "000"  , "000%",  "000%"},
                            {"000%" , "000" , "000" , "000"  , "",  ""},
                        };


int control1_master_text_xy[] = {
  MASTER_TEXT_X,  MASTER_TEXT_Y,
  MASTER_TEXT_X + (MASTER_TEXT_W + 200), MASTER_TEXT_Y,
};

int control1_sub_text_xy[] = {
  SUB_TEXT_X,  SUB_TEXT_Y,
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 4),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 5),
};

int control1_sub_text_x_offset[3] = {0,  250, 510};
int control1_sub_text_msg_off[3] = {150, 400, 670};

ControlMsg1_Page::ControlMsg1_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("ControlMsg1_Page");
    int i, j, k;

    backimg.load(":/icon/rpm_page_bg.png");
    tableimg.load(":/icon/control_msg1.png");

    j = 0;
    for (i = 0; i < 2; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(control1_master_text[i]);
        show_master_item[i]->setGeometry(control1_master_text_xy[j], control1_master_text_xy[j + 1],
                MASTER_TEXT_W, MASTER_TEXT_H);

        show_master_item[i]->show();
        j = j + 2;
    }

    for (i = 0; i < 3; i++) {
        j = 0;
        for (k = 0; k < 6; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(control1_sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(control1_sub_text_xy[j] + control1_sub_text_x_offset[i],
                                             control1_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = 20;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    for (i = 0; i < 3; i++) {
        j = 0;
        for (k = 0; k < 6; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(control1_sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(control1_sub_text_xy[j] + control1_sub_text_msg_off[i],
                                             control1_sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->m_font_size = 20;
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }
}

void ControlMsg1_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(8, 30, tableimg, 0, 0, 788, 360);
}
