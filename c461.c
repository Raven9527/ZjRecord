#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c;
    int f = 0;
    scanf("%d %d %d", &a, &b, &c);
    a = a > 0 ? 1 : 0;
    b = b > 0 ? 1 : 0;
    c = c > 0 ? 1 : 0;
    if ((!(a & b) && !c) || ((a & b) && c))
    {
        printf("AND\n");
        f++;
    }
    if ((!(a | b) && !c) || ((a | b) && c))
    {
        printf("OR\n");
        f++;
    }
    if ((!(a ^ b) && !c) || ((a ^ b) && c))
    {
        printf("XOR\n");
        f++;
    }
    if(!f)
        printf("IMPOSSIBLE\n");
    //system("pause");
    return 0;
}