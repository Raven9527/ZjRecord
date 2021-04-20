#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m;
    int i, j;
    int s = 0;
    int num[21] = {0};
    int f = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        int max = -10;
        for (j = 0; j < m;j++)
        {
            int k;
            scanf("%d", &k);
            if(k > max)
                max = k;
        }
        num[i] = max;
        s += max;
    }
    printf("%d\n", s);
    for (i = 0; i < n;i++)
    {
        if(s % num[i] == 0)
        {
            printf("%d ", num[i]);
            f = 1;
        }
    }
    if(!f)
        printf("-1");
    //system("pause");
    return 0;
}