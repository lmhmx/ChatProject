# include "DatabaseManager.h"
vector<User*> DatabaseManager::m_Users=vector<User*>();
vector<Group*> DatabaseManager::m_Groups=vector<Group*>();
vector<char> DatabaseManager::m_FirstCharacterOfID=vector<char>();
vector<char> DatabaseManager::m_OtherCharactersOfID=vector<char>();
QSqlDatabase* DatabaseManager::m_database = nullptr;



User DatabaseManager::getUserFromUid(string& uid, 
	string superuid, string superpwd) {
	if (_DB_checkAuthority(Authorization(),superuid, superpwd)) {
		User* user = _DB_getUserFromUid(uid);
		if (user == nullptr) {
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
	if (_DB_checkAuthority(Authorization(),superuid, superpwd)) {
		return _DB_getUidFromMail(mail);
	}
	return "";
}
string DatabaseManager::getUidFromPhone(string phone, 
	string superuid, string superpwd) {
	if (_DB_checkAuthority(Authorization(), superuid, superpwd)) {
		return _DB_getUidFromPhone(phone);
	}
	return "";
}

bool DatabaseManager::queryRegisterAUser(string& phone_mail, string& pwd, string registerway, 
	string superuid, string superpwd) {
	if (_DB_checkAuthority(Authorization(), superuid, superpwd)) {
		return _DB_queryRegisterAUser(phone_mail, pwd, registerway);
	}
	return false;
	
}
User DatabaseManager::doReigsterAUser(string& phone_mail, string& pwd, string registerway,
	string superuid, string superpwd) {
	User user = User::UserDefault;
	if (_DB_checkAuthority(Authorization(), superuid, superpwd)) {
		user = _DB_doReigsterAUser(phone_mail, pwd, registerway);
	}
	return user;
}

string DatabaseManager::generateNewUid() {
	string uid;
	checkCharacters();
	while (true) {
		uid = "";
		uid.push_back(getRandomFromVector(m_FirstCharacterOfID));
		for (int i = 0; i < 15; i++) {
			uid.push_back(getRandomFromVector(m_OtherCharactersOfID));
		}
		if (_DB_getUserFromUid(uid)==nullptr) {
			break;
		}
	}
	return uid;
}
User* DatabaseManager::_DB_getUserFromUid(string& uid) {
	vector<User*> users = __DB_getUsers();
	for (auto i = users.begin(); i != users.end(); i++) {
		if ((*i)->m_UserID == uid) {
			return (*i);
		}
	}
	return nullptr;
}
Group* DatabaseManager::_DB_getGroupFromGid(string& gid) {
	return 0;
}
string DatabaseManager::_DB_getUidFromMail(string mail) {
	vector<User*> users = __DB_getUsers();
	for (auto i = users.begin(); i != users.end(); i++) {
		if ((*i)->m_UserMail == mail) {
			return (*i)->m_UserID;
		}
	}
	return "";
}
string DatabaseManager::_DB_getUidFromPhone(string phone) {
	vector<User*> users = __DB_getUsers();
	for (auto i = users.begin(); i != users.end(); i++) {
		if ((*i)->m_UserPhone == phone) {
			return (*i)->m_UserID;
		}
	}
	return "";
}
bool DatabaseManager::_DB_queryRegisterAUser(string& phone_mail, string& pwd, string registerway) {
	if (registerway == "PHONE") {
		string phone = phone_mail;

		for (auto i = m_Users.begin(); i != m_Users.end(); i++) {
			if ((*i)->m_UserPhone == phone) {
				return false;
			}
		}
		return true;
	}
	else if (registerway == "MAIL") {
		string mail = phone_mail;

		for (auto i = m_Users.begin(); i != m_Users.end(); i++) {
			if ((*i)->m_UserMail == mail) {
				return false;
			}
		}
		return true;
	}
	return false;
}
User DatabaseManager::_DB_doReigsterAUser(string& phone_mail, string& pwd, string registerway) {
	User user = User::UserDefault;
	if (_DB_queryRegisterAUser(phone_mail, pwd, registerway)) {
		if (registerway == "MAIL") {
			user.m_UserMail = phone_mail;
			user.m_UserPasswd = pwd;
			user.m_UserID = generateNewUid();
		}
	}
	return user;
}
string DatabaseManager::generateNewGid() {
	string gid;
	checkCharacters();
	while (true) {
		gid = "";
		gid.push_back(getRandomFromVector(m_FirstCharacterOfID));
		for (int i = 0; i < 15; i++) {
			gid.push_back(getRandomFromVector(m_OtherCharactersOfID));
		}
		if (_DB_getUserFromUid(gid) == nullptr) {
			break;
		}
	}
	return gid;
}
void DatabaseManager::checkCharacters() {
	if (m_FirstCharacterOfID.size() == 0) {
		for (char i = 'a'; i <= 'z'; i++) {
			m_FirstCharacterOfID.push_back(i);
		}
		for (char i = 'A'; i <= 'Z'; i++) {
			m_FirstCharacterOfID.push_back(i);
		}
	}
	if (m_OtherCharactersOfID.size() == 0) {
		for (char i = 'a'; i <= 'z'; i++) {
			m_OtherCharactersOfID.push_back(i);
		}
		for (char i = 'A'; i <= 'Z'; i++) {
			m_OtherCharactersOfID.push_back(i);
		}
		for (char i = '0'; i <= '9'; i++) {
			m_OtherCharactersOfID.push_back(i);
		}
	}
}
bool  DatabaseManager::_DB_checkAuthority(Authorization authorization,
	string superuid, string superpwd) {
	return true;
}

void DatabaseManager::__DB_addToUsers(User* user) {
	__loadFromDatabase();
	

	m_Users.push_back(user);
	__saveToDatabase();
}
void DatabaseManager::__DB_removeFromUsers(User* user) {
	__loadFromDatabase();
	m_Users.erase(find(m_Users.begin(), m_Users.end(), user));
	__saveToDatabase();
}
const vector<User*> DatabaseManager::__DB_getUsers() {
	__loadFromDatabase();
	return m_Users;
}

void DatabaseManager::__loadFromDatabase() {
	__init();

}
void DatabaseManager::__init() {
	// todo: load
	if (m_database == nullptr) {
		m_database = new QSqlDatabase();
		m_database->setHostName("127.0.0.1");
		m_database->setDatabaseName("chat");
		m_database->setPort(3306);
		m_database->setPassword("liming18");
		m_database->setUserName("ChatappManager");
		
	}
	else {
		// do nothing

	}
}
void DatabaseManager::__loadUserFromDatabase() {
	__init();

}
void DatabaseManager::__saveUserToDatabase() {
	__init();
}


void DatabaseManager::__saveToDatabase() {
	__init();
	
}