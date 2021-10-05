#pragma once
# include <qwidget.h>
# include "ui_Widget_addFriend.h"
class Widget_addFriendUiController:public QWidget
{
	Q_OBJECT
public:
	Widget_addFriendUiController(QWidget* parent=Q_NULLPTR);

private:
	Ui::Widget_addFriend ui;
};

