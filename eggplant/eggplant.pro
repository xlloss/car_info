QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
/
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#KIT = QTx86
KIT = sunpluse

contains(KIT, QTx86) {
    LIBS += -L$$PWD/eggplantlib/ -lserial
    INCLUDEPATH += $$PWD/eggplantlib
    DEPENDPATH += $$PWD/eggplantlib
}
contains(KIT, sunpluse) {
    LIBS += -L$$PWD/eggplantlib_sunpluse/ -lserial
    INCLUDEPATH += $$PWD/eggplantlib_sunpluse
    DEPENDPATH += $$PWD/eggplantlib_sunpluse
}

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barframe.cpp \
    battery_temp_info_page.cpp \
    battery_volt_info_page.cpp \
    car_inout_temp_page.cpp \
    cmd_receive.cpp \
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
    serial_port.cpp \
    show_text.cpp \
    temp_module_page.cpp \
    time_adjust_page.cpp \
    slave_sat_out_msg_page.cpp \
    slave_sat_in_msg_page.cpp \
    sw_version_page.cpp \
    slave_sat_msg_page.cpp \
    bcm_page.cpp \
    tires_pressure_show_page.cpp

HEADERS += \
    barframe.h \
    battery_temp_info_page.h \
    battery_volt_info_page.h \
    car_inout_temp_page.h \
    cmd_receive.h \
    control_msg1_page.h \
    control_msg2_page.h \
    coordinate.h \
    eai_page.h \
    frame_page.h \
    home_page.h \
    icon_btn.h \
    main_page.h \
    mainwindow.h \
    mileage_rpm_page.h \
    page_ctl.h \
    protocol_fmt.h \
    screen_volume_adjust_page.h \
    serial_port.h \
    show_text.h \
    string/string.h \
    temp_module_page.h \
    time_adjust_page.h \
    slave_sat_out_msg_page.h \
    slave_sat_in_msg_page.h \
    sw_version_page.h \
    slave_sat_msg_page.h \
    bcm_page.h \
    tires_pressure_show_page.h

FORMS += \
    barframe.ui \
    frame_page.ui \
    mainwindow.ui \
    test_frame.ui \

TRANSLATIONS += \
    eggplant_zh_TW.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/eggplantlib/release/ -lserial
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/eggplantlib/debug/ -lserial
#else:unix: LIBS += -L$$PWD/eggplantlib/ -lserial
#
#INCLUDEPATH += $$PWD/eggplantlib
#DEPENDPATH += $$PWD/eggplantlib
#
#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/eggplantlib/release/libserial.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/eggplantlib/debug/libserial.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/eggplantlib/release/serial.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/eggplantlib/debug/serial.lib
#else:unix: PRE_TARGETDEPS += $$PWD/eggplantlib/libserial.a
