#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 2147483647, b = 0, c = -2147483647;
    int i;
    int k;
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &k);
        if(k < a)
            a = k;
        if(k > c)
            c = k;
        b += k;
    }
    b = b - a - c;

    printf("%d %d %d\n", a, b, c);
    if(a + b <= c)
        printf("No\n");
    else if (a * a + b * b < c * c)
        printf("Obtuse\n");
    else if (a * a + b * b == c * c)
        printf("Right\n");
    else if (a * a + b * b > c * c)
        printf("Acute\n");
    //system("pause");
    return 0;
}