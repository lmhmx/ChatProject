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
	void slotNewMessageFromUser(User* sender, Message message);
	
private:
	void replyToLogIn(Message& message);
	void replyToRegister(Message& message);
	void replyToMessage(Message& message);


private:
	SuperUserLogIn* m_SuperLogIn;
	SuperUserRegister* m_SuperRegister;

private:
	UserManager* m_UserManager;
	
};
