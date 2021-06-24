#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 1
#define PAUSE_FLAG 1
#define MAX_SIZE 1024

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
typedef struct String_s
{
    char string[MAX_SIZE];
    int size;
    int order; // 順序, 0 = 逆序, 1 = 正序
}String;
void StringAddChar(String*, char); // 字串增加一個字元
void StringAddString(String*, String*); // 字串增加另一個字串
void* ReverseString(String*); // 反轉字串
void ClearString(String*); // 清除字串
void Decode(char*, String*);
void PrintString(String*);

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
    char inp[MAX_SIZE];
    String master;
    ClearString(&master);

    scanf("%s", inp);
    Decode(inp, &master);
    PrintString(&master);
}

void PrintString(String *answer)
{
    printf("%s\n", answer->string);
}

void* ReverseString(String *master)
{
    char temp[MAX_SIZE];
    strcpy(temp, master->string);
    int i, t = 0;
    for (i = master->size - 1; i >= 0; i--)
    {
        master->string[t++] = temp[i];
    }
}

void StringAddChar(String *string, char c)
{
    string->string[string->size++] = c;
}

void StringAddString(String *master, String *caster)
{
    // 正序
    if (caster->order == 1)
    {
        strcat(master->string, caster->string);
        master->size += caster->size;
    }
    // 逆序
    else if (caster->order == 0)
    {
        ReverseString(caster);
        strcat(master->string, caster->string);
        master->size += caster->size;
    }
}

void ClearString(String* string)
{
    memset(string->string, '\0', sizeof(string->string));
    string->size = 0;
    string->order = 1;
}

void Decode(char inp[], String *master)
{
    String tempString;
    ClearString(&tempString);
    int i, s = strlen(inp);
    inp[s++] = '+';
    inp[s] = '\0';
    for (i = 0; i < s; i++)
    {
        // 串接並重設與指定下一個字串為正序
        if (inp[i] == '+')
        {
            if (tempString.size > 0)
            {
                StringAddString(master, &tempString);
                ClearString(&tempString);
            }
            tempString.order = 1;
        }
        // 串接並重設與指定下一個字串為逆序
        else if (inp[i] == '-')
        {
            if (tempString.size > 0)
            {
                StringAddString(master, &tempString);
                ClearString(&tempString);
            }
            tempString.order = 0;
        }
        // 增加字元到temp String
        else
        {
            StringAddChar(&tempString, inp[i]);
        }
    }
}

#if TEST_FLAG
int TestCase(char *testData, char *exceptData)
{
    String master;
    ClearString(&master);

    Decode(testData, &master);
    return AssertStringEqual(exceptData, master.string);
}
void TestString()
{
    int caseCount = 1;
    int failCount = 0;

    String testString;
    ClearString(&testString);

    failCount += OutputTest(caseCount++, AssertStringEqual("", testString.string));

    StringAddChar(&testString, 'a');
    StringAddChar(&testString, 'z');
    StringAddChar(&testString, 'b');
    StringAddChar(&testString, 'c');

    failCount += OutputTest(caseCount++, AssertStringEqual("azbc", testString.string));
    ReverseString(&testString);
    failCount += OutputTest(caseCount++, AssertStringEqual("cbza", testString.string));
    ReverseString(&testString);

    String addString;
    ClearString(&addString);
    addString.order = 0;
    strcpy(addString.string, "987654");
    addString.size = 6;

    StringAddString(&testString, &addString);
    failCount += OutputTest(caseCount++, AssertStringEqual("azbc456789", testString.string));
    failCount += OutputTest(caseCount++, AssertIntegerEquals(10, testString.size));

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
void TestMainProgram()
{
    int caseCount = 1;
    int failCount = 0;
    
    char testData1[] = "1234+5678";
    char exceptData1[] = "12345678";

    char testData2[] = "I-evol+you";
    char exceptData2[] = "Iloveyou";

    char testData3[] = "you+-aw+-tn+-nac+-yd";
    char exceptData3[] = "youwantcandy";

    char testData4[] = "1234-5678";
    char exceptData4[] = "12348765";
    
    char testData5[] = "ptt";
    char exceptData5[] = "ptt";

    char testData6[] = "snail+--+si--emosdnah";
    char exceptData6[] = "snailsihandsome";

    failCount += OutputTest(1, TestCase(testData1, exceptData1));
    failCount += OutputTest(2, TestCase(testData2, exceptData2));
    failCount += OutputTest(3, TestCase(testData3, exceptData3));
    failCount += OutputTest(4, TestCase(testData4, exceptData4));
    failCount += OutputTest(5, TestCase(testData5, exceptData5));
    failCount += OutputTest(6, TestCase(testData6, exceptData6));
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
// Test Region 
void TestProgram()
{
    printf("String part: \n");
    TestString();

    printf("\n------------------------\n\n");
    printf("Main Program part:\n");
    TestMainProgram();
}
#endif