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
	*  负责收到消息后的各种操作
	*  1. 解析message
	*  2. 针对解析结果进行决策，例如
	*     * 调用发送接口，对消息进行转发
	*     * 对消息进行静默处理（什么都不做）
	*/
	void slotNewMessageFromUser(User* sender, string& message);
	

private:
	UserManager* m_UserManager;
	
};
