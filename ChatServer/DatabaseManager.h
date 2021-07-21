#pragma once
# include "User.h"
# include "Group.h"
class DatabaseManager {
public:
	static User* getUserFromUid(string& uid);
	static Group* getGroupFromGid(string& gid);
	string getUidFromMail(string mail);
	string getUidFromPhone(string phone);
	static bool queryRegisterAUser(string& phone_mail, string&pwd, string registerway);
	static bool doReigsterAUser(string& phone_mail, string& pwd, string registerway);
};