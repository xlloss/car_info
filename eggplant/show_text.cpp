#include "icon_btn.h"
#include <QPainter>
#include <qdebug.h>
#include "show_text.h"

Show_text::Show_text(QWidget *parent) :
    QWidget(parent)
{
    m_text_x = 0;
    m_text_y = 0;
    font.setBold(0);
    font.setPointSize(30);
    font.setFamily("DroidSans");
    text_color = Qt::white;
}

Show_text::~Show_text()
{
}

void Show_text::load_image_bg(QString bg_name)
{
    QPalette palette;
    bg_img.load(bg_name);

    palette.setBrush(QPalette::Background, bg_img);
    this->setPalette(palette);
    //this->setGeometry(0, 0, bg_img.width(), bg_img.height());
}

void Show_text::set_text(QString text)
{
    m_show_text = text;
    m_text_x = 0;
    m_text_y = this->height() / 2 + 10;
}

void Show_text::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont usefont(font.family(), font.pointSize(), font.weight(), font.bold());

    if (!m_show_text.isNull()) {
        painter.setFont(usefont);
        painter.setPen(Qt::white);
        painter.drawText(m_text_x, m_text_y, m_show_text);
        //painter.drawText(m_text_x, m_text_y, "法課王");
    }
}
