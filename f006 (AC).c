#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 105

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
void InputArray(int[], int);
void FindMinAndMax(int[], int, int*, int*);
int GetMin(int, int);
int GetMax(int, int);

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
    int array[SIZE];
    int min = 10005, max = -1;

    scanf("%d", &n);
    InputArray(array, n);
    FindMinAndMax(array, n, &max, &min);
    printf("%d %d", max, min);
}

void InputArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void FindMinAndMax(int arr[], int n, int *max, int *min)
{
    int i;
    for (i = 0; i < n; i++)
    {
        *max = GetMax(*max, arr[i]);
        *min = GetMin(*min, arr[i]);
    }
}

int GetMin(int a, int b)
{
    return a <= b ? a : b;
}

int GetMax(int a, int b)
{
    return a >= b ? a : b;
}

#if TEST_FLAG
// Test Region
int TestCase1()
{
    int arr[SIZE] = { 2715,862,2513,5971,2395,9626,7339,9915,8993,3098 };
    int max = -1, min = 10005;
    FindMinAndMax(arr, 10, &max, &min);
    printf("%d %d\n",max, min);
    return AssertIntegerEquals(862, min) && AssertIntegerEquals(9915, max);
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif