#pragma once
# include "NetManager.h"
# include "UserManager.h"
# include "DatabaseManager.h"
# include <qdebug.h>
# include "SuperUserLogIn.h"
# include "SuperUserRegister.h"
class ChatCoreTask:public QObject {
	Q_OBJECT
public:
	ChatCoreTask();
	void init();

private:
	/**
	*  �����յ���Ϣ��ĸ��ֲ���
	*  1. ����message
	*  2. ��Խ���������о��ߣ�����
	*     * ���÷��ͽӿڣ�����Ϣ����ת��
	*     * ����Ϣ���о�Ĭ����ʲô��������
	*/
	void slotNewMessageFromUser(Message message, QTcpSocket* socket);
	
private:
	void replyToLogIn(Message& message, QTcpSocket* socket);
	void replyToRegister(Message& message, QTcpSocket* socket);
	void replyToMessage(Message& message, QTcpSocket* socket);

private:
	string generateNewCertifacate();
	bool checkUserCertifacate(string uid, string certifacate);
	void addUserCertifacate(string uid, string certifacate);
	void removeCertifacate(string uid, string certifacate);

public:
	map<string, string> m_Info;


private:
	SuperUserLogIn* m_SuperLogIn;
	SuperUserRegister* m_SuperRegister;

private:
	UserManager* m_UserManager;
	map<string, string> m_CertifacatesForUid;
};
