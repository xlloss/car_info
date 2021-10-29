#ifndef FRAME_PAGE_H
#define FRAME_PAGE_H

#include <QFrame>
#include "icon_btn.h"
#include "protocol_fmt.h"

namespace Ui {
class Frame_Page;
}

class Frame_Page : public QFrame
{
    Q_OBJECT

public:
    explicit Frame_Page(QWidget *parent = nullptr);
    ~Frame_Page();
    uint8_t *m_ackdata;
    Icon_btn *icon_id[50];
    void Enable_Icon_Light(int i);
    void Load_Background(QString image);
    uint8_t do_checksum(uint8_t *data, uint16_t data_len);
    class CarInfo_Data m_protolcol_data;
    virtual void GetMcuData(class CarInfo_Data *) = 0;
    virtual void GetAckData(uint8_t *);
    virtual void CopyDataToAck(class CarInfo_Data *protolcol_data);
private slots:

protected:
    QPixmap bgimg;

private:
    Ui::Frame_Page *ui;
};

#endif // FRAME_PAGE_H
