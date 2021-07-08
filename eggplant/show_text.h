#ifndef SHOW_TEST_H
#define SHOW_TEST_H

#include <QWidget>
#include <QImage>

namespace Ui {
class Show_text;
}

class Show_text : public QWidget
{
    Q_OBJECT

public:
    explicit Show_text(QWidget *parent = 0);
    ~Show_text();
    QPixmap bg_img;
    QString m_show_text;
    QFont font;
    QColor text_color;
    int m_text_x;
    int m_text_y;
    void set_text(QString set_text);
    void load_image_bg(QString bg_name);

protected:
    void paintEvent(QPaintEvent *);

private slots:

};

#endif
