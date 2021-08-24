#include "Widget_ChatList_Controller.h"

Widget_ChatList_Controller::Widget_ChatList_Controller(QWidget* parent) {
	ui.setupUi(this);
	
}

void Widget_ChatList_Controller::setItem(string id, int newMessageNum,
	QPixmap pic, string name, string message, string time, bool mute) {
	if (m_ID2Item.left.find(id) == m_ID2Item.left.end()) {
		newItemInsert(id, newMessageNum, pic, name, message, time, mute);
	}
	else {
		updateItem(id, newMessageNum, pic, name, message, time, mute);
	}
}
string Widget_ChatList_Controller::setCurrentSelect(string id) {
	QListWidgetItem* currentItem = m_ID2Item.left[id];
	ui.listWidget_ChatList->setCurrentItem(currentItem);

}
bool Widget_ChatList_Controller::newItemInsert(string id, int newMessageNum,
	QPixmap pic, string name, string message, string time, bool mute) {

	QListWidgetItem* item = new QListWidgetItem();

	Widget_ChatItem_Controller* item_widget = new Widget_ChatItem_Controller();

	item_widget->setContent(newMessageNum, pic, name, message, time, mute);


	ui.listWidget_ChatList->insertItem(1, item);

	ui.listWidget_ChatList->setItemWidget(item, item_widget);
	m_ID2Item.left.insert({ id, item });
	return true;
}

bool Widget_ChatList_Controller::updateItem(string id, int newMessageNum,
	QPixmap pic, string name, string message, string time, bool mute) {

	QListWidgetItem* item = m_ID2Item.left.at(id);
	Widget_ChatItem_Controller* item_widget =
		qobject_cast<Widget_ChatItem_Controller*>(ui.listWidget_ChatList->itemWidget(item));
	item_widget->setContent(newMessageNum, pic, name, message, time, mute);
	return 1;
}
bool Widget_ChatList_Controller::removeItem(string id) {
	QListWidgetItem* item = m_ID2Item.left.at(id);
	int row = ui.listWidget_ChatList->row(item);
	ui.listWidget_ChatList->takeItem(row);
	delete item;
	return true;
}