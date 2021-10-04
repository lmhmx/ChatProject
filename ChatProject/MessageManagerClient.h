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
	// 向下级发送的总接口
	void sendMessage(Message m);
	// 从下级获得信息的接口
	void slotNewMessage(string m);

public:

	void actionToLogInMessage(Message m);
	void actionToRegisterMessage(Message m);
	void actionToMessageMessage(Message m);

signals:
	void signal_LogInSucceed(bool succeed);
	void signal_RegisterSucceed(bool succeed);
	// 对上级提供的发送
	void signal_NewMessage(Message message);

private:
	NetManagerClient* m_NetManagerClient;
	User m_User;
	string m_OnlineCertificate;
};

