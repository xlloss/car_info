#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QMainWindow>
#include <QImage>
#include "frame_page.h"
#include <QPushButton>

class Main_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Main_Page(QWidget *parent = nullptr);

    QPushButton *btn[10];

signals:

};

#endif
