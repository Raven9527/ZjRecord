#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 得到總共需要花的時間
int GetCostTime(int m, int rate)
{
    int t = (m / rate);
    if (m % rate != 0)
        t++;
    return t;
}
void PrintAns(int remainTime, int h, int m, int s)
{
    printf("%d %d %d. ", h, m, s);
    if (remainTime >= 0)
        printf("I will make it!\n");
    else
        printf("I will be late!\n");
}
int main()
{
    int h, m, s;
    while(scanf("%d %d %d", &h, &m, &s) != EOF)
    {
        int costTime = GetCostTime(m, s);
        PrintAns(h - costTime, h, m, s);
    }
    return 0;
}