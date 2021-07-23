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
	User doRegisterAUser(string& phone_mail, string& pwd, string registerway);
	string getSuperUid();
	string getSuperPasswd();
	string getSuperUName();
	void setSuperUid(string uid);
	void setSuperPwd(string pwd);
	void setSuperUname(string uname);


};

