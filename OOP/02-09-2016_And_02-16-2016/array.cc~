#include <iostream>

using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

class ArrayError{};

template<typename T>
class Array
{
	T* data_;  // durjim elementite tuk
	int size_;
	int capacity_;	
		
	void resize()
	{
		int new_capacity = MAX(2 * capacity_, 1);
		T* new_data = new T[new_capacity];
		
		for (int i = 0; i < capacity_; ++i)
		{
			new_data{i] = data_[i];
		}
		
		delete [] data_;
		data_ = new_data;
		capacity_ = new_capacity;
	}
	
public:
	
	Array()
	: size_(0),
	capacity_(0),
	data_(0)
	{}
	
	void push_back(T val)
	{
		if (size_ >= capacity_)
		{
			resize(1);
		}
		
		data_[size++] = val;
	}
	
	bool empty() const
	{
		return size_ == 0;
	}
	
	T front() const
	{
		return data_[0];
	}
	
	T back() const
	{
		if (empty())
		{
			throw ArrayError();
		}
		
		return data_[size_ - 1];
	}
};

int main()
{
	Array<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	cout << "front: " << a.front() << endl;
	cout << "back: " << a.back() << endl;

	return 0;
}
