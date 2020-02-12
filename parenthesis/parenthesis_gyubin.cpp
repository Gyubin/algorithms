/*
https://swexpertacademy.com
1218. [S/W 문제해결 기본] 4일차 - 괄호 짝짓기
*/

#include<iostream>

#define SIZE 10000

using namespace std;

int main(int argc, char** argv)
{
	char table[256] = { 0 };
	table['('] = ')';
	table['['] = ']';
	table['<'] = '>';
	table['{'] = '}';
	
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		char stack[SIZE] = { 0 };
		int top = -1;
		int num, flag;
		char arr[SIZE] = { 0 };
		
		cin >> num;
		cin >> arr;
		
		flag = 0;
		for (int i = 0; i < num; i++)
		{
			if (table[arr[i]])
			{
				stack[++top] = arr[i];
				flag = 1;
			}
			else
			{
				if (table[stack[top]] == arr[i])
					stack[top--] = 0;
				else
					flag = 0;
			}
			if (flag == 0)
				break;
		}
		cout << '#' << test_case << ' ';
		if (top == -1 && flag == 1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
