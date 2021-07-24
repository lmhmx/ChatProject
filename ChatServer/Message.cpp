# include "Message.h"

using namespace std;
const char Message::m_Seperator = '&';

Message::Message() {
	exit(0);
	system("pause");
	this->m_MessageType = MessageType::MessageType::MESSAGE;
}
Message::Message(const Message& m) {
	this->m_MessageContent = m.m_MessageContent;
	this->m_MessageReceiver = m.m_MessageReceiver;
	this->m_MessageSender = m.m_MessageSender;
	this->m_MessageTime = m.m_MessageTime;
	this->m_MessageType = m.m_MessageType;
}
const Message& Message::operator=(const Message& m) {
	this->m_MessageContent = m.m_MessageContent;
	this->m_MessageReceiver = m.m_MessageReceiver;
	this->m_MessageSender = m.m_MessageSender;
	this->m_MessageTime = m.m_MessageTime;
	this->m_MessageType = m.m_MessageType;
	return *this;
}
string Message::to_String(Message m) {
	return m.to_String();
}
Message Message::to_Message(string s) {
	Message m;
	m.copyFromMessage(s);
	return m;
}


string Message::to_String() {
	string sep_str = "";
	sep_str.push_back(m_Seperator);
	sep_str.push_back(m_Seperator);

	// 加类型符
	string s;
	s.append(MessageType::to_String(m_MessageType));
	s.append(sep_str);
	

	// 加发送者
	s.append(m_MessageSender);
	s.append(sep_str);

	// 加接收者
	s.append(m_MessageReceiver);
	s.append(sep_str);

	// 加时间
	s.append(m_MessageTime);
	s.append(sep_str);

	// 加内容
	s.append(addEscapeCharacter(m_MessageContent.to_String(), m_Seperator));
	s.append(sep_str);
	return s;
	
}
void Message::copyFromMessage(string s) {
	string sep_str = "";
	sep_str.push_back(m_Seperator);
	sep_str.push_back(m_Seperator);

	vector<string> v_s = split(s, sep_str);

	if (v_s.size() == 5) {
		m_MessageType = MessageType::FromString(v_s[0]);
		m_MessageSender = v_s[1];
		m_MessageReceiver = v_s[2];
		m_MessageTime = v_s[3];
		string content_str = deleteEscapeCharacter(v_s[4], m_Seperator);
		m_MessageContent = MessageContent::to_MessageContent(content_str);
		
	}
	else {
		throw "input string " + s + " is illegal";
	}
}