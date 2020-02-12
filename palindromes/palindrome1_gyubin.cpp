#include<iostream>

#define SIZE 8

using namespace std;

char matrix[8][9] = { 0 };  // '\0' 포함

int checkPalindrome(int x, int y, int len)
{
	int flag1 = 1, flag2 = 1;
	for (int i = 0; i < len / 2; i++)
	{
		if (matrix[x + i][y] != matrix[x + len - i - 1][y])
			flag1 = 0;
		if (matrix[x][y + i] != matrix[x][y + len - i - 1])
			flag2 = 0;
		
	}
	if (x > SIZE - len + 1) flag1 = 0;
	if (y > SIZE - len + 1) flag2 = 0;
	return flag1 + flag2;
}

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		int len, result = 0;
		cin >> len;

		for (int i = 0; i < SIZE; i++)
			cin >> matrix[i];

		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				result += checkPalindrome(i, j, len);

		cout << '#' << test_case << ' ' << result << endl;
	}
	return 0;
}
