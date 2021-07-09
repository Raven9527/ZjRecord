#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define MAX_SIZE 5007

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct String_s
{
    char content[MAX_SIZE];
    int size;
}String;
void MainProgram();
void Input(String*); // 輸入
void ToUpperCase(String*); // 轉大寫
char IsLowerCase(char); // 判斷如果是小寫
char GetAbbreviation(char[]); // 得到這個字串的縮寫
void AddAbbreviationToString(String*, char); // 新增縮寫到String
void RunMainFunction(String*, String*); // 執行主要邏輯
void PrintAns(String*); // 輸出

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
    String wordString = {"", 0};
    String abbreviation = {"", 0};
    Input(&wordString);
    ToUpperCase(&wordString);
    RunMainFunction(&wordString, &abbreviation);
    PrintAns(&abbreviation);
}

void Input(String *string)
{
    gets(string->content);
    string->size = strlen(string->content);
}

char IsLowerCase(char k)
{
    return (k >= 'a' && k <= 'z');
}

void ToUpperCase(String *string)
{
    int i;
    for (i = 0; i < string->size; i++)
    {
        if (IsLowerCase(string->content[i]))
            string->content[i] -= 32;
    }
}

char GetAbbreviation(char word[])
{
    if (strcmp(word, "FOR") == 0)
        return '4';
    else if (strcmp(word, "TO") == 0)
        return '2';
    else if (strcmp(word, "AND") == 0)
        return 'n';
    else if (strcmp(word, "YOU") == 0)
        return 'u';
    return word[0];
}

void AddAbbreviationToString(String *string, char abbreviation)
{
    string->content[string->size] = abbreviation;
    string->size++;
}

void RunMainFunction(String *wordString, String *abbreviationString)
{
    int i;
    String tempWord = {"", 0};
    for (i = 0; i <= wordString->size; i++)
    {
        if (wordString->content[i] == ' ' || i == wordString->size)
        {
            AddAbbreviationToString(abbreviationString, GetAbbreviation(tempWord.content));
            memset(tempWord.content, '\0', sizeof(tempWord.content));
            tempWord.size = 0;
        }
        else
        {
            tempWord.content[tempWord.size] = wordString->content[i];
            tempWord.size++;
        }
    }
    //printf("abbreviation = 123%s456\n\n", abbreviationString->content);
}

void PrintAns(String *string)
{
    printf("%s", string->content);
}

#if TEST_FLAG
int TestCase1()
{
    String string = {"World Trade Organization", 0};
    string.size = strlen(string.content);
    String ans = {"", 0};
    ToUpperCase(&string);
    RunMainFunction(&string, &ans);
    return AssertStringEqual("WTO", ans.content);
}
int TestCase2()
{
    String string = {"As soon as possible", 0};
    string.size = strlen(string.content);
    String ans = {"", 0};
    ToUpperCase(&string);
    RunMainFunction(&string, &ans);
    return AssertStringEqual("ASAP", ans.content);
}
int TestCase3()
{
    String string = {"Bye for now", 0};
    string.size = strlen(string.content);
    String ans = {"", 0};
    ToUpperCase(&string);
    RunMainFunction(&string, &ans);
    return AssertStringEqual("B4N", ans.content);
}
int TestCase4()
{
    String string = {"FOR YOU", 0};
    string.size = strlen(string.content);
    String ans = {"", 0};
    ToUpperCase(&string);
    RunMainFunction(&string, &ans);
    return AssertStringEqual("4u", ans.content);
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