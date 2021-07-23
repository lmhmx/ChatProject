#include "SuperUserLogIn.h"
SuperUserLogIn::SuperUserLogIn() {

}
bool SuperUserLogIn::queryLoginAUser(string& phone_mail, string& pwd, string loginway) {
	return 1;
}
User SuperUserLogIn::getUserFromUid(string uid) {
	return User();
}
string SuperUserLogIn::getUidFromMail(string mail) {
	return "";
}
string SuperUserLogIn::getUidFromPhone(string phone) {
	return "";
}
bool SuperUserLogIn::doLoginAUser(string& phone_mail, string& pwd, string loginway) {

	return 1;
}
string SuperUserLogIn::getSuperUid() {
	return this->m_DatabaseUid;
}
string SuperUserLogIn::getSuperPasswd() {
	return this->m_DatabasePWD;
}
string SuperUserLogIn::getSuperUName() {
	return this->m_DatabaseUname;
}
void SuperUserLogIn::setSuperUid(string uid) {
	this->m_DatabaseUid = uid;
}
void SuperUserLogIn::setSuperPwd(string pwd) {
	this->m_DatabasePWD = pwd;

}

void SuperUserLogIn::setSuperUname(string uname)
{
	this->m_DatabaseUname = uname;
}