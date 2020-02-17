/*
https://swexpertacademy.com
1209. [S/W 문제해결 기본] 2일차 - Sum
*/

#include <stdio.h>
#include <malloc.h>

int max(int *arr, int len)
{
	int max_val = 0;
	for (int i = 0; i < len; i++)
		if (arr[i] > max_val) max_val = arr[i];
	return max_val;
}

int main()
{
	for (int tc = 1; tc <= 10; tc++)
	{
		int answer[202] = { 0 };
		scanf("%d", &tc);

		int arr[100][100] = { 0 };
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				scanf("%d", &arr[i][j]);

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				answer[i] += arr[i][j];  // row sum
				answer[100+j] += arr[i][j];  // col sum
				if (i == j) answer[200] += arr[i][j];
				if (i == -j) answer[201] += arr[i][j];
			}
		}
		printf("#%d %d\n", tc, max(answer, 202));
	}
	return 0;
}
