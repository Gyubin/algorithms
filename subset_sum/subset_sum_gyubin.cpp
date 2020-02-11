#include <iostream>
using namespace std;

#define SIZE 10

/*
10개의 수를 입력받아서 집합을 만든다.
공집합을 제외하고 부분집합 중에서 원소의 합이 0인 것이 있는지 확인.
있으면 O를, 없으면 X를 출력한다.
*/

void main(void)
{
	int n = SIZE, flag = 0, sub_sum;
	int arr[SIZE] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < (1 << (n)); i++)  // 부분집합 개수: n개의 서로 다른 원소를 가지는 집합의 부분집합 개수는 2의 n승
	{
		sub_sum = 0;
		for (int j = 0; j < n; j++)  // 각 부분집합마다 가능한 원소의 개수만큼 반복
		{
			/*
			부분집합의 개수가 16개면 0부터 15까지 정수의 이진표기법이 곧 부분집합 표기가 됨
			1을 비트 단위로 이동시키면서 비교하여 1이라면 출력하는 형태로 부분집합 원소 체크 가능
			*/
			if (i & (1 << j))
			{
				sub_sum += arr[j];
			}
		}
		if (sub_sum == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
		printf("O\n");
	else
		printf("X\n");
}
