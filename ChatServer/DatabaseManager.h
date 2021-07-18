#pragma once
# include "User.h"
# include "Group.h"
class DatabaseManager {
public:
	static User* getUserFromUid(string& uid);
	static Group* getGroupFromGid(string& gid);
	static void addToTmpUser(User* user);

};