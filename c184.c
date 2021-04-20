#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int FindFoctorSum(int n)
{
    int i, sum = 0;
    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        int i, AnotherN = 0, OtherN = 0;
        AnotherN = FindFoctorSum(n); // 284
        OtherN = FindFoctorSum(AnotherN); // 220
        if(AnotherN == n)
            printf("=%d\n", n);
        else if (OtherN == n)
            printf("%d\n", AnotherN);
        else
            printf("0\n");
    }
    return 0;
}