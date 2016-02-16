#include<iostream>

using namespace std;

void copy1(void* dst, void* src, int size)
{
	for(int i = 0; i < size; ++i)
	{
		((int*)dst)[i] = ((int*)src)[i];
	}
}

void print(int a[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		cout << a[i] << ' ';
	}
	
	cout << endl;
}

void print(double a[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		cout << a[i] << ' ';
	}
	
	cout << endl;
}

void copy2(void* dst, void* src, int size)
{
	for(int i = 0; i < size; ++i)
	{
		((char*)dst)[i] = ((char*)src)[i];
	}
}

int main()
{
	int a[10], b[10];
	
	for(int i = 0; i < 10; ++i)
	{
		a[i] = 100 * i;
	}
	
	copy1(b, a, 10);
	
	print(b, 10);
	
	double c[10], d[10];
	
	for(int i = 0; i < 10; ++i)
	{
		c[i] = 0.1 * i;
	}
	
	copy1(d, c, 10);
	print(d, 10);
	
	copy2(b, a, sizeof(a));
	print(b, 10);
	
	copy2(d, c, sizeof(c));
	print(d, 10);
}
