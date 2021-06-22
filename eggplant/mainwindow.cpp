#include "mainwindow.h"
#include "ui_mainwindow.h"

#define START_PAGE_X 500
#define START_PAGE_Y 100
#define START_PAGE_W 800
#define START_PAGE_H 200

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString icon_name[ICON_NUM][2] = {{APPLE_1, APPLE_2},
                                      {BANANA_1, BANANA_2}
                                     };

    int i;

    for (i = 0; i < ICON_NUM; i++) {
        icon_id[i] = new Icon_btn(this);
        icon_id[i]->load_image_ft(icon_name[i][0], icon_name[i][1]);
        icon_id[i]->setGeometry(ICON_ID_X + (ICON_W * i + ICON_ID_OFF),
                                ICON_ID_Y, ICON_W, ICON_H);
        icon_id[i]->show();
    }

    this->setGeometry(START_PAGE_X, START_PAGE_Y, START_PAGE_W, START_PAGE_H);
    test_cnt1 = 0;

    page_ctl = new Page_Ctl();
    //page_ctl->home_page->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_test_id1_btn_clicked()
{
    test_cnt1++;
    if (test_cnt1 % 2) {
        icon_id[0]->ft_light_enable();
        icon_id[0]->update();
    } else {
        icon_id[0]->ft_dark_enable();
        icon_id[0]->update();
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
