#include <stdio.h>

void swap(int *a, int *b)
{
	if (*a != *b)
		*a ^= *b ^= *a ^= *b;
}

void selectionSortLoop(int arr[], int len)
{
	int min;  // 최소값의 인덱스를 저장
	for (int i = 0; i < len - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < len; j++)
			if (arr[j] < arr[min])
				min = j;  // 더 작은 값의 인덱스로 대체
		swap(&arr[i], &arr[min]);
	}
}

void selectionSortRecursion(int arr[], int len, int start_idx) {
	if (start_idx == len)
		return;

	int min = start_idx;
	for (int i = start_idx + 1; i < len; i++)
		if (arr[i] < arr[min])
			min = i;
	swap(&arr[start_idx], &arr[min]);
	selectionSortRecursion(arr, len, start_idx + 1);
}

int main() {
	int arr[10] = { 39, 49, 2, 1, 0, 23, 18, 40, 199, 9 };

	selectionSortLoop(arr, 10);
	// selectionSortRecursion(arr, 10, 0);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
