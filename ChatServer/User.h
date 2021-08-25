#pragma once
# include <iostream>
# include <string>
# include <vector>
# include "UserHeader.h"
# include "UserCore.h"
using namespace std;

class User:public UserCore {
public:
	User();
	User(const User& user);
	~User();
	void init();

	User operator=(const User& user);
	bool operator==(const User& user);
	bool operator!=(const User& user);
	bool operator<(const User& user);
	bool operator<(const User& user) const;
private:
	void copyFrom(const User& user);
public:
	/*****************************************************
	* 
	* get and set functions
	* 
	**************************************************/
	//void setGroupsID(vector<string> groupsID);
	//void setFriendsID(vector<string> friendsID);

public:
	static const User UserDefault;
private:

public:
	UserType::UserType m_UserType;

private:
public:
	vector<string> m_GroupsID;
	vector<string> m_FriendsID;
	
	

};