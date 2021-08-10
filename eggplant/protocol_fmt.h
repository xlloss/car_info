#ifndef PROTOCOL_FMT_H
#define PROTOCOL_FMT_H
#include <QObject>

#define BAR_FRAME_OBJNAME "BarFrame"
#define HOME_PAGE_OBJNAME "Home_Page"
#define MAIN_PAGE_OBJNAME "Main_Page"
#define RPM_OBJNAME "Rpm_Page"


class CarInfo_Data
{
public:
    uint8_t page_number;
    uint8_t widge_id[3];
    uint8_t widge_data[50];
    uint8_t pad[2];
};

#endif // PROTOCOL_FMT_H
