#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define CLASS_SIZE 100032

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Class_s
{
    int dayOfWeek;
    int startTime;
    int endTime;
}Class;
void MainProgram();
void InputClasses(Class[], int n); // 輸入課程群
void Sort(Class[], int n); // 排序
int CountErabeClass(Class[], int n); // 計算可選擇的課程
int cmp(const void*, const void*); // 毫無反應只是個比較器

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
    int n;
    Class classes[CLASS_SIZE];
    scanf("%d", &n);
    InputClasses(classes, n);
    Sort(classes, n);
    printf("%d\n", CountErabeClass(classes, n));
}

// day of week 第一順位 由小到大, endTime 第二順位 由小到大, startTime第三順位 由小到大
int cmp(const void *a, const void *b)
{
    Class *c = (Class *)a;
    Class *d = (Class *)b;
    if (c->dayOfWeek == d->dayOfWeek)
    {
        if (c->endTime == d->endTime)
            return c->startTime < d->startTime ? -1 : 1;
        else
            return c->endTime < d->endTime ? -1 : 1;
    }
    else
    {
        return c->dayOfWeek < d->dayOfWeek ? -1 : 1;
    }
}

void InputClasses(Class classes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &classes[i].dayOfWeek, &classes[i].startTime, &classes[i].endTime);
    }
}

void Sort(Class classes[], int n)
{
    qsort(classes, n, sizeof(classes[0]), cmp);
}

int CountErabeClass(Class classes[], int n)
{
    int count = 0;
    int i;
    Class *currentClass = NULL;
    for (i = 0; i < n; i++)
    {
        if (currentClass == NULL || (currentClass->dayOfWeek != classes[i].dayOfWeek || currentClass->endTime <= classes[i].startTime))
        {
            currentClass = &classes[i];
            count++;
        }
    }
    return count;
}


#if TEST_FLAG
void PrintClass(Class classes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d %d %d\n", classes[i].dayOfWeek, classes[i].startTime, classes[i].endTime);
    }
    printf("\n");
}
// Test Region
int TestCase1()
{
    int n = 5;
    Class classes[CLASS_SIZE] = { {1, 1, 10}, {2, 3, 4}, {2, 3, 5}, {3, 7, 8}, {3, 8, 9} };
    Sort(classes, n);
    int count = CountErabeClass(classes, n);
    //PrintClass(classes, n);
    return AssertIntegerEquals(4, count);
}
int TestCase2()
{
    int n = 6;
    Class classes[CLASS_SIZE] = { {1, 1, 10}, {2, 3, 4}, {2, 4, 5}, {3, 6, 7}, {4, 8, 9}, {5, 8, 9} };
    Sort(classes, n);
    int count = CountErabeClass(classes, n);
    //PrintClass(classes, n);
    return AssertIntegerEquals(6, count);
}
int TestCase3()
{
    int n = 12;
    Class classes[CLASS_SIZE] = { {1, 1, 10}, {1, 1, 2}, {1, 2, 3}, {1, 3, 4}, {2, 1, 10}, {1, 4, 5}, {2, 3, 4}, {2, 4, 5}, {3, 6, 7}, {3, 1, 10}, {4, 1, 10}, {5, 1, 10} };
    Sort(classes, n);
    int count = CountErabeClass(classes, n);
    //PrintClass(classes, n);
    return AssertIntegerEquals(9, count);
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