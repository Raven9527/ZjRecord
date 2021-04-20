#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    int k, t1 = 0, t2 = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if(i % 2 == 0)
            t1 += k;
        else
            t2 += k;

    }
    //printf("t1 = %d\n t2 = %d\n", t1, t2);
    printf("%d", t1 >= t2 ? t1 : t2);
    //system("pause");
    return 0;
}