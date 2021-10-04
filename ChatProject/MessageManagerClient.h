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

public:

	void actionToLogInMessage(Message m);
	void actionToRegisterMessage(Message m);
	void actionToMessageMessage(Message m);

signals:
	void signal_LogInSucceed(bool succeed);
	void signal_RegisterSucceed(bool succeed);
	// ���ϼ��ṩ�ķ���
	void signal_NewMessage(Message message);

private:
	NetManagerClient* m_NetManagerClient;
	User m_User;
	string m_OnlineCertificate;
};

