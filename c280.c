#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    long long f[82];
    int n, i;
    f[1] = 1;
    f[2] = 1;
    for (i = 3; i < 81; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    scanf("%d", &n);
    printf("%lld\n",f[n]);
    return 0;
}