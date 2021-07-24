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
	static User getUserFromUid(string& uid, string superuid, string superpwd, string superuname);
	static Group getGroupFromGid(string& gid, string superuid, string superpwd, string superuname);
	static string getUidFromMail(string mail, string superuid, string superpwd, string superuname);
	static string getUidFromPhone(string phone, string speruid, string superpwd, string superuname);
	static bool queryRegisterAUser(string& phone_mail, string&pwd, string registerway,string superuid, string superpwd,string superuname);
	static bool doReigsterAUser(string& phone_mail, string& pwd, string registerway, string superuid, string superpwd, string superuname);
	
private:
	static string generateNewUid();
	static string generateNewGid();

	static User* _getUserFromUid(string& uid);
	static Group* _getGroupFromGid(string& gid);
	static string _getUidFromMail(string mail);
	static string _getUidFromPhone(string phone);
	static bool _queryRegisterAUser(string& phone_mail, string& pwd, string registerway);
	static bool _doReigsterAUser(string& phone_mail, string& pwd, string registerway);

	static bool _checkAuthority(Authorization authorization, string superuid, string superpwd, string superunam);

private:
	
	static void checkCharacters();
private:
	static vector<User*> m_Users;
	static vector<Group*> m_Groups;
	static vector<char> m_FirstCharacterOfID;
	static vector<char> m_OtherCharactersOfID;
};