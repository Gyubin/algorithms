/*
https://swexpertacademy.com
1220. [S/W 문제해결 기본] 5일차 - Magnetic
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

#define N 1
#define S 2

int table[100][100] = { 0 };

int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int count = 0;
		int size;
		scanf("%d", &size);

		// Initialize table
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				scanf("%d", &table[i][j]);

		// Check
		for (int col = 0; col < size; col++)
		{
			int stack[10000] = { 0 };
			int top = -1;
			
			for (int row = 0; row < size; row++)
			{
				int val = table[row][col];

				if (val == N && top == -1)
					stack[++top] = val;
				else if (val == S && top != -1)
				{
					if (stack[top] == val)
						stack[++top] = val;
					else
					{
						count++;
						top = -1;
					}
				}
			}
		}
		printf("#%d %d\n", test_case, count);
	}
	return 0;
}
