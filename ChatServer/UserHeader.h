#pragma once
#include <string>

// ��Ϣ����
using namespace std;
namespace UserType {
	enum class UserType {
		// 
		TmpUser,
		NormalUser

	};
	string to_String(UserType m);
	UserType FromString(string s);
}