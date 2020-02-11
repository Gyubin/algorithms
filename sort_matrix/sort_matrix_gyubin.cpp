#include <stdio.h>

#define SIZE1 7
#define SIZE2 25
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

/*
주어진 2차원 배열을 아래처럼 정렬하여 출력하기
{
	{ 1,  2,  3,  4, 5},
	{16, 17, 18, 19, 6},
	{15, 24, 25, 20, 7},
	{14, 23, 22, 21, 8},
	{13, 12, 11, 10, 9}
}
*/

void initMatrices();
void flatten();
void swap(int *a, int *b);
int partition(int low, int high);
void quickSort(int low, int high);
void fillMatrix();
int fill(int x, int y, int direction);
int getDirection(int x, int y);
void printMatrix();

int matrix[SIZE1-2][SIZE1-2] =
{
	{  9, 20,  2, 18, 11 },
	{ 19,  1, 25,  3, 21 },
	{  8, 24, 10, 17,  7 },
	{ 15,  4, 16,  5,  6 },
	{ 12, 13, 22, 23, 14 }
};
int arr[SIZE2] = { 0 };
int result[SIZE1][SIZE1] = { 0 };
int visited[SIZE1][SIZE1] = { 0 };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int arrIdx = 0;

int main()
{
	// 매트릭스 초기화 후 1차원 배열로 변환
	initMatrices();
	flatten();

	// 정렬
	quickSort(0, SIZE2 - 1);

	// 매트릭스 만들기
	fillMatrix();

	// 매트릭스 출력
	printMatrix();

	return 0;
}

void initMatrices()
{
	for (int i = 0; i < SIZE1; i++)
		for (int j = 0; j < SIZE1; j++)
			if (i == 0 || i == SIZE1 - 1 || j == 0 || j == SIZE1 - 1)
			{
				result[i][j] = 1;
				visited[i][j] = 1;
			}
}

void flatten()
{
	for (int i = 0; i < SIZE1 - 2; i++)
	{
		for (int j = 0; j < SIZE1 - 2; j++)
		{
			arr[i * 5 + j] = matrix[i][j];
		}
	}
}

void swap(int *a, int *b)
{
	if (*a != *b) *a ^= *b ^= *a ^= *b;
}

int partition(int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int low, int high)
{
	if (low < high)
	{
		int pi = partition(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}

void fillMatrix()
{
	int x = 1, y = 1, direction = RIGHT, flag;

	while (1)
	{
		if (direction == -1)
			break;
		flag = 1;
		while (flag)
		{
			flag = fill(x, y, direction);
			if (flag == 0)
				direction = getDirection(x, y);
			x += dx[direction];
			y += dy[direction];
		}
	}
}

int fill(int x, int y, int direction)
{
	result[x][y] = arr[arrIdx++];
	visited[x][y]++;
	if (visited[x + dx[direction]][y + dy[direction]] == 1)
		return 0;
	return 1;
}

int getDirection(int x, int y)
{
	if (x == 1 && y == 1)
	{
		return RIGHT;
	}
	else if ((visited[x + dx[DOWN]][y] == 1) &&
			 (visited[x][y + dy[LEFT]] == 1) &&
			 (visited[x + dx[UP]][y] == 0))
	{
		return UP;  // 하,좌 X -> 상
	}
	else if ((visited[x + dx[UP]][y] == 1) &&
		     (visited[x][y + dy[LEFT]] == 1) &&
			 (visited[x][y + dy[RIGHT]] == 0))
	{
		return RIGHT;  // 상,좌 X -> 우
	}
	else if ((visited[x + dx[UP]][y] == 1) &&
			 (visited[x][y + dy[RIGHT]] == 1) &&
			 (visited[x + dx[DOWN]][y] == 0))
	{
		return DOWN;  // 상,우 X -> 하
	}
	else if ((visited[x + dx[DOWN]][y] == 1) &&
			 (visited[x][y + dy[RIGHT]] == 1) &&
			 (visited[x][y + dy[LEFT]] == 0))
	{
		return LEFT;  // 하,우 X -> 좌
	}
	else
	{
		return -1;
	}
}

void printMatrix()
{
	for (int i = 1; i < SIZE1; i++)
	{
		for (int j = 1; j < SIZE1; j++)
		{
			if (i == SIZE1 - 1 || j == SIZE1 - 1)
				continue;
			else
				printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}
