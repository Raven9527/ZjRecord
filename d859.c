#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n, i;
    int f[1001] = {0};
    f[0] = 1;
    f[1] = 1;
    for (i = 2; i <= 1000; i++)
    {
        int k;
        for (k = 1; k <= i / 2; k++)
        {
            f[i] += f[k];
        }
        f[i]++;
    }
    scanf("%d", &n);
    printf("%d\n", f[n]);
    //system("pause");
    return 0;
}