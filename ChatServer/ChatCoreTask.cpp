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
	bool succeed = false;
	if (message.m_MessageType == MessageType::MessageType::LOGIN) {
		string way = message.m_MessageContent.m_Content["LOGIN_WAY"];
		string phone_or_mail;

		if (way == "MAIL") {
			phone_or_mail = message.m_MessageContent.m_Content["MAIL"];
		}
		else if (way == "PHONE") {
			phone_or_mail = message.m_MessageContent.m_Content["PHONE"];
		}

		string pwd = message.m_MessageContent.m_Content["PASSWORD"];
		bool query_succeed = m_SuperLogIn->queryLoginAUser(phone_or_mail, pwd, way);

		if (query_succeed) {
			bool login_succeed = m_SuperLogIn->doLoginAUser(phone_or_mail, pwd, way);
			if (login_succeed) {
				User logInUser;
				string uid;
				if (way == "MAIL") {
					uid = m_SuperLogIn->getUidFromMail(phone_or_mail);
				}
				else if (way == "PHONE") {
					uid = m_SuperLogIn->getUidFromPhone(phone_or_mail);
				}
				logInUser = m_SuperLogIn->getUserFromUid(uid);
				Message reply;
				m_UserManager->updateSocketToUserSocket(socket,logInUser);
				reply.m_MessageTime = strftime("%Y-%m-%d %H:%M:%S", time(0));
				reply.m_MessageReceiver = logInUser.m_UserID;
				reply.m_MessageSender = m_SuperLogIn->m_UserID;
				reply.m_MessageType = MessageType::MessageType::LOGIN;
				reply.m_MessageContent.m_MessageContentType = MessageContentType::MessageContentType::LOGIN_reply;
				string certifacate = generateNewCertifacate();
				addUserCertifacate(logInUser.m_UserID, certifacate);
				reply.m_MessageContent.m_Content["CERTIFACATE"] = certifacate;
				reply.m_MessageContent.m_Content["LOGIN_RESULT"] = "SUCCEED";
				reply.m_MessageContent.m_Content["LOG_IN_USER_ID"] = logInUser.m_UserID;
				
				m_UserManager->sendMessageToUser(logInUser, reply.to_String());
				succeed = true;
				return;
			}
		}
	}
	if (!succeed) {
		// 失败了，返回失败信息
		Message reply;
		reply.m_MessageTime = strftime("%Y-%m-%d %H:%M:%S", time(0));
		reply.m_MessageReceiver = "";
		reply.m_MessageSender = m_SuperLogIn->m_UserID;
		reply.m_MessageType = MessageType::MessageType::LOGIN;
		reply.m_MessageContent.m_MessageContentType = MessageContentType::MessageContentType::LOGIN_reply;
		reply.m_MessageContent.m_Content["LOGIN_RESULT"] = "FAILED";
		m_UserManager->sendMessageToSocket(socket, reply.to_String());
		return;
	}
}
void ChatCoreTask::replyToRegister(Message& message, QTcpSocket* socket) {
	bool succeed = false;
	if (message.m_MessageType == MessageType::MessageType::REGISTER) {
		string way = message.m_MessageContent.m_Content["REGISTER_WAY"];
		string phone_or_mail;

		if (way == "MAIL") {
			phone_or_mail = message.m_MessageContent.m_Content["MAIL"];
		}
		else if (way == "PHONE") {
			phone_or_mail = message.m_MessageContent.m_Content["PHONE"];
		}
		
		string pwd = message.m_MessageContent.m_Content["PASSWORD"];
		bool query_succeed = m_SuperRegister->queryRegisterAUser(phone_or_mail, pwd, way);

		if (query_succeed) {
			User registeruser = m_SuperRegister->doRegisterAUser(phone_or_mail, pwd, way);
			if (registeruser != User::UserDefault) {
				Message reply;
				m_UserManager->updateSocketToUserSocket(socket, registeruser);
				reply.m_MessageTime = strftime("%Y-%m-%d %H:%M:%S",time(0));
				reply.m_MessageReceiver = registeruser.m_UserID;
				reply.m_MessageSender = m_SuperRegister->m_UserID;
				reply.m_MessageType = MessageType::MessageType::REGISTER;
				reply.m_MessageContent.m_MessageContentType = MessageContentType::MessageContentType::REGISTER_reply;
				string certifacate = generateNewCertifacate();
				addUserCertifacate(registeruser.m_UserID, certifacate);
				reply.m_MessageContent.m_Content["CERTIFACATE"] = certifacate;
				reply.m_MessageContent.m_Content["REGISTER_RESULT"] = "SUCCEED";
				reply.m_MessageContent.m_Content["REGISTER_USER_ID"] = registeruser.m_UserID;
				m_UserManager->sendMessageToUser(registeruser, reply.to_String());
				succeed = true;
				return;
			}
		}
	}
	if (!succeed) {
		// 失败了，返回失败信息
		Message reply;
		reply.m_MessageTime = strftime("%Y-%m-%d %H:%M:%S", time(0));
		reply.m_MessageReceiver = "";
		reply.m_MessageSender = m_SuperRegister->m_UserID;
		reply.m_MessageType = MessageType::MessageType::REGISTER;
		reply.m_MessageContent.m_MessageContentType = MessageContentType::MessageContentType::REGISTER_reply;
		reply.m_MessageContent.m_Content["REGISTER_RESULT"] = "FAILED";
		m_UserManager->sendMessageToSocket(socket, reply.to_String());
		return;
	}
}

string ChatCoreTask::generateNewCertifacate() {
	string certifacate;
	int N = 20;
	vector<char> v;
	for (char c = 'a'; c <= 'z'; c++) {
		v.push_back(c);
	}
	for (int i = 0; i < N; i++) {
		certifacate.push_back(getRandomFromVector(v));
	}
	return certifacate;
}
bool ChatCoreTask::checkUserCertifacate(string uid, string certifacate) {
	if (m_CertifacatesForUid.find(uid) == m_CertifacatesForUid.end()) {
		return false;
	}
	else {
		return true;
	}
}
void ChatCoreTask::addUserCertifacate(string uid, string certifacate) {
	m_CertifacatesForUid[uid] = certifacate;
}
void ChatCoreTask::removeCertifacate(string uid, string certifacate) {
	auto iter = m_CertifacatesForUid.find(uid);
	if (iter != m_CertifacatesForUid.end()) {
		m_CertifacatesForUid.erase(iter);
	}
}
void ChatCoreTask::replyToMessage(Message& message, QTcpSocket* socket) {
	if (message.m_MessageType == MessageType::MessageType::MESSAGE) {

	}
	else {
		qDebug() << "there is an error in dealing with reply message ";
	}

}
