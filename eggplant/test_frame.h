#ifndef TEST_FRAME_H
#define TEST_FRAME_H

#include <QFrame>
#include "frame_page.h"
#include "QList"
#include "barframe.h"
namespace Ui {
class Test_Frame;
}

class Test_Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Test_Frame(QWidget *parent = nullptr);
    ~Test_Frame();
    QList <class Frame_Page *> page_list;
    void Register(class Frame_Page *frameage);
    void Bar_ID_Enable(QString objname, int icon_id);
    void Page_ID_Enable(QString objname, int icon_id);
    void Frame_Page_Show(QString objname);
    int Find_Frame(QString objname);
    QString current_page;
signals:
    void set_icon_light_enable(int);
    void set_show_page();
    void set_close_page();

private slots:
    void on_bar_comboBox_currentIndexChanged(int index);
    void on_bar_comboBox_activated(int index);

    void on_page_change_activated(int index);

    void on_page_icon_id_currentIndexChanged(int index);

private:
    Ui::Test_Frame *ui;
};

#endif // TEST_FRAME_H
