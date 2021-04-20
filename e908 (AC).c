#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void InputDayAndNext(char day[], int *next)
{
    scanf("%s %d", day, next);
    (*next) = (*next) % 7;
}
int ConvertDayToNumber(char week[8][15], char day[])
{
    int i;
    for (i = 0; i < 7; i++)
    {
        if (strcmp(week[i], day) == 0)
        {
            return i;
        }
    }
    return 0;
}
char* ConvertNumberToDay(char week[8][15], int day)
{
    day = day % 7;
    return week[day];
}
void PrinfAns(char *ans)
{
    printf("%s\n", ans);
}
int main()
{
    char week[8][15] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char day[15];
    int next;
    int first = 0;
    InputDayAndNext(day, &next);
    first += ConvertDayToNumber(week, day);
    first += next;
    PrinfAns(ConvertNumberToDay(week, first));
    //system("pause");
    return 0;
}