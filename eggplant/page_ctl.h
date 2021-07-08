#ifndef PAGE_CTL_H
#define PAGE_CTL_H

#include <QMainWindow>
#include "home_page.h"
#include "main_page.h"
#include "mileage_rpm_page.h"
#include "frame_page.h"
#include "car_inout_temp_page.h"
#include "time_adjust_page.h"
#include "screen_volume_adjust_page.h"
#include "eai_page.h"
#include "control_msg1_page.h"
class Page_Ctl
{

public:
    explicit Page_Ctl();

    Home_Page *home_page;
    Main_Page *main_page;
    Mile_Page *mile_page;
    CarInOut_Page *car_inout_page;
    TimeAdjust_Page *time_adjust_page;
    ScreenVolumeAdjust_Page *volume_adjust_page;
    EleAccInfo_Page *eai_page;
    ControlMsg1_Page *control_msg1_page;
    class Frame_Page *framepage;;

signals:

};

#endif
