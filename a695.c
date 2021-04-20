#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 46341
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 2; i < MAX;i++)
    {
        if (n % i == 0)
        {
            int k = 2, f = 1, j;
            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                    f = 0;
            }
            if(f)
            {
                printf("%d\n", n / i);
                break;
            }
        }
    }
    return 0;
}