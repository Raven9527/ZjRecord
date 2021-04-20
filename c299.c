#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a1, const void *a2)
{
    return *(int *)a1 - *(int *)a2;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int max = -2147483647, min = 2147483647;
    for (i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        if(k > max)
            max = k;
        if (k < min)
            min = k;
    }
    printf("%d %d ", min, max);
    if(max - min != n - 1)
        printf("no\n");
    else
        printf("yes\n");
    scanf("%d", &n);
    return 0;
}