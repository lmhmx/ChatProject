#pragma once
# include "MessageHeader.h"
# include "Common.h"
# include <string>
# include <map>
using namespace std;
class MessageContent
{
public:
	static string to_String(MessageContent m);
	static MessageContent to_MessageContent(string s);

public:
	MessageContent();
	MessageContent(const MessageContent& m);
	const MessageContent& operator=(const MessageContent& m);

	string to_String();
	void copyFromMessageContent(string s);

private:
	void copy(const MessageContent& m);

public:
	static string map2Str(map<string, string> m);
	static map<string, string> str2Map(string s);
private:

public:
	MessageContentType::MessageContentType m_MessageContentType;
	map<string,string> m_Content;

private:
	static const char m_Seperator;

};

