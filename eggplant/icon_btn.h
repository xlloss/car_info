#ifndef SPEED_METER_H
#define SPEED_METER_H

#include <QWidget>
#include <QImage>

namespace Ui {
class Icon_btn;
}


#define ICON_SCALE_SIZ_W 50
#define ICON_SCALE_SIZ_H 60

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
