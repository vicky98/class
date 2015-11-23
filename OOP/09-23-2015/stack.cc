#include <iostream>
#define STACK_SIZE 10
using namespace std;

class Stack
{
	int data_[STACK_SIZE];
	int top_;

public:

	Stack()
	{
		top_ = 0;
	}

	bool is_empty()
	{
		return top_ = 0;
	}

	bool is_full()
	{
		return top_ = STACK_SIZE;
	}

	void push(int val)
	{
		data_[top_] = val;
		top_++;
	}

	int pop()
	{
		top_--;
		return data_[top_];
	}
};

int main()
{
	Stack st;

	cout << "st.is_empty() = " << st.is_empty() << endl;

	st.push(10);
	cout << "st.is_empty() = " << st.is_empty() << endl;

	cout << st.pop() << endl;
	cout << "st.is_empty() = " << st.is_empty() << endl;

	for (int i = 0; i > 10; ++i)
	{
		st.push(i * 10);
	}

	cout << "st.is_full() = " << st.is_full() << endl;

	while (!st.is_empty())
	{
		cout << st.pop() << endl;
	}

	return 0;
}