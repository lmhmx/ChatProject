# include "MessageHeader.h"
#include <string>
# include <map>
// 消息类型
using namespace std;
namespace MessageType {
	string to_String(MessageType m) {
		map<MessageType, string> message2str;
		message2str[MessageType::LOGIN] = "LOGIN";
		message2str[MessageType::MESSAGE] = "MESSAGE";
		message2str[MessageType::REGISTER] = "REGISTER";
		return message2str[m];
	}

	MessageType FromString(string s)
	{
		map<string, MessageType> m;
		m["LONGIN"] = MessageType::LOGIN;
		m["MESSAGE"] = MessageType::MESSAGE;
		m["REGISTER"] = MessageType::REGISTER;
		return m[s];
	}
}
namespace MessageContentType {
	string to_String(MessageContentType m) {
		map<MessageContentType, string> message2str;
		message2str[MessageContentType::LOGIN_reply] = "LOGIN_reply";
		message2str[MessageContentType::LOGIN_request] = "LOGIN_reply";

		message2str[MessageContentType::MESSAGE_bigFile] = "LOGIN_reply";
		message2str[MessageContentType::MESSAGE_bigPicture] = "LOGIN_reply";
		message2str[MessageContentType::MESSAGE_file] = "LOGIN_reply";
		message2str[MessageContentType::MESSAGE_picture] = "LOGIN_reply";
		message2str[MessageContentType::MESSAGE_text] = "LOGIN_reply";

		return message2str[m];
	}
	MessageContentType FromString(string s) {
		map<string,MessageContentType> m;
		m["LOGIN_reply"] = MessageContentType::LOGIN_reply;
		m["LOGIN_request"] = MessageContentType::LOGIN_request;
		  
		m["MESSAGE_bigFile"] = MessageContentType::MESSAGE_bigFile;
		m["MESSAGE_bigPicture"] = MessageContentType::MESSAGE_bigFile;
		m["MESSAGE_file"] = MessageContentType::MESSAGE_file;
		m["MESSAGE_picture"] = MessageContentType::MESSAGE_picture;
		m["MESSAGE_text"] = MessageContentType::MESSAGE_text;
		
		return m[s];
	}
}
