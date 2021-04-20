#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char inp[200005];
char p1[10000005], p2[10000005];
int main()
{
    int n, m, i, j;
    int dep[128];
    memset(dep, 0, sizeof(dep));
    for (i = '0'; i <= 'z'; i++)
    {
        dep[i] = i;
    }
    scanf("%d %d", &n, &m);
    scanf("%s %s %s", inp, p1, p2);
    for (i = 0; i < m; i++)
    {
        for (j = '0'; j <= 'z'; j++)
        {
            if(dep[j] == p1[i])
            {
                dep[j] = p2[i];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        inp[i] = dep[inp[i]];
    }
    printf("%s\n", inp);
    //system("pause");
    return 0;
}