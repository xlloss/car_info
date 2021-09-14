#include "frame_page.h"
#include "ui_frame_page.h"
#include <QDebug>
#include <QPainter>
#include "coordinate.h"

Frame_Page::Frame_Page(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame_Page)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->close();
    this->setGeometry(GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                      GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
    this->setWindowState(Qt::WindowNoState);
}

Frame_Page::~Frame_Page()
{
    delete ui;
}

int Frame_Page::do_checksum(uint8_t *data, uint16_t data_len, uint8_t check)
{
    int ret = 0;
    uint32_t len = 0;

    do {
        ret = ret ^ data[len];
        len++;
    } while (len < data_len);

    return ret;
}

void Frame_Page::Load_Background(QString image)
{
    qDebug("%s\n", __func__);
}

void Frame_Page::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
}
