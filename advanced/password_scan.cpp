/*
https://swexpertacademy.com
[S/W 문제해결 응용] 1일차 - 암호코드 스캔
expert님의 코드를 많이 참조함
*/

#include <stdio.h>
#include <malloc.h>

char m[2222][2222] = { 0 };
int table[111];
 
void initializeTable()
{
    for (int i = 0; i < 111; i++)
        table[i] = -1;
    table[13] = 0;
    table[25] = 1;
    table[19] = 2;
    table[61] = 3;
    table[35] = 4;
    table[49] = 5;
    table[47] = 6;
    table[59] = 7;
    table[55] = 8;
    table[11] = 9;
}
 
int hexaToOct(char c)
{
    int num = 0;
    if (c >= '0' && c <= '9')
        num += c - '0';
    else if (c >= 'A' && c <= 'F')
        num += c - 'A' + 10;
    return num;
}
 
void fillMatrix(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        scanf("\n");
        for (int j = 0; j < col; j+=4)
        {
            char tmp;
            scanf("%c", &tmp);
            int num = hexaToOct(tmp);
 
            for (int idx = 3; idx >= 0; idx--)
            {
                m[i][j + idx] = '0' + num % 2;
                num /= 2;
            }
        }
    }
}
 
void flattenMatrix(int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (m[i + 1][j] == '1')
                m[i][j] = '0';
}
 
int decode(int r, int c, int len)
{
    // m[r][c] 원소를 암호코드의 시작으로 
    int sum = 0;
    int test = 0;
    for (int i = 0; i < 8; i++)  // 총 8개 암호코드를 찾아야 함
    {
        int val = 0;  // 이진화한 암호코드
        for (int j = 0; j < 7; j++)
        {
            val *= 2;  // 이진화해서 가장 왼쪽부터 탐색하기 때문에 우측으로 갈수록 2배
            val += m[r][c + 7 * i * len + j * len + len - 1] - '0';
        }
 
        if (table[val] == -1)  // 암호코드가 존재하지 않음. 바로 종료
            return -1;
 
        sum += table[val];  // 정답으로 쓸 암호코드들의 합
        test += table[val] * (i % 2 ? 1 : 3);  // 검증에 쓰일 값 계산
    }
    return test % 10 ? 0 : sum;
}
 
void scanPassword(int tc, int row, int col)
{
    // 3단계 : 가장 오른쪽 아래에 있는 1부터 시작해서 유효한 암호들을 찾아나간다.
    // 해독한 암호는 지워버린다.
    int ans = 0;
    for (int i = row - 1; i >= 0; i--)  // 오른쪽 끝부터
        for (int j = col - 1; j >= 0; j--)  // 맨 아래부터
            if (m[i][j] == '1')  // 모든 암호 코드의 끝이 1이므로 발견하면 탐색 시작
                for (int k = 1; ; k++)  // 암호코드 크기를 나타내는 배수
                {
                    // i : 시작 row
                    // j - 56 * k + 1 : 시작 column
                    int tmp = decode(i, j - 56 * k + 1, k);
                    if (tmp == -1)  // 찾지 못했으면 다음 배수 탐색(2배수, 3배수, ...)
                        continue;
                    ans += tmp;  // 정상적인 암호코드 찾았으면 정답에 추가 합산
                    for (int a = j - 56 * k + 1; a <= j; a++)  // 찾았으면 해당 라인 삭제
                        m[i][a] = '0';
                    break;
                }
    printf("#%d %d\n", tc, ans);
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
 
    int total_case;
    scanf("%d", &total_case);
 
    initializeTable();
    for (int tc = 1; tc <= total_case; tc++) 
    {
        int row, col;
        scanf("%d %d", &row, &col);
        col *= 4;
 
        fillMatrix(row, col);
        flattenMatrix(row, col);
 
        scanPassword(tc, row, col);
    }
 
    return 0;
}
