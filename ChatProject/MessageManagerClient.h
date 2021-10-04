#pragma once
# include <qobject.h>
# include <string>
# include "Share.h"
# include "NetManagerClient.h"
using namespace std;
class MessageManagerClient:public QObject
{
	Q_OBJECT
public:
	MessageManagerClient(QObject* parent = Q_NULLPTR);

public:
	// ���¼����͵��ܽӿ�
	void sendMessage(Message m);
	// ���¼������Ϣ�Ľӿ�
	void slotNewMessage(string m);

signals:
	void signal_NewMessage(Message message);

private:
	NetManagerClient* m_NetManagerClient;
};

