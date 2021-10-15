#include "Widget_SearchUiController.h"

using namespace std;

Widget_SearchUiController::Widget_SearchUiController(QWidget* parent):
	QDialog(parent) {
	ui.setupUi(this);
	m_addFriend = new Widget_addFriendUiController(ui.page_addFriend);
	m_searchFriend = new Widget_SearchFriendUiController(ui.page_searchFriend);
	connect(m_searchFriend, &Widget_SearchFriendUiController::signal_searchFriend,
		this, &Widget_SearchUiController::slot_searchFriend_searchFriend);
	connect(m_searchFriend, &Widget_SearchFriendUiController::signal_addFriend,
		this, &Widget_SearchUiController::slot_searchFriend_addFriend);
	connect(m_addFriend, &Widget_addFriendUiController::signal_addFriend,
		this, &Widget_SearchUiController::slot_addFriend_addFriend);
	ui.stackedWidget->setCurrentIndex(0);
}
void Widget_SearchUiController::slot_searchFriend_searchFriend(string id)
{
	emit signal_searchFriend(id);
}
void Widget_SearchUiController::slot_searchFriend_addFriend(string friend_id, string friend_name) {
	ui.stackedWidget->setCurrentIndex(1);
	m_addFriend->setInfomation("your name", friend_id, friend_name);

}
void Widget_SearchUiController::slot_addFriend_addFriend(string yourName, string id) {
	emit signal_addFriend(yourName, id);
}
void Widget_SearchUiController::setSearchResult(string id, string name) {
	ui.stackedWidget->setCurrentIndex(0);
	m_searchFriend->slot_showFindFriend(id, name);
}