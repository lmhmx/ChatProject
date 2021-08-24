#include "MainUiController.h"
MainUiController::MainUiController(QWidget* parent):QWidget(parent) {
	
	ui_main.setupUi(this);
	m_ChatList_Controller = new Widget_ChatList_Controller(ui_main.widget_ChatList);

	m_MessageSend_Controller = new Widget_MessageSend_Controller(ui_main.widget_MessageSend);

	m_MessageShow_Controller = new Widget_MessageShow_Controller(ui_main.widget_MessageShow);

	
	connect(m_ChatList_Controller, &Widget_ChatList_Controller::signal_itemSelectionChanged,
		this, &MainUiController::slot_SelectChanged);
}

void MainUiController::newMessage(Message message) {
	string uid = message.m_MessageSender;

	if (m_Messages.find(uid) == m_Messages.end()) {
		m_Messages[uid] = vector<Message>();
		m_Messages[uid].push_back(message);
	}

	this->m_ChatList_Controller->setItem(uid, 1, QPixmap(), "name", "message", "time", true);
	
}
void MainUiController::slot_SelectChanged() {
	string id = m_ChatList_Controller->currentSelectionID();
	setCurrentChat(id);
	
}
void MainUiController::setCurrentChat(string id){
	vector<Message> m = m_Messages[id];
	for (int i = 0; i < m.size(); i++) {

		;
	}
	m_ChatList_Controller->setCurrentSelect(id);
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