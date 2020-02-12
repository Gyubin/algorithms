/*
https://swexpertacademy.com
1213. [S/W 문제해결 기본] 3일차 - String
*/

#include<iostream>

using namespace std;

int myStrLen(char * str)
{
	int len = 0;
	while (*str++)
		len++;
	return len;
}

int myStrCompare(char * context, int idx, char * pattern)
{
	int pattern_len = myStrLen(pattern);
	for (int i = 0; i < pattern_len; i++)
	{
		if (context[idx + i] != pattern[i])
			return 0;
	}
	return 1;
}

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		char pattern[11];
		char context[1001];
		int result = 0;
		cin >> test_case;
		cin >> pattern;
		cin >> context;

		for (int i = 0; i < myStrLen(context); i++)
			result += myStrCompare(context, i, pattern);
		printf("#%d %d\n", test_case, result);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
