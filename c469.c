#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 31624
int main()
{
    long long area[MAX] = {0};
    long long int n;
    int i;
    scanf("%lld", &n);

    for (i = 0; i < MAX; i++)
    {
        if (n < i * i)
        {
            printf("%lld\n", n - (i - 1) * (i - 1));
            break;
        }
        else if (n == i * i)
        {
            printf("0\n");
            break;
        }
    }

    system("pause");
    return 0;
}