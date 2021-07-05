    #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
typedef struct CountableNumber_s
{
    int number;
    int count;
}CountableNumber;
int cmp(const void*, const void*); // 排序比較器
void InitializeNumberArray(CountableNumber[]); // 初始化
void ComputeSatisfaction(char[], CountableNumber[]); // 計算滿意度
void AddCount(CountableNumber*); // 計算次數
void Sort(CountableNumber[]); // 排序
int ConvertCharToNumber(char); // 字元換數字
void ProcessNumberArrayToAns(CountableNumber[], int[], int*); // 處理結果變成Ans
void PrintAns(int[], int size); // 輸出Ans

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
    char inp[100];
    int ans[15], size = 0;
    CountableNumber numberArray[10];
    scanf("%s", inp);
    InitializeNumberArray(numberArray);
    ComputeSatisfaction(inp, numberArray);
    Sort(numberArray);
    ProcessNumberArrayToAns(numberArray, ans, &size);
    PrintAns(ans, size);
}

void InitializeNumberArray(CountableNumber numberArray[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        numberArray[i].number = i;
        numberArray[i].count = 0;
    }
}

int ConvertCharToNumber(char k)
{
    return k - 48;
}

void ComputeSatisfaction(char inp[], CountableNumber numberArray[])
{
    int i, s = strlen(inp);
    for (i = 0; i < s; i++)
    {
        int number = ConvertCharToNumber(inp[i]);
        AddCount(&numberArray[number]);
    }
}

void AddCount(CountableNumber *countable)
{
    (countable->count)++;
}

int cmp(const void *a, const void *b)
{
    CountableNumber *c = (CountableNumber *)a;
    CountableNumber *d = (CountableNumber *)b;
    if (c->count > d->count)
        return -1;
    else if (c->count < d->count)
        return 1;
    else
        return (c->number < d->count) ? -1 : 0;
}

void Sort(CountableNumber numberArray[])
{
    qsort(numberArray, 10, sizeof(numberArray[0]), cmp);
}

void ProcessNumberArrayToAns(CountableNumber numberArray[], int ans[], int *size)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (numberArray[i].count != 0)
        {
            ans[(*size)++] = numberArray[i].number;
        }
    }
}

void PrintAns(int print[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", print[i]);
    }
    printf("\n");
}

#if TEST_FLAG
void Print(CountableNumber numberArray[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d %d\n", numberArray[i].number, numberArray[i].count);
    }
}
int TestCase1()
{
    char inp[] = "2425264426558";
    int active[15], size = 0;
    int except[] = {2, 4, 5, 6, 8};
    CountableNumber numberArray[10];
    InitializeNumberArray(numberArray);
    ComputeSatisfaction(inp, numberArray);
    Sort(numberArray);
    ProcessNumberArrayToAns(numberArray, active, &size);
    //Print(numberArray);
    PrintAns(active, size);
    AssertIntegerArrayEquals(active, size, except, 5);
}
int TestCase2()
{
    char inp[] = "1234567891011121314";
    int active[15], size = 0;
    int except[] = {1, 2, 3, 4, 0, 5, 6, 7, 8, 9};
    CountableNumber numberArray[10];
    InitializeNumberArray(numberArray);
    ComputeSatisfaction(inp, numberArray);
    Sort(numberArray);
    ProcessNumberArrayToAns(numberArray, active, &size);
    //Print(numberArray);
    PrintAns(active, size);
    AssertIntegerArrayEquals(active, size, except, 10);
}
// Test Region 
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;
    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif