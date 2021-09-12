#include <QPainter>
#include "fw_update_page.h"
#include "coordinate.h"

//UpdateThread::UpdateThread(QObject *parent, bool b) : QThread(parent), Stop(b)
//{
//
//}

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

    switch (cmd){
    case FW_UP_MOUNT_USBA_CMD:
        process.execute("mount /dev/sda1 /mnt/");
        break;

    case FW_UP_UMOUNT_USBA_CMD:
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
        case FW_UP_CKMOUNT_USB_CMD:
            if (strtmp.contains("/dev/sdb1") == 1)
                ret = 0;
            else
                ret = -1;
            break;

        case FW_UP_FIND_SOC_FWBIN_CMD:
            if (strtmp.contains("ISPBOOOT.BIN") == 1) {
                qDebug("found ISPBOOOT.BIN\n");
                ret = 0;
            } else {
                qDebug("can't found ISPBOOOT.BIN\n");
                ret = -1;
            }
            break;

        case FW_UP_FIND_MCU_FWBIN_CMD:
            if (strtmp.contains("AT313SFW.BIN") == 1) {
                qDebug("found AT313SFW.BIN\n");
                ret = 0;
            } else {
                qDebug("can't found AT313SFW.BIN\n");
                ret = -1;
            }
            break;
        default:
            break;
        }
    }

    return ret;
}

FwUpdate_Page::FwUpdate_Page(QWidget *parent) : Frame_Page(parent)
{
    setObjectName(FWV_UPDATE_OBJNAME);
    bgimg.load(FWV_UPDATE_BG_IMG);

    show_item = new Show_text(this);
    show_item->set_text(ITEM_TEXT);
    show_item->setGeometry(25, 40, 100, 50);
    show_item->show();

    show_item_child1 = new Show_text(this);
    show_item_child1->set_text(ITEM_CHILD_TEXT1);
    show_item_child1->setGeometry(170, 40, 100, 50);
    show_item_child1->show();

    show_item_child1_data = new Show_text(this);
    show_item_child1_data->set_text(ITEM_CHILD_TEXT1_DATA_DEF);
    show_item_child1_data->setGeometry(260, 40, 100, 50);
    show_item_child1_data->show();

    show_item_child2 = new Show_text(this);
    show_item_child2->set_text(ITEM_CHILD_TEXT2);
    show_item_child2->setGeometry(170, 100, 100, 50);
    show_item_child2->show();

    show_item_child2_data = new Show_text(this);
    show_item_child2_data->set_text(ITEM_CHILD_TEXT2_DATA_DEF);
    show_item_child2_data->setGeometry(260, 100, 100, 50);
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
    uint8_t page_data[128];
    uint8_t u8_data_tmp;
    uint8_t update_dev = 0;
    QString str_tmp;
    #define UPDATE_DEV_NO (1 << 0)
    #define UPDATE_DEV_APP (1 << 1)
    #define UPDATE_DEV_MCU (1 << 2)
    #define UPDATE_DEV_MSK 0x0F

    memcpy(page_data, protolcol_data->page_data, sizeof(uint8_t) * protolcol_data->page_data_sz);


    //Update Device
    update_thread->m_cmd = FW_UP_MOUNT_USBA_CMD;
    update_thread->start();

    u8_data_tmp = page_data[0];
    if (u8_data_tmp == 0) {
        show_item_child1_data->set_text("否");
        update_dev |= UPDATE_DEV_NO;
    } else if (u8_data_tmp == 1) {
        show_item_child1_data->set_text("APP");
        update_dev |= UPDATE_DEV_APP;
    } else {
        show_item_child1_data->set_text("MCU");
        update_dev |= UPDATE_DEV_MCU;
    }

    //Update Behave
    u8_data_tmp = page_data[1];
    if (u8_data_tmp == 0) {
        show_item_child2_data->set_text("無");
        return;
    }


    if (u8_data_tmp == 1) {
        show_item_child2_data->set_text("檢查更新檔");

        if (update_dev & UPDATE_DEV_APP) {
            update_thread->m_cmd = FW_UP_FIND_SOC_FWBIN_CMD;
            update_thread->start();

            if (!update_thread->m_cmd_ret)
                show_item_child1_data->set_text("APP 更新");
            else
                show_item_child1_data->set_text("無更新檔");
        } else if (update_dev & UPDATE_DEV_MCU) {
            update_thread->m_cmd = FW_UP_FIND_MCU_FWBIN_CMD;
            update_thread->start();

            if (!update_thread->m_cmd_ret)
                show_item_child1_data->set_text("MCUP 更新");
            else
                show_item_child1_data->set_text("無更新檔");
        }
    } else {
        show_item_child2_data->set_text("開始更新");
    }

    //update_thread->m_cmd = FW_UP_CKMOUNT_USB_CMD;
    //update_thread->start();
}
