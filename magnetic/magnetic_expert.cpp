/*
[모범 답안]
https://swexpertacademy.com
1220. [S/W 문제해결 기본] 5일차 - Magnetic
*/

#include <iostream>

using namespace std;

int n;
int mmap[100][100];

int main() {
	int tcc = 10;
	for(int tc = 1; tc <= tcc; tc++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &mmap[i][j]);

		int ret = 0;
		for(int j = 0; j < n; j++) {
			int pre = 2;
			for(int i = 0; i < n; i++) {
				if(mmap[i][j] == 0)	continue;

				if(pre == 1 && mmap[i][j] == 2)	ret++;
				pre = mmap[i][j];
			}
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}
