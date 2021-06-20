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

int Wholesale(int base, int productCount)
{
    if (productCount % base == 0)
        return productCount / base;
    else
        return base - (productCount % base);
}

void MainProgram()
{
    int base, n = -1;
    scanf("%d", &base);
    while(scanf("%d", &n))
    {
        if (n == 0)
            break;
        printf("%d\n", Wholesale(base, n));
    }
}


#if TEST_FLAG
// Test Region
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;
    failCount += (OutputTest(1, AssertIntegerEquals(10, Wholesale(10, 100))));
    failCount += (OutputTest(2, AssertIntegerEquals(5, Wholesale(10, 50))));
    failCount += (OutputTest(3, AssertIntegerEquals(1, Wholesale(10, 9))));
    failCount += (OutputTest(4, AssertIntegerEquals(3, Wholesale(5, 22))));
    failCount += (OutputTest(5, AssertIntegerEquals(1, Wholesale(5, 9))));
    failCount += (OutputTest(6, AssertIntegerEquals(20, Wholesale(5, 100))));
    failCount += (OutputTest(7, AssertIntegerEquals(2, Wholesale(5, 73))));
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif