#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
void TestProgram();
void MainProgram();

// Function Region

// Main Region
int main()
{
    if (TEST_FLAG)
        TestProgram();
    else
        MainProgram();

    if (PAUSE_FLAG)
        system("pause");
    return 0;
}

void MainProgram()
{
    printf("Hello CIA!\n");
}


// Test Region 
int OutputTest(int outputCase, int flag)
{
    if (flag)
        printf("case %d: pass\n", outputCase);
    else
        printf("case %d: fail\n", outputCase);
    return !flag;
}

void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}