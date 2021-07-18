#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "test_frame.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Test_Frame *testframe;


    ui->setupUi(this);
    this->setObjectName("Mainwindow");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setGeometry(0, 60, 800, 415);
    //this->hide();
    backimg.load(":/icon/background.png");

    bar_frame = new BarFrame (this);
    bar_frame->show();

    page_ctl = new Page_Ctl(this);
    page_ctl->home_page->show();
    //page_ctl->main_page->show();
    //page_ctl->mile_page->show();
    //page_ctl->car_inout_page->show();
    //page_ctl->time_adjust_page->show();
    //page_ctl->volume_adjust_page->show();
    //page_ctl->eai_page->show();
    //page_ctl->control_msg1_page->show();
    //page_ctl->control_msg2_page->show();
    //page_ctl->bat_temp_info_page->show();
    //page_ctl->bat_volt_info_page->show();
    //page_ctl->temp_module_page->show();
    //page_ctl->sat_outmsg_page->show();
    //page_ctl->sat_inmsg_page->show();
    //page_ctl->sw_version_page->show();
    //page_ctl->slave_sat_msg_page->show();
    //page_ctl->bcm_page->show();
    //page_ctl->tires_press_show_page->show();

    //testframe = new Test_Frame();
    //testframe->setGeometry(600, 0, 300, 300);
    //testframe->show();

    cmd_get = new Cmd_Receive(this);

    cmd_get->Register((class Frame_Page *)bar_frame);
    cmd_get->Register((class Frame_Page *)page_ctl->home_page);
    cmd_get->Register((class Frame_Page *)page_ctl->main_page);
    cmd_get->Register((class Frame_Page *)page_ctl->mile_page);
    cmd_get->Register((class Frame_Page *)page_ctl->car_inout_page);
    cmd_get->Register((class Frame_Page *)page_ctl->time_adjust_page);
    cmd_get->Register((class Frame_Page *)page_ctl->volume_adjust_page);
    cmd_get->Register((class Frame_Page *)page_ctl->eai_page);
    cmd_get->Register((class Frame_Page *)page_ctl->control_msg1_page);
    cmd_get->Register((class Frame_Page *)page_ctl->control_msg2_page);
    cmd_get->Register((class Frame_Page *)page_ctl->bat_temp_info_page);
    cmd_get->Register((class Frame_Page *)page_ctl->bat_volt_info_page);
    cmd_get->Register((class Frame_Page *)page_ctl->temp_module_page);
    cmd_get->Register((class Frame_Page *)page_ctl->sat_outmsg_page);
    cmd_get->Register((class Frame_Page *)page_ctl->sat_inmsg_page);
    cmd_get->Register((class Frame_Page *)page_ctl->sw_version_page);
    cmd_get->Register((class Frame_Page *)page_ctl->slave_sat_msg_page);
    cmd_get->Register((class Frame_Page *)page_ctl->bcm_page);
    cmd_get->Register((class Frame_Page *)page_ctl->tires_press_show_page);

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
}
