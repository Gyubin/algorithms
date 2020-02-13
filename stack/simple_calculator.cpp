/*
문자열 수식을 입력받아서
1. 숫자는 그대로 출력하고
2. 연산자는 스택에 넣었다가 나중에 출력하는 문제
3. 숫자와 연산자 각각 한 칸씩 띄워서 출력
*/

#include <iostream>

using namespace std;

void printStack(char *stack, int * top);
void printQueue(char *queue, int * top);
void stackCalc(char *str);


int main()
{
	char input[] = "10 0+3- 28/4 *50";
	
	stackCalc(input);
	return 0;
}


void printStack(char *stack, int * top)
{
	while (*top >= 0)
		cout << stack[(*top)--] << ' ';
}


void printQueue(char *queue, int * len)
{
	for (int i = 0; i < *len; i++)
		cout << queue[i];
	cout << ' ';
	*len = 0;
}


void stackCalc(char *str)
{
	char operatorStack[1000] = { 0 };
	char operandBuffer[100] = { 0 };
	int operatorTop = -1;
	int operandLen = 0;

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			operandBuffer[operandLen++] = *str;
		else if (*str == '+' || *str == '-' || *str == '*' || *str == '/')
		{
			printQueue(operandBuffer, &operandLen);
			operatorStack[++operatorTop] = *str;
		}
		str++;
	}
	printQueue(operandBuffer, &operandLen);
	printStack(operatorStack, &operatorTop);
	cout << endl;
	return;
}
