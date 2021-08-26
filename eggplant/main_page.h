#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QMainWindow>
#include <QImage>
#include <QPushButton>
#include "frame_page.h"
#include "icon_btn.h"
#include "coordinate.h"


#define MAIN_PAGE_BACKGROUND ":/icon/main_page_bg.png"
#define MAIN_PAGE_BUS ":/icon/bus-bg.png"
#define MAIN_PAG_FONT_TYPE "DroidSans"
#define MAIN_PAG_FONT_SIZE 22

class Main_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Main_Page(QWidget *parent = nullptr);

    Icon_btn *btn[10];
    void LoadBackground();
    int m_load_background_img;
    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;

private slots:
    void Enable_Icon_Light(int i);
    void Disable_Icon_Light(int i);

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
