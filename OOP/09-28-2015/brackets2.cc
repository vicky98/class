// nedovurshena i ne raboti

#include <iostream>

using namespace std;

int main()
{
	char ch[10];
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;
	int counter4 = 0;
	bool right = true;

	cin >> ch;

	for (int i = 0; i < 10; i++)
	{
		if (ch[i] == '(')
			counter++;
		if (ch[i] == ')')
			counter2++;
		if (ch[i] == '{')
			counter3++;
		if (ch[i] == '}')
			counter4++;

		/*
		if (counter == 0 && counter2 > 0 && counter2 % 2 == 0)
			right = true;
		else if (counter < 0 || counter2 < 0 || counter2 > counter)
			right = false;
		*/
		
		if ((counter == 0 && counter2 == 0 && counter3 == counter4 && counter3 > 0 && counter3 % 2 == 0) || (counter4 == 0 && counter3 == 0 && counter == counter2 && counter > 0 && counter % 2 == 0))
		{	
			right = true;
			break;
		} 
		else if (counter == counter2 && counter3 == counter4 && counter >= counter3)
		{
			right = true;
			break;
		}
		else if (counter != counter2 || counter3 != counter4 || counter3 > counter)
		{
			right = false;
			break;
		}
	}

	if (right == true)
		cout << "Right" << endl;
	else // (right == false)
		cout << "Not Right" << endl;

	return 0;
}