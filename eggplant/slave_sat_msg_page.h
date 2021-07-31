#ifndef SLAVE_SAT_MAIN_PAGE_H
#define SLAVE_SAT_MAIN_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include "icon_btn.h"
#include <QPushButton>


class SlaveSatMsg_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit SlaveSatMsg_Page(QWidget *parent = nullptr);

    Icon_btn *sat_msg_btn[8];
    Icon_btn *back_level_btn;
    Icon_btn *back_main_btn;
    QPixmap backimg;
    QPixmap frameimg;
    QString sat_msg_str[10];
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;
private slots:
    void Enable_Icon_Light(int i);

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
