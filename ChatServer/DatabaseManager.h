#pragma once
# include "User.h"
# include "Group.h"
# include <vector>
# include <regex>
# include <exception>
using namespace std;
class DatabaseManager {
public:
	static User* getUserFromUid(string& uid);
	static Group* getGroupFromGid(string& gid);
	static string getUidFromMail(string mail);
	static string getUidFromPhone(string phone);
	static bool queryRegisterAUser(string& phone_mail, string&pwd, string registerway,string uid, string superpwd,string uname);
	static bool doReigsterAUser(string& phone_mail, string& pwd, string registerway, string uid, string superpwd, string uname);
	
private:
	static string generateNewUid();
	static string generateNewGid();
private:
	static char getRandomFromVector(vector<char> v);
	static void checkCharacters();
private:
	static vector<User*> m_Users;
	static vector<Group*> m_Groups;
	static vector<char> m_FirstCharacterOfID;
	static vector<char> m_OtherCharactersOfID;
};