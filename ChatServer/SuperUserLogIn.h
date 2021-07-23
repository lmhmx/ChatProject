#pragma once
# include "User.h"
# include "DatabaseSuperUserInterface.h"
# include "DatabaseManager.h"
# include <string>

using namespace std;
class SuperUserLogIn:public User,public DatabaseSuperUserInterface
{
public:
	SuperUserLogIn();
	User getUserFromUid(string uid);
	string getUidFromMail(string mail);
	string getUidFromPhone(string phone);
	bool queryLoginAUser(string& phone_mail, string& pwd, string loginway);
	bool doLoginAUser(string& phone_mail, string& pwd, string loginway);
	string getSuperUid();
	string getSuperPasswd();
	string getSuperUName();
	void setSuperUid(string uid);
	void setSuperPwd(string pwd);
	void setSuperUname(string uname);

	
};

