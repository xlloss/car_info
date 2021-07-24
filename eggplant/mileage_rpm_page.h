#ifndef MILEAGE_RPM_PAGE_H
#define MILEAGE_RPM_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "show_text.h"

#define ID_L_0 ":/icon/rpm_page_str0.png"
#define ID_L_1 ":/icon/rpm_page_str1.png"
#define ID_L_2 ":/icon/rpm_page_str2.png"
#define ID_L_3 ":/icon/rpm_page_str3.png"
#define ID_R_0 ":/icon/rpm_page_str4.png"
#define ID_R_1 ":/icon/rpm_page_str5.png"
#define ID_R_2 ":/icon/rpm_page_str6.png"
#define ID_R_3 ":/icon/rpm_page_str7.png"

#define ID_STR_IMG_0 ID_L_0
#define ID_STR_IMG_1 ID_L_1
#define ID_STR_IMG_2 ID_L_2
#define ID_STR_IMG_3 ID_L_3
#define ID_STR_IMG_4 ID_R_0
#define ID_STR_IMG_5 ID_R_1
#define ID_STR_IMG_6 ID_R_2
#define ID_STR_IMG_7 ID_R_3

class Mile_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Mile_Page(QWidget *parent = nullptr);
    QPixmap backimg;
    QPixmap backimg2;
    QImage str_img[8];
    Icon_btn *btn[4];
    Show_text *show_string[6];

protected:
    void paintEvent(QPaintEvent *);

};

#endif
