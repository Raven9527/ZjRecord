#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define MAX_SIZE 1024

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();

typedef struct RepeatNumber_s
{
    int number;
    int repeat;
}RepeatNumber;
void InsertNumber(RepeatNumber[], int*, int, int*);
void UpdateMaxRepeat(int*, int);
void PrintAns(RepeatNumber[], int, int);

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
    int T, n, i, listSize = 0;
    int repeatCount = 0;
    RepeatNumber list[MAX_SIZE];
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &n);
        InsertNumber(list, &listSize, n, &repeatCount);
    }
    PrintAns(list, listSize, repeatCount);
}

void PrintAns(RepeatNumber list[], int listSize, int repeatCount)
{
    printf("%d\n", listSize);
    if (repeatCount == 1)
    {
        printf("NO\n");
    }
    else
    {
        int i;
        for (i = 0; i < listSize; i++)
        {
            if (list[i].repeat == repeatCount)
            {
                printf("%d ", list[i].number);
            }
        }
    }
}

void UpdateMaxRepeat(int *maxRepeat, int repeat)
{
    if (repeat > *maxRepeat)
        *maxRepeat = repeat;
}

void InsertNumber(RepeatNumber list[], int *listSize, int number, int *maxRepeat)
{
    int i;
    for (i = 0; i < *listSize; i++)
    {
        if (list[i].number == number)
        {
            list[i].repeat++;
            UpdateMaxRepeat(maxRepeat, list[i].repeat);
            return;
        }
    }

    RepeatNumber newNumber = {number, 1};
    list[(*listSize)++] = newNumber;
    UpdateMaxRepeat(maxRepeat, 1);
}

#if TEST_FLAG
// Test Region 
int TestCase(int input[], int size, int exceptOutput[], int eSize)
{
    RepeatNumber list[MAX_SIZE];
    int i, listSize = 0, repeatCount = 0;
    for (i = 0; i < size; i++)
    {
        InsertNumber(list, &listSize, input[i], &repeatCount);
    }

    if (eSize == 0)
    {
        return AssertIntegerEquals(1, repeatCount);
    }
    else
    {
        int eCount = 0;
        for (i = 0; i < listSize && eCount < eSize; i++)
        {
            if (list[i].repeat == repeatCount)
            {
                if (!AssertIntegerEquals(exceptOutput[eCount++], list[i].number))
                    return 0;
            }
        }
        return 1;
    }
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;
    int testData1[] = {1, 2, 3, 4, 5, 6, 7};
    int testData2[] = {10, 10, 10, 10, 10};
    int testData3[] = {5, -10, -8, 109, 32, -10, 5, 32};

    int exceptData1[] = {1, 2};
    int exceptData2[] = {10};
    int exceptData3[] = {5, -10, 32};
    failCount += OutputTest(1, TestCase(testData1, 7, exceptData1, 0));
    failCount += OutputTest(2, TestCase(testData2, 5, exceptData2, 1));
    failCount += OutputTest(3, TestCase(testData3, 8, exceptData3, 3));
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif