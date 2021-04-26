#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_day
{
    int day;
    int height;
}Day;
void InitializtDayState(Day *day)
{
    (*day).day = 0;
    (*day).height = 0;
}
void CopyDay(Day *targetDay, Day copyDay)
{
    (*targetDay).day = copyDay.day;
    (*targetDay).height = copyDay.height;
}
void Process(int height, int expect, int patience)
{
    Day currentDay;
    Day lastDay;
    InitializtDayState(&currentDay);
    InitializtDayState(&lastDay);
    currentDay.height = height;

    while (patience > 0 && currentDay.height < expect)
    {
        int isPause = 0;
        currentDay.day++;

        if (currentDay.day % 10 == 1 && currentDay.day >= 10)
        {
            patience--;
        }

        if (lastDay.day % 10 == 9 || (lastDay.day % 10 == 0 && lastDay.day >= 10))
        {
            isPause = 1;
        }

        // 使用神奇肥料
        if (currentDay.day % 3 == 1 && currentDay.day > 3 && isPause == 0)
        {
            currentDay.height += lastDay.height / 3;
        }
        // 不使用
        else if (isPause == 0)
        {
            currentDay.height += lastDay.height / 10;
        }

        CopyDay(&lastDay, currentDay);
        // printf("%d %d\n", currentDay.day, currentDay.height);
        // system("pause");
    }

    if (currentDay.height < expect)
    {
        printf("unsalable");
    }
    else
    {
        if (currentDay.day == 0)
            printf("1");
        else
            printf("%d", currentDay.day);
    }
}
int main()
{
    int height, expect, patience;
    scanf("%d %d %d", &height, &expect, &patience);
    Process(height, expect, patience);
    return 0;
}