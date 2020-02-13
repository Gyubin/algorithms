/*
주어진 모집단의 멱집합 중 합이 10인 부분집합 찾아서 출력하기
DFS, Backtracking 사용
*/

#include <iostream>
#define LEFT 1
#define RIGHT 2

using namespace std;

int target_sum = 10;
int population[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int powerset[100] = { 0 };
int len_powerset = 0;


void printPowerset()
{
	cout << "{ ";
	for (int i = 0; i < len_powerset; i++)
		cout << powerset[i] << ' ';
	cout << "}" << endl;
}

int getPowersetSum()
{
	int result = 0;
	for (int i = 0; i < len_powerset; i++)
		result += powerset[i];
	return result;
}

void addToPowerset(int pop_id)
{
	powerset[len_powerset] = population[pop_id];
	len_powerset++;
}

void removeFromPowerset()
{
	len_powerset--;
	powerset[len_powerset] = 0;
}

void backtrack(int pop_id, int len, int direction)
{	
	int sum = getPowersetSum();
	if (direction == LEFT && sum == target_sum)
		printPowerset();
	if (pop_id <= len && sum < target_sum)
	{
		addToPowerset(pop_id);
		backtrack(pop_id + 1, len, LEFT);

		removeFromPowerset();
		backtrack(pop_id + 1, len, RIGHT);
	}
}

int main()
{
	int len = sizeof(population) / sizeof(population[0]);
	backtrack(0, len, LEFT);

	return 0;
}
