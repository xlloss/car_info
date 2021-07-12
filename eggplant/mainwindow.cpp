#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test_frame.h"
#include "home_page.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Test_Frame *testframe;
    Home_Page *home_page;

    ui->setupUi(this);
    this->setObjectName("Mainwindow");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setGeometry(0, 100 + 65, 800, 415);
    //this->hide();
    backimg.load(":/icon/background.png");

    bar_frame = new BarFrame (this);
    bar_frame->show();

    //home_page = new Home_Page();
    //home_page->setGeometry(0, 170, 800, 480);
    //home_page->show();

    page_ctl = new Page_Ctl(this);
    //page_ctl->home_page->show();
    //page_ctl->main_page->show();
    page_ctl-> mile_page->show();

    testframe = new Test_Frame();
    //testframe->Register((class Frame_Page *)bar_frame);
    //testframe->Register((class Frame_Page *)page_ctl->home_page);
    //testframe->Register((class Frame_Page *)page_ctl->main_page);
    //testframe->Register((class Frame_Page *)page_ctl->mile_page);
    //testframe->Register((class Frame_Page *)page_ctl->car_inout_page);
    //testframe->Register((class Frame_Page *)page_ctl->time_adjust_page);
    //testframe->Register((class Frame_Page *)page_ctl->volume_adjust_page);
    //testframe->Register((class Frame_Page *)page_ctl->eai_page);
    //testframe->Register((class Frame_Page *)page_ctl->control_msg1_page);
    //testframe->Register((class Frame_Page *)page_ctl->control_msg2_page);
    //testframe->Register((class Frame_Page *)page_ctl->bat_temp_info_page);
    //testframe->Register((class Frame_Page *)page_ctl->bat_volt_info_page);
    //testframe->Register((class Frame_Page *)page_ctl->temp_module_page);
    //testframe->Register((class Frame_Page *)page_ctl->sat_outmsg_page);
    //testframe->Register((class Frame_Page *)page_ctl->sat_inmsg_page);
    //testframe->Register((class Frame_Page *)page_ctl->sw_version_page);
    //testframe->Register((class Frame_Page *)page_ctl->slave_sat_msg_page);
    //testframe->Register((class Frame_Page *)page_ctl->bcm_page);
    //testframe->Register((class Frame_Page *)page_ctl->tires_press_show_page);
    testframe->setGeometry(600, 0, 300, 300);
    testframe->show();

    //this->close();
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
