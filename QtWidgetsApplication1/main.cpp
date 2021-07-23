#include <boost/bimap.hpp>
# include <boost/bimap/tags/tagged.hpp>
#include <string>
#include <iostream>
# include <qdebug.h>
# include <map>
class AA {
public :
	AA(int m) {
		this->m = m;
	}
	/*bool operator==(AA a) {
		return m == a.m;
	}
	bool operator<(AA a) {
		return m < a.m;
	}
	bool less(AA a) {
		return m < a.m;
	}*/
	int m;
};
using namespace std;
int main()
{
	map<AA, int> m;
	
	
	
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