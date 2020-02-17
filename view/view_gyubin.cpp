/*
https://swexpertacademy.com
1206. [S/W 문제해결 기본] 1일차 - View
*/

#include <stdio.h>
#include <malloc.h>

int main()
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int arr[1000] = { 0 };
		int length, tmp, result = 0;

		scanf("%d", &length);
		for (int i = 0; i < length; i++)
			scanf("%d", &arr[i]);

		for (int i = 2; i < length - 2; i++)
		{
			int min_val = 99999;
			for (int j = -2; j <= 2; j++)
			{
				if (j == 0) continue;
				tmp = arr[i] - arr[i + j];
				if (tmp < min_val) min_val = tmp;
			}
			if (min_val > 0) result += min_val;
		}
		printf("#%d %d\n", test_case, result);
	}
	return 0;
}
