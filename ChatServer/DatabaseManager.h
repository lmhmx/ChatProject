#pragma once
# include "User.h"
# include "Group.h"
# include <vector>
# include <regex>
# include "PrivateDatabase.h"
# include <exception>
# include <qsqldatabase.h>
# include <qstringlist.h>
# include <qsql.h>
# include "PrivateDatabase.h"
# include "User.h"
# include "Authorization.h"
# include "Common.h"

using namespace std;
class DatabaseManager {
public:
	// ���ڼ��賡��Ϊһ����������������Ҫʵʱ�������ݣ�������Ҫд���ײ�洢��
	
public:
	static User getUserFromUid(string& uid, string superuid, string superpwd);
	static Group getGroupFromGid(string& gid, string superuid, string superpwd);
	static string getUidFromMail(string mail, string superuid, string superpwd);
	static string getUidFromPhone(string phone, string speruid, string superpwd);
	static bool queryRegisterAUser(string& phone_mail, string&pwd, string registerway,string superuid, string superpwd);
	static User doReigsterAUser(string& phone_mail, string& pwd, string registerway, string superuid, string superpwd);

	static PrivateDatabase m_PrivateDatabase;
};