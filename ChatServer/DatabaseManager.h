#pragma once
# include "User.h"
# include "Group.h"
# include <vector>
# include <regex>
# include <exception>
# include "Authorization.h"
# include "Common.h"
using namespace std;
class DatabaseManager {
public:
	// 现在假设场景为一个服务器，由于需要实时更新数据，所以需要写到底层存储中
	

public:
	static User getUserFromUid(string& uid, string superuid, string superpwd);
	static Group getGroupFromGid(string& gid, string superuid, string superpwd);
	static string getUidFromMail(string mail, string superuid, string superpwd);
	static string getUidFromPhone(string phone, string speruid, string superpwd);
	static bool queryRegisterAUser(string& phone_mail, string&pwd, string registerway,string superuid, string superpwd);
	static User doReigsterAUser(string& phone_mail, string& pwd, string registerway, string superuid, string superpwd);
	
private:
	static string generateNewUid();
	static string generateNewGid();

	static User* _DB_getUserFromUid(string& uid);
	static Group* _DB_getGroupFromGid(string& gid);
	static string _DB_getUidFromMail(string mail);
	static string _DB_getUidFromPhone(string phone);
	static bool _DB_queryRegisterAUser(string& phone_mail, string& pwd, string registerway);
	static User _DB_doReigsterAUser(string& phone_mail, string& pwd, string registerway);

	static bool _DB_checkAuthority(Authorization authorization, string superuid, string superpwd);

private:
	
	static void checkCharacters();
	

private:
	static vector<User*> m_Users;
	static vector<Group*> m_Groups;
	static vector<char> m_FirstCharacterOfID;
	static vector<char> m_OtherCharactersOfID;
};