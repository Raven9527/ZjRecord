#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define MAX_SIZE 4500
int primeTable[MAX_SIZE], prime[MAX_SIZE];

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct PowerNumber_s
{
    int number;
    int power;
}PowerNumber;
void MainProgram();
void CreatePrimeTable(int table[], int size);
void CreatePrimeArray(int table[], int tableSize, int primeArray[], int *primeArraySize);
void PrimeFactorization(int, PowerNumber[], int*, int[], int); // 質因數分解
void PrintAns(PowerNumber[], int, int);

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
    PowerNumber numbers[MAX_SIZE];
    int primeArraySize = 0, numberSize = 0;
    int n;
    CreatePrimeTable(primeTable, MAX_SIZE);
    CreatePrimeArray(primeTable, MAX_SIZE, prime, &primeArraySize);    
    scanf("%d", &n);

    PrimeFactorization(n, numbers, &numberSize, prime, primeArraySize);
    PrintAns(numbers, numberSize, n);
}

// 篩質數表
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

// 線性質數表
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

void PrimeFactorization(int divNumber, PowerNumber numbers[], int *numberSize, int primeArray[], int primeArraySize)
{
    int i = 0;
    for (i = 0; i < primeArraySize && divNumber > 1; i++)
    {
        if (divNumber % primeArray[i] == 0)
        {
            numbers[(*numberSize)].number = primeArray[i];
            numbers[(*numberSize)].power = 0;

            while (divNumber % primeArray[i] == 0 && divNumber > 1)
            {
                numbers[(*numberSize)].power++;
                divNumber /= primeArray[i];
            }

            (*numberSize)++;
        }
    }

    if (divNumber > 1)
    {
        numbers[(*numberSize)].number = divNumber;
        numbers[(*numberSize)].power = 1;
        (*numberSize)++;
    }
}

void PrintAns(PowerNumber numbers[], int numberSize, int n)
{
    int i;
    printf("%d = ", n);
    for (i = 0; i < numberSize; i++)
    {
        if (numbers[i].power > 1)
            printf("%d^%d", numbers[i].number, numbers[i].power);
        else
            printf("%d", numbers[i].number);
        
        if (i != numberSize - 1)
            printf(" * ");
    }
    printf("\n");
}

#if TEST_FLAG
// Test Region
int TestCase1()
{
    PowerNumber numbers[MAX_SIZE];
    int primeArraySize = 0, numberSize = 0;
    int n = 84;
    CreatePrimeTable(primeTable, MAX_SIZE);
    CreatePrimeArray(primeTable, MAX_SIZE, prime, &primeArraySize);
    PrimeFactorization(n, numbers, &numberSize, prime, primeArraySize);
    PrintAns(numbers, numberSize, n);
    return AssertIntegerEquals(2, numbers[0].number) && AssertIntegerEquals(2, numbers[0].power) &&
            AssertIntegerEquals(3, numbers[1].number) && AssertIntegerEquals(1, numbers[1].power) &&
            AssertIntegerEquals(7, numbers[2].number) && AssertIntegerEquals(1, numbers[2].power);
}
int TestCase2()
{
    PowerNumber numbers[MAX_SIZE];
    int primeArraySize = 0, numberSize = 0;
    int n = 100;
    CreatePrimeTable(primeTable, MAX_SIZE);
    CreatePrimeArray(primeTable, MAX_SIZE, prime, &primeArraySize);
    PrimeFactorization(n, numbers, &numberSize, prime, primeArraySize);
    PrintAns(numbers, numberSize, n);
    return AssertIntegerEquals(2, numbers[0].number) && AssertIntegerEquals(2, numbers[0].power) &&
            AssertIntegerEquals(5, numbers[1].number) && AssertIntegerEquals(2, numbers[1].power);
}
int TestCase3()
{
    PowerNumber numbers[MAX_SIZE];
    int primeArraySize = 0, numberSize = 0;
    int n = 97;
    CreatePrimeTable(primeTable, MAX_SIZE);
    CreatePrimeArray(primeTable, MAX_SIZE, prime, &primeArraySize);
    PrimeFactorization(n, numbers, &numberSize, prime, primeArraySize);
    PrintAns(numbers, numberSize, n);
    return AssertIntegerEquals(97, numbers[0].number) && AssertIntegerEquals(1, numbers[0].power);
}

int TestCase4()
{
    PowerNumber numbers[MAX_SIZE];
    int primeArraySize = 0, numberSize = 0;
    int n = 1681122;
    CreatePrimeTable(primeTable, MAX_SIZE);
    CreatePrimeArray(primeTable, MAX_SIZE, prime, &primeArraySize);
    PrimeFactorization(n, numbers, &numberSize, prime, primeArraySize);
    PrintAns(numbers, numberSize, n);
    return AssertIntegerEquals(2, numbers[0].number) && AssertIntegerEquals(1, numbers[0].power) &&
            AssertIntegerEquals(3, numbers[1].number) && AssertIntegerEquals(1, numbers[1].power) &&
            AssertIntegerEquals(280187, numbers[2].number) && AssertIntegerEquals(1, numbers[2].power);
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());
    failCount += OutputTest(caseCount++, TestCase3());
    failCount += OutputTest(caseCount++, TestCase4());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif