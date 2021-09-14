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
    int do_checksum(uint8_t *data, uint16_t data_len, uint8_t check);

    virtual void GetMcuData(class CarInfo_Data *) = 0;
    virtual void GetAckData(unsigned char *) = 0;
private slots:

protected:
    QPixmap bgimg;

private:
    Ui::Frame_Page *ui;
};

#endif // FRAME_PAGE_H
