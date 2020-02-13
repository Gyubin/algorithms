/*
https://swexpertacademy.com
1221. [S/W 문제해결 기본] 5일차 - GNS
*/

#include <stdio.h>
#include <malloc.h>

int gnsToInt(char *buf)
{
	switch (buf[0]) {
	case 'Z':
		return 0;
	case 'O':
		return 1;
	case 'T':
		if (buf[1] == 'W') return 2;
		else return 3;
	case 'F':
		if (buf[1] == 'O') return 4;
		else return 5;
	case 'S':
		if (buf[1] == 'I') return 6;
		else return 7;
	case 'E':
		return 8;
	default:
		return 9;
	}
}

int main()
{
	int total_case;
	scanf("%d", &total_case);

	for (int tc = 1; tc <= total_case; tc++)
	{
		int num;
		scanf(" #%d %d", &tc, &num);

		char gns[5];
		int cnt[10] = { 0 };
		for (int i = 0; i < num; i++)
		{
			scanf("%s", gns);
			cnt[gnsToInt(gns)]++;
		}

		const char * dict[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };
		printf("#%d\n", tc);
		for (int i = 0; i < 10; i++)
			for (int c = 0; c < cnt[i]; c++)
				printf("%s ", dict[i]);
		printf("\n");
	}

	return 0;
}
