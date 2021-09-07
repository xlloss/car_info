#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coordinate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setObjectName(MAINWINDOW_OBJNAME);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setGeometry(GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                      GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);

    backimg.load(MAINWINDOW_BG_IMG);

    bar_frame = new BarFrame (this);
    page_ctl = new Page_Ctl(this);
    cmd_get = new Cmd_Receive(this);

    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->home_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->main_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->mile_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->car_inout_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->system_setup_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->volume_adjust_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->eai_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->control_msg1_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->control_msg2_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->bat_temp_info_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->bat_volt_info_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->temp_module_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->sat_outmsg_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->sat_inmsg_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->sw_version_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->slave_sat_msg_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->bcm_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(page_ctl->tires_press_show_page));
    cmd_get->Register(dynamic_cast<Frame_Page *>(bar_frame));

    page_ctl->home_page->setWindowState(Qt::WindowActive);

    bar_frame->show();
    page_ctl->home_page->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, backimg,
                       GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
}
