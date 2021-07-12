#ifndef PAGE_CTL_H
#define PAGE_CTL_H

#include <QMainWindow>
#include <QWidget>"
#include "home_page.h"
#include "main_page.h"
#include "mileage_rpm_page.h"
#include "frame_page.h"
#include "car_inout_temp_page.h"
#include "time_adjust_page.h"
#include "screen_volume_adjust_page.h"
#include "eai_page.h"
#include "control_msg1_page.h"
#include "control_msg2_page.h"
#include "battery_temp_info_page.h"
#include "battery_volt_info_page.h"
#include "temp_module_page.h"
#include "slave_sat_out_msg_page.h"
#include "slave_sat_in_msg_page.h"
#include "sw_version_page.h"
#include "slave_sat_msg_page.h"
#include "bcm_page.h"
#include "tires_pressure_show_page.h"

class Page_Ctl
{

public:
    explicit Page_Ctl(QWidget *parent);

    Home_Page *home_page;
    Main_Page *main_page;
    Mile_Page *mile_page;
    CarInOut_Page *car_inout_page;
    TimeAdjust_Page *time_adjust_page;
    ScreenVolumeAdjust_Page *volume_adjust_page;
    EleAccInfo_Page *eai_page;
    ControlMsg1_Page *control_msg1_page;
    ControlMsg2_Page *control_msg2_page;
    BatTempInfo_Page *bat_temp_info_page;
    BatVoltInfo_Page *bat_volt_info_page;
    TempModule_Page *temp_module_page;
    SatOutMsg_Page *sat_outmsg_page;
    SatInMsg_Page *sat_inmsg_page;
    SwVersion_Page *sw_version_page;
    SlaveSatMsg_Page *slave_sat_msg_page;
    Bcm_Page *bcm_page;
    TiresPressShow_Page *tires_press_show_page;

    class Frame_Page *framepage;

signals:

};

#endif
