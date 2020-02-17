/*
https://swexpertacademy.com/
최빈수 구하기
*/

#include <stdio.h>

int main(void)
{
	int test_case;
	int T;
	int score, mode_score, mode_count;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &test_case);

		int arr[101] = { 0 };
		mode_score = -1;
		mode_count = -1;
		for (int i = 0; i < 1000; i++)
		{
			scanf("%d", &score);
			arr[score]++;
		}

		for (int i = 0; i < 101; i++)
		{
			if (arr[i] >= mode_count)
			{
				mode_count = arr[i];
				mode_score = i;
			}
		}
		printf("#%d %d\n", test_case, mode_score);
	}
	return 0;
}
