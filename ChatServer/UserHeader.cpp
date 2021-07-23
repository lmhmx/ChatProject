# include "UserHeader.h"
# include <string>
# include <map>

namespace UserType {
	string to_String(UserType m) {
		map<UserType, string> message2str;
		message2str[UserType::TmpUser] = "TmpUser";
		message2str[UserType::NormalUser] = "NormalUser";
		message2str[UserType::DefaultUser] = "DefaultUser";
		return message2str[m];
	}

	UserType FromString(string s)
	{
		map<string, UserType> m;
		m["TmpUser"] = UserType::TmpUser;
		m["NormalUser"] = UserType::NormalUser;
		m["DefaultUser"] = UserType::DefaultUser;
		return m[s];
	}
}
