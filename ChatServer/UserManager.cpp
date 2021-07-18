# include "UserManager.h"
using namespace std;
UserManager::UserManager() {
	init();
}
void UserManager::init() {
	m_NetManager = new NetManager();
	connect(m_NetManager, &NetManager::signalNewConnection, this, &UserManager::slotNewConnection);
	connect(m_NetManager, &NetManager::signalDisconnected, this, &UserManager::slotDisconnect);

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
void UserManager::slotNewConnection(QTcpSocket* socket) {
	User* user = new User();
	user->init();

	m_User2Socket.insert(boost::bimap<User*, QTcpSocket*>::value_type(user, socket));
	DatabaseManager::addToTmpUser(user);
}
void UserManager::slotNewMessage(QTcpSocket* socket, string& message) {
	
	auto socket_user =  m_User2Socket.right.find(socket);
	if (socket_user == m_User2Socket.right.end()) {
		qDebug() << "invalid socket";// 意味着出bug了，没有查到IP对应的用户
	}
	else {
		Message m = Message::to_Message(message);
		User* sender = DatabaseManager::getUserFromUid(m.m_MessageSender);
		
		emit signalNewMessageFromUser(sender, message);

		// 如果消息类型是重新登录类型，更新User和socket之间的对应关系  
		// 消息中包含了User 的信息  

		// socket_user->first;

		// 如果消息类型是消息类型，将消息交给上级进行处理
		// 
		
		
		// 如果消息类型是注册类型，向上级提交注册类型信息
		// 
		// 
		// 如果消息类型是登录类型，将消息交给上级



		
	}
}
void UserManager::sendMessageToUser(User* receiver, string& message) {
	auto user_socket = m_User2Socket.left.find(receiver);
	user_socket->second->write(QByteArray::fromStdString(message));
}
