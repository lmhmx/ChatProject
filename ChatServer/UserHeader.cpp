# include "UserHeader.h"
# include <string>
# include <map>

namespace UserType {
	string to_String(UserType m) {
		map<UserType, string> message2str;
		message2str[UserType::TmpUser] = "TmpUser";
		message2str[UserType::NormalUser] = "NormalUser";
		return message2str[m];
	}

	UserType FromString(string s)
	{
		map<string, UserType> m;
		m["TmpUser"] = UserType::TmpUser;
		m["NormalUser"] = UserType::NormalUser;
		
		return m[s];
	}
}
