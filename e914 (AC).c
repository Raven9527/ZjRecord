// 細節: 母親今年至少18歲，母親 + n年後最多99歲，女兒要比母親年紀小
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct IntArray_s
{
    int number[100];
    int size;
}IntArray;
void MainProgram();
void InitializeArray(IntArray*);
void FindMikoAge(IntArray*, int); // 尋找小美的年紀
void PrintMikoAge(IntArray*); // 輸出小美可能的年紀

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
    int n ;
    IntArray array;
    InitializeArray(&array);
    scanf("%d", &n);
    FindMikoAge(&array, n);
    PrintMikoAge(&array);
}

void InitializeArray(IntArray *array)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        array->number[i] = 0;
    }
    array->size = 0;
}

void FindMikoAge(IntArray *array, int n)
{
    int momAge;
    for (momAge = 18; momAge + n <= 99; momAge++)
    {
        int m1 = momAge / 10, m2 = momAge % 10;
        int mikoAge = m2 * 10 + m1;
        if ((mikoAge + n) * 2 == momAge + n && mikoAge < momAge)
        {
            array->number[array->size] = mikoAge;
            array->size++;
        }
    }
}

void PrintMikoAge(IntArray *array)
{
    if (array->size == 0)
        printf("no answer\n");
    else
    {
        int i;
        for (i = 0; i < array->size; i++)
        {
            printf("%d\n", array->number[i]);
        }
    }
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    int n = 5;
    IntArray array;
    InitializeArray(&array);
    FindMikoAge(&array, n);
    return AssertIntegerEquals(13, array.number[0]);
}
int TestCase2()
{
    int n = 24;
    IntArray array;
    InitializeArray(&array);
    FindMikoAge(&array, n);
    return AssertIntegerEquals(3, array.number[0]);
}
int TestCase3()
{
    int n = 22;
    IntArray array;
    InitializeArray(&array);
    FindMikoAge(&array, n);
    return AssertIntegerEquals(0, array.size);
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