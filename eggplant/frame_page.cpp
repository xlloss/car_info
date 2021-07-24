#include "frame_page.h"
#include "ui_frame_page.h"
#include <QDebug>
#include <QPainter>

Frame_Page::Frame_Page(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame_Page)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->close();
    this->setGeometry(0, 55, 800, 480 - 55);
    this->setWindowState(Qt::WindowNoState);
}

Frame_Page::~Frame_Page()
{
    delete ui;
}

void Frame_Page::Load_Background(QString image)
{
}

void Frame_Page::Enable_Icon_Light(int i)
{
    qDebug("%s i=%d", __func__, i);
}

void Frame_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
}
