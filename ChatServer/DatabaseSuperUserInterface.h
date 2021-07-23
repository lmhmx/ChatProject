#pragma once
# include <string>

using namespace std;

class DatabaseSuperUserInterface
{
private:
	virtual string getSuperUid()=0;
	virtual string getSuperPasswd()=0;
	virtual string getSuperUName()=0;
	virtual void setSuperUid(string uid)=0;
	virtual void setSuperPwd(string pwd)=0;
	virtual void setSuperUname(string uname)=0;
public:
	// ��ȡdatabase�����룬id���Լ��ܹ���������name
	string m_DatabasePWD;
	string m_DatabaseUid;
	string m_DatabaseUname;

};

