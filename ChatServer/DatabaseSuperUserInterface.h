#pragma once
# include <string>

using namespace std;

class DatabaseSuperUserInterface
{
private:
	virtual string getUid()=0;
	virtual string getPasswd()=0;
	virtual string getUName()=0;
	virtual void setUid(string uid)=0;
	virtual void setPwd(string pwd)=0;
	virtual void setUname(string uname)=0;
public:
	// 读取database的密码，id，以及能够被人理解的name
	string m_DatabasePWD;
	string m_DatabaseUid;
	string m_DatabaseUname;

};

