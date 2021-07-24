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
void  UserManager::sendMessageToSocket(QTcpSocket* socket, string message) {
	socket->write(QByteArray::fromStdString(message));
}
void UserManager::slotDisconnect(QTcpSocket* socket) {
	if (socket == nullptr) {
		// do nothing
	}
	else {
		this->removeSocketFromUserSocket(socket);
	}
}

void UserManager::removeSocketFromUserSocket(QTcpSocket* socket) {
	auto iter = m_User2Socket.right.find(socket);
	m_User2Socket.right.erase(iter);
}
void UserManager::updateSocketToUserSocket(QTcpSocket* socket, User user) {
	if (m_User2Socket.right.count(socket) > 0) {
		m_User2Socket.right.insert({ socket, user});
	}
	else {
		m_User2Socket.left.insert({ user, socket });
	}
}
void UserManager::slotNewMessage(QTcpSocket* socket, string message) {
	
	auto socket_user =  m_User2Socket.right.find(socket);
	if (socket_user == m_User2Socket.right.end()) {
		qDebug() << "invalid socket";// 意味着出bug了，没有查到IP对应的用户
	}
	else {
		Message m = Message::to_Message(message);		
		emit signalNewMessageFromUser(m, socket);
	}
}
void UserManager::sendMessageToUser(User receiver, string message) {
	auto user_socket = m_User2Socket.left.find(receiver);
	user_socket->second->write(QByteArray::fromStdString(message));
}
