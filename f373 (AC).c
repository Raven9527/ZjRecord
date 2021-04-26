#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Discount(int money, int index)
{
    if (index == 0)
    {
        return money - ((money / 2000) * 200);
    }
    else
    {
        return money - ((money / 1000) * 100);
    }
}
void PrintAns(int money0, int money1)
{
    //printf("%d %d\n", money0, money1);
    if (money0 <= money1)
        printf("%d 0", money0);
    else
        printf("%d 1", money1);
}
int main()
{
    int n;
    scanf("%d", &n);
    int money0 = Discount(n, 0);
    int money1 = Discount(n, 1);
    PrintAns(money0, money1);
    //system("pause");
    return 0;
}