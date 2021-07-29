#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Constant_s
{
    int a;
    int b;
    int c;
}Constant;
void MainProgram();
void InputConstant(Constant*); // 輸入
int GetMax(int, int); // 回傳兩個之中比較大的值
int GetProfit(Constant, int); // 得到收益
int ComputeMaxProfit(Constant*, Constant*, int); // 計算最大收益

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
    Constant c1;
    Constant c2;
    int n = 2;
    InputConstant(&c1);
    InputConstant(&c2);
    scanf("%d", &n);
    printf("%d\n", ComputeMaxProfit(&c1, &c2, n));
}

void InputConstant(Constant *constant)
{
    scanf("%d %d %d", &(constant->a), &(constant->b), &(constant->c));
}

int GetMax(int a, int b)
{
    return a >= b ? a : b;
}

int GetProfit(Constant constant, int employee)
{
    return (constant.a * employee * employee) + (constant.b * employee) + constant.c;
}

int ComputeMaxProfit(Constant *constant1, Constant *constant2, int n)
{
    int max = -21487;
    int i;
    for (i = 0; i <= n; i++)
    {
        int tempProfit = GetProfit(*constant1, n - i) + GetProfit(*constant2, i);
        max = GetMax(tempProfit, max);
    }
    return max;
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    Constant c1 = {2, -1, 3};
    Constant c2 = {4, -5, 2};
    int n = 2;
    int ans = ComputeMaxProfit(&c1, &c2, n);
    return AssertIntegerEquals(11, ans);
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif