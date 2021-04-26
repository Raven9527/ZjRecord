#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_day
{
    int day;
    int height;
    int specialFertilizerCount;
    int preHolidayCount;
    int holidayCount;

    int isUseSpecialFertilize;
    int isGiveWater;
    int isPause;
    int isVisit;
    int isHolidayDone;
}Day;
void InitializtDayState(Day *day)
{
    (*day).day = 0;
    (*day).height = 0;
    (*day).specialFertilizerCount = 0;
    (*day).preHolidayCount = 0;
    (*day).holidayCount = 0;

    (*day).isUseSpecialFertilize = 0;
    (*day).isGiveWater = 0;
    (*day).isPause = 0;
    (*day).isVisit = 0;
    (*day).isHolidayDone = 0;
}
void CopyDay(Day *targetDay, Day copyDay)
{
    (*targetDay).day = copyDay.day;
    (*targetDay).height = copyDay.height;
    (*targetDay).specialFertilizerCount = copyDay.specialFertilizerCount;
    (*targetDay).preHolidayCount = copyDay.preHolidayCount;
    (*targetDay).holidayCount = copyDay.holidayCount;

    (*targetDay).isUseSpecialFertilize = copyDay.isUseSpecialFertilize;
    (*targetDay).isGiveWater = copyDay.isGiveWater;
    (*targetDay).isPause = copyDay.isPause;
    (*targetDay).isVisit = copyDay.isVisit;
    (*targetDay).isHolidayDone = copyDay.isHolidayDone;
}
void ProcessSpecialFertilizer(Day *dayState)
{
    if ((*dayState).isPause == 1 || (*dayState).isVisit == 1)
        return;

    (*dayState).specialFertilizerCount++;
    if ((*dayState).specialFertilizerCount >= 3)
    {
        (*dayState).isUseSpecialFertilize = 1;
        (*dayState).specialFertilizerCount = 0;
    }
}
void ProcessPreHolidayCount(Day *dayState)
{
    if ((*dayState).isPause == 1)
        return;

    (*dayState).preHolidayCount++;
    if ((*dayState).preHolidayCount >= 8)
    {
        (*dayState).isPause = 1;
        (*dayState).preHolidayCount = 0;
    }
}
void ProcesHolidayCount(Day *dayState)
{
    if ((*dayState).isPause == 0)
        return;

    (*dayState).holidayCount++;
    if ((*dayState).holidayCount > 2) // Call Function 順序問題
    {
        (*dayState).isPause = 0;
        (*dayState).holidayCount = 0;
    }

    if ((*dayState).holidayCount == 2) // 實際上為2時 休假最後一天
    {
        (*dayState).isHolidayDone = 1;
    }
}
void ProcessGiveWater(Day *dayState)
{
    if ((*dayState).isPause == 1)
        (*dayState).isGiveWater = 0;
    else
        (*dayState).isGiveWater = 1;
}
void ProcessVisit(Day *dayState, int *patience)
{
    if ((*dayState).isHolidayDone == 1)
    {
        (*dayState).isVisit = 1;
        (*dayState).isHolidayDone = 0;
    }
    else
    {
        (*dayState).isVisit = 0;
    }
    
    if ((*dayState).isVisit)
    {
        (*patience)--;
    }
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
        currentDay.day++;
        ProcessVisit(&currentDay, &patience);

        // 使用神奇肥料
        if (lastDay.isUseSpecialFertilize)
        {
            currentDay.height += lastDay.height / 3;
            currentDay.isUseSpecialFertilize = 0;
        }
        // 不使用
        else if (lastDay.isGiveWater)
        {
            currentDay.height += lastDay.height / 10;
        }

        ProcesHolidayCount(&currentDay);
        ProcessSpecialFertilizer(&currentDay);
        ProcessGiveWater(&currentDay);
        ProcessPreHolidayCount(&currentDay);

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