#include <stdio.h>
#include <malloc.h>

#define ESIZE 8
#define NSIZE 8
#define QSIZE 100

int m[NSIZE][NSIZE] = { 0 };
int visited[NSIZE] = { 0 };
int queue[QSIZE] = { 0 };
int front = -1;
int rear = -1;

bool isEmpty()
{
	return front == rear;
}

bool isFull()
{
	return rear == QSIZE - 1;
}

void enqueue(int val)
{
	queue[++rear] = val;
}

int dequeue()
{
	return queue[++front];
}

void bfs(int start_node)
{
	enqueue(start_node);
	while (!isEmpty())
	{
		int cur = dequeue();
		if (visited[cur])
			continue;
		visited[cur] = 1;
		printf("%d ", cur);
		for (int i = 0; i < NSIZE; i++)
			if (m[cur][i] == 1 && !visited[i])
				enqueue(i);
	}
	printf("\n");
}

void makeAdjacencyMatrix()
{
	// input -> 1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7
	int a, b;
	for (int i = 0; i < ESIZE; i++)
	{
		scanf("%d %d", &a, &b);
		m[a][b] = m[b][a] = 1;
	}
}

int main()
{
	makeAdjacencyMatrix();
	bfs(1);
	return 0;
}
