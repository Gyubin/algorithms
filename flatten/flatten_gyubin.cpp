/*
https://swexpertacademy.com
1208. [S/W 문제해결 기본] 1일차 - Flatten
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 100

void findIndices(int *arr, int *ptr_max, int *ptr_min)
{
	int temp_max = -1, temp_min = 999;
	int idx_max, idx_min;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > temp_max)
		{
			temp_max = arr[i];
			idx_max = i;
		}
		if (arr[i] < temp_min)
		{
			temp_min = arr[i];
			idx_min = i;
		}
	}
	*ptr_max = idx_max;
	*ptr_min = idx_min;
}

void dump(int *arr)
{
	int idx_max, idx_min;

	findIndices(arr, &idx_max, &idx_min);
	arr[idx_max]--;
	arr[idx_min]++;
}

int main()
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int arr[SIZE] = { 0 };
		int dump_num, idx_max, idx_min;

		scanf("%d", &dump_num);
		for (int i = 0; i < SIZE; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < dump_num; i++)
			dump(arr);

		findIndices(arr, &idx_max, &idx_min);
		printf("#%d %d\n", test_case, arr[idx_max] - arr[idx_min]);
	}
	return 0;
}
