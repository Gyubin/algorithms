/*
https://swexpertacademy.com
1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱
*/

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		int base, mult, result;

		cin >> test_case;
		cin >> base >> mult;

		result = 1;
		for (int i = 0; i < mult; i++)
			result *= base;

		cout << '#' << test_case << ' ' << result << endl;
	}
	return 0;
}
