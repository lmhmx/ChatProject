# include "NetManagerClient.h"
# include <algorithm>
using namespace std;
NetManagerClient::NetManagerClient() {
	init();
	
}
void NetManagerClient::init() {
	m_MAX_MESSAGE_LENGTH = 10240;
	m_Socket = new QTcpSocket(this);
	
	
	m_ServerAddress.setAddress("127.0.0.1");
	m_ServerPort = 9527;
	m_Socket->connectToHost(m_ServerAddress, m_ServerPort);
	
	m_ConnectToServerTimer = new QTimer(this);
	connect(m_Socket, &QTcpSocket::readyRead, this, &NetManagerClient::slotReceiveMessage);
	connect(m_ConnectToServerTimer, &QTimer::timeout, this, &NetManagerClient::slotTryToConnectToServer);
	m_ConnectToServerTimer->start(1000);
}


void NetManagerClient::slotReceiveMessage() {
	char* message = new char[m_MAX_MESSAGE_LENGTH] {'\0'};
	m_Socket->read(message, m_MAX_MESSAGE_LENGTH);
	string message_str = message;
	qDebug() <<"NetManagerClient::slotReceiveMessage: "<< message;
	emit signalReceiveMessage(message_str);
}
void NetManagerClient::slotSendMessage(const string m) {
	
	if (m_Socket->state() == QAbstractSocket::SocketState::ConnectedState) {
		QByteArray t = QByteArray::fromStdString(m);
		qDebug() <<"NetManagerClient::slotSendMessage: "<< t;
		m_Socket->write(t);
	}
	else {
		qDebug() << "net not connect";
	}
}
void NetManagerClient::slotTryToConnectToServer() {
	if (m_Socket->state() != QAbstractSocket::ConnectedState) {
		qDebug() << "try to connect to host: "
			<< " address "  << m_ServerAddress
			<<" port " << m_ServerPort;
		m_Socket->connectToHost(m_ServerAddress, m_ServerPort);
	}

}
QAbstractSocket::SocketState NetManagerClient::currentNetworkState() {
	return m_Socket->state();
}