#include "icon_btn.h"
#include <QPainter>
#include <qdebug.h>


Icon_btn::Icon_btn(QWidget *parent) :
    QWidget(parent)
{
}

Icon_btn::~Icon_btn()
{
}

void Icon_btn::load_image_bg(QString bg_name)
{
    QPalette palette;
    bg_img.load(bg_name);
    width = bg_img.width();
    height = bg_img.height();

    palette.setBrush(QPalette::Background, bg_img);
    this->setPalette(palette);
    this->setGeometry(0, 0, bg_img.width(), bg_img.height());
}

void Icon_btn::load_image_ft(QString ft_dark_name, QString ft_light_name)
{
    if (ft_img_dark.load(ft_dark_name) == false) {
        qDebug("ft_dark load fail");
        return;
    }

    if (ft_img_light.load(ft_light_name) == false) {
        qDebug("ft_light load fail");
        return;
    }

    ft_img_dark = ft_img_dark.scaled(ICON_SCALE_SIZ_W, ICON_SCALE_SIZ_H);
    ft_img_light = ft_img_light.scaled(ICON_SCALE_SIZ_W, ICON_SCALE_SIZ_H);
    ft_img = ft_img_dark;
}

void Icon_btn::ft_dark_enable()
{
    ft_img = ft_img_dark;
}

void Icon_btn::ft_light_enable()
{
    ft_img = ft_img_light;
}

void Icon_btn::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //QTransform trans;
    //painter.drawPixmap(0, 0, bg_img);

    qDebug("paintEvent");
    //trans.translate(bg_img.width()/2, bg_img.height()/2);
    //trans.rotate(rot_cnt);
    //trans.translate(-(bg_img.width()/2), -(bg_img.width()/2));
    //painter.setTransform(trans);
    painter.drawImage(0, 0, ft_img);
}
