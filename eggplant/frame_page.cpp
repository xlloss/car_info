#include "frame_page.h"
#include "ui_frame_page.h"
#include <QDebug>

Frame_Page::Frame_Page(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame_Page)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setGeometry(500, 100 + 65, 800, 415);
}

Frame_Page::~Frame_Page()
{
    delete ui;
}

void Frame_Page::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
}
