#pragma once
# include "MessageContent.h"
# include <string>

using namespace std;
const char MessageContent::m_Seperator = '&';

string MessageContent::to_String(MessageContent m) {
	return m.to_String();
	
}
MessageContent::MessageContent() {
	m_MessageContentType = MessageContentType::MessageContentType::MESSAGE_text;
	m_Content = this->str2Map("");
}
void MessageContent::copy(const MessageContent& m) {
	m_Content = m.m_Content;
	m_MessageContentType = m.m_MessageContentType;
}
MessageContent::MessageContent(const MessageContent& m) {
	m_Content = m.m_Content;
	m_MessageContentType = m.m_MessageContentType;
}
const MessageContent& MessageContent::operator=(const MessageContent& m) {
	copy(m);
	return *this;
}

MessageContent MessageContent::to_MessageContent(string s) {
	MessageContent m;
	m.copyFromMessageContent(s);
	return m;
}

string MessageContent::to_String() {
	string s;
	s.append(MessageContentType::to_String(m_MessageContentType));
	s.push_back(m_Seperator);
	s.push_back(m_Seperator);
	string t = addEscapeCharacter(this->map2Str(m_Content), m_Seperator);
	s.append(t);
	s.push_back(m_Seperator);
	s.push_back(m_Seperator);
	return s;
}
void MessageContent::copyFromMessageContent(string s) {
	string sep_str = "";
	sep_str.push_back(m_Seperator);
	sep_str.push_back(m_Seperator);

	vector<string> v_s = split(s,sep_str);

	if (v_s.size() == 2) {
		m_MessageContentType = MessageContentType::FromString(v_s[0]);
		string content = deleteEscapeCharacter(v_s[1], m_Seperator);
		m_Content = this->str2Map(content);
	}
	else {
		throw "input string " + s + " is illegal";
	}
}
string MessageContent::map2Str(map<string, string> m) {
	string res;
	return res;
}
map<string, string> MessageContent::str2Map(string s) {
	map<string, string> res;
	return res;
}