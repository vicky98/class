#include <iostream>
using namespace std;

class StackError 
{
	int status_;

public:
	StackError(int status) 
	{
		status_ = status;
	}
	
	int get_status() 
	{
		return status_;
	}
};

class Stack 
{
	int* data_;
	int top_;
	int size_;
	static const int chunk_ = 2; // nqma da bude unishtojena ot destruktora na kompilatora, zatova pishem nash?
	
public:
	
	Stack(int size = 2)
	{
		top_ = 0;
		size_ = size;
		data_ = new int[size_];
	}
	
	~Stack() // destruktor
	{
		cout << "calling destructor..." << endl;
		delete[] data_;
	}
	
	Stack(const Stack& other)
	{
		cout << "calling copy constructor..." << endl;
		top_ = other.top_;
		size_ = other.size_;
		data_ = new int[size_];
		for (int i = 0; i < top_; i++)
		{
			data_[i] = other.data_[i];
		}
	}
	
	Stack& operator = (const Stack& other) // operator za prisvoqvane
	{
		if (this != &other)
		{	// ne moje da viknem Stack(const Stack& other) zashtoto nqma da promeni obekta
			cout << "different object. copying..." << endl;
			top_ = other.top_;
			size_ = other.size_;
			data_ = new int[size_];
			for (int i = 0; i < top_; i++)
			{
				data_[i] = other.data_[i];
			}
		}
		
		return *this;		
	}

	bool is_empty()
	{
		return top_ == 0;
	}
	
	bool is_full() 
	{
		return top_ == size_;
	}
	
	void push(int val) 
	{
		if(is_full()) 
		{
			resize();
		}
		
		data_[top_++] = val;
	}
	
	int pop() 
	{
		if(is_empty()) 
		{
			cout << "OOOPS: stack is empty..." << endl;
			throw StackError(2);
		}
	
		return data_[--top_];
	}
	
private:
	
	void resize()
	{
		cout << "resizing..." << endl;
		size_ += chunk_;
		int* temp_ = data_;		
		data_ = new int[size_];
		for (int i = 0; i < top_; i++)
		{
			data_[i] = temp_[i];
		}
		
		delete[] temp_;
	}
	
	
};

void function(Stack st) // vika se kopi konstruktor; ako povikame referencia(Stack& st), funkciqta nqma da se izpulni
{
	cout << "pop from function: " << st.pop() << endl;
	cout << "pop from function: " << st.pop() << endl;
	st.push(100);
}

void function_by_ref(Stack& st)
{
	cout << "pop from function: " << st.pop() << endl;
	cout << "pop from function: " << st.pop() << endl;
	st.push(100);
}

/*   vika kopi konstruktor
Stack return_with()
{}
*/  

int main() 
{
	Stack st(100);
	
	//Stack st2 = st; // vika se kopi konstruktor
	//Stack st3(st);  // vika se kopi konstruktor
	
	for (int i = 0; i < 100; i++)
	{
		st.push(i);
	}
	
	function(st);  // vika kopi konstruktor 
	cout << "pop from main: " << st.pop() << endl;
	
	function_by_ref(st); // s referencia
	cout << "pop from main: " << st.pop() << endl;	

	Stack st2;
	st = st;
	st2 = st;  // prisvoqvashtiqt operator pravi sushtoto kato copy konstruktora
	
	return 0;
}
