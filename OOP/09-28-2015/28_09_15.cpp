#include <iostream>
using namespace std;

int main()
{
	char ch[10];
	int counter = 0;
	int counter2 = 0;
	int i;
	bool right = true;
	
	cin >> ch;
	
	for (i = 0; i < 10; i++)
	{
		if (ch[i] == '(')
			counter++;
		if (ch[i] == ')')
			counter--;
		if (ch[i] == '{')
			counter2++;
		if (ch[i] == '}')
			counter2--;
		if (counter < 0 || counter2 < 0 || counter2 > counter)
			right = false;
	}

	if (counter == 0 && counter2 == 0 && right == true)
		cout << "Right" << endl;
	if (counter != 0 || counter2 != 0 || right == false)
		cout << "Not Right" << endl;
	
	return 0;
}


