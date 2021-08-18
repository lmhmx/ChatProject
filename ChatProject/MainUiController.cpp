#include "MainUiController.h"
MainUiController::MainUiController(QWidget* parent):QWidget(parent) {
	
	ui_main.setupUi(this);
	ui_ChatList.setupUi(ui_main.widget_ChatList);
	ui_MessageShow.setupUi(ui_main.widget_MessageShow);
	ui_send.setupUi(ui_main.widget_MessageSend);
	connect(ui_ChatList.listWidget_ChatList, &QListWidget::itemSelectionChanged,
		this, &MainUiController::slot_SelectChanged);
}

void MainUiController::newMessage(Message message) {
	string uid = message.m_MessageSender;

	if (m_Messages.find(uid) == m_Messages.end()) {
		m_Messages[uid] = vector<Message>();
		m_Messages[uid].push_back(message);
	}

	this->setItem(uid, 1, QPixmap(), "name", "message", "time", true);

}
void MainUiController::setItem(string id, int newMessageNum, 
	QPixmap pic, string name, string message, string time, bool mute) {
	if (m_ID2Item.left.find(id) == m_ID2Item.left.end()) {
		newItemInsert(id,newMessageNum, pic, name, message, time, mute);
	}
	else {
		updateItem(id, newMessageNum, pic, name, message, time, mute);
	}
}
bool MainUiController::newItemInsert(string id,int newMessageNum,
	QPixmap pic, string name, string message, string time, bool mute) {
	
	QListWidgetItem* item = new QListWidgetItem();
	
	Widget_ChatItem_Controller* item_widget = new Widget_ChatItem_Controller();

	item_widget->setContent(newMessageNum, pic, name, message, time, mute);
	

	ui_ChatList.listWidget_ChatList->insertItem(1, item);
	
	ui_ChatList.listWidget_ChatList->setItemWidget(item, item_widget);
	m_ID2Item.left.insert({ id, item });
	return true;
}

bool MainUiController::updateItem(string id, int newMessageNum,
	QPixmap pic, string name, string message, string time, bool mute) {
	
	QListWidgetItem* item = m_ID2Item.left.at(id);
	Widget_ChatItem_Controller* item_widget = 
		qobject_cast<Widget_ChatItem_Controller*>(ui_ChatList.listWidget_ChatList->itemWidget(item));
	item_widget->setContent(newMessageNum, pic, name, message, time, mute);
	return 1;
}
bool MainUiController::removeItem(string id) {
	QListWidgetItem* item = m_ID2Item.left.at(id);
	int row = ui_ChatList.listWidget_ChatList->row(item);
	ui_ChatList.listWidget_ChatList->takeItem(row);
	delete item;
	return true;
}
void MainUiController::slot_SelectChanged() {
	QListWidgetItem* item =	ui_ChatList.listWidget_ChatList->currentItem();
	string id = m_ID2Item.right.at(item);
	vector<Message> m = m_Messages.at(id);
	setMessage(m);
	
}
void MainUiController::setMessage(vector<Message> m) {
	for (int i = 0; i < m.size(); i++) {
		ui_MessageShow.textEdit_Show->append(m[i].to_String().c_str());
	}
}
void MainUiController::slot_SendMessageClick() {

}
void MainUiController::slot_SendMessageEnterClick() {

}
void MainUiController::slot_EmojiClick() {

}
void MainUiController::slot_FileClick() {

}
void MainUiController::slot_AddClick() {
	QMessageBox::information(0, "add click", "not yet");
}