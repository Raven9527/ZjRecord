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
typedef struct CountableChar_s
{
    char c;
    int count;
}CountableChar;
int cmp(const void*, const void*);
void Sort(CountableChar[]); // 排序 (串cmp)
void InitializeCharArray(CountableChar[]); // 初始化 char 陣列
void AddCharCount(CountableChar[], char); // 新增字元的出現次數
int GetCharIndex(char); // 得到字元的index
void Decode(char[], CountableChar[]); // 解碼
void PrintAns(CountableChar[]);

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
    char inp[105];
    CountableChar charArray[26];
    InitializeCharArray(charArray);
    scanf("%s", inp);
    Decode(inp, charArray);
    PrintAns(charArray);
}

void Decode(char inp[], CountableChar charArray[])
{
    int i;
    for (i = 0; inp[i]; i++)
    {
        AddCharCount(charArray, inp[i]);
    }

    Sort(charArray);
}

void PrintAns(CountableChar charArray[])
{
    int i;
    for (i = 0; i < 26; i++)
    {
        if (charArray[i].count > 0)
            printf("%c", charArray[i].c);
    }
}

void InitializeCharArray(CountableChar charArray[])
{
    int i;
    for (i = 0; i < 26; i++)
    {
        charArray[i].c = i + 'A';
        charArray[i].count = 0;
    }
}

void AddCharCount(CountableChar charArray[], char c)
{
    int index = GetCharIndex(c);
    charArray[index].count++;
}

int cmp(const void *a, const void *b)
{
    CountableChar *c = (CountableChar *)a;
    CountableChar *d = (CountableChar *)b;
    if (c->count != d->count)
        return c->count > d->count ? -1 : 1;
    else
        return c->c < d->c ? -1 : 1;
}

void Sort(CountableChar charArray[])
{
    qsort(charArray, 26, sizeof(charArray[0]), cmp);
}

int GetCharIndex(char c)
{
    return c - 'A';
}

#if TEST_FLAG
int TestCase(char testData[], char exceptData[], int eSize)
{
    CountableChar charArray[26];
    InitializeCharArray(charArray);
    Decode(testData, charArray);
    
    
    // PrintAns(charArray);
    // printf("\n");

    int i, k = 0;

    // for (i = 0; i < 26; i++)
    // {
    //     printf("%c: %d\n", charArray[i].c, charArray[i].count);
    // }

    for (i = 0; i < 25; i++)
    {
        if (charArray[i].count < charArray[i + 1].count)
            return 0;
    }

    for (i = 0; i < 26; i++)
    {
        if (charArray[i].count == 0)
            break;
        if (charArray[i].c != exceptData[i])
            return 0;
    }
    return 1;
}
// Test Region 
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    char testData1[] = "ABCCCB";
    char exceptData1[] = "CBA";

    char testData2[] = "ORWRWRWOOWLD";
    char exceptData2[] = "WORDL";

    char testData3[] = "REDGREENBLUE";
    char exceptData3[] = "ERBDGLNU";

    failCount += OutputTest(caseCount++, TestCase(testData1, exceptData1, strlen(exceptData1)));
    failCount += OutputTest(caseCount++, TestCase(testData2, exceptData2, strlen(exceptData2)));
    failCount += OutputTest(caseCount++, TestCase(testData3, exceptData3, strlen(exceptData3)));

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif