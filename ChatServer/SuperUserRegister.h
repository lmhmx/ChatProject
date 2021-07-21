#pragma once
# include "User.h"
# include "DatabaseManager.h"
# include <string>
using namespace std;
class SuperUserRegister:public User
{
public:

	SuperUserRegister();
	bool queryRegisterAUser(string& phone_mail, string& pwd, string registerway);
	bool doRegisterAUser(string& phone_mail, string& pwd, string registerway);

public:
	// 读取database的密码，id，以及能够被人理解的name
	string m_DatabasePWD;
	string m_DatabaseUid;
	string m_DatabaseUname;

};

