# include "ChatCoreTask.h"
ChatCoreTask::ChatCoreTask() {
	init();
}

void ChatCoreTask::init() {
	m_UserManager = new UserManager();

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

		message.m_MessageContent.m_Content;

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