#include "page_ctl.h"


Page_Ctl::Page_Ctl(QWidget *parent)
{
    home_page = new Home_Page(parent);
    main_page = new Main_Page(parent);
    mile_page = new Mile_Page(parent);
    car_inout_page = new CarInOut_Page(parent);
    time_adjust_page = new TimeAdjust_Page(parent);
    volume_adjust_page = new ScreenVolumeAdjust_Page(parent);
    eai_page = new EleAccInfo_Page(parent);
    control_msg1_page = new ControlMsg1_Page(parent);
    control_msg2_page = new ControlMsg2_Page(parent);
    bat_temp_info_page = new BatTempInfo_Page(parent);
    bat_volt_info_page = new BatVoltInfo_Page(parent);
    temp_module_page = new TempModule_Page(parent);
    sat_outmsg_page = new SatOutMsg_Page(parent);
    sat_inmsg_page = new SatInMsg_Page(parent);
    sw_version_page = new SwVersion_Page(parent);
    slave_sat_msg_page = new SlaveSatMsg_Page(parent);
    bcm_page = new Bcm_Page(parent);
    tires_press_show_page = new TiresPressShow_Page(parent);
}
