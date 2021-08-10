#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 10032

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct String_s
{
    char string[SIZE];
    int size;
}String;
void MainProgram();
void InputStringData(String*);
void FindMaxSequenceString(String*, String*); // 找出最長的有序字串
void CaptureSequenceString(String*, int, String*); // 從指定的點開始擷取第一個有序字串

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
    String testData;
    String maxSequenceString;
    InputStringData(&testData);
    FindMaxSequenceString(&testData, &maxSequenceString);
    printf("%d %s\n", maxSequenceString.size, maxSequenceString.string);
}

void InputStringData(String *string)
{
    scanf("%s", (string->string));
    string->size = strlen(string->string);
}

void FindMaxSequenceString(String *main, String *maxSequence)
{
    memset(maxSequence->string, '\0', sizeof(maxSequence->string));
    maxSequence->size = 0;
    String tempCapture;
    int i, k;
    for (i = 0; i < main->size; i++)
    {
        tempCapture.size = 0;
        CaptureSequenceString(main, i, &tempCapture);
        if (maxSequence->size <= tempCapture.size)
        {
            strcpy(maxSequence->string, tempCapture.string);
            maxSequence->size = tempCapture.size;
        }
    }
}

void CaptureSequenceString(String *string, int start, String *capture)
{
    int index = 0;
    int i;
    char currentChar = string->string[start];
    for (i = start; i < string->size; i++)
    {
        if (currentChar + index == string->string[i])
        {
            capture->string[index++] = string->string[i];
            capture->size = index;
        }
        else
        {
            capture->string[index] = '\0';
            break;
        }
    }
}

#if TEST_FLAG
// Test Region
int TestCase1()
{
    String data;
    String ans;
    strcpy(data.string, "abcwkodvwxyzwia");
    data.size = strlen(data.string);
    FindMaxSequenceString(&data, &ans);
    printf("%s %d\n", ans.string, ans.size);
    return AssertIntegerEquals(5, ans.size) && AssertStringEqual("vwxyz", ans.string);
}
int TestCase2()
{
    String data;
    strcpy(data.string, "gfeabuvstyzijo");
    data.size = strlen(data.string);
    String ans;
    FindMaxSequenceString(&data, &ans);
    printf("%s %d\n", ans.string, ans.size);
    return AssertIntegerEquals(2, ans.size) && AssertStringEqual("ij", ans.string);
}
int TestCase3()
{
    String data;
    strcpy(data.string, "apple");
    data.size = strlen(data.string);
    String ans;
    FindMaxSequenceString(&data, &ans);
    return AssertIntegerEquals(1, ans.size) && AssertStringEqual("e", ans.string);
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());
    failCount += OutputTest(caseCount++, TestCase3());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif