#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test_frame.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Test_Frame *testframe;

    ui->setupUi(this);
    this->setObjectName("Mainwindow");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setGeometry(500, 100 + 65, 800, 415);
    this->hide();
    backimg.load(":/icon/background.png");

    bar_frame = new BarFrame (this);
    bar_frame->show();

    page_ctl = new Page_Ctl();
    page_ctl->home_page->show();
    test_cnt1 = 0;


    testframe = new Test_Frame();
    testframe->Register((class Frame_Page *)bar_frame);
    testframe->Register((class Frame_Page *)page_ctl->home_page);
    testframe->Register((class Frame_Page *)page_ctl->main_page);
    testframe->Register((class Frame_Page *)page_ctl->mile_page);
    testframe->Register((class Frame_Page *)page_ctl->car_inout_page);
    testframe->Register((class Frame_Page *)page_ctl->time_adjust_page);
    testframe->Register((class Frame_Page *)page_ctl->volume_adjust_page);
    testframe->Register((class Frame_Page *)page_ctl->eai_page);
    testframe->Register((class Frame_Page *)page_ctl->control_msg1_page);
    testframe->Register((class Frame_Page *)page_ctl->control_msg2_page);
    testframe->Register((class Frame_Page *)page_ctl->bat_info_page);
    testframe->show();

    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, backimg, 0, 55, 800, 480);
    //painter.drawPixmap(0, 0, backimg);
}
