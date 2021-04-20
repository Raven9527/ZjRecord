#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
int candy[1000001];
int t=0;
/* 進階二分搜，大概理解一些些 */
/* keyword: lower_bound()，用二分搜尋找序列中第一個 >= val的值*/
int cmp(const void *s1 , const void *s2)
{
	return *(int *)s1 - *(int *)s2;
}
int BiranySearch(int left, int right, int num, int flag)
{
    //printf("%d %d %d\n", left, right, num);
    int mid = 0, n = right + 1;
    while(left <= right)
    {
        mid = (left + right) / 2;
        //printf("num = %d %d %d %d\n",num , left, right, mid);
        if(flag == 0) //left 
        {
            if(num > candy[mid])
            {
                left = mid + 1;
            }
            else if(num <= candy[mid])
            {
                right = mid - 1;
            }
        }

        else
        {
            if(num >= candy[mid])
            {
                left = mid + 1;
            }
            else if(num < candy[mid])
            {
                right = mid - 1;
            }
        }
    }
    if(flag == 0)
    {
        if(candy[left] > num)
            return left - 1;
        return left;
    }
    else 
    {
        if(candy[right] < num)
            return right + 1;
        return right;
    }
}
int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &candy[i]);
        }
        qsort(candy, n, sizeof(int), cmp);

        for (i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            int left = BiranySearch(0, n - 1, a, 0);
            int right = BiranySearch(0, n - 1, b, 1);

            //printf("left = %d\n right = %d\n", left, right);
            int k;
            
            if(candy[left] != a && candy[right] != b)
            {
                k = right - left - 1;
            }
            else if((candy[left] == a && candy[right] != b) ||(candy[left] != a && candy[right] == b))
            {
                k = right - left;
            }
            else if (candy[left] == a && candy[right] == b)
            {
                k = right - left + 1;
            }

            if (k == 0)
                printf("The candies are too short\n");
            else
                printf("%d\n", k);
        }
    }
    return 0;
}