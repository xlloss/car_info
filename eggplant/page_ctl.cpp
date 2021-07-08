#include "page_ctl.h"

Page_Ctl::Page_Ctl()
{
    home_page = new Home_Page();
    //home_page->show();
    framepage = home_page;
    framepage->show();

    main_page = new Main_Page();
    mile_page = new Mile_Page();
    car_inout_page = new CarInOut_Page();
    time_adjust_page = new TimeAdjust_Page();
    volume_adjust_page = new ScreenVolumeAdjust_Page();
}
