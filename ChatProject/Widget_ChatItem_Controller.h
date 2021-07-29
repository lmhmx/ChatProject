#pragma once
#include <qwidget.h>
# include "ui_Widget_ChatItem.h"
# include <string>
using namespace std;
class Widget_ChatItem_Controller :
    public QWidget
{
    Q_OBJECT
public:
    Widget_ChatItem_Controller(QWidget* parent = Q_NULLPTR);
    void setContent(int newMessageNum,
        QPixmap pic, string name, string message, string time, bool mute);

    Ui::Widget_ChatItem ui;
};

