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
void InputGroupData(char[80][5], int); // 輸入院系組別資料
void InputTestStudentId(char[10][10]);
void RunTest(int[], char[10][10], char[80][5], int);
int CheckStudentIdValid(char[], char[80][5], int);
int CheckBachelorClassCodeValud(char[]); // 檢查學士班代號是有效的
int CheckStudyYearValid(char[]); // 檢查入學年是有效的
int CheckGroupCodeValid(char[], char[80][5], int); // 檢查院系組別代號是有效的
int CompareGroupCode(char[], char[]); // 比對兩個組別代號是否相同
int CheckSequenceIdValid(char[]); // 檢查流水號是有效的
int IsNumber(char);
void PrintAns(int[]);

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
    int n, i;
    char groupData[80][5];
    char testStudentId[10][10];
    int testResult[10] = {0};
    scanf("%d", &n);
    InputGroupData(groupData, n);
    InputTestStudentId(testStudentId);
    RunTest(testResult, testStudentId, groupData, n);
    PrintAns(testResult);
}

void RunTest(int result[], char testStudentId[10][10], char groupData[80][5], int size)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        result[i] = CheckStudentIdValid(testStudentId[i], groupData, size);
    }
}

void InputGroupData(char group[80][5], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%s", group[i]);
    }
}

void InputTestStudentId(char studentIds[10][10])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        scanf("%s", studentIds[i]);
    }
}

void PrintAns(int result[])
{
    int i, failCount = 0;
    for (i = 0; i < 10; i++)
    {
        if (result[i] == 0)
        {
            printf("N\n");
            failCount++;
        }
        else
        {
            printf("Y\n");
        }
    }
    
    if (failCount == 10)
        printf("1\n");
    else if (failCount == 0)
        printf("0\n");
    else
        printf("0.%d\n", failCount);
}

int CheckStudentIdValid(char id[], char groupData[80][5], int groupSize)
{
    return CheckBachelorClassCodeValud(id) && CheckStudyYearValid(id) && CheckGroupCodeValid(id, groupData, groupSize) && CheckSequenceIdValid(id);
}

int CheckBachelorClassCodeValud(char id[])
{
    return id[0] == 'B';
}

int CheckStudyYearValid(char id[])
{
    return IsNumber(id[1]) && IsNumber(id[2]);
}

int CheckGroupCodeValid(char id[], char groupData[80][5], int groupSize)
{
    char idGroupCode[5];
    int i, j;
    for (i = 3; i <= 6; i++)
        idGroupCode[i - 3] = id[i];

    for (i = 0; i < groupSize; i++)
    {
        if (CompareGroupCode(idGroupCode, groupData[i]))
            return 1;
    }
    return 0;
}

int CheckSequenceIdValid(char id[])
{
    return IsNumber(id[7]) && IsNumber(id[8]);
}

int CompareGroupCode(char idA[], char idB[])
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (idA[i] != idB[i])
            return 0;
    }
    return 1;
}

int IsNumber(char k)
{
    return k >= '0' && k <= '9';
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    char testData[80][5] = { "0000", "1000", "1010", "1011", "1020", "1030", "1040", "1050", "1060", "1070", "1090", "2000", "2010", "2020", "2030", "2040", "2070", "2080", "2090", "3000", "3021", "3022", "3023", "3030", "3050", "3100", "4000", "4010", "4020", "4030", "4031", "4040", "4060", "4080", "4081", "4090", "4120", "5000", "5010", "5020", "5040", "5050", "5070", "5080", "6000", "6010", "6020", "6030", "6050", "6060", "6070", "6080", "6090", "6100", "6110", "6120", "6130", "7000", "7011", "7012", "7020", "7030", "7040", "7050", "8000", "8010", "9000", "9010", "9020", "A000", "A011", "A012", "A013", "B000", "B010", "B020" };
    int n = 76;
    char checkData[10][10] = { "B00100000", "R00100000", "BA0100000", "B00101300", "B001000A0", "B09902005", "B06A01233", "B12701256", "B80310020", "B98901030" };
    int except[10] = {1, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int i, flag = 1;
    for (i = 0; i < 10; i++)
    {
        if (except[i] != CheckStudentIdValid(checkData[i], testData, n))
            flag = 0;
    }
    return flag;
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif