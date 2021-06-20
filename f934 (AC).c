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

// Function Region

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

void UpdateProfit(int inputNumber, int min, int *profit)
{
    if (inputNumber - min >= *profit)
        *profit = inputNumber - min;
}

void UpdateMin(int inputNumber, int *min)
{
    if ((*min) == -1 || inputNumber <= (*min))
        *min = inputNumber;
}

void MainProgram()
{
    int n;
    int min = -1;
    int profit = 0;
    while (scanf("%d", &n) != EOF)
    {
        UpdateMin(n, &min);
        UpdateProfit(n, min, &profit);
    }
    printf("%d\n", profit);
}


#if TEST_FLAG
// Test Region 
int TestCase(int input[], int size)
{
    int min = -1, profit = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        UpdateMin(input[i], &min);
        UpdateProfit(input[i], min, &profit);
    }
    return profit;
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;
    int testData1[7] = {100, 108, 115, 115, 120, 109, 110};
    int testData2[8] = {100, 90, 120, 120, 135, 100, 130, 110};
    int testData3[5] = {100, 90, 120, 120, 135};
    int testData4[6] = {100, 130, 120, 90, 110, 110};
    int testData5[4] = {10, 80, 5, 20};

    failCount += OutputTest(1, AssertIntegerEquals(20, TestCase(testData1, 7)));
    failCount += OutputTest(2, AssertIntegerEquals(45, TestCase(testData2, 8)));
    failCount += OutputTest(3, AssertIntegerEquals(45, TestCase(testData3, 5)));
    failCount += OutputTest(4, AssertIntegerEquals(30, TestCase(testData4, 6)));
    failCount += OutputTest(5, AssertIntegerEquals(70, TestCase(testData5, 4)));
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif