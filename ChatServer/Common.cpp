#include "Common.h"
using namespace std;
string addEscapeCharacter(string s, char c){
	if (s.find(c) == s.size()) {
		return s;
	}
	else {
		string result;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != c) {
				result.push_back(s[i]);
			}
			else {
				result.push_back(s[i]);
				result.push_back(' ');
			}
		}
		return result;
	}
}

char getRandomFromVector(vector<char> v) {
	static unsigned int seed = time(0);
	static bool srand_flag = false;
	if (!srand_flag) {
		srand(seed);
		srand_flag = true;
	}
	if (v.size() == 0) {
		throw "vector length is 0";
	}
	else {

		int index = rand() % v.size();
		return v[index];
	}
}

vector<string> split(string s, string sep, bool reserve_last, bool reserve_last_empty ) {
	vector<string> v_s;
	int sep_size = sep.size();
	int s_size = s.size();
	int current = 0;
	string tmp="";
	for (int i = 0; i < s_size; i++) {
		if (i + sep_size -1 < s_size) {
			if (s.substr(i, sep_size) == sep) {
				v_s.push_back(tmp);
				// v_s.push_back(s.substr(current, i - current));
				i = i + sep_size - 1;
				tmp = "";
			}
			else {
				tmp.push_back(s[i]);
			}
		}
		else {
			tmp.push_back(s[i]);
		}
	}
	if (reserve_last) {
		if (reserve_last_empty) {
			v_s.push_back(tmp);
		}
		else {
			if (!tmp.empty()) {
				v_s.push_back(tmp);
			}
			else {
				// do nothing
			}
		}
	}
	else {
		// do nothing
	}
	return v_s;
}
string deleteEscapeCharacter(string s, char c) {
	if (s.find(c) == s.size()) {
		return s;
	}
	else {
		string result;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != c) {
				result.push_back(s[i]);
			}
			else {
				if (i < s.size() - 1) {
					if (s[i + 1] == c || s[i + 1] == ' ') {
						result.push_back(c);
						i++;
					}
					else {
						result = "";
						return result;
					}
				}
				else {
					result = "";
					return result;
				}

			}

		}
		return result;
	}
}
string strftime(string format, time_t t, int buffer_size) {
	char* buffer = new char[buffer_size] {'\0'};
	
	strftime(buffer, buffer_size, format.c_str(), localtime(&t));
	string result = buffer;
	delete[] buffer;
	return result;
}