#include <stdio.h>
#include  <string.h>
#include <math.h>
int Convertdecmal(int n , int b)
{
    int num = 0;
    int k = 1;
    while(b > 0)
    {
        num += k * (b % 10);
        k *= n;
        b /= 10;
    }
    return num;
}
int main()
{
    int n, b, i;
    scanf("%d %d", &n, &b);
    int num = Convertdecmal(n, b);
    int ans = 0;
    //printf("num = %d\n", num);
    int l = (int)log10(b) + 1;
    while(b > 0)
    {
        int k = 1;
        for (i = 0; i < l; i++)
        {
            k *= b % 10;
        }
        ans += k;
        
        //printf("ans = %d\n", ans);
        b /= 10;
    }
    printf(ans == num ? "YES\n" : "NO\n");
    scanf("%d", &n);
    return 0;
}