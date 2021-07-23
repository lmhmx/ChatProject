#pragma once
# include "User.h"
# include "DatabaseSuperUserInterface.h"
# include "DatabaseManager.h"
# include <string>

using namespace std;
class SuperUserLogIn:public DatabaseSuperUserInterface
{
public:
	SuperUserLogIn();
	bool queryLoginAUser(string& phone_mail, string& pwd, string loginway);
	bool doLoginAUser(string& phone_mail, string& pwd, string loginway);
	string getUid();
	string getPasswd();
	string getUName();
	void setUid(string uid);
	void setPwd(string pwd);
	void setUname(string uname);

	
};

