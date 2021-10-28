#ifndef FW_UPDATE_PAGE_H
#define FW_UPDATE_PAGE_H

#include <QMainWindow>
#include <QThread>
#include <QImage>
#include <QFile>
#include <QProcess>
#include <QEvent>
#include "frame_page.h"
#include "show_text.h"
#include "serial_port.h"



#define FWV_UPDATE_BG_IMG ":/icon/system_setup.png"

#define ITEM_TEXT "系統更新"
#define ITEM_CHILD_TEXT1 "更新設備:"
#define ITEM_CHILD_TEXT2 "更新狀態:"

#define ITEM_CHILD_TEXT1_DATA_DEF "APP"
#define ITEM_CHILD_TEXT2_DATA_DEF "無更新檔"

enum
{
    FW_UP_CHECK_USB_DRIVER_CMD = 0,
    FW_UP_INSTALL_USB_DRIVER_CMD,
    FW_UP_MOUNT_USBA_CMD,
    FW_UP_MOUNT_USBB_CMD,
    FW_UP_UMOUNT_MNT_CMD,
    FW_UP_UMOUNT_USBA_CMD,
    FW_UP_UMOUNT_USBB_CMD,
    FW_UP_CKMOUNT_USB_CMD,
    FW_UP_FIND_SOC_FWBIN_CMD,
    FW_UP_FIND_MCU_FWBIN_CMD,
    FW_UP_NO_CMD,
};

class UpdateThread : public QThread
{
    Q_OBJECT
public:
    explicit UpdateThread(QObject *parent = 0, bool b = false);

    void run();
    bool Stop;
    int find_update();
    int m_cmd;
    int m_cmd_ret;
    int exe_cmd(int cmd);
    QProcess process;

    // if Stop = true, the thread will break
    // out of the loop, and will be disposed
//    bool Stop;
//    QList <Cmd_Buf *> cmd_list;
//    Cmd_Buf *getcmd;
//    Serial_Port *serialport;
//    int do_checksum(uint8_t *data, uint16_t data_len, uint8_t check);

private:
    QFile mfile;

signals:
    // To communicate with Gui Thread
    // we need to emit a signal
    //void valueChanged(int);

public slots:
};

class FwUpdate_Page : public Frame_Page
{
Q_OBJECT
public:
    explicit FwUpdate_Page(QWidget *parent = nullptr);

    Show_text *show_item;
    Show_text *show_item_child1;
    Show_text *show_item_child2;

    Show_text *show_item_child1_data;
    Show_text *show_item_child2_data;
    UpdateThread *update_thread;
    uint16_t Crc16_Encode(char *addr,uint16_t len);

    virtual void GetMcuData(class CarInfo_Data *protolcol_data) override;

protected:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    int OpenMCUFile(QString filename);
    int ReadMCUFile();
    void CloseMCUFile();
    QFile m_mcufile;
    QByteArray m_mcufw_bin;
    char *m_int8_mcufw_bin;

signals:

};

#endif
