#include <stdio.h>
#include <malloc.h>
#include <cstdlib>
#include <assert.h>

#define SIZE 1000

using namespace std;

void swap(int *a, int *b)
{
	if (*a != *b)
		*a ^= *b ^= *a ^= *b;
}

void insertionSort(int *data, int len)
{
	for (int i = 1; i < len; i++)
		for (int j = i; j >= 0; j--)
		{
			if (data[j] < data[j - 1])
				swap(&data[j], &data[j - 1]);
			else
				break;
		}
}

int main(void)
{
	int data[SIZE];
	for (int i = 0; i < SIZE; i++)
		data[i] = rand();
	insertionSort(data, SIZE);

	for (int i = 0; i < SIZE - 1; i++)
		assert(data[i] <= data[i + 1]);
	return 0;
}
