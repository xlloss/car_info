#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "icon_btn.h"
#include "page_ctl.h"

#define ICON_NUM 2

#define APPLE_1 ":/icon/apple-1.png"
#define APPLE_2 ":/icon/apple-2.png"

#define BANANA_1 ":/icon/banana-1.png"
#define BANANA_2 ":/icon/banana-2.png"

#define ICON_W ICON_SCALE_SIZ_W
#define ICON_H ICON_SCALE_SIZ_H

#define ICON_ID_X 10
#define ICON_ID_Y 0
#define ICON_ID_OFF 10


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
namespace name {
    class Frame_Page;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Icon_btn *icon_id[ICON_NUM];

    Page_Ctl *page_ctl;
    int test_cnt1;

private slots:
    void on_test_id1_btn_clicked();


    void on_home_page_clicked();

    void on_main_page_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
