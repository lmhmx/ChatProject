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
	// ��ȡdatabase�����룬id���Լ��ܹ���������name
	string m_DatabasePWD;
	string m_DatabaseUid;
	string m_DatabaseUname;

};

