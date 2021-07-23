#include "SuperUserLogIn.h"
SuperUserLogIn::SuperUserLogIn() {

}
bool SuperUserLogIn::queryLoginAUser(string& phone_mail, string& pwd, string loginway) {
	return 1;
}
bool SuperUserLogIn::doLoginAUser(string& phone_mail, string& pwd, string loginway) {

	return 1;
}
string SuperUserLogIn::getUid() {
	return this->m_DatabaseUid;
}
string SuperUserLogIn::getPasswd() {
	return this->m_DatabasePWD;
}
string SuperUserLogIn::getUName() {
	return this->m_DatabaseUname;
}
void SuperUserLogIn::setUid(string uid) {
	this->m_DatabaseUid = uid;
}
void SuperUserLogIn::setPwd(string pwd) {
	this->m_DatabasePWD = pwd;

}

void SuperUserLogIn::setUname(string uname)
{
	this->m_DatabaseUname = uname;
}