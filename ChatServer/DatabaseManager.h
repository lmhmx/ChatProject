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
	// ���ڼ��賡��Ϊһ����������������Ҫʵʱ�������ݣ�������Ҫд���ײ�洢��
	

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

	static User* _DB_getUserFromUid(string& uid);
	static Group* _DB_getGroupFromGid(string& gid);
	static string _DB_getUidFromMail(string mail);
	static string _DB_getUidFromPhone(string phone);
	static bool _DB_queryRegisterAUser(string& phone_mail, string& pwd, string registerway);
	static bool _DB_doReigsterAUser(string& phone_mail, string& pwd, string registerway);

	static bool _DB_checkAuthority(Authorization authorization, string superuid, string superpwd, string superunam);

private:
	
	static void checkCharacters();
	

private:
	static vector<User*> m_Users;
	static vector<Group*> m_Groups;
	static vector<char> m_FirstCharacterOfID;
	static vector<char> m_OtherCharactersOfID;
};