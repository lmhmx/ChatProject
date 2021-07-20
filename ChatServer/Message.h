#pragma once
# include <string>
# include <vector>
# include "MessageHeader.h"
# include "MessageContent.h"
# include "Common.h"
using namespace std;
class Message {
public:
	static string to_String(Message m);
	static Message to_Message(string s);

public:
	Message();
	Message(const Message& m);
	const Message& operator=(const Message& m);
	string to_String();
	void copyFromMessage(string s);

private:

private:

public:
	MessageType::MessageType m_MessageType;
	// 将消息以字节的方式存储
	MessageContent m_MessageContent;
	string m_MessageTime;
	string m_MessageReceiver;
	string m_MessageSender;

private:
	static const char m_Seperator;
};