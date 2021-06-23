#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(500, 100, 800, 200);

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

void MainWindow::on_test_id1_btn_clicked()
{
    test_cnt1++;
    if (test_cnt1 % 2) {
        bar_frame->icon_id[0]->ft_light_enable();
        bar_frame->icon_id[0]->update();
    } else {
        bar_frame->icon_id[0]->ft_dark_enable();
        bar_frame->icon_id[0]->update();
    }
}

void MainWindow::on_home_page_clicked()
{
    page_ctl->home_page->setWindowState(Qt::WindowActive);
    page_ctl->main_page->setWindowState(Qt::WindowNoState);
}

void MainWindow::on_main_page_clicked()
{
    page_ctl->main_page->setWindowState(Qt::WindowActive);
    page_ctl->home_page->setWindowState(Qt::WindowNoState);
}
