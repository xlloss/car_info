#ifndef PAGE_CTL_H
#define PAGE_CTL_H

#include <QMainWindow>
#include "home_page.h"
#include "main_page.h"
class Page_Ctl
{

public:
    explicit Page_Ctl();

    Home_Page *home_page;
    Main_Page *main_page;
signals:

};

#endif
