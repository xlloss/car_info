#include <QDebug>
#include "serial_port.h"

Serial_Port::Serial_Port()
{

}

/* Open /dev/ttyUSB0 with baudrate 115200, and defaults of 8N1, no flow control */
int Serial_Port::Serial_Port_Open(QString port_name, int speed)
{
    m_serial = serial_new();
    if (!m_serial)
        return  -EINVAL;

    if (serial_open(m_serial, port_name.toUtf8().data(), speed) < 0) {
        qDebug("serial_open(): %s\n", serial_errmsg(m_serial));
        return -EINVAL;
    }

    return  0;
}

int Serial_Port::Serial_Port_Write(QByteArray *data_write)
{
    unsigned char *buf;

    if (!data_write)
        return -EINVAL;

    /* Write to the serial port */
    buf = (unsigned char *)data_write->data();

    qDebug("Write Data Size %d\n", data_write->size());
    if (serial_write(m_serial, buf, data_write->size()) < 0) {
        qDebug("serial_write(): %s\n", serial_errmsg(m_serial));
        return -EINVAL;
    }

    return 0;
}

int Serial_Port::Serial_Port_Write(uint8_t *data_write, uint32_t data_len)
{
    if (!data_write)
        return -EINVAL;

    /* Write to the serial port */
    if (serial_write(m_serial, data_write, data_len) < 0) {
        qDebug("serial_write(): %s\n", serial_errmsg(m_serial));
        return -EINVAL;
    }

    return 0;
}

int Serial_Port::Serial_Port_Read(QByteArray *data_read)
{
    #define BUF_SIZE 512
    #define TIMEOUT 10
    uint8_t buf[BUF_SIZE];
    int ret;

    if (!data_read)
        return -EINVAL;

    /* Read up to buf size or 100ms timeout */
    if ((ret = serial_read(m_serial, buf, sizeof(uint8_t) * BUF_SIZE, TIMEOUT)) < 0) {
        qDebug("serial_read(): %s\n", serial_errmsg(m_serial));
        return -EINVAL;
    }

    data_read->resize(ret);
    memcpy(data_read->data(), buf, ret);

    return 0;
}

int Serial_Port::Serial_Port_Close()
{
    serial_close(m_serial);
    serial_free(m_serial);
    return 0;
}
