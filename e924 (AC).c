#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define STACK_SIZE 1005

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Stack_s
{
    char stack[STACK_SIZE];
    int size;
}Stack;
void StackPush(Stack*, char);
char GetStackTop(Stack*);
char StackPop(Stack*);
int IsStackEmpty(Stack*);
void MainProgram();
int IsBracketStringMatch(char[]); // 括號串是否匹配
int IsLeftBracket(char); // 是否是左括號
char GetLeftBracketByRight(char); // 根據右括號取得匹配的左括號

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
    int n;
    char input[STACK_SIZE];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", input);
        printf(IsBracketStringMatch(input) == 0 ? "N\n" : "Y\n");
    }
}

void StackPush(Stack *stack, char element)
{
    stack->stack[stack->size] = element;
    stack->size++;
}

char GetStackTop(Stack *stack)
{
    if (stack->size <= 0)
        return 0;
    return stack->stack[stack->size - 1];
}

char StackPop(Stack *stack)
{
    if (stack->size <= 0)
        return 0;

    stack->size--;
    return stack->stack[stack->size];
}

int IsStackEmpty(Stack *stack)
{
    return stack->size == 0;
}

int IsBracketStringMatch(char bracket[])
{
    Stack stack = { "", 0 };
    int bracketSize = strlen(bracket), i;
    for (i = 0; i < bracketSize; i++)
    {
        if (IsLeftBracket(bracket[i]))
            StackPush(&stack, bracket[i]);
        else if (!IsStackEmpty(&stack) && GetStackTop(&stack) == GetLeftBracketByRight(bracket[i]))
            StackPop(&stack);
        else
            return 0;
    }

    return IsStackEmpty(&stack);
}

int IsLeftBracket(char b)
{
    return b == '[' || b == '(' || b == '<' || b == '{';
}

char GetLeftBracketByRight(char b)
{
    if (b == ']')
        return '[';
    else if (b == ')')
        return '(';
    else if (b == '>')
        return '<';
    else if (b == '}')
        return '{';

    return 0;
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    char testData[] = "{()<>}[]";
    return AssertIntegerEquals(1, IsBracketStringMatch(testData));
}
int TestCase2()
{
    char testData[] = "(){";
    return AssertIntegerEquals(0, IsBracketStringMatch(testData));
}
int TestCase3()
{
    char testData[] = "{(})";
    return AssertIntegerEquals(0, IsBracketStringMatch(testData));
}
int TestCase4()
{
    char testData[] = "())";
    return AssertIntegerEquals(0, IsBracketStringMatch(testData));
}
int TestCase5()
{
    char testData[] = "";
    return AssertIntegerEquals(1, IsBracketStringMatch(testData));
}
int TestCase6()
{
    char testData[] = ")([]";
    return AssertIntegerEquals(0, IsBracketStringMatch(testData));
}
int TestCase7()
{
    char testData[] = "(()";
    return AssertIntegerEquals(0, IsBracketStringMatch(testData));
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());
    failCount += OutputTest(caseCount++, TestCase3());
    failCount += OutputTest(caseCount++, TestCase4());
    failCount += OutputTest(caseCount++, TestCase5());
    failCount += OutputTest(caseCount++, TestCase6());
    failCount += OutputTest(caseCount++, TestCase7());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif