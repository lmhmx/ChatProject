#include <boost/bimap.hpp>
# include <boost/bimap/tags/tagged.hpp>
#include <string>
#include <iostream>
# include <qdebug.h>
# include <map>
using namespace std;
class Mystring//:public string
{

public :
	Mystring(int m) {
		m_m = m;
	}
	bool operator<(const Mystring a)const {
		bool r = m_m < a.m_m;
		cout << " less res " << r << endl;
		return r;
	}
	bool operator<(const Mystring a) {
		bool r = m_m < a.m_m;
		cout << " less res " << r << endl;
		return r;
	}
	bool operator>(const Mystring& a) {
		bool r = m_m > a.m_m;
		cout << " greater res " << r << endl;
		return r;
	}
	bool operator==(const Mystring& a) {
		bool r = m_m == a.m_m;
		cout << " greater res " << r << endl;
		return r;
	}
	
	/*bool less<Mystring>::operator()(const Mystring& s1, const Mystring& s2) {
		return 1;
	}*/
	

public:
	int m_m;
};
using namespace std;
int main()
{
	
	boost::bimap<Mystring, int> m;
	Mystring a(1);
	Mystring b(2);
	m.insert({ a,1 });
	m.insert({ b,4 });


	
	cout << (a < b);
	
	/*animals.insert({ AA(2), 4 });
	animals.insert({ AA(3), 4 });
	animals.insert({ AA(4), 8 });
	qDebug() << "s kjjkj";
	qDebug() << animals.left.count("cat");
	qDebug() << animals.right.count(4);
	for (auto it = animals.begin(); it != animals.end(); ++it) {
		qDebug() << it->left.m; qDebug() << " has "; qDebug() << it->right; qDebug() << " legs\n";
	}*/
	system("pause");
	return 0;
}