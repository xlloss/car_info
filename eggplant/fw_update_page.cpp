#include <QPainter>
#include <QDir>
#include "fw_update_page.h"
#include "coordinate.h"
#include "string/string.h"

#define MCU_FW_NAME "AT313SFW.BIN"
#define SOC_FW_NAME "ISPBOOOT.BIN"

UpdateThread::UpdateThread(QObject *parent, bool b) :
    QThread(parent), Stop(b)
{
}

void UpdateThread::run()
{
    m_cmd_ret = exe_cmd(m_cmd);
    msleep(5);
}

int UpdateThread::find_update()
{
    int ret = 0;
    QProcess process;

    process.start("mount", QStringList() << "/dev/sda1 /mnt/");

    return ret;
}

int UpdateThread::exe_cmd(int cmd)
{
    int ret = 0;
    qDebug("%s %d\n", __func__, __LINE__);
    switch (cmd){

    case FW_UP_CHECK_USB_DRIVER_CMD:
        process.execute("lsmod | grep sp_bc");
        break;
    case FW_UP_INSTALL_USB_DRIVER_CMD:
        process.execute("insmod  /tmp/sp/usr/local/drivers/sp-bc.ko");
        process.execute("insmod  /tmp/sp/usr/local/drivers/ehci-hcd.ko");
        break;

    case FW_UP_MOUNT_USBA_CMD:
        qDebug("%s %d\n", __func__, __LINE__);
        process.execute("mount /dev/sda1 /mnt/");
        break;

    case FW_UP_UMOUNT_MNT_CMD:
        qDebug("%s %d\n", __func__, __LINE__);
        process.execute("umount /mnt");
        break;

    case FW_UP_UMOUNT_USBA_CMD:
        qDebug("%s %d\n", __func__, __LINE__);
        process.execute("umount /dev/sda1");
        break;

    case FW_UP_MOUNT_USBB_CMD:
        process.execute("mount /dev/sdb1 /mnt/");
        break;

    case FW_UP_UMOUNT_USBB_CMD:
        process.execute("umount /dev/sdb1");
        break;

    case FW_UP_CKMOUNT_USB_CMD:
        process.start("mount");
        break;

    case FW_UP_FIND_SOC_FWBIN_CMD:
    case FW_UP_FIND_MCU_FWBIN_CMD:
        process.start("ls /mnt");
        break;


    default:
        break;
    }

    if (process.waitForFinished()) {
        QString strtmp;
        strtmp = process.readAll();

        switch (cmd) {
        case FW_UP_CHECK_USB_DRIVER_CMD:
            if (strtmp.contains("sp_bc") == 1)
                ret = 0;
            else
                ret = -1;
            break;

        case FW_UP_CKMOUNT_USB_CMD:
            if (strtmp.contains("/dev/sda1") == 1)
                ret = 0;
            else
                ret = -1;
            break;

        case FW_UP_FIND_SOC_FWBIN_CMD:
            if (strtmp.contains(SOC_FW_NAME) == 1) {
                qDebug("found %s\n", SOC_FW_NAME);
                ret = 0;
            } else {
                qDebug("can't found %s\n", SOC_FW_NAME);
                ret = -1;
            }
            break;

        case FW_UP_FIND_MCU_FWBIN_CMD:
            if (strtmp.contains(MCU_FW_NAME) == 1) {
                qDebug("found %s\n", MCU_FW_NAME);
                ret = 0;
            } else {
                qDebug("can't found %s\n", MCU_FW_NAME);
                ret = -1;
            }
            break;
        default:
            break;
        }
    }

    return ret;
}

uint16_t FwUpdate_Page:: Crc16_Encode(char *addr, uint16_t len)
{
    uint8_t uchCRCHi = 0xff;
    uint8_t uchCRCLo = 0xff;
    uint16_t uindex;

    static const uint8_t auchCRCHi[]= {
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
        0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
        0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
        0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
        0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
        0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40
    };

    static const uint8_t auchCRCLo[] = {
        0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4,
        0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
        0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD,
        0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
        0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7,
        0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
        0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE,
        0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
        0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2,
        0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
        0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB,
        0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
        0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50, 0x90, 0x91,
        0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
        0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88,
        0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
        0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80,
        0x40
    };


    while (len--) {
        uindex = uchCRCHi ^ *addr++;
        uchCRCHi = uchCRCLo ^ auchCRCHi[uindex];
        uchCRCLo = auchCRCLo[uindex];
    }

    return uint16_t(uchCRCHi << 8 | uchCRCLo);
}

FwUpdate_Page::FwUpdate_Page(QWidget *parent) : Frame_Page(parent)
{
    setObjectName(FWV_UPDATE_OBJNAME);
    bgimg.load(FWV_UPDATE_BG_IMG);

    show_item = new Show_text(this);
    show_item->set_text(ITEM_TEXT);
    show_item->setGeometry(FW_UPDATE_ITEM_X, FW_UPDATE_ITEM_Y,
                           FW_UPDATE_ITEM_W, FW_UPDATE_ITEM_H);
    show_item->show();

    show_item_child1 = new Show_text(this);
    show_item_child1->set_text(ITEM_CHILD_TEXT1);
    show_item_child1->setGeometry(FW_UPDATE_CHILD_TEXT1_X, FW_UPDATE_CHILD_TEXT1_Y,
                                  FW_UPDATE_CHILD_TEXT1_W, FW_UPDATE_CHILD_TEXT1_H);
    show_item_child1->show();

    show_item_child1_data = new Show_text(this);
    show_item_child1_data->set_text(ITEM_CHILD_TEXT1_DATA_DEF);
    show_item_child1_data->setGeometry(FW_UPDATE_CHILD_TEXT1_DATA_X, FW_UPDATE_CHILD_TEXT1_DATA_Y,
                                       FW_UPDATE_CHILD_TEXT1_DATA_W, FW_UPDATE_CHILD_TEXT1_DATA_H);
    show_item_child1_data->show();

    show_item_child2 = new Show_text(this);
    show_item_child2->set_text(ITEM_CHILD_TEXT2);
    show_item_child2->setGeometry(FW_UPDATE_CHILD_TEXT2_X, FW_UPDATE_CHILD_TEXT2_Y,
                                  FW_UPDATE_CHILD_TEXT2_W, FW_UPDATE_CHILD_TEXT2_H);
    show_item_child2->show();

    show_item_child2_data = new Show_text(this);
    show_item_child2_data->set_text(ITEM_CHILD_TEXT2_DATA_DEF);
    show_item_child2_data->setGeometry(FW_UPDATE_CHILD_TEXT2_DATA_X, FW_UPDATE_CHILD_TEXT2_DATA_Y,
                                       FW_UPDATE_CHILD_TEXT2_DATA_W, FW_UPDATE_CHILD_TEXT2_DATA_H);
    show_item_child2_data->show();


    update_thread = new UpdateThread();


}

void FwUpdate_Page::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, bgimg,
                       GOBAL_BACKGROUND_IMG_X, GOBAL_BACKGROUND_IMG_Y,
                       GOBAL_BACKGROUND_IMG_W, GOBAL_BACKGROUND_IMG_H);
}

void FwUpdate_Page::GetMcuData(class CarInfo_Data *protolcol_data)
{
    uint8_t page_data[256];
    uint8_t u8_data_b0, u8_data_b1, u8_data_b2;
    uint8_t update_dev = 0, update_sat = 0;
    uint32_t mcu_fw_offset;
    uint32_t mcu_fw_size;
    int32_t  m_cmd_ret;
    static int32_t show_counter = 0;
    QString str_tmp;
    #define UPDATE_DEV_NO (1 << 0)
    #define UPDATE_DEV_APP (1 << 1)
    #define UPDATE_DEV_MCU (1 << 2)
    #define UPDATE_DEV_MSK 0x0F
    #define UPDATE_SAT_NO (1 << 0)
    #define UPDATE_SAT_APP (1 << 1)
    #define UPDATE_SAT_MCU (1 << 2)
    #define UPDATE_CHECK_FILE (1 << 3)
    #define B0_NONE_UPDATE_DEV 0x00
    #define B0_APP_UPDATE_DEV 0x01
    #define B0_MCU_UPDATE_DEV 0x02
    #define B1_NONE_BEHAVE 0x00
    #define B1_CHECK_UPDATE 0x01
    #define B1_START_UPDATE 0x02
    #define B1_UPDATE_FAIL 0x03
    #define B2_NONE 0x0
    #define B2_NOFILE_UPDATE 0x01
    #define B2_SOC_UPDATE 0x02
    #define B2_MCU_UPDATE 0x03
    #define B2_CHECK_SOC_UPDATING 0x04
    #define B2_CHECK_MCU_UPDATING 0x05
    #define B2_MCU_UPDATING 0x06
    #define B2_UPDATE_FAIL 0x07

    memcpy(page_data, protolcol_data->page_data, sizeof(uint8_t) * protolcol_data->page_data_sz);

    u8_data_b0 = page_data[0];
    u8_data_b1 = page_data[1];
    u8_data_b2 = page_data[2];

    qDebug("%s %d u8_data_b0 0x%x\n", __func__, __LINE__, u8_data_b0);
    qDebug("%s %d u8_data_b1 0x%x\n", __func__, __LINE__, u8_data_b1);
    qDebug("%s %d u8_data_b2 0x%x\n", __func__, __LINE__, u8_data_b2);

    if (u8_data_b0 == B0_NONE_UPDATE_DEV &&
        u8_data_b1 == B1_NONE_BEHAVE &&
        u8_data_b2 == B2_NONE) {
        qDebug("%s %d\n", __func__, __LINE__);
        show_item_child1_data->set_text("無");
        show_item_child2_data->set_text("無");
        update_dev |= UPDATE_DEV_NO;

        protolcol_data->page_data[2] = B2_NONE;
        protolcol_data->page_data_sz = 8;
        memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));

        /* umount device last time if device already mount */
        m_cmd_ret = update_thread->exe_cmd(FW_UP_CKMOUNT_USB_CMD);
        if (!m_cmd_ret)
            update_thread->exe_cmd(FW_UP_UMOUNT_MNT_CMD);

        show_counter = 0;
        return;
    }

    if (u8_data_b2 == B2_NOFILE_UPDATE) {
        if (u8_data_b0 == B0_APP_UPDATE_DEV)
            show_item_child1_data->set_text("APP");
        else
            show_item_child1_data->set_text("MCU");

        show_item_child2_data->set_text("無更新檔");

        qDebug("%s %d\n", __func__, __LINE__);

        //for ACK
        protolcol_data->page_data_sz = 8;
        protolcol_data->page_data[2] = B2_NOFILE_UPDATE;
        memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
        m_cmd_ret = update_thread->exe_cmd(FW_UP_CKMOUNT_USB_CMD);
        if (!m_cmd_ret)
            update_thread->exe_cmd(FW_UP_UMOUNT_MNT_CMD);
        show_counter = 0;
        return;
    }

    if (u8_data_b1 == B1_NONE_BEHAVE) {
        if (u8_data_b0 == B0_APP_UPDATE_DEV) {
            show_item_child1_data->set_text("APP");
            update_dev |= UPDATE_DEV_APP;
        } else if (u8_data_b0 == B0_MCU_UPDATE_DEV) {
            show_item_child1_data->set_text("MCU");
            update_dev |= UPDATE_DEV_MCU;
        }

        protolcol_data->page_data_sz = 8;
        memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
        return;
    }

    //Check Update
    if (u8_data_b1 == B1_CHECK_UPDATE) {
        qDebug("%s %d\n", __func__, __LINE__);
        if (show_counter < 30) {
            qDebug("%s %d\n", __func__, __LINE__);
            show_item_child2_data->set_text("檢查更新檔");
            if (show_counter == 1) {
                m_cmd_ret = update_thread->exe_cmd(FW_UP_CHECK_USB_DRIVER_CMD);
                if (!m_cmd_ret)
                    update_thread->exe_cmd(FW_UP_INSTALL_USB_DRIVER_CMD);
            } else if (show_counter == 25)
                update_thread->exe_cmd(FW_UP_MOUNT_USBA_CMD);

            show_counter++;
            protolcol_data->page_data_sz = 8;

            if (u8_data_b0 == B0_APP_UPDATE_DEV) {
                show_item_child2_data->set_text("檢查 APP 更新檔中 ...");
                protolcol_data->page_data[2] = B2_CHECK_SOC_UPDATING;
            } else {
                show_item_child2_data->set_text("檢查 MCU 更新檔中 ...");
                protolcol_data->page_data[2] = B2_CHECK_MCU_UPDATING;
            }

            memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
            QThread::msleep(100);
            return;
        }

        qDebug("%s %d\n", __func__, __LINE__);
        if (u8_data_b0 == B0_APP_UPDATE_DEV) {
            m_cmd_ret = update_thread->exe_cmd(FW_UP_FIND_SOC_FWBIN_CMD);
            QThread::msleep(500);
            if (!m_cmd_ret) {
                show_item_child2_data->set_text("SOC 可更新");
                update_sat &= ~UPDATE_SAT_NO;
                update_sat |= UPDATE_SAT_APP;
                protolcol_data->page_data[2] = B2_SOC_UPDATE;
                protolcol_data->page_data_sz = 8;
                memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
                return;
            } else {
                qDebug("%s %d\n", __func__, __LINE__);
                show_item_child2_data->set_text("無更新檔");
                update_sat |= UPDATE_SAT_NO;
            }
        } else if (u8_data_b0 == B0_MCU_UPDATE_DEV) {
            m_cmd_ret = update_thread->exe_cmd(FW_UP_FIND_MCU_FWBIN_CMD);
            QThread::msleep(500);
            if (!m_cmd_ret) {
                uint32_t mcu_fw_size;
                uint16_t crc_ret;
                show_item_child2_data->set_text("MCU 可更新");
                update_sat &= ~UPDATE_SAT_NO;
                update_sat |= UPDATE_SAT_MCU;

                m_mcufile.setFileName(MCU_FW_NAME);
                QDir::setCurrent("/mnt");
                if (!m_mcufile.open(QIODevice::ReadOnly)) {
                    qDebug("File Open Fail\n");
                    show_item_child1_data->set_text("更新檔 讀取錯誤");
                    protolcol_data->page_data[2] = B2_UPDATE_FAIL;
                    protolcol_data->page_data_sz = 8;
                    memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
                    return;
                }

                /* qDebug("File Size %lld\n", m_mcufile.size()); */
                mcu_fw_size = uint32_t(m_mcufile.size());
                protolcol_data->page_data[5] = uint8_t((mcu_fw_size & 0xFF0000) >> 16);
                protolcol_data->page_data[4] = uint8_t((mcu_fw_size & 0x00FF00) >> 8);
                protolcol_data->page_data[3] = uint8_t((mcu_fw_size & 0x0000FF) >> 0);

                while (!m_mcufile.atEnd()) {
                    m_mcufw_bin = m_mcufile.readAll();
                }

                m_int8_mcufw_bin = m_mcufw_bin.data();
                crc_ret = Crc16_Encode(m_int8_mcufw_bin, uint16_t(m_mcufw_bin.length()));

                protolcol_data->page_data[7] = uint8_t((crc_ret & 0xFF00) >> 8);
                protolcol_data->page_data[6] = uint8_t((crc_ret & 0x00FF));
                protolcol_data->page_data[2] = B2_MCU_UPDATE;
                protolcol_data->page_data_sz = 8;
                memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
                return;
            } else {
                qDebug("%s %d\n", __func__, __LINE__);
                show_item_child2_data->set_text("無更新檔");
                update_sat |= UPDATE_SAT_NO;
            }
        }

        protolcol_data->page_data[2] = B2_NOFILE_UPDATE;
        protolcol_data->page_data_sz = 8;
        memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
        return;
    }

    if (u8_data_b1 == B1_START_UPDATE) {
        //Start Update
        show_item_child2_data->set_text("更新中 0~100%");

        mcu_fw_offset = protolcol_data->page_data[10] << 16  |
                        protolcol_data->page_data[9]  << 8   |
                        protolcol_data->page_data[8];

        mcu_fw_size = protolcol_data->page_data[12] << 8 |
                      protolcol_data->page_data[11];


        memcpy(&protolcol_data->page_data[13], (m_int8_mcufw_bin + mcu_fw_offset),
            mcu_fw_size);

        protolcol_data->page_data_sz = mcu_fw_size + 13;

        protolcol_data->page_data[2] = B2_MCU_UPDATING;
        memcpy(&m_protolcol_data, protolcol_data, sizeof(m_protolcol_data));
        return;
    }
}
