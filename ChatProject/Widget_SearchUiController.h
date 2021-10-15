#pragma once
# include <qdialog.h>
# include <string>
# include "ui_Widget_search.h"
# include "Widget_addFriendUiController.h"
# include "Widget_SearchFriendUiController.h"
using namespace std;
class Widget_SearchUiController:public QDialog
{
	Q_OBJECT


public:
	Widget_SearchUiController(QWidget* parent = Q_NULLPTR);


public:
	void setSearchResult(string id, string name);

signals:	
	void signal_searchFriend(string id);
signals:
	void signal_addFriend(string yourName, string id);

public:
	// slots
	void slot_searchFriend_searchFriend(string id);
	void slot_searchFriend_addFriend(string friend_id, string friend_name);

	void slot_addFriend_addFriend(string yourName, string id);
	
private:
	Widget_SearchFriendUiController* m_searchFriend;
	Widget_addFriendUiController* m_addFriend;
	Ui::Widget_search ui;
};

