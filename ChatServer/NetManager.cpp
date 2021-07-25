# include "NetManager.h"
# include <algorithm>
using namespace std;
NetManager::NetManager() {
	init();
	
}
void NetManager::init() {
	m_MAX_MESSAGE_LENGTH = 10240;
	m_Server = new QTcpServer();
	m_Server->listen(QHostAddress::Any, 9527);
	connect(m_Server, &QTcpServer::newConnection, this, &NetManager::slotNewConnection);
	qDebug() << "NetManager:" << "init:" << "ok";
	
}

void NetManager::slotNewConnection() {
	QTcpSocket* socket = m_Server->nextPendingConnection();
	connect(socket, &QTcpSocket::disconnected, this, &NetManager::slotdisconnected);
	connect(socket, &QTcpSocket::readyRead, this, &NetManager::slotReceiveMessage);
	m_Clients.push_back(socket);
	qDebug() <<"NetManager info:" <<"slotNewConnection info:" 
		<<"sokcet address:"<<socket->localAddress()
		<< "socket port" <<socket->localPort();
}
void NetManager::slotReceiveMessage() {
	char* message = new char[m_MAX_MESSAGE_LENGTH] {'\0'};
	QTcpSocket* socketsender = qobject_cast<QTcpSocket*> (sender());

	socketsender->read(message, m_MAX_MESSAGE_LENGTH);
	string message_str = message;
	qDebug() << "NetManager:" << "slotdisconnected:"
		<< "sokcet address:" << socketsender->localAddress()
		<< "socket port:" << socketsender->localPort()
		<< "socket message" << message;
	emit signalReceiveMessage(socketsender, message_str);
	

}

void NetManager::slotdisconnected() {
	QTcpSocket* socketsender = qobject_cast<QTcpSocket*> (sender());
	auto s = remove(m_Clients.begin(), m_Clients.end(), socketsender);

	emit signalDisconnected(socketsender);
	qDebug() << "NetManager:" << "slotdisconnected:"
		<< "sokcet address:" << socketsender->localAddress()
		<< "socket port:" << socketsender->localPort();

	(*s)->deleteLater();

}