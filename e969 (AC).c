#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define PRICE_APPLE_PIE 32
#define PRICE_CORN_SOUP 55

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();

typedef struct Wayne_s
{
    int money;
    int minute;
    int order;
    int eatTime;
}Wayne;
void Input(Wayne*); // 輸入資料
void Eat(Wayne*); // 吃一次
int IsWayneCanEat(Wayne*); // Wayne的錢足夠吃嗎?
void AddEatTime(Wayne*); // 增加吃的時間
void PrintLine(Wayne*); // 吃後 輸出一條訊息

// Main Region
int main()
{
    #if TEST_FLAG
        TestProgram();
    #else
        MainProgram();
    #endif

    #if PAUSE_FLAG
        system("pause");
    #endif

    return 0;
}

void MainProgram()
{
    Wayne wayne;
    Input(&wayne);
    while (IsWayneCanEat(&wayne))
    {
        Eat(&wayne);
    }

    if (wayne.eatTime == 0)
    {
        printf("Wayne can't eat and drink.\n");
    }
}

void Input(Wayne *wayne)
{
    int money, min, order;
    scanf("%d %d %d", &money, &min, &order);
    wayne->money = money;
    wayne->minute = min;
    wayne->order = order;
    wayne->eatTime = 0;
}

int IsWayneCanEat(Wayne *wayne)
{
    if (wayne->order == 0)
        return wayne->money >= PRICE_APPLE_PIE;
    else
        return wayne->money >= PRICE_CORN_SOUP;
}

void Eat(Wayne *wayne)
{
    if (wayne->order == 0)
    {
        wayne->money -= PRICE_APPLE_PIE;
        PrintLine(wayne);
        AddEatTime(wayne);
        wayne->order = 1;
    }
    else
    {
        wayne->money -= PRICE_CORN_SOUP;
        PrintLine(wayne);
        AddEatTime(wayne);
        wayne->order = 0;
    }
}

void AddEatTime(Wayne *wayne)
{
    wayne->eatTime += wayne->minute;
}

void PrintLine(Wayne *wayne)
{
    // if (TEST_FLAG)
    //     return;
    if (wayne->order == 0)
    {
        if (wayne->money == 1)
            printf("%d: Wayne eats an Apple pie, and now he has %d dollar.\n", wayne->eatTime, wayne->money);
        else if (wayne->money != 0)
            printf("%d: Wayne eats an Apple pie, and now he has %d dollars.\n", wayne->eatTime, wayne->money);
        else
            printf("%d: Wayne eats an Apple pie, and now he doesn't have money.\n", wayne->eatTime);
    }
    else if (wayne->order == 1)
    {
        if (wayne->money == 1)
            printf("%d: Wayne drinks a Corn soup, and now he has %d dollar.\n", wayne->eatTime, wayne->money);
        else if (wayne->money != 0)
            printf("%d: Wayne drinks a Corn soup, and now he has %d dollars.\n", wayne->eatTime, wayne->money);
        else
            printf("%d: Wayne drinks a Corn soup, and now he doesn't have money.\n", wayne->eatTime);
    }
}

#if TEST_FLAG
void RunTest(Wayne *wayne, Wayne active[100])
{
    int count = 0;
    while(IsWayneCanEat(wayne))
    {
        Eat(wayne);
        active[count].eatTime = wayne->eatTime - wayne->minute;
        active[count].money = wayne->money;
        count++;
    }
}
int TestCase1()
{
    Wayne wayne = {65, 5, 0, 0};
    Wayne except[100] = { {33, 0, 0, 0} };
    Wayne active[100];
    int goal = 1;
    int count = 0;
    RunTest(&wayne, active);

    for (count = 0; count < goal; count++)
        if (!AssertIntegerEquals(except[count].eatTime, active[count].eatTime) || !AssertIntegerEquals(except[count].money, active[count].money))
            return 0;
    return 1;
}
int TestCase2()
{
    Wayne wayne = {143, 18, 1, 0};
    Wayne except[100] = { {88, 0, 0, 0}, {56, 0, 0, 18}, {1, 0, 0, 36} };
    Wayne active[100];
    int goal = 3;
    int count = 0;
    RunTest(&wayne, active);

    for (count = 0; count < goal; count++)
        if (!AssertIntegerEquals(except[count].eatTime, active[count].eatTime) || !AssertIntegerEquals(except[count].money, active[count].money))
            return 0;
    return 1;
}
int TestCase3()
{
    Wayne wayne = {55, 1, 1, 0};
    Wayne except[100] = { {0, 0, 0, 0} };
    Wayne active[100];
    int goal = 1;
    int count = 0;
    RunTest(&wayne, active);

    for (count = 0; count < goal; count++)
        if (!AssertIntegerEquals(except[count].eatTime, active[count].eatTime) || !AssertIntegerEquals(except[count].money, active[count].money))
            return 0;
    return 1;
}
// Test Region 
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());
    failCount += OutputTest(caseCount++, TestCase3());
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif