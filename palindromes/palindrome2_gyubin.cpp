/*
https://swexpertacademy.com
1216. [S/W 문제해결 기본] 3일차 - 회문2
*/

#include<iostream>

#define SIZE 100

using namespace std;

char matrix[SIZE][SIZE + 1] = { 0 };  // '\0' 포함

int checkPalindrome(int x, int y, int len)
{
	int flag1 = 1, flag2 = 1;
	for (int i = 0; i < len / 2; i++)
	{
		if (flag1 + flag2 == 0) return 0;

		if (x + len - i - 1 >= SIZE || x + i >= SIZE)
			flag1 = 0;
		else if (matrix[x + i][y] != matrix[x + len - i - 1][y])
			flag1 = 0;
		
		if (y + len - i - 1 >= SIZE || y + i >= SIZE)
			flag2 = 0;
		else if (matrix[x][y + i] != matrix[x][y + len - i - 1])
			flag2 = 0;
	}
	return flag1 + flag2;
}

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> test_case;
		int result = 0;
		int flag = 0;

		for (int i = 0; i < SIZE; i++)
			cin >> matrix[i];

		for (int len = SIZE; len > 0; len--)
		{
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (checkPalindrome(i, j, len))
					{
						result = len;
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}

		cout << '#' << test_case << ' ' << result << endl;
	}
	return 0;
}
