#include <stdio.h>
#include <malloc.h>

#define NSIZE 8
#define ESIZE 8

int m[NSIZE][NSIZE] = { 0 };
int visited[NSIZE] = { 0 };
int stack[1000] = { 0 };
int top = -1;

bool isEmpty()
{
	return top < 0;
}

int pop()
{
	return stack[top--];
}

void push(int n)
{
	stack[++top] = n;
}

bool isVisited(int n)
{
	return visited[n];
}

void dfs(int start_node)
{
	push(start_node);
	while (!isEmpty())
	{
		int node = pop();
		if (isVisited(node))
			continue;
		visited[node] = 1;
		printf("%d ", node);
		for (int j = NSIZE - 1; j >= 1; j--)
			if (m[node][j] && !isVisited(j))
				push(j);
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
		m[a][b] = 1;
		m[b][a] = 1;
	}
}

int main()
{
	makeAdjacencyMatrix();
	dfs(1);
	return 0;
}
