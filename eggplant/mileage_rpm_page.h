#ifndef MILEAGE_RPM_PAGE_H
#define MILEAGE_RPM_PAGE_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include "frame_page.h"


class Mile_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit Mile_Page(QWidget *parent = nullptr);
    QLabel *lable_title[2];
    QLabel *lable_subitem[6];
protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif
