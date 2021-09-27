#pragma once
#include <string>

// 消息类型
using namespace std;
namespace MessageType {
	enum class MessageType {
		// 
		LOGIN,
		MESSAGE,
		COMMAND,
		REGISTER

	};
	string to_String(MessageType m);
	MessageType FromString(string s);
}
namespace MessageContentType {
	enum class MessageContentType {
		MESSAGE_text,
		MESSAGE_picture,
		MESSAGE_file,
		MESSAGE_bigPicture,
		MESSAGE_bigFile,
		MESSAGE_addFriend,

		COMMAND_searchUser_request,
		COMMAND_searchUser_reply,


		LOGIN_request,
		LOGIN_reply,
		REGISTER_request,
		REGISTER_reply
	};
	string to_String(MessageContentType m);
	MessageContentType FromString(string s);
}