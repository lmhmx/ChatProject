#include "SuperUserLogIn.h"
SuperUserLogIn::SuperUserLogIn() {

}
bool SuperUserLogIn::queryLoginAUser(string& phone_mail, string& pwd, string loginway) {
	string id;
	if (loginway == "MAIL") {
		id=  DatabaseManager::getUidFromMail(phone_mail, m_DatabaseUid, m_DatabasePWD);
	}
	else if (loginway == "PHONE") {
		id = DatabaseManager::getUidFromPhone(phone_mail, m_DatabaseUid, m_DatabasePWD);
	}
	User u = DatabaseManager::getUserFromUid(id , m_DatabaseUid,m_DatabasePWD);

	if (u == User::UserDefault) {
		return false;
	}
	else {
		if (u.m_UserPasswd == pwd) {
			return true;
		}
		return false;
	}
}
User SuperUserLogIn::getUserFromUid(string uid) {
	User u = DatabaseManager::getUserFromUid(uid, m_DatabaseUid, m_DatabasePWD);
	return u;
	
}
string SuperUserLogIn::getUidFromMail(string mail) {
	return "";
}
string SuperUserLogIn::getUidFromPhone(string phone) {
	return "";
}
bool SuperUserLogIn::doLoginAUser(string& phone_mail, string& pwd, string loginway) {
	string id;
	if (loginway == "MAIL") {
		id = DatabaseManager::getUidFromMail(phone_mail, m_DatabaseUid, m_DatabasePWD);
	}
	else if (loginway == "PHONE") {
		id = DatabaseManager::getUidFromPhone(phone_mail, m_DatabaseUid, m_DatabasePWD);
	}
	User u = DatabaseManager::getUserFromUid(id, m_DatabaseUid, m_DatabasePWD);

	if (u == User::UserDefault) {
		return false;
	}
	else {
		if (u.m_UserPasswd == pwd) {
			return true;
		}
		return false;
	}
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