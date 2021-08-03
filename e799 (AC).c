#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 65

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Password_s
{
    long long int number;
    int bites[SIZE];
    int len;
    char password[SIZE * 2];
}Password;
void MainProgram();
void ConvertNumberToBites(int[], long long int, int); // 數字換成二進位
void ConvertBitesToString(char[], int[], int, char); // 二進位換成字串
void Decode(Password*, char);

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
    Password pwd[SIZE];
    int n, m, i;
    char dk;
    scanf("%d %d", &n, &m);
    scanf(" %c ", &dk);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &(pwd[i].number));
        pwd[i].len = m;
    }

    for (i = 0; i < n; i++)
        Decode(&pwd[i], dk);
    
    for (i = 0; i < n; i++)
        printf("%s\n", pwd[i].password);
}

void Decode(Password *password, char dk)
{
    ConvertNumberToBites(password->bites, password->number, password->len);
    ConvertBitesToString(password->password, password->bites, password->len, dk);
}

void ConvertNumberToBites(int bites[], long long int number, int len)
{
    int i = 0, j, tempSize = 0;
    int tempBites[SIZE] = {0};
    for (tempSize = 0; len > 0; tempSize++, len--)
    {
        if (number > 0)
        {
            tempBites[tempSize] = number % 2;
            number = number >> 1;
        }
    }

    for (i = tempSize - 1, j = 0; i >= 0; i--, j++)
    {
        bites[j] = tempBites[i];
    }
}

void ConvertBitesToString(char string[], int bites[], int len, char dk)
{
    int i;
    for (i = 0; i < len; i++)
    {
        string[i * 2] = (bites[i] == 1) ? dk : '.';
        string[i * 2 + 1] = ' ';
    }
    string[i * 2] = '\0';
}

#if TEST_FLAG
// Test Region
int TestConvert1()
{
    long long int number = 127;
    int i, n = 10;
    int except[SIZE] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    int ans[SIZE] = {0};
    ConvertNumberToBites(ans, number, n);
    return AssertIntegerArrayEquals(except, n, ans, n);
}
int TestConvert2()
{
    long long int number = 28;
    int i, n = 10;
    int except[SIZE] = {0, 0, 0, 0, 0, 1, 1, 1, 0, 0};
    int ans[SIZE] = {0};
    ConvertNumberToBites(ans, number, n);
    return AssertIntegerArrayEquals(except, n, ans, n);
}
int TestCase1()
{
    Password pwd[9];
    int i, n = 9;
    long long int numberArray[] = {0, 127, 127, 28, 28, 28, 127, 127, 0};
    int len = 7;
    char dk = '@';
    char except[SIZE][SIZE] = {". . . . . . . ", "@ @ @ @ @ @ @ ", "@ @ @ @ @ @ @ ", ". . @ @ @ . . ", ". . @ @ @ . . ", ". . @ @ @ . . ", "@ @ @ @ @ @ @ ", "@ @ @ @ @ @ @ ", ". . . . . . . " };
    for (i = 0; i < n; i++)
    {
        pwd[i].number = numberArray[i];
        pwd[i].len = len;
    }

    for (i = 0; i < n; i++)
        Decode(&pwd[i], dk);

    for (i = 0; i < n; i++)
    {
        if (AssertStringEqual(except[i], pwd[i].password) == 0)
            return 0;
    }
    return 1;
}
int TestCase2()
{
    Password pwd[8];
    int i, n = 8;
    long long int numberArray[] = {0, 102, 255, 255, 126, 60, 24, 0};
    int len = 8;
    char dk = '#';
    char except[SIZE][SIZE] = {". . . . . . . . ", ". # # . . # # . ", "# # # # # # # # ", "# # # # # # # # ", ". # # # # # # . ", ". . # # # # . . ", ". . . # # . . . ", ". . . . . . . . " };
    for (i = 0; i < n; i++)
    {
        pwd[i].number = numberArray[i];
        pwd[i].len = len;
    }

    for (i = 0; i < n; i++)
        Decode(&pwd[i], dk);

    for (i = 0; i < n; i++)
    {
        if (AssertStringEqual(except[i], pwd[i].password) == 0)
            return 0;
    }
    return 1;
}
int TestCase3()
{
    Password pwd[7];
    int i, n = 6;
    long long int numberArray[] = {99, 99, 99, 99, 119, 62};
    int len = 7;
    char dk = '6';
    char except[SIZE][SIZE] = {"6 6 . . . 6 6 ", "6 6 . . . 6 6 ", "6 6 . . . 6 6 ", "6 6 . . . 6 6 ", "6 6 6 . 6 6 6 ", ". 6 6 6 6 6 . " };
    for (i = 0; i < n; i++)
    {
        pwd[i].number = numberArray[i];
        pwd[i].len = len;
    }

    for (i = 0; i < n; i++)
        Decode(&pwd[i], dk);

    for (i = 0; i < n; i++)
    {
        if (AssertStringEqual(except[i], pwd[i].password) == 0)
            return 0;
    }
    return 1;
}
void TestProgram()
{
    int caseCount = 1;
    int convertCase = 1;
    int failCount = 0;

    failCount += OutputTest(convertCase++, TestConvert1());
    failCount += OutputTest(convertCase++, TestConvert2());

    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());
    failCount += OutputTest(caseCount++, TestCase3());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif