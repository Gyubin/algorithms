#include<iostream>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

/*
https://swexpertacademy.com
1206. [S/W 문제해결 기본] 1일차 - View
*/

int getMin(int pp, int p, int n, int nn)
{
	return MIN(MIN(MIN(pp, p), n), nn);
}

int main(int argc, char** argv)
{
	int testCase;
	int T;

	for (testCase = 1; testCase <= 10; ++testCase)
	{
		int arr[1000] = { 0 };
		int length, pp, p, n, nn, result, minVal;
		
		cin >> length;
		for (int i = 0; i < length; i++)
			cin >> arr[i];

		result = 0;
		for (int i = 2; i < length - 2; i++)
		{
			pp = arr[i] - arr[i - 2];
			p = arr[i] - arr[i - 1];
			n = arr[i] - arr[i + 1];
			nn = arr[i] - arr[i + 2];
			minVal = getMin(pp, p, n, nn);
			if (minVal > 0)
				result += minVal;
		}
		cout << "#" << testCase << " " << result << endl;
	}
	return 0;
}
