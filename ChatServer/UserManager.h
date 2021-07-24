# pragma once
# include <vector>
# include <string>
# include <boost/bimap.hpp>
# include "User.h"
# include "Group.h"
# include "Message.h"
# include "NetManager.h"
using namespace std;
/** UserManager Class
* @brief 管理用户到IP地址的映射，负责发送消息和接收消息
* @author liming
* @version 1.0
* 
*/
class UserManager:public QObject {
	Q_OBJECT
public:
	UserManager();


public:



private:
	void init();


public:
	void sendMessageToUser(User receicer, string message);
	void sendMessageToSocket(QTcpSocket* socket, string message);

	void removeSocketFromUserSocket(QTcpSocket* socket);
	void updateSocketToUserSocket(QTcpSocket* socket, User user);

signals:
	// 
	void signalNewMessageFromUser(Message message, QTcpSocket* socket);
	


private:
	// slots
	// void slotNewConnection(QTcpSocket* socket);
	void slotDisconnect(QTcpSocket* socket);
	void slotNewMessage(QTcpSocket* socket, string s);

	

private:
	boost::bimap<User, QTcpSocket*> m_User2Socket;
	
	
	NetManager* m_NetManager;

private:
	// 在任务队列中需要发送的消息
	map<User, vector<string>> m_UserWillSendMessage;
	// 已经发送需要确认的消息
	map<User, vector<string>> m_UserConfirmingMessage;
};
