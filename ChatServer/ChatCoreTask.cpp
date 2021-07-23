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

void ChatCoreTask::slotNewMessageFromUser(Message message, QTcpSocket* socket) {

	qDebug() << QString::fromStdString(message.to_String());
	switch (message.m_MessageType)
	{
	case MessageType::MessageType::LOGIN: {
		replyToLogIn(message,socket);
		break;
	}
	case MessageType::MessageType::REGISTER: {
		replyToRegister(message,socket);
		break;
	}
	case MessageType::MessageType::MESSAGE: {
		replyToMessage(message,socket);
		break;
	}
	default:
		break;
	}

}
void ChatCoreTask::replyToLogIn(Message& message, QTcpSocket* socket) {
	if (message.m_MessageType == MessageType::MessageType::LOGIN) {
		
	}
	else {
		qDebug() << "there is an error in dealing with reply log in ";
	}
}
void ChatCoreTask::replyToRegister(Message& message, QTcpSocket* socket) {
	if (message.m_MessageType == MessageType::MessageType::REGISTER) {
		string way = message.m_MessageContent.m_Content["REGISTERWAY"];
		if (way == "MAIL") {
			string mail = message.m_MessageContent.m_Content["MAIL"];
			string pwd = message.m_MessageContent.m_Content["PASSWORD"];
			bool query_succeed = m_SuperRegister->queryRegisterAUser(mail, pwd, way);

			if (query_succeed) {
				User* registeruser = m_SuperRegister->doRegisterAUser(mail, pwd, way);
				if (registeruser!=nullptr) {
					Message reply;
					time_t t = time(0);
					char timebuffer[128];
					m_UserManager->updateSocketToUserSocket(socket, registeruser);
					strftime( timebuffer,128, "%Y-%m-%d %H:%M:%s", localtime(&t));
					reply.m_MessageTime = timebuffer;
					reply.m_MessageReceiver = registeruser->m_UserID;
					reply.m_MessageSender = m_SuperRegister->m_UserID;
					reply.m_MessageType = MessageType::MessageType::REGISTER;
					reply.m_MessageContent.m_MessageContentType = MessageContentType::MessageContentType::REGISTER_reply;
					reply.m_MessageContent.m_Content["REGISTER_USER_ID"] = registeruser->m_UserID;
					m_UserManager->sendMessageToUser(registeruser, reply.to_String());
					return ;
				}
			}
		}
		else if(way == "PHONE"){
			
		}

	}
	else {
		qDebug() << "there is an error in dealing with reply register ";
	}
}
void ChatCoreTask::replyToMessage(Message& message, QTcpSocket* socket) {
	if (message.m_MessageType == MessageType::MessageType::MESSAGE) {

	}
	else {
		qDebug() << "there is an error in dealing with reply message ";
	}

}