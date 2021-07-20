#pragma once
# include <qtcpsocket.h>
# include <qtcpserver.h>
# include <qdebug.h>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;
class NetManager:public QObject{
	Q_OBJECT

public:
	NetManager();
	void init();
	
public:
	// vector<QTcpSocket*>& getClient();
	

public:
	// Slots
	void slotNewConnection();
	void slotdisconnected();
	void slotReceiveMessage();
signals:
	void signalReceiveMessage(QTcpSocket* socket, string s);
signals:
	void signalDisconnected(QTcpSocket* socket);
//signals:
//	void signalNewConnection(QTcpSocket* socket);


private:
	QTcpServer* m_Server;
	vector<QTcpSocket*> m_Clients;

private:
	long m_MAX_MESSAGE_LENGTH;
};