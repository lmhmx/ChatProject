#pragma once
#include <string>

// ��Ϣ����
using namespace std;
namespace UserType {
	enum class UserType {
		// 
		TmpUser,
		NormalUser,
		DefaultUser
	};
	string to_String(UserType m);
	UserType FromString(string s);
}