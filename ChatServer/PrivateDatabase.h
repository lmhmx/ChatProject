#pragma once
# include "User.h"
# include "Group.h"
# include <vector>
# include <regex>
# include <qdebug.h>
# include <exception>
# include <qsqldatabase.h>
# include <qstringlist.h>
# include <qsql.h>
# include "Authorization.h"
# include "Common.h"

class PrivateDatabase
{
public:
	PrivateDatabase();
	~PrivateDatabase();

	string generateNewUid();
	string generateNewGid();

	User DB_getUserFromUid(string uid);
	Group DB_getGroupFromGid(string gid);
	string DB_getUidFromMail(string mail);
	string DB_getUidFromPhone(string phone);
	bool DB_queryRegisterAUser(string phone_mail, string pwd, string registerway);
	User DB_doReigsterAUser(string phone_mail, string pwd, string registerway);

	bool DB_checkAuthority(Authorization authorization, string superuid, string superpwd);


private:

	void checkCharacters();

private:

private:
	void loadFromDatabase();

	void saveToDatabase();

	void loadUserFromDatabase();
	void saveUserToDatabase();

	void init();


private:
	QSqlDatabase* m_database;
	vector<User> m_Users;
	vector<Group> m_Groups;
	vector<char> m_FirstCharacterOfID;
	vector<char> m_OtherCharactersOfID;

};

