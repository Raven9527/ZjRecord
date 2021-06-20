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
int GetArea(int);
int GetRow(int, int);
int GetSeatCount(int, int);
void ComputeSeat(int, int*, int*, int*);

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
    int index;
    int area = 0, row = 0, seatCount = 0;
    scanf("%d", &index);
    ComputeSeat(index, &area, &row, &seatCount);
    printf("%d %d %d\n", area, row, seatCount);
}

int GetArea(int index)
{
    if (index >= 1 && index <= 2500)
        return 1;
    else if (index > 2500 && index <= 7500)
        return 2;
    else
        return 3;
}

int GetRow(int index, int area)
{
    if (area == 1)
        return (index / 25) + (index % 25 == 0 ? 0 : 1);
    else if (area == 2)
        return ((index - 2500) / 50) + (index % 50 == 0 ? 0 : 1);
    else
        return ((index - 7500) / 25) + (index % 25 == 0 ? 0 : 1);
}

int GetSeatCount(int index, int area)
{
    if (area == 2)
        return (index % 50 == 0) ? 50 : index % 50;
    else
        return (index % 25 == 0) ? 25 : index % 25;
}

void ComputeSeat(int index, int *area, int *row, int *count)
{
    (*area) = GetArea(index);
    (*row) = GetRow(index, *area);
    (*count) = GetSeatCount(index, *area);
}


#if TEST_FLAG
// Test Region 
int TestCase(int index, int exceptArea, int exceptRow, int exceptCount)
{
    int area = 0, row = 0, count = 0;
    ComputeSeat(index, &area, &row, &count);
    printf("%d %d %d\n", area, row, count);
    return AssertIntegerEquals(exceptArea, area) && AssertIntegerEquals(exceptRow, row) && AssertIntegerEquals(exceptCount, count);
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;
    failCount += OutputTest(1, TestCase(26, 1, 2, 1));
    failCount += OutputTest(2, TestCase(7499, 2, 100, 49));
    failCount += OutputTest(3, TestCase(8765, 3, 51, 15));
    failCount += OutputTest(4, TestCase(1, 1, 1, 1));
    failCount += OutputTest(5, TestCase(100, 1, 4, 25));
    failCount += OutputTest(6, TestCase(25, 1, 1, 25));
    failCount += OutputTest(7, TestCase(2499, 1, 100, 24));
    failCount += OutputTest(8, TestCase(2500, 1, 100, 25));
    failCount += OutputTest(9, TestCase(7500, 2, 100, 50));
    failCount += OutputTest(10, TestCase(10000, 3, 100, 25));
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif