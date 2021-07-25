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
	*  负责收到消息后的各种操作
	*  1. 解析message
	*  2. 针对解析结果进行决策，例如
	*     * 调用发送接口，对消息进行转发
	*     * 对消息进行静默处理（什么都不做）
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
