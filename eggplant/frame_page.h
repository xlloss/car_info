#ifndef FRAME_PAGE_H
#define FRAME_PAGE_H

#include <QFrame>
#include "icon_btn.h"

namespace Ui {
class Frame_Page;
}

class Frame_Page : public QFrame
{
    Q_OBJECT

public:
    explicit Frame_Page(QWidget *parent = nullptr);
    ~Frame_Page();
    Icon_btn *icon_id[50];
    void Enable_Icon_Light(int i);

private slots:


private:
    Ui::Frame_Page *ui;
};

#endif // FRAME_PAGE_H
