/*
문자열 뒤집는 함수 직접 c로 구현
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

int main()
{
	char str[] = "abcdefg zzz";

	printf("original: %s\n", str);
	reverse(str);
	printf("reversed: %s\n", str);

	return 0;
}
