#include <vector>
#include <iostream>
using namespace std;

void print(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it = v.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v1(a, a + 10);
	v1.push_back(1000);
	v1.push_back(1001);
	print(v1);
	
	vector<int>::iterator it = v1.begin();
	v1.insert(it, -1);		
	print(v1);
	
	// v1.insert() + v1.erase()
	
	return 0;
}
