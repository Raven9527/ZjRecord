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
    scanf("%d %d", &n, &m);
    char inp;
    int sum = 0, k = 0;
    int flag = 1;
    inp = getchar();
    do
    {
        inp = getchar();
        if (inp >= '0' && inp <= '9')
        {
            sum *= 10;
            sum += inp - 48;
        }
        else if (inp == '-')
        {
            flag = -1;
        }
        else
        {
            candy[k++] = sum * flag;
            flag = 1;
            sum = 0;
        }
    } while (inp != '\n');

    int i, j;
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
    //system("pause");
    return 0;
}