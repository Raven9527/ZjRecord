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

typedef struct Fraction_s
{
    long long numerator;
    long long denominator;
}Fraction;
typedef struct Treasure_s
{
    int index;
    int coin;
    Fraction times;
}Treasure;
void MainProgram();
void InitializeTreasures(Treasure[], int); // 初始化寶藏群
void PutCoinToTreasures(Treasure[], int, int, int); // 對一系列的寶箱放置金幣
void EnlargeConinToTreasures(Treasure[], int, int, int); // 對一系列的寶箱擴充其倍數
void ReduceTreasuresInfomation(Treasure[], int); // 還原寶箱的資訊 (將只記錄變化的資訊還原至coin multi div等資訊)
int ComputeTreasurePrice(Treasure*); // 計算寶箱的價值
Treasure* GetMaxPriceTreasure(Treasure[], int); // 回傳最有價值的寶箱
long long gcd(long long, long long);
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
    ReduceTreasuresInfomation(treasures, n);

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
        treasure[i].times.numerator = 1;
        treasure[i].times.denominator = 1;
    }
}

void PutCoinToTreasures(Treasure treasures[], int start, int goal, int coins)
{
    treasures[start].coin += coins;
    treasures[goal + 1].coin -= coins;
}

void EnlargeConinToTreasures(Treasure treasures[], int start, int goal, int times)
{
    treasures[start].times.numerator *= times;
    treasures[goal + 1].times.denominator *= times;
}

void ReduceTreasuresInfomation(Treasure treasures[], int size)
{
    int i;
    for (i = 1; i < size; i++)
    {
        treasures[i].coin = treasures[i].coin + treasures[i - 1].coin;
        treasures[i].times.numerator = treasures[i].times.numerator * treasures[i - 1].times.numerator;
        treasures[i].times.denominator = treasures[i].times.denominator * treasures[i - 1].times.denominator;
    
        int g = gcd(treasures[i].times.numerator, treasures[i].times.denominator); // 約分很重要
        treasures[i].times.numerator /= g;
        treasures[i].times.denominator /= g;
    }
}

int ComputeTreasurePrice(Treasure *treasure)
{
    return treasure->coin * (treasure->times.numerator / treasure->times.denominator);
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

long long gcd(long long a,long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
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

    ReduceTreasuresInfomation(treasures, n);
    Treasure *maxTreasure = NULL;
    maxTreasure = GetMaxPriceTreasure(treasures, n);
    // for (i = 0; i < n; i++)
    // {
    //     printf("index %d: %d %d %d %lf\n", treasures[i].index, treasures[i].coin, treasures[i].multis, treasures[i].divs, treasures[i].times);
    // }
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

    ReduceTreasuresInfomation(treasures, n);
    Treasure *maxTreasure = NULL;
    maxTreasure = GetMaxPriceTreasure(treasures, n);
    // for (i = 0; i < n; i++)
    // {
    //     printf("index %d: %d %d %d %lf\n", treasures[i].index, treasures[i].coin, treasures[i].multis, treasures[i].divs, treasures[i].times);
    // }
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

    ReduceTreasuresInfomation(treasures, n);
    Treasure *maxTreasure = NULL;
    maxTreasure = GetMaxPriceTreasure(treasures, n);
    // for (i = 0; i < n; i++)
    // {
    //     printf("index %d: %d %d %d %lf\n", treasures[i].index, treasures[i].coin, treasures[i].multis, treasures[i].divs, treasures[i].times);
    // }
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