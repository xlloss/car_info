#include "test_frame.h"
#include "ui_test_frame.h"
#include <QDebug>

Test_Frame::Test_Frame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Test_Frame)
{
    QString str;
    int i;

    ui->setupUi(this);

    for (i = 0; i < 15; i++) {
        str.sprintf("ID%d", i);
        ui->bar_comboBox->insertItem(i, str);
    }

    for (i = 0; i < 15; i++) {
        str.sprintf("Page%d", i);
        ui->page_change->insertItem(i, str);
    }

    this->setGeometry(0, 600, 500, 400);
}

void Test_Frame::Register(class Frame_Page *frameage)
{
    page_list.append(frameage);
}


int Test_Frame::Find_Frame(QString objname)
{
    int i, ret, list_cnt;
    class Frame_Page *frameage;

    if (page_list.empty())
        return -1;

    list_cnt = page_list.count();
    for (i = 0; i < list_cnt; i++) {
        frameage = page_list.at(i);
        ret = objname.compare(frameage->objectName());
        qDebug() << "frameage->objectName()" << frameage->objectName();
        if (!ret)
            break;
    }

    if (i >= list_cnt)
        return -1;

    return i;
}

void Test_Frame::Frame_Page_Show(QString objname)
{
    class Frame_Page *frameage;
    int i;

    i = Find_Frame(objname);
    if (i < 0) {
        qDebug("can't find any frameage");
        return;
    }

    frameage = page_list.at(i);
    qDebug() << "frameage objname=" <<frameage->objectName();
    this->connect(this, SIGNAL(set_show_page()), frameage, SLOT(show()));
    emit set_show_page();
}

void Test_Frame::Bar_ID_Enable(QString objname, int icon_id)
{
    class Frame_Page *frameage;
    int i;

    i = Find_Frame(objname);
    if (i < 0) {
        qDebug("can't find any frameage");
        return;
    }

    frameage = page_list.at(i);
    this->connect(this, SIGNAL(set_icon_light_enable(int)), frameage, SLOT(Enable_Icon_Light(int)));
    emit set_icon_light_enable(icon_id);
    frameage->update();
}

Test_Frame::~Test_Frame()
{
    delete ui;
}

void Test_Frame::on_bar_comboBox_currentIndexChanged(int index)
{
    qDebug("on_bar_comboBox_currentIndexChanged %d\n", index);
}

void Test_Frame::on_bar_comboBox_activated(int index)
{
    qDebug("on_bar_comboBox_activated %d\n", index);
    Bar_ID_Enable("BarFrame", index);
}

void Test_Frame::on_page_change_activated(int index)
{
    QString objname = "Main_Page";

    Frame_Page_Show(objname);
}
