#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int GetMaxValue(int a, int b)
{
    return a >= b ? a : b;
}
int GetMinValue(int a, int b)
{
    return a <= b ? a : b;
}
// 輸入商品價錢的同時計算是否購買與花費
void InputProductPriceAndComputeCount(int d, int *count, int *sum)
{
    int p1, p2, p3;
    scanf("%d %d %d", &p1, &p2, &p3);
    int max = GetMaxValue(GetMaxValue(p1, p2), p3);
    int min = GetMinValue(GetMinValue(p1, p2), p3);
    //printf("max: %d, min = %d\n", max, min);
    if (max - min >= d)
    {
        (*count) += 1;
        (*sum) += ((p1 + p2 + p3) / 3);
    }
}
void PrintAns(int count, int sum)
{
    printf("%d %d\n", count, sum);
}
int main()
{
    int n, d, i;
    int count = 0, sum = 0;
    scanf("%d %d", &n, &d);
    for (i = 0; i < n; i++)
    {
        InputProductPriceAndComputeCount(d, &count, &sum);
    }
    PrintAns(count, sum);
    //system("pause");
    return 0;
}