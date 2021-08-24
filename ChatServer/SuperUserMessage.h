#pragma once
# include "User.h"
# include "DatabaseManager.h"
# include "DatabaseSuperUserInterface.h"
class SuperUserMessage:public User,public DatabaseSuperUserInterface
{
public:
	SuperUserMessage();
	User getUserFromUid(string uid);
	
	vector<User> translateReceiverID(string receiver);
	
	string getSuperUid();
	string getSuperPasswd();
	string getSuperUName();
	void setSuperUid(string uid);
	void setSuperPwd(string pwd);
	void setSuperUname(string uname);
public:

};

