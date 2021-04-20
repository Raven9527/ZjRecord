#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int arr[10000005];
int cmp(const void *s1 , const void *s2)
{
	return *(int *)s1 - *(int *)s2;
}
int main()
{
    int stage;
    scanf("%d", &stage);
    while(stage--)
    {
        int n, i, k, flag = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        
        qsort(arr, n, sizeof(int), cmp);

        for (i = 0; i < n - 2 ;i++)
        {
            if (arr[i] + arr[i + 1] > arr[i + 2])
            {
                flag = 1;
                break;
            }
        }
        printf(flag == 1 ? "YES\n" : "NO\n");
    }
    //system("pause");
    return 0;
}