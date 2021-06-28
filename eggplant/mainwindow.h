#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QPaintEvent>

#include "icon_btn.h"
#include "page_ctl.h"
#include "barframe.h"


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
    QPixmap backimg;

    BarFrame *bar_frame;
    Page_Ctl *page_ctl;
    int test_cnt1;

protected:
    void paintEvent(QPaintEvent *);

private slots:

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
