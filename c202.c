#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long int gcd(long long int a, long long int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int n, i;
    long long data[101];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &data[i]);
    }

    long long int g = data[0];
    for (i = 0; i < n - 1; i++)
    {
        g = gcd(g, data[i + 1]);
    }
    printf("%lld\n", g);
    //system("pause");

    return 0;
}