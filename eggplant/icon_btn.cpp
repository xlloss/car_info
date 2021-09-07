#include "icon_btn.h"
#include <QPainter>
#include <qdebug.h>

Icon_btn::Icon_btn(QWidget *parent) :
    QWidget(parent)
{
    l_scale_sz_w = CARGEAR_ICON_SCALE_SIZ_W;
    l_scale_sz_h = CARGEAR_ICON_SCALE_SIZ_H;
    d_scale_sz_w = CARGEAR_ICON_SCALE_SIZ_W;
    d_scale_sz_h = CARGEAR_ICON_SCALE_SIZ_H;
    m_set_text_x = 0;
    m_set_text_x = 0;
    enable_scale = 1;
    font.setBold(0);
    font.setPointSize(30);
    font.setFamily("DroidSans");
    m_set_text_x = 30;
    m_set_text_y = 40;
    m_texcolor = Qt::white;
}

Icon_btn::~Icon_btn()
{
}

void Icon_btn::load_image_bg(QString bg_name)
{
    qDebug("Icon_btn::load_image_bg");

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

    if (enable_scale) {
        ft_img_dark = ft_img_dark.scaled(d_scale_sz_w, d_scale_sz_h);
        ft_img_light = ft_img_light.scaled(l_scale_sz_w, l_scale_sz_h);
    }

    ft_img = ft_img_dark;
}

void Icon_btn::set_text(QString text)
{
    m_set_text = text;
}

void Icon_btn::ft_dark_enable()
{
    if (ft_img == ft_img_dark)
        return;

    ft_img = ft_img_dark;
}

void Icon_btn::ft_light_enable()
{
    if (ft_img == ft_img_light)
        return;

    ft_img = ft_img_light;
}

void Icon_btn::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont usefont(font.family(), font.pointSize(), font.weight(), font.bold());

    painter.drawImage(0, 0, ft_img);

    if (!m_set_text.isNull()) {
        painter.setFont(usefont);
        painter.setPen(m_texcolor);
        painter.drawText(m_set_text_x, m_set_text_y, m_set_text);
    }
}
