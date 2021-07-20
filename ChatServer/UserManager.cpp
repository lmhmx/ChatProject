# include "UserManager.h"
using namespace std;
UserManager::UserManager() {
	init();
}
void UserManager::init() {
	m_NetManager = new NetManager();
	connect(m_NetManager, &NetManager::signalDisconnected, this, &UserManager::slotDisconnect);
	connect(m_NetManager, &NetManager::signalReceiveMessage, this, &UserManager::slotNewMessage);
}

void UserManager::slotDisconnect(QTcpSocket* socket) {
	if (socket == nullptr) {
		// do nothing
	}
	else {
		auto iter = m_User2Socket.right.find(socket);
		m_User2Socket.right.erase(iter); 
	}
}

void UserManager::removeSocketFromUserSocket(QTcpSocket* socket) {
	auto iter = m_User2Socket.right.find(socket);
	m_User2Socket.right.erase(iter);
}
void UserManager::addSocketToUserSocket(QTcpSocket* socket, User* user) {
	m_User2Socket.left.insert(pair <User*, QTcpSocket* >(user, socket));
}
void UserManager::slotNewMessage(QTcpSocket* socket, string message) {
	
	auto socket_user =  m_User2Socket.right.find(socket);
	if (socket_user == m_User2Socket.right.end()) {
		qDebug() << "invalid socket";// 意味着出bug了，没有查到IP对应的用户
	}
	else {
		Message m = Message::to_Message(message);
		User* sender = DatabaseManager::getUserFromUid(m.m_MessageSender);
		
		emit signalNewMessageFromUser(sender, m);
	}
}
void UserManager::sendMessageToUser(User* receiver, string message) {
	auto user_socket = m_User2Socket.left.find(receiver);
	user_socket->second->write(QByteArray::fromStdString(message));
}
