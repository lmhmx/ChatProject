#include "PrivateDatabase.h"

//vector<User> PrivateDatabase::m_Users = vector<User>();
//vector<Group> PrivateDatabase::m_Groups = vector<Group>();
//vector<char> PrivateDatabase::m_FirstCharacterOfID = vector<char>();
//vector<char> PrivateDatabase::m_OtherCharactersOfID = vector<char>();
//QSqlDatabase* PrivateDatabase::m_database = nullptr;

PrivateDatabase::PrivateDatabase() {
	init();
}
PrivateDatabase::~PrivateDatabase() {
	qDebug() << "private delete";
	saveToDatabase();
}
void PrivateDatabase::init() {
	qDebug() << "private init";
	loadFromDatabase();
	//// todo: load
	//if (m_database == nullptr) {
	//	m_database = new QSqlDatabase();
	//	m_database->setHostName("127.0.0.1");
	//	m_database->setDatabaseName("chat");
	//	m_database->setPort(3306);
	//	m_database->setPassword("liming18");
	//	m_database->setUserName("ChatappManager");
	//
	//}
	//else {
	//	// do nothing
	//
	//}
}
string PrivateDatabase::generateNewUid() {
	string uid;
	checkCharacters();
	while (true) {
		uid = "";
		uid.push_back(getRandomFromVector(m_FirstCharacterOfID));
		for (int i = 0; i < 15; i++) {
			uid.push_back(getRandomFromVector(m_OtherCharactersOfID));
		}
		if (DB_getUserFromUid(uid) == User::UserDefault) {
			break;
		}
	}
	return uid;
}
User PrivateDatabase::DB_getUserFromUid(string uid) {
	
	for (auto i = m_Users.begin(); i != m_Users.end(); i++) {
		if ((*i).m_UserID == uid) {
			return (*i);
		}
	}
	return User::UserDefault;
}
Group PrivateDatabase::DB_getGroupFromGid(string gid) {
	return Group();
}
string PrivateDatabase::DB_getUidFromMail(string mail) {
	
	for (auto i = m_Users.begin(); i != m_Users.end(); i++) {
		if ((*i).m_UserMail == mail) {
			return (*i).m_UserID;
		}
	}
	return "";
}
string PrivateDatabase::DB_getUidFromPhone(string phone) {
	for (auto i = m_Users.begin(); i != m_Users.end(); i++) {
		if ((*i).m_UserPhone == phone) {
			return (*i).m_UserID;
		}
	}
	return "";
}
bool PrivateDatabase::DB_queryRegisterAUser(string phone_mail, string pwd, string registerway) {
	if (registerway == "PHONE") {
		string phone = phone_mail;

		for (auto i = m_Users.begin(); i != m_Users.end(); i++) {
			if ((*i).m_UserPhone == phone) {
				return false;
			}
		}
		return true;
	}
	else if (registerway == "MAIL") {
		string mail = phone_mail;

		for (auto i = m_Users.begin(); i != m_Users.end(); i++) {
			if ((*i).m_UserMail == mail) {
				return false;
			}
		}
		return true;
	}
	return false;
}
User PrivateDatabase::DB_doReigsterAUser(string phone_mail, string pwd, string registerway) {
	User user = User::UserDefault;
	if (DB_queryRegisterAUser(phone_mail, pwd, registerway)) {
		if (registerway == "MAIL") {
			user.m_UserMail = phone_mail;
			user.m_UserPasswd = pwd;
			user.m_UserID = generateNewUid();
		}
		else if(registerway == "PHONE"){
			user.m_UserPhone = phone_mail;
			user.m_UserPasswd = pwd;
			user.m_UserID = generateNewUid();
		}
		m_Users.push_back(user);
	}
	return user;
}
string PrivateDatabase::generateNewGid() {
	string gid;
	checkCharacters();
	while (true) {
		gid = "";
		gid.push_back(getRandomFromVector(m_FirstCharacterOfID));
		for (int i = 0; i < 15; i++) {
			gid.push_back(getRandomFromVector(m_OtherCharactersOfID));
		}
		
	}
	return gid;
}
void PrivateDatabase::checkCharacters() {
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
bool  PrivateDatabase::DB_checkAuthority(Authorization authorization,
	string superuid, string superpwd) {

	return true;
}


void PrivateDatabase::loadFromDatabase() {
	loadUserFromDatabase();
	// load others
}

void PrivateDatabase::loadUserFromDatabase() {

	vector<vector<string>> user_info = load_CSV("User.database.table.csv");
	for (auto user = user_info.begin(); user != user_info.end(); user++) {
		User aUser;
		aUser.m_UserID = (*user)[0];
		aUser.m_UserMail = (*user)[1];
		aUser.m_UserPhone = (*user)[2];
		aUser.m_UserType = UserType::FromString((*user)[3]);
		aUser.m_UserPasswd = (*user)[4];
		m_Users.push_back(aUser);
	}
}

void PrivateDatabase::saveUserToDatabase() {
	vector<vector<string>> v;
	for (auto user = m_Users.begin(); user != m_Users.end(); user++) {
		vector<string> user_info;
		user_info.push_back((*user).m_UserID);
		user_info.push_back((*user).m_UserMail);
		user_info.push_back((*user).m_UserPhone);
		user_info.push_back((*user).m_UserPasswd);
		user_info.push_back(UserType::to_String((*user).m_UserType));

		v.push_back(user_info);
	}
	qDebug() << "save user to csv";
	save_To_CSV("User.database.table.csv", v);
}


void PrivateDatabase::saveToDatabase() {
	// save others
	saveUserToDatabase();
}