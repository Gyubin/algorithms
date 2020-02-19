#include <stdio.h>
#include <malloc.h>

int money, cnt, len;
int dp[11][1000000];  // 계산했던 숫자에 대해서 기록
int mults[] = { 1, 10, 100, 1000, 10000, 100000 }; // 자리수

void initializeDP()
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 1000000; j++)
			dp[i][j] = -1;
}

int pickDigit(int num, int i)
{
	// 숫자에서 원하는 자리수의 숫자 리턴
	return num / mults[i] % 10;
}

int swapDigits(int num, int i, int j)
{
	// 숫자에서 i, j 자리수의 숫자를 교체
	// 각 자리수의 숫자를 골라서 원래 자리수를 곱해 빼고, 교체할 자리수를 곱해 더한다.
	int a = pickDigit(num, i);
	int b = pickDigit(num, j);
	return num + (b - a) * mults[i] + (a - b) * mults[j];
}


int getLength(int num)
{
	// 숫자의 자리수를 구하는 함수
	if (num <= 0) return -1;

	int len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return len;
}

// Memoization
int getMaxPrize(int num, int step)
{
	if (step == cnt)  // 기저 조건 : 목표 스텝에 도달했을 때 해당 "숫자" 리턴. 대소 비교 대상이 숫자임
		return num;

	if (dp[step][num] != -1)   // 도달했던 숫자라면
		return dp[step][num];  // 저장된 값을 리턴

	int &ref = dp[step][num] = 0;  // 중간 과정일 때 처음 도달했으면 값을 0으로 바꿈
	for (int i = 0; i < len; i++)  // 항상 1의 자리수부터 끝까지 기준 자리수를 잡음
	{
		for (int j = i + 1; j < len; j++)  // 기준 자리수와 이후 자리수의 숫자들을 교환
		{
			int swapNum = swapDigits(num, i, j);  // 선택 자리수를 swap
			int tmp = getMaxPrize(swapNum, step + 1);  // 스텝 증가시키고 해당 수를 다시 체크
			if (tmp > ref)  // 이전 저장된 값보다 크면 대치
				ref = tmp;
		}
	}
	return ref;  // 최종 값 리턴
}

int main()
{
	int total_case;

	freopen("input.txt", "r", stdin);
	scanf("%d", &total_case);

	for (int tc = 1; tc <= total_case; tc++)
	{
		scanf("%d %d", &money, &cnt);
		initializeDP();
		len = getLength(money);
		printf("#%d %d\n", tc, getMaxPrize(money, 0));
	}
	return 0;
}
