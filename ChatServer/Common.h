#pragma once
# include <string>
# include <vector>
# include <fstream>
# include <ctime>
using namespace std;
string addEscapeCharacter(string s, char c);
string deleteEscapeCharacter(string s, char c);
vector<string> split(string s, string sep, bool reserve_last = false, bool reserve_last_empty = false);
string strftime(string format = "%Y:-%m-%d %H:%M:%S", time_t t = time(0), int buffer_size = 256);
char getRandomFromVector(vector<char> v);
vector<vector<string>> load_CSV(string file, string separator=",");
void save_To_CSV(string file, const vector<vector<string>>& v, string separator = ",");