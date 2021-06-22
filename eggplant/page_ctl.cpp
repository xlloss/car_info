#include "page_ctl.h"

Page_Ctl::Page_Ctl()
{
    home_page = new Home_Page();
    home_page->show();

    main_page = new Main_Page();
    main_page->show();

}
