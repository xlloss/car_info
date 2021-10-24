#ifndef PROTOCOL_FMT_H
#define PROTOCOL_FMT_H
#include <QObject>

/* ==================================================================
 * | B0  |   B1  |   B2  |   B3  |   B4  |   B5 ... Bn  |  Checksum |
 * ==================================================================
 *  Head1| Head2 |   ID  |D_LenH |D_LenL |   Page_Data  |           |
 * ==================================================================
 *
 *  Head1 : 0x5A
 *  Head2 : 0x87
 *  ID    : 0x0B -> PAGE_RQ
 *  ID    : 0x0C -> PAGE_RP
 *  D_LenH, D_LenL : B5 ~ Bn
 *  Checksum : checksum compute from B0 ~ Bn
 */

/*
 * For PAGE_RQ
 *
 * ==================================================================
 * | B5  |   B6  |   B7  |   B8  | B9 ... Bn
 * ==================================================================
 *
 *  B5      : Current Page Number
 *  B6 ~ B8 : Meter Status
 *  B9 ~ Bn : Page Data
 */

#define HEAD1 0x5A
#define HEAD2 0x87
#define PAGE_RQ 0x0B

#define HEAD1_OFF 0
#define HEAD2_OFF 1
#define ID_OFF 2
#define LENH_OFF 3
#define LENL_OFF 4
#define PAGE_DATA_OFF 5

#define HEAD_SIZE 5
#define PAGE_NUM_OFF 0
#define METER_SAT_OFF 1
#define PAGE_DAT_OFF 4

class CarInfo_Data
{
public:
    uint8_t page_number;
    uint8_t meter_sat[3];
    uint8_t page_data[512];
    uint32_t page_data_sz;
};

#endif // PROTOCOL_FMT_H
