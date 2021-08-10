#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define STRING_SIZE 1000005

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
void Sort(char[], int);
int cmp(const void*, const void*);

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
    char testData[STRING_SIZE];
    scanf("%s", testData);
    Sort(testData, strlen(testData));
    printf("%s", testData);
}

void Sort(char string[], int size)
{
    qsort(string, size, sizeof(string[0]), cmp);
}

int cmp(const void *a, const void *b)
{
    return (*(char*)a) - (*(char*)b);
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    char testData[] = "ABABDC";
    Sort(testData, strlen(testData));
    return AssertStringEqual("AABBCD", testData);
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif