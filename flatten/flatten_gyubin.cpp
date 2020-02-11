#include<iostream>
#define SIZE 100

using namespace std;

/*
https://swexpertacademy.com
1208. [S/W 문제해결 기본] 1일차 - Flatten
*/

void findIndices(int *arr, int *ptrMax, int *ptrMin)
{
	int tempMax = -1, tempMin = 999;
	int idxMax, idxMin;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > tempMax)
		{
			tempMax = arr[i];
			idxMax = i;
		}
		if (arr[i] < tempMin)
		{
			tempMin = arr[i];
			idxMin = i;
		}
	}
	*ptrMax = idxMax;
	*ptrMin = idxMin;
}

void dump(int *arr)
{
	int idxMax, idxMin;

	findIndices(arr, &idxMax, &idxMin);
	arr[idxMax]--;
	arr[idxMin]++;
}

int main(int argc, char** argv)
{
	int testCase;
	for (testCase = 1; testCase <= 10; ++testCase)
	{
		int arr[SIZE] = { 0 };
		int dumpNum, idxMax, idxMin;

		cin >> dumpNum;
		for (int i = 0; i < SIZE; i++)
			cin >> arr[i];
		for (int i = 0; i < dumpNum; i++)
			dump(arr);

		findIndices(arr, &idxMax, &idxMin);
		cout << "#" << testCase << " " << arr[idxMax] - arr[idxMin] << endl;
	}
	return 0;
}
