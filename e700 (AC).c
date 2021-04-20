#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 月*100 + 日 做判斷
int ReturnStartValue(int month, int date)
{
    return month * 100 + date;
}
void PrintAns(int starValue)
{
    if (starValue >= 121 && starValue <= 219)
    {
        printf("水瓶座\n");
    }
    else if (starValue >= 220 && starValue <= 320)
    {
        printf("雙魚座\n");
    }
    else if (starValue >= 321 && starValue <= 420)
    {
        printf("牡羊座\n");
    }
    else if (starValue >= 421 && starValue <= 521)
    {
        printf("金牛座\n");
    }
    else if (starValue >= 522 && starValue <= 621)
    {
        printf("雙子座\n");
    }
    else if (starValue >= 622 && starValue <= 722)
    {
        printf("巨蟹座	\n");
    }
    else if (starValue >= 723 && starValue <= 821)
    {
        printf("獅子座\n");
    }
    else if (starValue >= 822 && starValue <= 923)
    {
        printf("處女座\n");
    }
    else if (starValue >= 924 && starValue <= 1023)
    {
        printf("天秤座\n");
    }
    else if (starValue >= 1024 && starValue <= 1122)
    {
        printf("天蠍座\n");
    }
    else if (starValue >= 1123 && starValue <= 1222)
    {
        printf("射手座\n");
    }
    else
    {
        printf("摩羯座\n");
    }
}
int main()
{
    int month, date;
    while(scanf("%d/%d", &month, &date) != EOF)
    {
        PrintAns(ReturnStartValue(month, date));
    }
    return 0;
}