/*
정수와 문자열 포인터를 입력으로 받아서 정수를 문자열로 바꿔 저장하는 함수
*/

#include <string.h>
#include <stdio.h>

void reverse(char *src)
{
	int len = strlen(src);

	for (int i = 0; i < len / 2; i++)
	{
		char tmp = src[i];
		src[i] = src[len - i - 1];
		src[len - i - 1] = tmp;
	}
	src[len] = '\0';
}

void itoa(int num, char *dest)
{
	int idx = 0;
	while (num)
	{
		dest[idx++] = num % 10 + '0';
		num /= 10;
	}
	dest[idx] == '\0';
	reverse(dest);
}

int main()
{
	int num = 972430240;
	char dest[100] = { 0 };

	itoa(num, dest);
	printf("%s\n", dest);

	return 0;
}
