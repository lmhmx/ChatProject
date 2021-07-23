# include "User.h"
const User User::UserDefault = User();
User::User() {
	m_UserType = UserType::UserType::DefaultUser;

}
User::User(const User& user) {
	this->m_FriendsID = user.m_FriendsID;
	this->m_GroupsID = user.m_GroupsID;
	this->m_NickName = user.m_NickName;
	this->m_UserID = user.m_UserID;
	this->m_UserMail = user.m_UserMail;
	this->m_UserPasswd = user.m_UserPasswd;
	this->m_UserPhone = user.m_UserPhone;
	this->m_UserType = user.m_UserType;
}
User User::operator=(const User& user) {
	this->copyFrom(user);
}
bool User::operator==(const User& user) {
	return this->m_UserID == user.m_UserID;
}
bool User::operator!=(const User& user) {
	return !(this->operator==(user));
}
void User::copyFrom(const User& user) {
	this->m_FriendsID = user.m_FriendsID;
	this->m_GroupsID = user.m_GroupsID;
	this->m_NickName = user.m_NickName;
	this->m_UserID = user.m_UserID;
	this->m_UserMail = user.m_UserMail;
	this->m_UserPasswd = user.m_UserPasswd;
	this->m_UserPhone = user.m_UserPhone;
	this->m_UserType = user.m_UserType;
}
void User::init() {

}
