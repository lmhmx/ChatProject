#pragma once
# include <qwidget.h>
# include "ui_Widget_searchFriend.h"
# include <string>
using namespace std;

class Widget_SearchFriendUiController:public QWidget
{
	Q_OBJECT
public:

	Widget_SearchFriendUiController(QWidget* parent = Q_NULLPTR);

	void slot_showFindFriend(string friend_id, string friend_name);

signals:
	void signal_searchFriend(string id);
	void signal_addFriend(string friend_id, string friend_name);

signals:
	

private:
	Ui::Widget_searchFriend ui;

};

