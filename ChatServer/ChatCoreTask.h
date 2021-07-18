#pragma once
# include "NetManager.h"
# include "UserManager.h"
# include "DatabaseManager.h"
# include <qdebug.h>
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
	void slotNewMessageFromUser(User* sender, string& message);
	

private:
	UserManager* m_UserManager;
	
};
