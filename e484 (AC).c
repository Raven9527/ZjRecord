// 就質數拉
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10005
int prime[MAX];

void CreatePrimeTable()
{
    memset(prime, 1, sizeof(prime));
    int i, j;
    for (i = 2; i * i <= MAX; i++)
    {
        for (j = 2; i * j <= MAX; j++)
        {
            prime[i * j] = 0;
        }
    }
    prime[2] = 1;
}

void PrintAns(int index)
{
    if (prime[index] != 0)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}

int main()
{
    CreatePrimeTable();
    int n;
    scanf("%d", &n);
    PrintAns(n);
    //system("pause");
    return 0;
}