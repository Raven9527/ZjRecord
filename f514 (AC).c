#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define MAX_SIZE 105

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
void InputCharCard(char[]); // 輸入字母卡
void InputTargetString(char[]); // 輸入目標詞彙
void RunSpelling(char[], char[], int[], int*); // 進行拼字
int FindChar(char[], char); // 尋找字元，返回字元所在的編號
void StoreCardIndex(int[], int*, int); // 儲存卡片編號
void PrintAns(int[], int); // 輸出答案


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
    char charCard[MAX_SIZE];
    char targetString[MAX_SIZE];
    int cardIndexArray[MAX_SIZE];
    int size = 0;
    InputCharCard(charCard);
    InputTargetString(targetString);
    RunSpelling(charCard, targetString, cardIndexArray, &size);
    PrintAns(cardIndexArray, size);
}

void InputCharCard(char inp[])
{
    scanf("%s", inp);
}

void InputTargetString(char target[])
{
    scanf("%s", target);
}

void RunSpelling(char charCard[], char target[], int indexArray[], int *size)
{
    int i, targetLength = strlen(target);
    for (i = 0; i < targetLength; i++)
    {
        int index = FindChar(charCard, target[i]);
        if (index >= 0) // 找到的狀況 → char card 拿走一個 儲存卡片位置
        {
            charCard[index] = '_';
            StoreCardIndex(indexArray, size, index + 1);
        }
        else // 沒找到的狀況 → 卡片位置儲存-1 
        {
            StoreCardIndex(indexArray, size, -1);
        }
    }
}

int FindChar(char card[], char targetChar)
{
    int index = 0;
    while(card[index])
    {
        if (card[index] == targetChar)
            return index;
        index++;   
    }
    return -1;
}

void StoreCardIndex(int indexArray[], int *size, int targetIndex)
{
    indexArray[(*size)++] = targetIndex;
}

void PrintAns(int ans[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (ans[i] > 0)
            printf("%d ", ans[i]);
        else
            printf("X ");
    }
}

#if TEST_FLAG
int TestCase1()
{
    char card[] = "tca";
    char target[] = "cat";
    int indexArray[MAX_SIZE], size = 0;
    RunSpelling(card, target, indexArray, &size);
    return AssertIntegerEquals(2, indexArray[0]) && 
           AssertIntegerEquals(3, indexArray[1]) && 
           AssertIntegerEquals(1, indexArray[2]);
}
int TestCase2()
{
    char card[] = "gjidjiaisodjogjfi";
    char target[] = "good";
    int indexArray[MAX_SIZE], size = 0;
    RunSpelling(card, target, indexArray, &size);
    return AssertIntegerEquals(1, indexArray[0]) && 
           AssertIntegerEquals(10, indexArray[1]) && 
           AssertIntegerEquals(13, indexArray[2]) &&
           AssertIntegerEquals(4, indexArray[3]);
}
int TestCase3()
{
    char card[] = "ivjifjifawods";
    char target[] = "wow";
    int indexArray[MAX_SIZE], size = 0;
    RunSpelling(card, target, indexArray, &size);
    return AssertIntegerEquals(10, indexArray[0]) && 
           AssertIntegerEquals(11, indexArray[1]) && 
           AssertIntegerEquals(-1, indexArray[2]);
}
int TestCase4()
{
    char card[] = "cnvieqpzkgoaotjfd";
    char target[] = "gogoro";
    int indexArray[MAX_SIZE], size = 0;
    RunSpelling(card, target, indexArray, &size);
    return AssertIntegerEquals(10, indexArray[0]) && 
           AssertIntegerEquals(11, indexArray[1]) && 
           AssertIntegerEquals(-1, indexArray[2]) && 
           AssertIntegerEquals(13, indexArray[3]) && 
           AssertIntegerEquals(-1, indexArray[4]) && 
           AssertIntegerEquals(-1, indexArray[5]);
}
// Test Region 
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