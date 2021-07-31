#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 1005

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
void TakeBus(int[], int, int); // 搭公車 (a -> b)
int GetMaxCountStopIndex(int[], int); // 得到最多人經過的站牌的編號
int GetMinCountStopIndex(int[], int); // 得到最少人經過的站牌的編號

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
    int stop[SIZE] = {0};
    int n, T, startStop, targetStop;
    scanf("%d %d", &n, &T);
    while(T--)
    {
        scanf("%d %d", &startStop, &targetStop);
        TakeBus(stop, startStop, targetStop);
    }
    printf("%d %d\n", GetMinCountStopIndex(stop, n), GetMaxCountStopIndex(stop, n));
}

void TakeBus(int stop[], int aStop, int bStop)
{
    int i;
    int start = (aStop >= bStop) ? bStop : aStop;
    int target = (aStop + bStop) - start;
    for (i = start; i <= target; i++)
        stop[i]++;
}

int GetMaxCountStopIndex(int stop[], int n)
{
    int maxIndex = 1, maxCount = stop[1];
    int i;
    for (i = 1; i <= n; i++)
    {
        if (stop[i] >= maxCount)
        {
            maxCount = stop[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int GetMinCountStopIndex(int stop[], int n)
{
    int minIndex = 1, minCount = stop[1];
    int i;
    for (i = 1; i <= n; i++)
    {
        if (stop[i] < minCount)
        {
            minCount = stop[i];
            minIndex = i;
        }
    }
    return minIndex;
}

#if TEST_FLAG
// Test Region
int TestCase1()
{
    int stop[SIZE] = {0};
    TakeBus(stop, 2, 7);
    TakeBus(stop, 5, 3);
    TakeBus(stop, 5, 8);
    int min = GetMinCountStopIndex(stop, 8);
    int max = GetMaxCountStopIndex(stop, 8);
    return AssertIntegerEquals(1, min) && AssertIntegerEquals(5, max);
}
int TestCase2()
{
    int stop[SIZE] = {0};
    TakeBus(stop, 1, 5);
    TakeBus(stop, 10, 5);
    TakeBus(stop, 4, 2);
    TakeBus(stop, 8, 10);
    TakeBus(stop, 4, 5);
    TakeBus(stop, 7, 10);
    TakeBus(stop, 2, 4);
    TakeBus(stop, 10, 8);
    TakeBus(stop, 8, 9);
    int min = GetMinCountStopIndex(stop, 10);
    int max = GetMaxCountStopIndex(stop, 10);
    return AssertIntegerEquals(1, min) && AssertIntegerEquals(9, max);
}
int TestCase3()
{
    int stop[SIZE] = {0};
    TakeBus(stop, 1, 1000);
    TakeBus(stop, 1, 1000);
    int min = GetMinCountStopIndex(stop, 1000);
    int max = GetMaxCountStopIndex(stop, 1000);
    return AssertIntegerEquals(1, min) && AssertIntegerEquals(1000, max);
}
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