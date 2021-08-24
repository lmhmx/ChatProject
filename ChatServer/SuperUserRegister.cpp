#include "SuperUserRegister.h"
SuperUserRegister::SuperUserRegister() {

}
bool SuperUserRegister::queryRegisterAUser(string& phone_mail, string& pwd, string registerway) {
	bool res = DatabaseManager::queryRegisterAUser(phone_mail, pwd, registerway,
		m_DatabaseUid,m_DatabasePWD);

	return res;
}
User SuperUserRegister::doRegisterAUser(string& phone_mail, string& pwd, string registerway) {
	User resUser = DatabaseManager::doReigsterAUser(phone_mail, pwd, registerway,
		m_DatabaseUid, m_DatabasePWD);
	return resUser;
}

string SuperUserRegister::getSuperUid() {
	return this->m_DatabaseUid;
}
string SuperUserRegister::getSuperPasswd() {
	return this->m_DatabasePWD;
}
string SuperUserRegister::getSuperUName() {
	return this->m_DatabaseUname;
}
void SuperUserRegister::setSuperUid(string uid) {
	this->m_DatabaseUid = uid;
}
void SuperUserRegister::setSuperPwd(string pwd){
	this->m_DatabasePWD = pwd;
	
}

void SuperUserRegister::setSuperUname(string uname)
{
	this->m_DatabaseUname = uname;
}