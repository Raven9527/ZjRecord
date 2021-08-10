#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 24

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct String_s
{
    char string[SIZE];
    int length;
}String;
void MainProgram();
void InputPassword(String*);
int ComputePasswordScore(String*); // 計算密碼的分數
int GetStringLength(String*); // 得到字串(密碼)的長度
int GetEnglishCharLength(String*); // 得到字串裡英文字元的個數
int GetNumberCharLength(String*); // 得到字串裡數字字元的個數
int IsStringOnlyEnglish(String*); // 字串是否都是英文
int IsStringOnlyNumber(String*); // 字串是否都是數字
int GetContinuouslyNumberCount(String*); // 字串的連續數字的個數
int IsPasswordQualified(String*); // 密碼是否達到合格標準
int IsCharEnglish(char); // 字元是否是英文
int IsCharNumber(char); // 字元是否是數字

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
    String password;
    InputPassword(&password);
    printf("%d\n", ComputePasswordScore(&password));
}

void InputPassword(String *pwd)
{
    scanf("%s", pwd->string);
    pwd->length = strlen(pwd->string);
}

int ComputePasswordScore(String *pwd)
{
    int addScore = GetStringLength(pwd) * 3 + GetEnglishCharLength(pwd) * 3 + GetNumberCharLength(pwd) * 2;
    int deductScore = (IsStringOnlyEnglish(pwd) ? GetStringLength(pwd) : 0) + (IsStringOnlyNumber(pwd) ? GetStringLength(pwd) : 0) + GetContinuouslyNumberCount(pwd) * 2;
    return addScore + -deductScore + (IsPasswordQualified(pwd) ? 10 : -5);
}

int GetStringLength(String *pwd)
{
    return pwd->length;
}

int GetEnglishCharLength(String *pwd)
{
    int i, count = 0;
    for (i = 0; i < pwd->length; i++)
        count += IsCharEnglish(pwd->string[i]);
    return count;
}

int GetNumberCharLength(String *pwd)
{
    int i, count = 0;
    for (i = 0; i < pwd->length; i++)
        count += IsCharNumber(pwd->string[i]);
    return count;
}

int IsStringOnlyEnglish(String *pwd)
{
    int i;
    for (i = 0; i < pwd->length; i++)
        if (!(IsCharEnglish(pwd->string[i])))
            return 0;
    return 1;
}

int IsStringOnlyNumber(String *pwd)
{
    int i;
    for (i = 0; i < pwd->length; i++)
        if (!(IsCharNumber(pwd->string[i])))
            return 0;
    return 1;
}

int GetContinuouslyNumberCount(String *pwd)
{
    int i, count = 0;
    int isContinuouslyNumberMode = 0;
    for (i = 0; i < pwd->length; i++)
    {
        if (IsCharNumber(pwd->string[i]))
        {
            if (isContinuouslyNumberMode)
                count++;
            else
                isContinuouslyNumberMode = 1;
        }
        else
        {
            isContinuouslyNumberMode = 0;
        }
    }
    return count;
}

int IsPasswordQualified(String *pwd)
{
    return GetStringLength(pwd) >= 8 && !IsStringOnlyEnglish(pwd) && !IsStringOnlyNumber(pwd);
}


int IsCharEnglish(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int IsCharNumber(char c)
{
    return c >= '0' && c <= '9';
}

#if TEST_FLAG
// Test Region
int TestCase1()
{
    String pwd = { {"123456"}, 6 };
    return AssertIntegerEquals(9, ComputePasswordScore(&pwd));
}
int TestCase2()
{
    String pwd = { {"Q8e8e8QaPpLe"}, 12 };
    return AssertIntegerEquals(79, ComputePasswordScore(&pwd));
}
int TestCase3()
{
    String pwd = { {"2020Happy2000"}, 13 };
    return AssertIntegerEquals(68, ComputePasswordScore(&pwd));
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