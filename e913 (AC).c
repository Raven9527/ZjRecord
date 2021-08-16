#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 123478
int primeTable[SIZE], prime[SIZE];

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
void CreatePrimeTable(int[], int); // 創建質數篩表
void CreatePrimeArray(int[], int, int[], int*); // 創建質數陣列
int CountTwinPrimePair(int[], int, int); // 統計孿生質數

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
    int primeArraySize = 0;
    CreatePrimeTable(primeTable, SIZE);
    CreatePrimeArray(primeTable, SIZE, prime, &primeArraySize);
    int n = 10;
    scanf("%d", &n);
    printf("%d\n", CountTwinPrimePair(prime, primeArraySize, n));
}

void CreatePrimeTable(int table[], int size)
{
    int i, j;
    for (i = 3; i <= size; i += 2)
    {
        table[i] = 1;
    }

    for (i = 3; i <= size; i += 2)
    {
        for (j = 2; i * j <= size; j++)
            table[i * j] = 0;
    }
}

void CreatePrimeArray(int table[], int tableSize, int primeArray[], int *primeArraySize)
{
    primeArray[0] = 2;
    *primeArraySize = 1;

    int i;
    for (i = 3; i <= tableSize; i += 2)
    {
        if (table[i])
            primeArray[(*primeArraySize)++] = i;
    }
}

int CountTwinPrimePair(int primeArray[], int primeArraySize, int maxLimit)
{
    int i, count = 0;
    for (i = 1; i < primeArraySize && primeArray[i] <= maxLimit; i++)
    {
        if (primeArray[i] == primeArray[i - 1] + 2)
            count++;
    }
    return count;
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    int primeArraySize = 0;
    int n = 10;
    int except = 2;
    CreatePrimeTable(primeTable, SIZE);
    CreatePrimeArray(primeTable, SIZE, prime, &primeArraySize);

    //PrintIntegerArray(prime, primeArraySize);
    printf("%d\n", CountTwinPrimePair(prime, primeArraySize, n));
    return AssertIntegerEquals(except, CountTwinPrimePair(prime, primeArraySize, n));
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif