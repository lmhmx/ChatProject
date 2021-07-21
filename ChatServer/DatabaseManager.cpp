# include "DatabaseManager.h"
User* DatabaseManager::getUserFromUid(string& uid) {
	return 0;
}
Group* DatabaseManager::getGroupFromGid(string& gid) {
	return 0;
}
string DatabaseManager::getUidFromMail(string mail) {
	return "";
}
string DatabaseManager::getUidFromPhone(string phone) {
	return "";
}

bool DatabaseManager::queryRegisterAUser(string& phone_mail, string& pwd, string registerway) {
	return 1;
}
bool DatabaseManager::doReigsterAUser(string& phone_mail, string& pwd, string registerway) {
	return 1;
}
