# include "ChatCoreTask.h"
ChatCoreTask::ChatCoreTask() {
	init();
}

void ChatCoreTask::init() {
	m_UserManager = new UserManager();
	m_SuperLogIn = new SuperUserLogIn();
	m_SuperRegister = new SuperUserRegister();
	connect(m_UserManager, &UserManager::signalNewMessageFromUser, this, &ChatCoreTask::slotNewMessageFromUser);


}

void ChatCoreTask::slotNewMessageFromUser(User* sender, Message message) {

	qDebug() << QString::fromStdString(message.to_String());
	switch (message.m_MessageType)
	{
	case MessageType::MessageType::LOGIN: {
		replyToLogIn(message);
		break;
	}
	case MessageType::MessageType::REGISTER: {
		replyToRegister(message);
		break;
	}
	case MessageType::MessageType::MESSAGE: {
		replyToMessage(message);
		break;
	}
	default:
		break;
	}

}
void ChatCoreTask::replyToLogIn(Message& message) {
	if (message.m_MessageType == MessageType::MessageType::LOGIN) {
		
	}
	else {
		qDebug() << "there is an error in dealing with reply log in ";
	}
}
void ChatCoreTask::replyToRegister(Message& message) {
	if (message.m_MessageType == MessageType::MessageType::REGISTER) {
		string way = message.m_MessageContent.m_Content["REGISTERWAY"];
		if (way == "MAIL") {
			string mail = message.m_MessageContent.m_Content["MAIL"];
			string pwd = message.m_MessageContent.m_Content["PASSWORD"];
			bool query_succeed = m_SuperRegister->queryRegisterAUser(mail, pwd, way);

			if (query_succeed) {
				bool do_succeed = m_SuperRegister->doRegisterAUser(mail, pwd, way);
				if (do_succeed) {
					Message reply;
					reply;
				}
			}
		}
		else if(way == "PHONE"){
			string phone = message.m_MessageContent.m_Content["PHONE"];
			string pwd = message.m_MessageContent.m_Content["PASSWORD"];
			DatabaseManager::queryRegisterAUser(phone, pwd, way);
		}

	}
	else {
		qDebug() << "there is an error in dealing with reply register ";
	}
}
void ChatCoreTask::replyToMessage(Message& message) {
	if (message.m_MessageType == MessageType::MessageType::MESSAGE) {

	}
	else {
		qDebug() << "there is an error in dealing with reply message ";
	}
}