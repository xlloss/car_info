#ifndef SPEED_METER_H
#define SPEED_METER_H

#include <QWidget>
#include <QImage>
#include "coordinate.h"

namespace Ui {
class Icon_btn;
}


class Icon_btn : public QWidget
{
    Q_OBJECT

public:
    explicit Icon_btn(QWidget *parent = 0);
    ~Icon_btn();
    QPixmap bg_img;
    QImage ft_img_light;
    QImage ft_img_dark;
    QImage ft_img;
    int l_scale_sz_w;
    int l_scale_sz_h;
    int d_scale_sz_w;
    int d_scale_sz_h;
    int enable_scale;
    QString m_set_text;
    QFont font;
    int m_set_text_x;
    int m_set_text_y;
    QRect rectangle;
    QRect boundingRect;
    QColor m_texcolor;

    void set_text(QString set_text);

    int width;
    int height;
    void load_image_bg(QString bg_name);
    void load_image_ft(QString ft_dark, QString ft_light);
    void ft_dark_enable();
    void ft_light_enable();

protected:
    void paintEvent(QPaintEvent *);

private slots:

private:
    Ui::Icon_btn *ui;
};

#endif // WIDGET_H
