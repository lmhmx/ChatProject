#include "SuperUserRegister.h"
SuperUserRegister::SuperUserRegister() {

}
bool SuperUserRegister::queryRegisterAUser(string& phone_mail, string& pwd, string registerway) {
	return 0;
}
User* SuperUserRegister::doRegisterAUser(string& phone_mail, string& pwd, string registerway) {
	
	return 0;
}
string SuperUserRegister::getUid() {
	return this->m_DatabaseUid;
}
string SuperUserRegister::getPasswd() {
	return this->m_DatabasePWD;
}
string SuperUserRegister::getUName() {
	return this->m_DatabaseUname;
}
void SuperUserRegister::setUid(string uid) {
	this->m_DatabaseUid = uid;
}
void SuperUserRegister::setPwd(string pwd){
	this->m_DatabasePWD = pwd;
	
}

void SuperUserRegister::setUname(string uname)
{
	this->m_DatabaseUname = uname;
}