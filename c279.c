#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20001
int prime[MAX], p[MAX];
void rekkursion(int num , int index , int n , int *d , int k)
{
    printf("%d\n", num);
    if(num > n || p[index] > n)
        return;
    if(num == n)
    {
        (*d)++;
        system("pause");
        return;
    }

    int i;
    for (i = index; p[i] <= n; i++)
    {
        rekkursion(num + p[index] , index + 1, n, &(*d), k);
    }
}
int main()
{
    int i;
    for (i = 3; i <= MAX; i += 2)
    {
        prime[i] = i;
    }
    p[0] = 2;
    int k = 1;
    for (i = 3; i <= MAX; i += 2)
    {
        int j = 2;
        if(prime[i])
            p[k++] = i;
        while(i * j <= MAX)
        {
            prime[i * j] = 0;
            j++;
        }
    }

    int n;
    int d = 0;
    scanf("%d", &n);

    rekkursion(0, 0, n, &d, k);
    printf("%d\n", d);
    system("pause");
    return 0;
}