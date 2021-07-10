QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barframe.cpp \
    battery_temp_info_page.cpp \
    battery_volt_info_page.cpp \
    car_inout_temp_page.cpp \
    control_msg1_page.cpp \
    control_msg2_page.cpp \
    eai_page.cpp \
    frame_page.cpp \
    home_page.cpp \
    icon_btn.cpp \
    main.cpp \
    main_page.cpp \
    mainwindow.cpp \
    mileage_rpm_page.cpp \
    page_ctl.cpp \
    screen_volume_adjust_page.cpp \
    show_text.cpp \
    temp_module_page.cpp \
    test_frame.cpp \
    time_adjust_page.cpp \
    slave_sat_out_msg_page.cpp \
    slave_sat_in_msg_page.cpp \
    sw_version_page.cpp \
    slave_sat_msg_page.cpp \
    bcm_page.cpp

HEADERS += \
    barframe.h \
    battery_temp_info_page.h \
    battery_volt_info_page.h \
    car_inout_temp_page.h \
    control_msg1_page.h \
    control_msg2_page.h \
    eai_page.h \
    frame_page.h \
    home_page.h \
    icon_btn.h \
    main_page.h \
    mainwindow.h \
    mileage_rpm_page.h \
    page_ctl.h \
    screen_volume_adjust_page.h \
    show_text.h \
    temp_module_page.h \
    string/main_string.h \
    test_frame.h \
    time_adjust_page.h \
    slave_sat_out_msg_page.h \
    slave_sat_in_msg_page.h \
    sw_version_page.h \
    slave_sat_msg_page.h \
    bcm_page.h

FORMS += \
    barframe.ui \
    frame_page.ui \
    mainwindow.ui \
    test_frame.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc
