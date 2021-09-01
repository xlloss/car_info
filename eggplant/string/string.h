#ifndef STRING_H
#define STRING_H

#include <QMainWindow>

/******************************************
 *  car gear page
 ******************************************/


/******************************************
 *  home page
 ******************************************/
#define HOME_ITEM_TEX_DATE_TIME "日期時間:"
#define HOME_ITEM_TEX_SLOPE "坡度:"
#define HOME_ITEM_TEX_GEAR_SAT "檔位狀態:"
#define HOME_ITEM_TEX_BATT_SAT "電池狀態:"
#define HOME_ITEM_TEX_IMM_PWR_CONSUMP "瞬間耗電:"
#define HOME_ITEM_TEX_TOTAL_MILEAGE "里程總數:"
#define HOME_ITEM_TEX_PRE_MILEAGE "當次里程:"
#define HOME_ITEM_TEX_AVAILABLE_MILE "剩餘可行里程數:"
#define HOME_ITEM_TEX_MOTO_TEMP "馬達溫度:"
#define HOME_ITEM_TEX_BATT_PACK "電池PACK:"
#define HOME_ITEM_TEX_SMALL_VOLAT "小電電壓:"
#define HOME_ITEM_TEX_TOTAL_VOLT "總電壓:"
#define HOME_ITEM_TEX_TOTAL_CURREN "總電流:"
#define HOME_ITEM_TEX_BATT_SOC "電池 SOC:"
#define HOME_ITEM_TEX_FRONT_AIR_PRESSURE "前儲氣筒氣壓值:"
#define HOME_ITEM_TEX_BEHIND_AIR_PRESSURE "後儲氣筒氣壓值:"
#define HOME_ITEM_TEX_ALARM_MSG "警報訊息"

/******************************************
 *  main page
 ******************************************/
#define MAIN_STR_NUM 10

#define MAIN_STR_ID0 "里程與轉速訊息"
#define MAIN_STR_ID1 "車內外及艙溫"
#define MAIN_STR_ID2 "時間調整"
#define MAIN_STR_ID3 "揚聲器設定"
#define MAIN_STR_ID4 "電輔件訊息"
#define MAIN_STR_ID5 "控制器狀態訊息"
#define MAIN_STR_ID6 "電池狀態訊息"
#define MAIN_STR_ID7 "總線系統狀態"
#define MAIN_STR_ID8 "輪胎壓力指示"
#define MAIN_STR_ID9 "返回主界面"

/******************************************
 *  rpm page
 ******************************************/
#define RPM_PAGE_BTN_NAME "歸零"
#define RPM_DATA_DEF_STR_ID0 "012345678Km"
#define RPM_DATA_DEF_STR_ID1 "0000.2Km"
#define RPM_DATA_DEF_STR_ID2 "0204.9Km"
#define RPM_DATA_DEF_STR_ID3 "000002040Kr"
#define RPM_DATA_DEF_STR_ID4 "000000002h"
#define RPM_DATA_DEF_STR_ID5 "100000002h"

#define RPM_SAMPLE_BTN_OBJ_ID0 "set_zero_0"
#define RPM_SAMPLE_BTN_OBJ_ID1 "set_zero_0"
#define RPM_SAMPLE_BTN_OBJ_ID2 "set_zero_1"
#define RPM_SAMPLE_BTN_OBJ_ID3 "set_zero_2"


/******************************************
 *  can inout page
 ******************************************/
#define CAR_INOUT_OBJ "CarInOut_Page"
#define CAR_INOUT_TEX_ID0 "車內溫度:"
#define CAR_INOUT_TEX_ID1 "車外溫度:"
#define CAR_INOUT_TEX_ID2 "設備倉溫:"
#define CAR_INOUT_TEX_SAMPLE "000°C"


/******************************************
 *  time adj page
 ******************************************/

#define TIME_ADJ_TEX_TIME "時間:"
#define TIME_ADJ_TEX_WEEK "星期:"
#define TIME_ADJ_TEX_DATE "日期:"
#define TIME_ADJ_TEX_YEAR "年"
#define TIME_ADJ_TEX_MONTH "月"
#define TIME_ADJ_TEX_DAY "日"

#define TIME_ADJ_CHILD_TEX_TIME_SAMPLE "13:00:00"
#define TIME_ADJ_CHILD_TEX_WEEK_SAMPLE "星期三"
#define TIME_ADJ_CHILD_TEX_YEAR_SAMPLE "2021"
#define TIME_ADJ_CHILD_TEX_MONTH_SAMPLE "07"
#define TIME_ADJ_CHILD_TEX_DAY_SAMPLE "13"


/******************************************
 *  volume adj page
 ******************************************/
#define VOLUME_TEXT "螢幕音量:"
#define VOLUME_TEXT_SAMPLE_VAL "15"

/******************************************
 *  EAI page
 ******************************************/

#define EAI_MAS_TEX_ID0 "電轉向控制器"
#define EAI_MAS_TEX_ID1 "DCDC變換器"
#define EAI_MAS_TEX_ID2 "電機空壓機控制器"

#define EAI_SUB_STR_ID00 "電機轉速:"
#define EAI_SUB_STR_ID01 "控制器母線:"
#define EAI_SUB_STR_ID02 "控制器電流:"
#define EAI_SUB_STR_ID03 "故障編碼:"
#define EAI_SUB_STR_ID04 "控制器溫度:"
#define EAI_SUB_STR_ID05 "電動油磊狀態:"
#define EAI_SUB_STR_ID06 "預充電狀態:"

#define EAI_SUB_STR_ID10 "輸入電壓:"
#define EAI_SUB_STR_ID11 "輸入電流:"
#define EAI_SUB_STR_ID12 "輸出電流:"
#define EAI_SUB_STR_ID13 "控制器溫度:"
#define EAI_SUB_STR_ID14 "故障編碼:"
#define EAI_SUB_STR_ID15 "DCDC狀態:"
#define EAI_SUB_STR_ID16 "預充電狀態:"


#define EAI_SUB_STR_ID20 "電機轉速:"
#define EAI_SUB_STR_ID21 "控制器母線:"
#define EAI_SUB_STR_ID22 "控制器電流:"
#define EAI_SUB_STR_ID23 "故障編碼:"
#define EAI_SUB_STR_ID24 "控制器溫度:"
#define EAI_SUB_STR_ID25 "電動油磊狀態:"
#define EAI_SUB_STR_ID26 "電動油磊狀態:"

#define EAI_SUB_SAMPLE_STR_ID00 "000rpm"
#define EAI_SUB_SAMPLE_STR_ID01 "000V"
#define EAI_SUB_SAMPLE_STR_ID02 "000A"
#define EAI_SUB_SAMPLE_STR_ID03 "000°C"
#define EAI_SUB_SAMPLE_STR_ID04 "00"
#define EAI_SUB_SAMPLE_STR_ID05 "停止"
#define EAI_SUB_SAMPLE_STR_ID06 "未完成"

#define EAI_SUB_SAMPLE_STR_ID10 "000V"
#define EAI_SUB_SAMPLE_STR_ID11 "000A"
#define EAI_SUB_SAMPLE_STR_ID12 "000A"
#define EAI_SUB_SAMPLE_STR_ID13 "000°C"
#define EAI_SUB_SAMPLE_STR_ID14 "00"
#define EAI_SUB_SAMPLE_STR_ID15 "停止"
#define EAI_SUB_SAMPLE_STR_ID16 "未完成"

#define EAI_SUB_SAMPLE_STR_ID20 "000rpm"
#define EAI_SUB_SAMPLE_STR_ID21 "000V"
#define EAI_SUB_SAMPLE_STR_ID22 "000A"
#define EAI_SUB_SAMPLE_STR_ID23 "000°C"
#define EAI_SUB_SAMPLE_STR_ID24 "00"
#define EAI_SUB_SAMPLE_STR_ID25 "停止"
#define EAI_SUB_SAMPLE_STR_ID26 "未完成"



/******************************************
 *  control msg 1 page
 ******************************************/

#define CONTROL1_MAS_TEX_ID0 "系統工作狀態"
#define CONTROL1_MAS_TEX_ID1 "系統信息狀態"

#define CONTROL1_SUB_TEX_ID00 "電控:"
#define CONTROL1_SUB_TEX_ID01 "電機:"
#define CONTROL1_SUB_TEX_ID02 "轉向:"
#define CONTROL1_SUB_TEX_ID03 "氣磊:"
#define CONTROL1_SUB_TEX_ID04 "DCDC:"
#define CONTROL1_SUB_TEX_ID05 ""

#define CONTROL1_SUB_TEX_ID10 "電控心跳:"
#define CONTROL1_SUB_TEX_ID11 "電機心跳:"
#define CONTROL1_SUB_TEX_ID12 "電池心跳:"
#define CONTROL1_SUB_TEX_ID13 "轉向心跳:"
#define CONTROL1_SUB_TEX_ID14 "加速踏板開度:"
#define CONTROL1_SUB_TEX_ID15 "制動踏板開度:"

#define CONTROL1_SUB_TEX_ID20 "氣磊心跳:"
#define CONTROL1_SUB_TEX_ID21 "DCDC心跳:"
#define CONTROL1_SUB_TEX_ID22 "絕緣B心跳:"
#define CONTROL1_SUB_TEX_ID23 "絕緣S心跳:"
#define CONTROL1_SUB_TEX_ID24 ""
#define CONTROL1_SUB_TEX_ID25 ""


#define CONTROL1_SUB_MSG_ID00 "電控:"
#define CONTROL1_SUB_MSG_ID01 "電機:"
#define CONTROL1_SUB_MSG_ID02 "轉向:"
#define CONTROL1_SUB_MSG_ID03 "氣磊:"
#define CONTROL1_SUB_MSG_ID04 "DCDC:"
#define CONTROL1_SUB_MSG_ID05 ""

#define CONTROL1_SUB_MSG_ID10 "000"
#define CONTROL1_SUB_MSG_ID11 "000"
#define CONTROL1_SUB_MSG_ID12 "000"
#define CONTROL1_SUB_MSG_ID13 "000"
#define CONTROL1_SUB_MSG_ID14 "000%"
#define CONTROL1_SUB_MSG_ID15 "000%"

#define CONTROL1_SUB_MSG_ID20 "000%"
#define CONTROL1_SUB_MSG_ID21 "000"
#define CONTROL1_SUB_MSG_ID22 "000"
#define CONTROL1_SUB_MSG_ID23 "000"
#define CONTROL1_SUB_MSG_ID24 ""
#define CONTROL1_SUB_MSG_ID25 ""



/******************************************
 *  control msg 2 page
 ******************************************/

#define CONTROL2_MAS_TEX_ID0 "高壓配電工作狀態"

#define CONTROL2_SUB_TEX_ID00 "K1預充電:"
#define CONTROL2_SUB_TEX_ID01 "K2主電機:"
#define CONTROL2_SUB_TEX_ID02 "K3電附件:"
#define CONTROL2_SUB_TEX_ID03 "K4電空調:"
#define CONTROL2_SUB_TEX_ID04 "K5電除霜:"
#define CONTROL2_SUB_TEX_ID05 "K6電池充電:"
#define CONTROL2_SUB_TEX_ID06 "K6電池組內部:"

#define CONTROL2_SUB_TEX_ID10 "S1高壓急斷:"
#define CONTROL2_SUB_TEX_ID11 "B正極絕緣電阻:"
#define CONTROL2_SUB_TEX_ID12 "B負極絕緣電阻:"
#define CONTROL2_SUB_TEX_ID13 "S正極絕緣電阻:"
#define CONTROL2_SUB_TEX_ID14 "S負極絕緣電阻:"
#define CONTROL2_SUB_TEX_ID15 "制動踏板開度:"
#define CONTROL2_SUB_TEX_ID16 ""

#define CONTROL2_SUB_MSG_ID00 "斷開:"
#define CONTROL2_SUB_MSG_ID01 "斷開:"
#define CONTROL2_SUB_MSG_ID02 "斷開:"
#define CONTROL2_SUB_MSG_ID03 "斷開:"
#define CONTROL2_SUB_MSG_ID04 "斷開"
#define CONTROL2_SUB_MSG_ID05 "斷開"
#define CONTROL2_SUB_MSG_ID06 "斷開"

#define CONTROL2_SUB_MSG_ID10 "斷開"
#define CONTROL2_SUB_MSG_ID11 "00000KΩ"
#define CONTROL2_SUB_MSG_ID12 "00000KΩ"
#define CONTROL2_SUB_MSG_ID13 "00000KΩ"
#define CONTROL2_SUB_MSG_ID14 "00000KΩ%"
#define CONTROL2_SUB_MSG_ID15 ""
#define CONTROL2_SUB_MSG_ID16 ""


/******************************************
 *  battery temp page
 ******************************************/

#define BATT_MAS_TEX_ID0 "電池溫度資訊"

#define BATT_SUB_TEX_ID00 "電池第一高溫度:"
#define BATT_SUB_TEX_ID01 "電池第二高溫度:"
#define BATT_SUB_TEX_ID02 "電池第三高溫度:"
#define BATT_SUB_TEX_ID03 "電池第四高溫度:"

#define BATT_SUB_TEX_ID10 "電池第一低溫度:"
#define BATT_SUB_TEX_ID11 "電池第二低溫度:"
#define BATT_SUB_TEX_ID12 "電池第三低溫度:"
#define BATT_SUB_TEX_ID13 "電池第四低溫度:"

#define BATT_SUB_TEX_ID20 "位置(箱):"
#define BATT_SUB_TEX_ID21 "位置(箱):"
#define BATT_SUB_TEX_ID22 "位置(箱):"
#define BATT_SUB_TEX_ID23 "位置(箱):"

#define BATT_SUB_TEX_ID30 "位置(箱):"
#define BATT_SUB_TEX_ID31 "位置(箱):"
#define BATT_SUB_TEX_ID32 "位置(箱):"
#define BATT_SUB_TEX_ID33 "位置(箱):"


#define BATT_SUB_TEX_ID40 "位置(號):"
#define BATT_SUB_TEX_ID41 "位置(號):"
#define BATT_SUB_TEX_ID42 "位置(號):"
#define BATT_SUB_TEX_ID43 "位置(號):"

#define BATT_SUB_TEX_ID50 "位置(號):"
#define BATT_SUB_TEX_ID51 "位置(號):"
#define BATT_SUB_TEX_ID52 "位置(號):"
#define BATT_SUB_TEX_ID53 "位置(號):"


#define BATT_MSG_TEX_ID00 "021°C"
#define BATT_MSG_TEX_ID01 "021°C"
#define BATT_MSG_TEX_ID02 "021°C"
#define BATT_MSG_TEX_ID03 "021°C"
#define BATT_MSG_TEX_ID10 "021°C"
#define BATT_MSG_TEX_ID11 "021°C"
#define BATT_MSG_TEX_ID12 "021°C"
#define BATT_MSG_TEX_ID13 "021°C"
#define BATT_MSG_TEX_ID20 "001"
#define BATT_MSG_TEX_ID21 "001"
#define BATT_MSG_TEX_ID22 "001"
#define BATT_MSG_TEX_ID23 "001"
#define BATT_MSG_TEX_ID30 "001"
#define BATT_MSG_TEX_ID31 "001"
#define BATT_MSG_TEX_ID32 "001"
#define BATT_MSG_TEX_ID33 "001"
#define BATT_MSG_TEX_ID40 "001"
#define BATT_MSG_TEX_ID41 "001"
#define BATT_MSG_TEX_ID42 "001"
#define BATT_MSG_TEX_ID43 "001"
#define BATT_MSG_TEX_ID50 "001"
#define BATT_MSG_TEX_ID51 "001"
#define BATT_MSG_TEX_ID52 "001"
#define BATT_MSG_TEX_ID53 "001"



/******************************************
 *  battery volt page
 ******************************************/

#define BATVOL_MAS_TEX_ID0 "電池電壓資訊"
#define BATVOL_SUB_TEX_ID00 "單體第一高電壓:"
#define BATVOL_SUB_TEX_ID01 "單體第一高電壓:"
#define BATVOL_SUB_TEX_ID02 "單體第一高電壓:"
#define BATVOL_SUB_TEX_ID03 "單體第一高電壓:"

#define BATVOL_SUB_TEX_ID10 "單體第一低電壓:"
#define BATVOL_SUB_TEX_ID11 "單體第一低電壓:"
#define BATVOL_SUB_TEX_ID12 "單體第一低電壓:"
#define BATVOL_SUB_TEX_ID13 "單體第一低電壓:"

#define BATVOL_SUB_TEX_ID20 "位置(箱):"
#define BATVOL_SUB_TEX_ID21 "位置(箱):"
#define BATVOL_SUB_TEX_ID22 "位置(箱):"
#define BATVOL_SUB_TEX_ID23 "位置(箱):"
#define BATVOL_SUB_TEX_ID30 "位置(箱):"
#define BATVOL_SUB_TEX_ID31 "位置(箱):"
#define BATVOL_SUB_TEX_ID32 "位置(箱):"
#define BATVOL_SUB_TEX_ID33 "位置(箱):"
#define BATVOL_SUB_TEX_ID40 "位置(號):"
#define BATVOL_SUB_TEX_ID41 "位置(號):"
#define BATVOL_SUB_TEX_ID42 "位置(號):"
#define BATVOL_SUB_TEX_ID43 "位置(號):"
#define BATVOL_SUB_TEX_ID50 "位置(號):"
#define BATVOL_SUB_TEX_ID51 "位置(號):"
#define BATVOL_SUB_TEX_ID52 "位置(號):"
#define BATVOL_SUB_TEX_ID53 "位置(號):"


#define BATVOL_MSG_TEX_ID00 "003.32V"
#define BATVOL_MSG_TEX_ID01 "003.32V"
#define BATVOL_MSG_TEX_ID02 "003.32V"
#define BATVOL_MSG_TEX_ID03 "003.32V"
#define BATVOL_MSG_TEX_ID10 "003.32V"
#define BATVOL_MSG_TEX_ID11 "003.32V"
#define BATVOL_MSG_TEX_ID12 "003.32V"
#define BATVOL_MSG_TEX_ID13 "003.32V"
#define BATVOL_MSG_TEX_ID20 "001"
#define BATVOL_MSG_TEX_ID21 "001"
#define BATVOL_MSG_TEX_ID22 "001"
#define BATVOL_MSG_TEX_ID23 "001"
#define BATVOL_MSG_TEX_ID30 "001"
#define BATVOL_MSG_TEX_ID31 "001"
#define BATVOL_MSG_TEX_ID32 "001"
#define BATVOL_MSG_TEX_ID33 "001"
#define BATVOL_MSG_TEX_ID40 "001"
#define BATVOL_MSG_TEX_ID41 "001"
#define BATVOL_MSG_TEX_ID42 "001"
#define BATVOL_MSG_TEX_ID43 "001"
#define BATVOL_MSG_TEX_ID50 "001"
#define BATVOL_MSG_TEX_ID51 "001"
#define BATVOL_MSG_TEX_ID52 "001"
#define BATVOL_MSG_TEX_ID53 "001"





/******************************************
 *  temp module info page
 ******************************************/
#define TEMP_SUB_TEX_ID00 "主站模塊"
#define TEMP_SUB_TEX_ID01 "從站模塊1"
#define TEMP_SUB_TEX_ID02 "從站模塊3:"
#define TEMP_SUB_TEX_ID03 "從站模塊5:"
#define TEMP_SUB_TEX_ID04 "從站模塊7"
#define TEMP_SUB_TEX_ID05 "胎壓模塊1"
#define TEMP_SUB_TEX_ID06 "胎壓模塊2"
#define TEMP_SUB_TEX_ID07 "胎壓模塊3"

#define TEMP_SUB_TEX_ID10 "從站模塊0"
#define TEMP_SUB_TEX_ID11 "從站模塊2"
#define TEMP_SUB_TEX_ID12 "從站模塊4:"
#define TEMP_SUB_TEX_ID13 "從站模塊6:"
#define TEMP_SUB_TEX_ID14 ""
#define TEMP_SUB_TEX_ID15 ""
#define TEMP_SUB_TEX_ID16 ""
#define TEMP_SUB_TEX_ID17 ""


#define TEMP_MSG_TEX_ID00 "00°C"
#define TEMP_MSG_TEX_ID01 "00°C"
#define TEMP_MSG_TEX_ID02 "00°C"
#define TEMP_MSG_TEX_ID03 "00°C"
#define TEMP_MSG_TEX_ID04 "00°C"
#define TEMP_MSG_TEX_ID05 "在線"
#define TEMP_MSG_TEX_ID06 "在線"
#define TEMP_MSG_TEX_ID07 "在線"

#define TEMP_MSG_TEX_ID10 "00°C"
#define TEMP_MSG_TEX_ID11 "00°C"
#define TEMP_MSG_TEX_ID12 "00°C"
#define TEMP_MSG_TEX_ID13 "00°C"
#define TEMP_MSG_TEX_ID14 "00°C"
#define TEMP_MSG_TEX_ID15 ""
#define TEMP_MSG_TEX_ID16 ""
#define TEMP_MSG_TEX_ID17 ""



/******************************************
 *  sat out info page
 ******************************************/
#define SATOUT_SUB_TEX_ID00 "J1-01"
#define SATOUT_SUB_TEX_ID01 "J1-05"
#define SATOUT_SUB_TEX_ID02 "J2-04"
#define SATOUT_SUB_TEX_ID03 "J3-06"
#define SATOUT_SUB_TEX_ID04 "J3-10"
#define SATOUT_SUB_TEX_ID05 "J3-14"
#define SATOUT_SUB_TEX_ID06 "J3-21"
#define SATOUT_SUB_TEX_ID07 "J3-25"

#define SATOUT_SUB_TEX_ID10 "J1-02"
#define SATOUT_SUB_TEX_ID11 "J1-06"
#define SATOUT_SUB_TEX_ID12 "J2-05"
#define SATOUT_SUB_TEX_ID13 "J3-07"
#define SATOUT_SUB_TEX_ID14 "J3-11"
#define SATOUT_SUB_TEX_ID15 "J3-15"
#define SATOUT_SUB_TEX_ID16 "J3-22"
#define SATOUT_SUB_TEX_ID17 "預留"

#define SATOUT_SUB_TEX_ID20 "J1-03"
#define SATOUT_SUB_TEX_ID21 "J1-07"
#define SATOUT_SUB_TEX_ID22 "J2-06"
#define SATOUT_SUB_TEX_ID23 "J3-08"
#define SATOUT_SUB_TEX_ID24 "J3-12"
#define SATOUT_SUB_TEX_ID25 "J3-16"
#define SATOUT_SUB_TEX_ID26 "J3-23"
#define SATOUT_SUB_TEX_ID27 "預留"

#define SATOUT_SUB_TEX_ID30 "J1-04"
#define SATOUT_SUB_TEX_ID31 "J1-08"
#define SATOUT_SUB_TEX_ID32 "J2-07"
#define SATOUT_SUB_TEX_ID33 "J3-09"
#define SATOUT_SUB_TEX_ID34 "J3-13"
#define SATOUT_SUB_TEX_ID35 "J3-17"
#define SATOUT_SUB_TEX_ID36 "J3-24"
#define SATOUT_SUB_TEX_ID37 "預留"

#define SATOUT_MSG_SUB_TEX_MSG "正常"


/******************************************
 *  sat in info page
 ******************************************/

#define SATIN_SUB_TEX_ID00 "J6-01"
#define SATIN_SUB_TEX_ID01 "J6-05"
#define SATIN_SUB_TEX_ID02 "J6-09"
#define SATIN_SUB_TEX_ID03 "J6-13"
#define SATIN_SUB_TEX_ID04 "J6-17"
#define SATIN_SUB_TEX_ID05 "J7-04"
#define SATIN_SUB_TEX_ID06 "J8-01"
#define SATIN_SUB_TEX_ID07 "預留"

#define SATIN_SUB_TEX_ID10 "J6-02"
#define SATIN_SUB_TEX_ID11 "J6-06"
#define SATIN_SUB_TEX_ID12 "J6-10"
#define SATIN_SUB_TEX_ID13 "J6-14"
#define SATIN_SUB_TEX_ID14 "J6-18"
#define SATIN_SUB_TEX_ID15 "J7-05"
#define SATIN_SUB_TEX_ID16 "J8-02"
#define SATIN_SUB_TEX_ID17 "預留"

#define SATIN_SUB_TEX_ID20 "J6-03"
#define SATIN_SUB_TEX_ID21 "J6-07"
#define SATIN_SUB_TEX_ID22 "J6-11"
#define SATIN_SUB_TEX_ID23 "J6-15"
#define SATIN_SUB_TEX_ID24 "J7-02"
#define SATIN_SUB_TEX_ID25 "J7-06"
#define SATIN_SUB_TEX_ID26 "預留"
#define SATIN_SUB_TEX_ID27 "預留"

#define SATIN_SUB_TEX_ID30 "J6-04"
#define SATIN_SUB_TEX_ID31 "J6-08"
#define SATIN_SUB_TEX_ID32 "J6-12"
#define SATIN_SUB_TEX_ID33 "J6-16"
#define SATIN_SUB_TEX_ID34 "J7-03"
#define SATIN_SUB_TEX_ID35 "J7-07"
#define SATIN_SUB_TEX_ID36 "預留"
#define SATIN_SUB_TEX_ID37 "預留"

#define SATIN_MSG_SUB_TEX_MSG "開關無效"


/******************************************
 *  sw version page
 ******************************************/
#define SWVER_SUB_TEX_ID00 "儀表"
#define SWVER_SUB_TEX_ID01 "主站"
#define SWVER_SUB_TEX_ID02 "從站0"
#define SWVER_SUB_TEX_ID03 "從站1"
#define SWVER_SUB_TEX_ID04 "從站2"
#define SWVER_SUB_TEX_ID05 "從站3"
#define SWVER_SUB_TEX_ID06 "從站4"
#define SWVER_SUB_TEX_ID07 "從站5"
#define SWVER_SUB_TEX_ID08 "從站6"
#define SWVER_SUB_TEX_ID09 "從站7"

#define SWVER_SUB_TEX_ID10 "DATE"
#define SWVER_SUB_TEX_ID11 "DATE"
#define SWVER_SUB_TEX_ID12 "DATE"
#define SWVER_SUB_TEX_ID13 "DATE"
#define SWVER_SUB_TEX_ID14 "DATE"
#define SWVER_SUB_TEX_ID15 "DATE"
#define SWVER_SUB_TEX_ID16 "DATE"
#define SWVER_SUB_TEX_ID17 "DATE"
#define SWVER_SUB_TEX_ID18 "DATE"
#define SWVER_SUB_TEX_ID19 "DATE"

#define SATIN_MSG_SUB_TEX_MSG_ID0 "ZB2711K-A-CZN4.2.1K"
#define SATIN_MSG_SUB_TEX_MSG_ID1 "20210313"


/******************************************
 *  slave station mesg page
 ******************************************/
#define SLASAT_MSG_BTN_NAME "從站訊息"
#define SLASAT_BACKMAIN_BTN_NAME "返回主頁"
#define SLASAT_BACKPREV_BTN_NAME "返回上一層"


/******************************************
 *  bcm info page
 ******************************************/
#define BCM_BTN_STR_ID0 "從站輸入狀態"
#define BCM_BTN_STR_ID1 "從站故障檢測"
#define BCM_BTN_STR_ID2 "模塊溫度"
#define BCM_BTN_STR_ID3 "程式序號版本"
#define BCM_BACKPREV_BTN_NAME "返回上級菜單"


/******************************************
 *  tire press info page
 ******************************************/
#define TIRES_ID0_OBJNAME "tires_id_1"
#define TIRES_ID1_OBJNAME "tires_id_6"
#define TIRES_ID2_OBJNAME "tires_id_3"
#define TIRES_ID3_OBJNAME "tires_id_4"
#define TIRES_ID4_OBJNAME "tires_id_2"
#define TIRES_ID5_OBJNAME "tires_id_5"

#define TIRES_AIR_VAL_DEF "000kPa"
#define TIRES_BTN_STR_ID0 "輪胎1"
#define TIRES_BTN_STR_ID1 "輪胎6"
#define TIRES_BTN_STR_ID2 "輪胎3"
#define TIRES_BTN_STR_ID3 "輪胎4"
#define TIRES_BTN_STR_ID4 "輪胎2"
#define TIRES_BTN_STR_ID5 "輪胎5"

#define TIRES_AIR_TEX_ID0 "輪胎01:"
#define TIRES_AIR_TEX_ID1 "輪胎06:"
#define TIRES_AIR_TEX_ID2 "輪胎03:"
#define TIRES_AIR_TEX_ID3 "輪胎04:"
#define TIRES_AIR_TEX_ID4 "輪胎02:"
#define TIRES_AIR_TEX_ID5 "輪胎05:"

#define TIRES_TEMP_TEX_ID0 "溫度01:"
#define TIRES_TEMP_TEX_ID1 "溫度06:"
#define TIRES_TEMP_TEX_ID2 "溫度02:"
#define TIRES_TEMP_TEX_ID3 "溫度03:"
#define TIRES_TEMP_TEX_ID4 "溫度04:"
#define TIRES_TEMP_TEX_ID5 "溫度05:"

#endif
