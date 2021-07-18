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
	
	void init();

	

public:
	/*****************************************************
	* 
	* get and set functions
	* 
	**************************************************/
	//void setGroupsID(vector<string> groupsID);
	//void setFriendsID(vector<string> friendsID);




private:

public:
	UserType::UserType m_UserType;

private:
	vector<string> m_GroupsID;
	vector<string> m_FriendsID;
	
	

};