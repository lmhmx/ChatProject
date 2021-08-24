#include "SuperUserMessage.h"

SuperUserMessage::SuperUserMessage() {

}

User SuperUserMessage::getUserFromUid(string uid) {
	User u = DatabaseManager::getUserFromUid(uid, m_DatabaseUid, m_DatabasePWD);
	return u;
}

string SuperUserMessage::getSuperUid() {
	return this->m_DatabaseUid;
}
string SuperUserMessage::getSuperPasswd() {
	return this->m_DatabasePWD;
}
string SuperUserMessage::getSuperUName() {
	return this->m_DatabaseUname;
}
void SuperUserMessage::setSuperUid(string uid) {
	this->m_DatabaseUid = uid;
}
void SuperUserMessage::setSuperPwd(string pwd) {
	this->m_DatabasePWD = pwd;

}
vector<User> SuperUserMessage::translateReceiverID(string receiver) {
	vector<User> users;

	users.push_back(getUserFromUid(receiver));
	return users;
}
void SuperUserMessage::setSuperUname(string uname)
{
	this->m_DatabaseUname = uname;
}

