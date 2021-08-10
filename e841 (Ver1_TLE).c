#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 1000005

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Treasure_s
{
    int index;
    int coin;
    int times;
}Treasure;
void MainProgram();
void InitializeTreasures(Treasure[], int); // 初始化寶藏群
void PutCoinToTreasures(Treasure[], int, int, int); // 對一系列的寶箱放置金幣
void EnlargeConinToTreasures(Treasure[], int, int, int); // 對一系列的寶箱擴充其倍數
int ComputeTreasurePrice(Treasure*); // 計算寶箱的價值
Treasure* GetMaxPriceTreasure(Treasure[], int); // 回傳最有價值的寶箱
Treasure treasures[SIZE];

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
    int n, m, i;
    int p, q, r, s;
    scanf("%d %d", &n, &m);
    InitializeTreasures(treasures, n);
    
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &p, &q, &r, &s);
        if (r == 1)
            PutCoinToTreasures(treasures, p - 1, q - 1, s);
        else if (r == 2)
            EnlargeConinToTreasures(treasures, p - 1, q - 1, s);
    }

    Treasure *maxTreasure = NULL;
    maxTreasure = GetMaxPriceTreasure(treasures, n);
    printf("%d %d\n", maxTreasure->index, ComputeTreasurePrice(maxTreasure));
}

void InitializeTreasures(Treasure treasure[], int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        treasure[i].index = i + 1;
        treasure[i].coin = 0;
        treasure[i].times = 1;
    }
}

void PutCoinToTreasures(Treasure treasures[], int start, int goal, int coins)
{
    int i;
    for (i = start; i <= goal; i++)
    {
        treasures[i].coin += coins;
    }
}

void EnlargeConinToTreasures(Treasure treasures[], int start, int goal, int times)
{
    int i;
    for (i = start; i <= goal; i++)
    {
        treasures[i].times *= times;
    }
}

int ComputeTreasurePrice(Treasure *treasure)
{
    return treasure->coin * treasure->times;
}

Treasure* GetMaxPriceTreasure(Treasure treasures[], int size)
{
    int i;
    Treasure *maxPriceTreasure = &treasures[0];
    for (i = 1; i < size; i++)
    {
        if (ComputeTreasurePrice(&treasures[i]) > ComputeTreasurePrice(maxPriceTreasure))
        {
            maxPriceTreasure = &treasures[i];
        }
    }
    return maxPriceTreasure;
}


#if TEST_FLAG
// Test Region
int TestCase1()
{
    Treasure treasures[20];
    int input[10][10] = { {3, 5, 2, 2}, {1, 4, 1, 2}, {5, 5, 2, 2}, {2, 5, 1, 3} };
    int i, j, k;
    int n = 5, m = 4;
    int exceptIndex = 5, exceptPrice = 12;
    InitializeTreasures(treasures, n);
    
    for (i = 0; i < m; i++)
    {
        int p = input[i][0], q = input[i][1], r = input[i][2], s = input[i][3];
        if (r == 1)
            PutCoinToTreasures(treasures, p - 1, q - 1, s);
        else if (r == 2)
            EnlargeConinToTreasures(treasures, p - 1, q - 1, s);
    }

    Treasure *maxTreasure = NULL;
    maxTreasure = GetMaxPriceTreasure(treasures, n);
    return AssertIntegerEquals(exceptIndex, maxTreasure->index) && AssertIntegerEquals(exceptPrice, ComputeTreasurePrice(maxTreasure));
}
int TestCase2()
{
    Treasure treasures[20];
    int input[10][10] = { {1, 6, 1, 1}, {2, 3, 1, 2}, {3, 5, 2, 2}, {2, 2, 1, 3}, {4, 5, 1, 2} };
    int i, j, k;
    int n = 6, m = 5;
    int exceptIndex = 2, exceptPrice = 6;
    InitializeTreasures(treasures, n);
    
    for (i = 0; i < m; i++)
    {
        int p = input[i][0], q = input[i][1], r = input[i][2], s = input[i][3];
        if (r == 1)
            PutCoinToTreasures(treasures, p - 1, q - 1, s);
        else if (r == 2)
            EnlargeConinToTreasures(treasures, p - 1, q - 1, s);
    }

    Treasure *maxTreasure = NULL;
    maxTreasure = GetMaxPriceTreasure(treasures, n);
    return AssertIntegerEquals(exceptIndex, maxTreasure->index) && AssertIntegerEquals(exceptPrice, ComputeTreasurePrice(maxTreasure));
}
int TestCase3()
{
    Treasure treasures[20];
    int input[10][10] = { {2, 9, 1, 99}, {1, 7, 2, 1249}, {5, 10, 2, 1}, {5, 6, 1, 999999}, {6, 7, 1, 500000} };
    int i, j, k;
    int n = 10, m = 5;
    int exceptIndex = 6, exceptPrice = 1873622402;
    InitializeTreasures(treasures, n);
    
    for (i = 0; i < m; i++)
    {
        int p = input[i][0], q = input[i][1], r = input[i][2], s = input[i][3];
        if (r == 1)
            PutCoinToTreasures(treasures, p - 1, q - 1, s);
        else if (r == 2)
            EnlargeConinToTreasures(treasures, p - 1, q - 1, s);
    }

    Treasure *maxTreasure = NULL;
    maxTreasure = GetMaxPriceTreasure(treasures, n);
    return AssertIntegerEquals(exceptIndex, maxTreasure->index) && AssertIntegerEquals(exceptPrice, ComputeTreasurePrice(maxTreasure));
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