#include "frame_page.h"
#include "ui_frame_page.h"

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
