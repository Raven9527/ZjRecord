#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int FD(long long int b,long long  int d1,long long  int d2)
{
    if(b >= d1 && b <= d2)
        return 0;

    else if(b < d1)
        return d1 - b;

    else if(b >  d2)
        return b - d2;
}
int main()
{
    long long int bx, by, x1, x2, y1, y2;
    long long int sum = 0;
    scanf("%lld %lld %lld %lld %lld %lld", &bx, &by, &x1, &y1, &x2, &y2);
    sum += FD(bx, x1, x2) + FD(by, y1, y2);
    printf("%lld\n", sum);
    //system("pause");
    return 0;
}