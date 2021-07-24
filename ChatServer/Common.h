#pragma once
# include <string>
# include <vector>
# include <ctime>
using namespace std;
string addEscapeCharacter(string s, char c);
string deleteEscapeCharacter(string s, char c);
vector<string> split(string s, string sep, bool reserve_last = false, bool reserve_last_empty = false);
string strftime(string format, time_t t,int buffer_size= 256);
char getRandomFromVector(vector<char> v);