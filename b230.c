#include <stdio.h>
#include <stdlib.h>
int main()
{
    int fn[70] = {0};
    int num = 1;
    int k = 0; // 現在有幾個數ㄌ
    while(k <= 64)
    {
        int a, b, c;
        int cn = 0;
        int f = 0;
        for (a = 1; (a * (a + 1) + (a + 1) * (a + 2) + a * (a + 2)) <= num && f == 0; a++)
        {
            for (b = a + 1; (a * b + b * (b + 1) + a * (b + 1)) <= num && f == 0; b++)
            { 
                for (c = b + 1; (a * b + b * c + a * c) <= num && f == 0; c++)
                {
                    if((a * b + b * c + a * c) == num)
                    {
                        f = 1;
                    }
                }
            }
        }

        if(f == 0)
        {
            fn[k++] = num;
            //printf("num = %d\n", num);
        }
        num++;
        //printf("k = %d\n", k);
    }
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", fn[n - 1]);
    }
        return 0;
}