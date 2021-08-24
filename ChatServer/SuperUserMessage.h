#pragma once
# include "User.h"
# include "DatabaseSuperUserInterface.h"
class SuperUserMessage:public User,public DatabaseSuperUserInterface
{
	SuperUserMessage();
	User getUserFromUid(string uid);
	string getSuperUid();
	string getSuperPasswd();
	string getSuperUName();
	void setSuperUid(string uid);
	void setSuperPwd(string pwd);
	void setSuperUname(string uname);
};

