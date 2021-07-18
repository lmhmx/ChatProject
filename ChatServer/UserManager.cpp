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
		qDebug() << "invalid socket";// ��ζ�ų�bug�ˣ�û�в鵽IP��Ӧ���û�
	}
	else {
		Message m = Message::to_Message(message);
		User* sender = DatabaseManager::getUserFromUid(m.m_MessageSender);
		
		emit signalNewMessageFromUser(sender, message);

		// �����Ϣ���������µ�¼���ͣ�����User��socket֮��Ķ�Ӧ��ϵ  
		// ��Ϣ�а�����User ����Ϣ  

		// socket_user->first;

		// �����Ϣ��������Ϣ���ͣ�����Ϣ�����ϼ����д���
		// 
		
		
		// �����Ϣ������ע�����ͣ����ϼ��ύע��������Ϣ
		// 
		// 
		// �����Ϣ�����ǵ�¼���ͣ�����Ϣ�����ϼ�



		
	}
}
void UserManager::sendMessageToUser(User* receiver, string& message) {
	auto user_socket = m_User2Socket.left.find(receiver);
	user_socket->second->write(QByteArray::fromStdString(message));
}
