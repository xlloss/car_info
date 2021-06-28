#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setGeometry(500, 100, 800, 480);
    backimg.load(":/icon/background.png");

    bar_frame = new BarFrame (this);
    bar_frame->setGeometry(BAR_FRAME_X, BAR_FRAME_Y, BAR_FRAME_W, BAR_FRAME_H);
    bar_frame->show();

    page_ctl = new Page_Ctl();
    page_ctl->home_page->show();
    test_cnt1 = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, backimg);
}
