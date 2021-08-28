#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define STRING_SIZE 12

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct GuessChar_s
{
    char ans;
    int isHide;
}GuessChar;
typedef struct GuessString_s
{
    GuessChar string[STRING_SIZE];
    int size;
}GuessString;
void MainProgram();
void InputGuessString(GuessString*);
void Guess(GuessString*, char);
void PrintString(GuessString*);

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
    GuessString string;
    int n;
    char guess;
    InputGuessString(&string);
    scanf("%d", &n);
    PrintString(&string);
    while (n--)
    {
        scanf(" %c ", &guess);
        Guess(&string, guess);
        PrintString(&string);
    }
}

void InputGuessString(GuessString *string)
{
    char tempInput[STRING_SIZE];
    scanf("%s", tempInput);
    int i, s = strlen(tempInput);
    for (i = 0; i < s; i++)
    {
        string->string[i].ans = tempInput[i];
        string->string[i].isHide = 1;
    }
    string->size = s;
}

void Guess(GuessString *string, char c)
{
    int i;
    for (i = 0; i < string->size; i++)
    {
        if (string->string[i].ans == c)
            string->string[i].isHide = 0;
    }
}

void PrintString(GuessString *string)
{
    int i;
    for (i = 0; i < string->size; i++)
    {
        if (string->string[i].isHide)
            printf("*");
        else   
            printf("%c", string->string[i].ans);
    }
    printf("\n");
}

#if TEST_FLAG
// Test Region 
void Convert(GuessString* string, char covt[])
{
    int i, s = strlen(covt);
    for (i = 0; i < s; i++)
    {
        string->string[i].ans = covt[i];
        string->string[i].isHide = 1;
    }
    string->size = s;
}
void Fetch(GuessString* string, char fetch[])
{
    int i;
    for (i = 0; i < string->size; i++)
    {
        if (string->string[i].isHide)
            fetch[i] = '*';
        else
            fetch[i] = string->string[i].ans;
    }
    fetch[i] = '\0';
}
int TestCase1()
{
    GuessString string;
    char test[] = "hangman";
    char guessCode[] = "angpht";
    char fetch[STRING_SIZE];
    char except[100][100] = { "*a***a*", "*an**an", "*ang*an", "*ang*an", "hang*an", "hang*an" };
    int n = 6, i, flag = 1;
    Convert(&string, test);
    for (i = 0; i < n; i++)
    {
        Guess(&string, guessCode[i]);
        Fetch(&string, fetch);
        flag = flag & AssertStringEqual(except[i], fetch);
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