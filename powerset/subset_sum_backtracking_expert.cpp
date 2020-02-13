/*
[모범 답안]
주어진 모집단의 멱집합 중 합이 10인 부분집합 찾아서 출력하기
DFS, Backtracking 사용
*/

#include <stdio.h>
#include <malloc.h>

int set[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int candidate[10];
int cansize = 0;
int nsol = 0;

void backtrack(int sum, int k) {
	if (k >= 10) return;
	if (sum > 10) return;
	if (sum == 10) {
		nsol++;
		for (int i = 0; i < cansize; i++) {
			printf("%d ", candidate[i]);
		}
		printf("\n");
		return;
	}

	for (int i = k; i < 10; i++) {
		candidate[cansize++] = set[i];
		backtrack(sum + set[i], i + 1);
		cansize--;
	}
}

int main() {
	printf("Find subsets:\n");
	backtrack(0, 0);
	printf("Total number of solutions: %d\n", nsol);
	return 0;
}
