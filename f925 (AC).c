#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
void TestProgram();
void MainProgram();

// Function Region
void Input(int *month, int *date)
{
    scanf("%d %d", month, date);
}
char* JudgementCIA(int month, int date)
{
    if (month == 6 && date == 12)
        return "Yes";
    else
        return "No";
}

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
    int m, d;
    Input(&m, &d);
    printf(JudgementCIA(m, d));
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
    failCount += OutputTest(caseCount++, (strcmp(JudgementCIA(6, 12), "Yes") == 0) ? 1 : 0);
    failCount += OutputTest(caseCount++, (strcmp(JudgementCIA(6, 11), "No") == 0) ? 1 : 0);
    failCount += OutputTest(caseCount++, (strcmp(JudgementCIA(6, 13), "No") == 0) ? 1 : 0);
    failCount += OutputTest(caseCount++, (strcmp(JudgementCIA(7, 12), "No") == 0) ? 1 : 0);

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}