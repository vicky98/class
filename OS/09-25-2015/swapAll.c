// ne raboti

#include <stdio.h>

void swap(void* a, void* b, size_t size)
{
	size_t i;
	char xap = a;
	char xbp = b;

	for (i = 0; i < size; i++)
	{
		char tmp;
		tmp = ap[i];
		ap[i] = bp[i];
		bp[i] = tmp;
	}
}

int main()
{
	int a[200];
	int b[200];

	swap(a, b, 200 * sizeof(int));
	/*
	float x, y;
	swap(x, y, sizeof(float));
	*/
	return 0;
}