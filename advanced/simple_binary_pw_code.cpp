/*
https://swexpertacademy.com/
[S/W 문제해결 응용] 1일차 - 단순 2진 암호코드
expert님의 코드를 대부분 참고함
*/

#include <stdio.h>
#include <malloc.h>

/*
주석 명칭 통일
암호 숫자 : 7자리 비트가 표현되는 0-9의 숫자 하나
암호 코드 : 암호 숫자 8개로 이루어지는 문제에서 찾아야할 숫자 집합
암호 테이블 : 암호 숫자의 비트 매핑 정보가 기록되어있는 매트릭스
*/

int crypto[10][4] =
{
	{ 3, 2, 1, 1 },  // 0
	{ 2, 2, 2, 1 },  // 1
	{ 2, 1, 2, 2 },  // 2
	{ 1, 4, 1, 1 },  // 3
	{ 1, 1, 3, 2 },  // 4
	{ 1, 2, 3, 1 },  // 5
	{ 1, 1, 1, 4 },  // 6
	{ 1, 3, 1, 2 },  // 7
	{ 1, 2, 1, 3 },  // 8
	{ 3, 1, 1, 2 }   // 9
};
int row, col;
int matrix[51][101];

void fillMatrix()
{
	scanf("%d %d", &row, &col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			scanf("%1d", &matrix[i][j]);
}

int sumArray(int arr[], int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int decryptSingle(int x, int y)
{
	for (int i = 0; i <= 9; i++)  // 암호 테이블 10개 순환하면서 암호 숫자 찾기
	{
		int tmp_y = y;
		bool check = true;
		for (int j = 0, k = 0; j < 4; j++, k ^= 1)  // 비트 정보 4개 체크 
		{
			int n = crypto[i][j];
			while (n--)
			{
				if (matrix[x][tmp_y] != k)
				{
					check = false;
					break;
				}
				++tmp_y;
			}
			if (!check) break;
		}
		if (check) return i;
	}
	return -1;
}

bool decrypt(int x, int y, int res[8])
{
	for (int i = 0; i < 8; i++)
	{
		int num = decryptSingle(x, y + i * 7);  // 다음 숫자 parse
		if (num == -1)
			return false;
		res[i] = num;
	}
	return true;
}

bool check(int code[8])
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
		sum += code[i] * (i % 2 ? 1 : 3);
	return sum % 10 == 0;
}

int solve()
{
	int decrypted[8];  // 8자리의 암호 코드
	for (int x = 0; x < row; x++)
		for (int y = 0; y < col; y++)
			if (decrypt(x, y, decrypted))
				if (check(decrypted))
					return sumArray(decrypted, 8);
	return 0;
}

int main()
{
	int total_case, answer;
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &total_case);

	for (int tc = 1; tc <= total_case; tc++)
	{
		fillMatrix();
		answer = solve();
		printf("#%d %d\n", tc, answer);
	}
	return 0;
}
