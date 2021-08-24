#include "SuperUserMessage.h"

SuperUserMessage::SuperUserMessage() {

}

User SuperUserMessage::getUserFromUid(string uid) {
	return User();
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

void SuperUserMessage::setSuperUname(string uname)
{
	this->m_DatabaseUname = uname;
}