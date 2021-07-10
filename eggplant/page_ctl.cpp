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
    eai_page = new EleAccInfo_Page();
    control_msg1_page = new ControlMsg1_Page();
    control_msg2_page = new ControlMsg2_Page();
    bat_temp_info_page = new BatTempInfo_Page();
    bat_volt_info_page = new BatVoltInfo_Page();
    temp_module_page = new TempModule_Page();
    sat_outmsg_page = new SatOutMsg_Page();
    sat_inmsg_page = new SatInMsg_Page();
    sw_version_page = new SwVersion_Page();
    slave_sat_msg_page = new SlaveSatMsg_Page();
    bcm_page = new Bcm_Page();
    tires_press_show_page = new TiresPressShow_Page();
}
