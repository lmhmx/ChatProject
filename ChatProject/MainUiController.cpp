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
	map<string, string> message;
	message.insert({ "TYPE","MESSAGE_TEXT" });
	message.insert({"MESSAGE_TEXT",message_text});
	message.insert({ "MESSAGE_RECEIVER",m_ChatList_Controller->currentSelectionID() });
	emit signal_SendMessage(message);
}
void MainUiController::slot_SearchClicked() {
	Widget_SearchUiController* searchWindow = new  Widget_SearchUiController(this);
	connect(searchWindow, &Widget_SearchUiController::signal_searchFriend,
		[=](string id) {
			map<string, string> message;
			message.insert({ "TYPE","COMMAND" });
			message.insert({ "COMMAND","SEARCH" });
			message.insert({ "SEARCH_ID",id });
			emit signal_SendMessage(message);
		});
	
}
void MainUiController::newMessage(map<string,string> message) {
	string message_type = message["TYPE"];
	// 可能的类型
	// MESSAGE_TEXT  包含 RECEIVER、MESSAGE_TEXT
	// COMMAND       包含 SEARCH_RESULT,SEARCH_RESULT 含有 YOUR_NAME,ID,NAME
	// ... 

	if (message_type == "MESSAGE_TEXT") {
		
	}
	else if(message_type == "SEARCH_RESULT"){

	}
	else {
		qDebug() << "error happened in mainui and chatappclient, the message format is wrong";
	}

	// this->m_ChatList_Controller->setItem(uid, 1, QPixmap(), "name", "message", "time", true);
	
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
