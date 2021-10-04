#pragma once
# include <qobject.h>
# include <string>
# include "Share.h"
# include "MessageManagerClient.h"
class MessageProcessCore:public QObject
{
	Q_OBJECT
public:
	MessageProcessCore(QObject* parent = Q_NULLPTR);

public:
	// ���¼����͵��ܽӿ�
	void sendMessage(Message m);
	// ���¼������Ϣ�Ľӿ�
	void slotNewMessage(Message m);


public:

	void actionToLogInMessage(Message m);
	void actionToRegisterMessage(Message m);
	void actionToMessageMessage(Message m);

signals:
	void signal_LogInSucceed(bool succeed);
signals:
	void signal_RegisterSucceed(bool succeed);
	// ���ϼ��ṩ�ķ���
signals:
	void signal_NewMessage(Message message);


private:
	MessageManagerClient* m_MessageManagerClient;
	User m_User;
	string m_OnlineCertificate;
};

