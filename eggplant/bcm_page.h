#ifndef BCM_PAGE_H
#define BCM_PAGE_H

#include <QMainWindow>
#include <QPushButton>
#include <QImage>
#include "frame_page.h"
#include "icon_btn.h"


#define FUNC_BTN_X 70
#define FUNC_BTN_Y 50
#define FUNC_BTN_W 200
#define FUNC_BTN_H 120
#define FUNC_BTN_OFF_X 210
#define FUNC_BTN_OFF_Y 130

#define BACK_BTN_X 500
#define BACK_BTN_Y 50
#define BACK_BTN_W 200
#define BACK_BTN_H 260


class Bcm_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Bcm_Page(QWidget *parent = nullptr);

    Icon_btn *func_btn[4];
    Icon_btn *back_btn;
    QPixmap back_img;
    QPixmap frame_img;

private slots:
    void Enable_Icon_Light(int i);

signals:

protected:
    void paintEvent(QPaintEvent *);
};

#endif
