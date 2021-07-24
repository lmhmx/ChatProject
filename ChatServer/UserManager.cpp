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
	if (iter != m_User2Socket.right.end()) {
		m_User2Socket.right.erase(iter);
	}
	else {
		qDebug() << "invalid socket";
	}
}
void UserManager::updateSocketToUserSocket(QTcpSocket* socket, User user) {
	m_User2Socket.left.insert({ user,socket });
	
}
void UserManager::slotNewMessage(QTcpSocket* socket, string message) {
	Message m = Message::to_Message(message);
	emit signalNewMessageFromUser(m, socket);
}
void UserManager::sendMessageToUser(User receiver, string message) {
	auto user_socket = m_User2Socket.left.find(receiver);
	if (user_socket != m_User2Socket.left.end()) {
		user_socket->second->write(QByteArray::fromStdString(message));
	}
	else {
		qDebug() << "invalid user";
	}
}
