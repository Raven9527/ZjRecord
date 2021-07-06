#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define MAX_SIZE 1024

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();

void Input(char[]); // 輸出
void LowerCase(char[]);
int IsLove(char[]); // 這個字串是love的變異體嗎?
int ComputeShiftBit(char[]); // 計算要位移的bit量
int GetBitAfterDecodePassword(char[]); // 解碼 (回傳要位移的bit量)
int IsEnglish(char);

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
    char password[MAX_SIZE];
    Input(password);
    LowerCase(password);
    printf("%d\n", GetBitAfterDecodePassword(password));  
}

void Input(char inp[])
{
    gets(inp);
}

int IsEnglish(char k)
{
    return (k >= 'A' && k <= 'Z') || (k >= 'a' && k <= 'z');
}

void LowerCase(char rmString[])
{
    int index = 0;
    while(rmString[index])
    {
        if (rmString[index] >= 'A' && rmString[index] <= 'Z')
            rmString[index] += 32;
        index++;
    }
    rmString[index++] = '\0';
}

int IsLove(char love[])
{
    if (!IsEnglish(love[0]) || !IsEnglish(love[1]) || !IsEnglish(love[2]) || !IsEnglish(love[3]))
        return 0;

    int i, j;
    char temp[5];
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 4; j++)
            temp[j] = (love[j] + i > 'z') ? love[j] + i - 26 : love[j] + i;
        temp[4] = '\0';
        
        if (strcmp("love", temp) == 0)
            return 1;
    }
    return 0;
}

int ComputeShiftBit(char love[])
{
    return ('e' - love[3] >= 0) ? 'e' - love[3] : 26 + ('e' - love[3]);
}

int GetBitAfterDecodePassword(char pwd[])
{
    int s = strlen(pwd), i;
    char love[5];
    for (i = 0; i < s - 3; i++)
    {
        love[0] = pwd[i];
        love[1] = pwd[i + 1];
        love[2] = pwd[i + 2];
        love[3] = pwd[i + 3];
        love[4] = '\0';

        if (IsLove(love))
        {
            return ComputeShiftBit(love);
        }
    }
    return -999;
}

#if TEST_FLAG
int TestIsLove()
{
    if (IsLove("Love"))
        return 0;
    if (!IsLove("love"))
        return 0;
    if (!IsLove("ilsb"))
        return 0;
    if (IsLove("zxcv"))
        return 0;

    return 1;
}
int TestShiftBit()
{
    if (!AssertIntegerEquals(0, ComputeShiftBit("love")))
        return 0;

    if (!AssertIntegerEquals(3, ComputeShiftBit("ilsb")))
        return 0;

    return 1;
}
int TestCase3()
{
    char pwd[] = "F ilsb vlr.";
    LowerCase(pwd);
    int bit = GetBitAfterDecodePassword(pwd);
    return AssertIntegerEquals(3, bit);
}
int TestCase4()
{
    char pwd[] = "NqxgRgceg";
    LowerCase(pwd);
    int bit = GetBitAfterDecodePassword(pwd);
    printf("%d\n", bit);
    return AssertIntegerEquals(24, bit);
}
int TestCase5()
{
    char pwd[] = "At the touch of love everyone becomes a poet.";
    LowerCase(pwd);
    int bit = GetBitAfterDecodePassword(pwd);
    return AssertIntegerEquals(0, bit);
}
int TestRemoveSpace()
{
    char pwd[] = "I Love You.";
    char pwd2[] = "At the touch of love everyone becomes a poet.";

    LowerCase(pwd);
    LowerCase(pwd2);
    // printf("%s\n", pwd);
    // printf("%s\n", pwd2);
    if (!AssertStringEqual("i love you.", pwd))
        return 0;
    if (!AssertStringEqual("at the touch of love everyone becomes a poet.", pwd2))
        return 0;

    return 1;
}
int TestCase7()
{
    char pwd[] = "I L o v e You.";
    LowerCase(pwd);
    int bit = GetBitAfterDecodePassword(pwd);
    return AssertIntegerEquals(-999, bit);
}
int TestCase8()
{
    char pwd[] = "I L_o1v,e You.";
    LowerCase(pwd);
    int bit = GetBitAfterDecodePassword(pwd);
    return AssertIntegerEquals(-999, bit);
}
int TestCase9()
{
    char pwd[] = "I L,o,v,e You.";
    LowerCase(pwd);
    int bit = GetBitAfterDecodePassword(pwd);
    return AssertIntegerEquals(-999, bit);
}
int TestCase10()
{
    char pwd[] = "11Love";
    LowerCase(pwd);
    int bit = GetBitAfterDecodePassword(pwd);
    return AssertIntegerEquals(0, bit);
}
int TestCase11()
{
    char pwd[] = "NooINotL0o0v0eYou";
    LowerCase(pwd);
    int bit = GetBitAfterDecodePassword(pwd);
    return AssertIntegerEquals(-999, bit);
}
// Test Region 
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestIsLove());
    failCount += OutputTest(caseCount++, TestShiftBit());
    failCount += OutputTest(caseCount++, TestCase3());
    failCount += OutputTest(caseCount++, TestCase4());
    failCount += OutputTest(caseCount++, TestCase5());
    failCount += OutputTest(caseCount++, TestRemoveSpace());
    failCount += OutputTest(caseCount++, TestCase7());
    failCount += OutputTest(caseCount++, TestCase8());
    failCount += OutputTest(caseCount++, TestCase9());
    failCount += OutputTest(caseCount++, TestCase10());
    failCount += OutputTest(caseCount++, TestCase11());
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif