#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class MultBy {
	int mult_;
public:
	MultBy(int val):mult_(val) {};
	
	int 
	*****
	
};

int main() {
	ostream_iterator<int> it(cout, "\n");
	
	*it = 1;
	++it;
	*it = 2;
	*it = 42;
	
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int N = sizeof(a)/sizeof(a[0]);
	
	copy(a, a+N, it);
	
	copy(a, a+N, ostream_iterator<int>(cout, ", "));
	cout << endl;
	
	cout << "---------------------------------------" << endl;
	
	list<int> l;
	copy(a, a+N, l.begin());
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
	
	back_insert_iterator<list<int>>
	
	return 0;
}
