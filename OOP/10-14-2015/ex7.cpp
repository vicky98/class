#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string istr = "42 3.14 ala-bala";
	istringstream in(istr);
	
	int d;
	float f;
	string s;
	in >> d;
	in >> f;
	in >> s;
	cout << "d = " << d << endl;
	cout << "f = " << f << endl;
	cout << "s = " << s << endl;
	
	in >> d;
	cout << "in stream not good..." << endl;
	
	ostringstream out;
	cout << d << ' ' << f << ' ' << s;
	
	cout << "out.str()= " << out.str() << endl;

	return 0;
}
