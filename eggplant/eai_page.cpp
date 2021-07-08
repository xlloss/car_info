#include "eai_page.h"
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


QString master_text[3] = {"電轉向控制器", "DCDC變換器", "電機空壓機控制器"};

QString sub_text[3][7] = {
                            {"電機轉速:", "控制器母線:" , "控制器電流:" , "故障編碼:"  , "控制器溫度:", "電動油磊狀態:",  "預充電狀態:"},
                            {"輸入電壓:", "輸入電流:"   , "輸出電流:"  , "控制器溫度:" , "故障編碼:" , "DCDC狀態:"   ,  "預充電狀態:"},
                            {"電機轉速:", "控制器母線:" , "控制器電流:" , "故障編碼:"  , "控制器溫度:", "電動油磊狀態:",  "預充電狀態:"},
						};

QString sub_text_msg[3][7] = {
                            {"000rpm", "000V" , "000A" , "000°C" , "00",  "停止",  "未完成"},
                            {"000V"  , "000A" , "000A" , "000°C" , "00" , "停止",  "未完成"},
                            {"000rpm", "000V" , "000A" , "000°C" , "00",  "停止",  "未完成"},
                        };


int master_text_xy[] = {
  MASTER_TEXT_X,  MASTER_TEXT_Y,
  MASTER_TEXT_X + (MASTER_TEXT_W + 70) * 1, MASTER_TEXT_Y,
  MASTER_TEXT_X + (MASTER_TEXT_W + 50) * 2, MASTER_TEXT_Y,
};

int sub_text_xy[] = {
  SUB_TEXT_X,  SUB_TEXT_Y,
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 1),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 2),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 3),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 4),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 5),
  SUB_TEXT_X , SUB_TEXT_Y + (SUB_TEXT_GAP  * 6),
};

int sub_text_x_offset[3] = {0,  260, 510};
int sub_text_msg_off[3] = {150, 400, 670};

EleAccInfo_Page::EleAccInfo_Page(QWidget *parent) : Frame_Page(parent)
{
    this->setObjectName("EleAccInfo_Page");
    int i, j, k;

    backimg.load(":/icon/rpm_page_bg.png");
    tableimg.load(":/icon/electrical_accessories_information.png");

    j = 0;
    for (i = 0; i < 3; i++) {
        show_master_item[i] = new Show_text(this);
        show_master_item[i]->set_text(master_text[i]);
        show_master_item[i]->setGeometry(master_text_xy[j], master_text_xy[j + 1], MASTER_TEXT_W, MASTER_TEXT_H);
        show_master_item[i]->show();
        j = j + 2;
    }

    for (i = 0; i < 3; i++) {
        j = 0;
        for (k = 0; k < 7; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(sub_text[i][k]);
            show_sub_item[i][k]->setGeometry(sub_text_xy[j] + sub_text_x_offset[i], sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    for (i = 0; i < 3; i++) {
        j = 0;
        for (k = 0; k < 7; k++) {
            show_sub_item[i][k] = new Show_text(this);
            show_sub_item[i][k]->set_text(sub_text_msg[i][k]);
            show_sub_item[i][k]->setGeometry(sub_text_xy[j] + sub_text_msg_off[i], sub_text_xy[j + 1], SUB_TEXT_W, SUB_TEXT_H);
            show_sub_item[i][k]->font.setPixelSize(20);
            show_sub_item[i][k]->show();
            j = j + 2;
        }
    }

    this->setWindowState(Qt::WindowActive);
}

void EleAccInfo_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    painter.drawPixmap(8, 30, tableimg, 0, 0, 788, 360);
}
