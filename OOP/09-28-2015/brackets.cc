#include <iostream>

using namespace std;

int main()
{
	char ch[10];
	int counter = 0;
	bool right = true;

	cin >> ch;

	for (int i = 0; i < 10; i++)
	{
		if (ch[i] == '(')
			counter++;
		if (ch[i] == ')')
			counter--;
		if (counter < 0)
			right = false;
	}

	if (counter == 0 && right == true)
		cout << "Right" << endl;
	else // (counter != 0 || right == false)
		cout << "Not Right" << endl;

	return 0;
}