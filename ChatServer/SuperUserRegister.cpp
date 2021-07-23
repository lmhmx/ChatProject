#include "SuperUserRegister.h"
SuperUserRegister::SuperUserRegister() {

}
bool SuperUserRegister::queryRegisterAUser(string& phone_mail, string& pwd, string registerway) {
	return 0;
}
User SuperUserRegister::doRegisterAUser(string& phone_mail, string& pwd, string registerway) {
	
	return User();
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