# include "DatabaseManager.h"
PrivateDatabase DatabaseManager::m_PrivateDatabase =  PrivateDatabase();

User DatabaseManager::getUserFromUid(string& uid, 
	string superuid, string superpwd) {
	if (m_PrivateDatabase.DB_checkAuthority(Authorization(),superuid, superpwd)) {
		User user = m_PrivateDatabase.DB_getUserFromUid(uid);
		if (user == User::UserDefault) {
			return User::UserDefault;
		}
	}
	return User::UserDefault;
}

Group DatabaseManager::getGroupFromGid(string& gid, 
	string superuid, string superpwd) {
	throw exception("Group* DatabaseManager::getGroupFromGid(string& gid) not finished yet");
	return Group();
}
string DatabaseManager::getUidFromMail(string mail, 
	string superuid, string superpwd) {
	if (m_PrivateDatabase.DB_checkAuthority(Authorization(),superuid, superpwd)) {
		return m_PrivateDatabase.DB_getUidFromMail(mail);
	}
	return "";
}
string DatabaseManager::getUidFromPhone(string phone, 
	string superuid, string superpwd) {
	if (m_PrivateDatabase.DB_checkAuthority(Authorization(), superuid, superpwd)) {
		return m_PrivateDatabase.DB_getUidFromPhone(phone);
	}
	return "";
}

bool DatabaseManager::queryRegisterAUser(string& phone_mail, string& pwd, string registerway, 
	string superuid, string superpwd) {
	if (m_PrivateDatabase.DB_checkAuthority(Authorization(), superuid, superpwd)) {
		return m_PrivateDatabase.DB_queryRegisterAUser(phone_mail, pwd, registerway);
	}
	return false;
	
}
User DatabaseManager::doReigsterAUser(string& phone_mail, string& pwd, string registerway,
	string superuid, string superpwd) {
	User user = User::UserDefault;
	if (m_PrivateDatabase.DB_checkAuthority(Authorization(), superuid, superpwd)) {
		user = m_PrivateDatabase.DB_doReigsterAUser(phone_mail, pwd, registerway);
	}
	return user;
}
