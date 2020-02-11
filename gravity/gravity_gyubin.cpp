#include <iostream>
using namespace std;

/*
첫 줄에 테스트 케이스 개수 입력받음(ex. 1)
이후에 테스트 케이스 마다 다음 두 줄을 입력받음
1. 매트릭스의 가로, 세로 길이(ex. 9 8)
2. 막대 그래프의 길이들(ex. 7 4 2 0 0 6 0 7 0)
*/

int main()
{
	int num_test, row, col;  // 테스트 개수, 행, 열 변수 선언
	int height, count, answer;  // 높이, 개수, 정답 변수
	int dp[100][100] = { 0 };  // 블록이 있는 위치를 기록할 매트릭스

	cin >> num_test;  // test case 개수
	for (int t = 0; t < num_test; t++)  // test case 반복	
	{
		cin >> col >> row; // 가로 길이 col(9), 세로 길이 row(8) 입력 받기

		for (int c = 0; c < col; c++)  // 매트릭스에 블록 위치한 부분 1로 표시
		{
			cin >> height;
			int tmp = row - height;
			for (int r = row-1; r >= tmp; r--)
			{
				dp[r][c] = 1;
			}
		}

		answer = 0;  // 테스트 케이스마다 출력할 정답
		for (int r = 0; r < row; r++)  // row 순서대로 반복
		{
			count = 0;
			for (int c = col - 1; c > -1; c--)  // column 역순으로 순회하면서 count 누적
			{
				if (dp[r][c] == 1)
				{
					if (count > answer)
					{
						answer = count;
					}
				}
				else
				{
					count++;
				}
			}
		}
		cout << answer << endl;
	}
	return 0;
}
