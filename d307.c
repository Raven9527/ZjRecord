#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 32768
int pr[MAX];
int main()
{
    int n, i, k;
    memset(pr, 1, sizeof(pr));
    for (i = 3; i * i <= MAX; i += 2)
    {
        for (k = 2; i * k <= MAX; k++)
            pr[i * k] = 0;
    }
    pr[1] = 0;
    /*for (i = 3; i <= MAX; i += 2)
    {
        if(pr[i])
            printf("%d ", i);
    }*/
    int stage = 1;
    while (scanf("%d", &n) != EOF)
    {
        int sum = 0;
        if (n == 0)
            break;

        for (i = 3; i <= MAX; i += 2)
        {
            if (i > n / 2)
                break;
            if (pr[n - i] && pr[i])
            {
                sum++;
            }
        }
        if(n == 4)
            sum = 1;
        printf("%d\n", sum);
    }
    return 0;
}