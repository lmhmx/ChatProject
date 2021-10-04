#pragma once
# include <qdialog.h>
# include <string>
# include "ui_Widget_searchFriend.h"
# include "ui_Widget_AddFriend.h"
using namespace std;
class Widget_SearchUiController:public QDialog
{
	Q_OBJECT


public:
	Widget_SearchUiController(QWidget* parent = Q_NULLPTR);

signals:
	void signal_searchFriend(string friend_id);
	void signal_addFriend(string friend_id, string friend_name, string your_name);
	

public:
	

private:
	Ui::Widget_searchFriend ui_widget_searchFriend;
	Ui::Widget_addFriend ui_widget_addFriend;
};

