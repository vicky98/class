#include <iostream>
using namespace std;

class Stack
{
	int data_[10];
	int top_;
	
public:
	
	Stack() : top_(0) {}
	
	void push_back(int val)
	{
		data_[++top_] = val;
	}
	
	int pop_back()
	{
		return data_[--top_];
	}
};

int main() {

	return 0;
}
