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
vector<string> split(string s, string sep) {
	vector<string> v_s;
	int sep_size = sep.size();
	int current = 0;
	for (int i = 0; i < s.size()-sep.size() + 1; i++) {
		if (s.substr(i, sep_size) == sep) {
			v_s.push_back(s.substr(current, i - current));
			i = i + sep_size - 1;
		}
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