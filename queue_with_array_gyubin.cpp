#include <stdio.h>
#include <malloc.h>

#define QUEUE_SIZE 100

int queue[QUEUE_SIZE];
int head = 0, tail = 0;

void enqueue(int value)
{
	queue[tail++] = value;
}

int dequeue(int value)
{
	return queue[head++];
}

bool isEmpty()
{
	return head == tail;
}

int main()
{
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		enqueue(data[i]);
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		printf("%d ", dequeue(data[i]));
	printf("\n");

	return 0;
}
