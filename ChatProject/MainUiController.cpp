#include "MainUiController.h"
MainUiController::MainUiController( QWidget* parent):QWidget(parent) {
	ui_main.setupUi(this);
	m_ChatList_Controller = new Widget_ChatList_Controller(ui_main.widget_ChatList);

	m_MessageSend_Controller = new Widget_MessageSend_Controller(ui_main.widget_MessageSend);

	m_MessageShow_Controller = new Widget_MessageShow_Controller(ui_main.widget_MessageShow);

	
	
	connect(m_ChatList_Controller, &Widget_ChatList_Controller::signal_itemSelectionChanged,
		this, &MainUiController::slot_SelectChanged);
	connect(ui_main.pushButton_Add, &QPushButton::clicked,
		this, &MainUiController::slot_SearchClicked);
	connect(m_MessageSend_Controller, &Widget_MessageSend_Controller::signal_SendMessage,
		this, &MainUiController::slot_SendMessage);
}
void MainUiController::slot_SendMessage(string message_text) {

}
void MainUiController::slot_SearchClicked() {
	Widget_SearchUiController* searchWindow = new  Widget_SearchUiController(this);
	connect(searchWindow, &Widget_SearchUiController::signal_searchFriend,
		[=](string id) {
			Message m;
			m.m_MessageType = MessageType::MessageType::COMMAND;
			m.m_MessageSender = m_currentUser.m_UserID;
			m.m_MessageContent.m_MessageContentType =
				MessageContentType::MessageContentType::COMMAND_searchUser_request;
			m.m_MessageContent.m_Content.insert({ "SEARCH_USER",id });
		});
	
}
void MainUiController::newMessage(Message message) {
	string uid = message.m_MessageSender;

	if (m_Messages.find(uid) == m_Messages.end()) {
		m_Messages[uid] = vector<Message>();
		m_Messages[uid].push_back(message);
	}

	this->m_ChatList_Controller->setItem(uid, 1, QPixmap(), "name", "message", "time", true);
	
}

//void MainUiController::slot_SendMessage(MessageContent m) {
//	Message message;
//	message.m_MessageContent = m;
//	message.m_MessageType = MessageType::MessageType::MESSAGE;
//	message.m_MessageReceiver = m_ChatList_Controller->currentSelectionID();
//	
//	emit signal_SendMessage(message);
//}
void MainUiController::slot_SelectChanged() {
	string id = m_ChatList_Controller->currentSelectionID();
	setCurrentChat(id);
	
}
void MainUiController::setCurrentChat(string id){
	vector<Message> m = m_Messages[id];
	
	m_MessageShow_Controller->setMessage(m);
	m_ChatList_Controller->setCurrentSelect(id);
}
