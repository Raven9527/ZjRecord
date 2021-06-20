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

typedef struct Stock_s
{
    int profit;
    int buyPrice;
    int purchasePrice;
}Stock;

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

void UpdateProfit(int inputNumber, int min, Stock *stock)
{
    if (inputNumber - min > 0 && inputNumber - min >= stock->profit)
    {
        stock->buyPrice = min;
        stock->purchasePrice = inputNumber;
        stock->profit = inputNumber - min;
    }
}

void UpdateMin(int inputNumber, int *min)
{
    if ((*min) == -1 || inputNumber <= (*min))
        *min = inputNumber;
}

void MainProgram()
{
    int n, min = -1;
    Stock stock = {0, -1, -1};
    while (scanf("%d", &n) != EOF)
    {
        UpdateMin(n, &min);
        UpdateProfit(n, min, &stock);
    }
    printf("%d %d %d\n", stock.profit, stock.buyPrice, stock.purchasePrice);
}


#if TEST_FLAG
// Test Region
int TestCase(int input[], int size, int except_profit, int except_buy, int except_purchase)
{
    int min = -1;
    Stock stock = {0, -1, -1};
    int i;
    for (i = 0; i < size; i++)
    {
        UpdateMin(input[i], &min);
        UpdateProfit(input[i], min, &stock);
    }
    printf("%d %d %d\n", stock.profit, stock.buyPrice, stock.purchasePrice);
    return AssertIntegerEquals(except_profit, stock.profit) && AssertIntegerEquals(except_buy, stock.buyPrice) && AssertIntegerEquals(except_purchase, stock.purchasePrice);
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
    int testData6[5] = {100, 99, 98, 96, 95};

    failCount += OutputTest(1, TestCase(testData1, 7, 20, 100, 120));
    failCount += OutputTest(2, TestCase(testData2, 8, 45, 90, 135));
    failCount += OutputTest(3, TestCase(testData3, 5, 45, 90, 135));
    failCount += OutputTest(4, TestCase(testData4, 6, 30, 100, 130));
    failCount += OutputTest(5, TestCase(testData5, 4, 70, 10, 80));
    failCount += OutputTest(6, TestCase(testData6, 5, 0, -1, -1));
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif