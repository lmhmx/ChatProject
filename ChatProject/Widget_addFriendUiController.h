#pragma once
# include <qwidget.h>
# include <string>
# include "ui_Widget_addFriend.h"
using namespace std;
class Widget_addFriendUiController:public QWidget
{
	Q_OBJECT
public:
	Widget_addFriendUiController(QWidget* parent=Q_NULLPTR);
	void setInfomation(string yourName, string id, string name);

signals:
	void signal_addFriend(string yourName, string id);
private:
	Ui::Widget_addFriend ui;
};

