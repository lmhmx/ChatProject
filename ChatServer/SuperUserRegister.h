#pragma once
# include "User.h"
# include "DatabaseManager.h"
# include <string>
# include"DatabaseSuperUserInterface.h"
# include "User.h"
using namespace std;
class SuperUserRegister :public User,public DatabaseSuperUserInterface
{
public:

	SuperUserRegister();
	bool queryRegisterAUser(string& phone_mail, string& pwd, string registerway);
	User* doRegisterAUser(string& phone_mail, string& pwd, string registerway);
	string getUid();
	string getPasswd();
	string getUName();
	void setUid(string uid);
	void setPwd(string pwd);
	void setUname(string uname);


};

