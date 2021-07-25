#pragma once
# include <qtcpsocket.h>

# include <qdebug.h>
# include <string>
# include <vector>
# include <algorithm>
# include <qtimer.h>
# include <qhostaddress.h>
using namespace std;
class NetManagerClient :public QObject {
	Q_OBJECT

public:
	NetManagerClient();
	void init();

public:
	// vector<QTcpSocket*>& getClient();


public:
	// Slots
	void slotReceiveMessage();
	void slotTryToConnectToServer();
	void slotSendMessage(const string& m);

signals:
	void signalReceiveMessage(string& s);
signals:
	void signalDisconnected(QTcpSocket* socket);


private:
	QTcpSocket* m_Socket;
	QTimer* m_ConnectToServerTimer;
	
	QHostAddress m_ServerAddress;
	int m_ServerPort;
private:
	long m_MAX_MESSAGE_LENGTH;
};