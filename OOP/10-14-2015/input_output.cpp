#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	cin >> word;
	
	while (cin)
	{
		cout << '(' << word << ')' << endl;
		cin >> word;
	}

		
	
	return 0;
}

// ./a.out < string.cpp > aa.txt
