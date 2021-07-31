#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 14

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Gate_s
{
    int value;
    void (*OPT)(struct Gate_s*, int);
}Gate;

void MainProgram();
void InitializeGateArray(Gate[], int, int, void(Gate*, int));
void InputTestData(int[], int); // 輸入測試資料
void RunGateGroupOperation(Gate[], int[], int); // 執行 gate群 操作 (gate, test data, length)
void ANDOperation(Gate*, int); // AND 操作
void OROperation(Gate*, int); // OR 操作
void XOROperation(Gate*, int); // XOR 操作
void PrintGateAnswer(char[], Gate[], int);

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
    Gate andGate[SIZE];
    Gate orGate[SIZE];
    Gate xorGate[SIZE];
    int i, j, n, m;
    int testData[SIZE];
    scanf("%d %d", &n, &m);
    InitializeGateArray(andGate, m, 1, &ANDOperation);
    InitializeGateArray(orGate, m, 0, &OROperation);
    InitializeGateArray(xorGate, m, 0, &XOROperation);
    while(n--)
    {
        InputTestData(testData, m);
        RunGateGroupOperation(andGate, testData, m);
        RunGateGroupOperation(orGate, testData, m);
        RunGateGroupOperation(xorGate, testData, m);
    }
    PrintGateAnswer("AND", andGate, m);
    PrintGateAnswer(" OR", orGate, m);
    PrintGateAnswer("XOR", xorGate, m);
}

void InitializeGateArray(Gate gate[], int n, int value, void opt(Gate*, int))
{
    int i;
    for (i = 0; i < n; i++)
    {
        gate[i].value = value;
        gate[i].OPT = opt;
    }
}

void InputTestData(int data[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
}

// gate對data做operation
void RunGateGroupOperation(Gate gate[], int data[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        gate[i].OPT(&gate[i], data[i]);
    }
}

void ANDOperation(Gate *gate, int v)
{
    gate->value = (gate->value) & v;
}

void OROperation(Gate *gate, int v)
{
    gate->value = (gate->value) | v;
}

void XOROperation(Gate *gate, int v)
{
    gate->value = (gate->value) ^ v;
}

void PrintGateAnswer(char preix[], Gate gate[], int n)
{
    int i;
    printf("%s: ", preix);
    for (i = 0; i < n; i++)
        printf("%d ", gate[i].value);
    printf("\n");
}

#if TEST_FLAG
// 比對 二維 int array相等
int AssertInteger2DArrayEquals(int except[SIZE][SIZE], int active[SIZE][SIZE], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (except[i][j] != active[i][j])
                return 0;
        }
    }
    return 1;
}
int TestCase1()
{
    Gate andGate[SIZE];
    Gate orGate[SIZE];
    Gate xorGate[SIZE];
    int data[SIZE][SIZE] = { {0, 1, 0, 1, 0}, {1, 0, 1, 1, 0} };
    int answer[SIZE][SIZE];
    int except[SIZE][SIZE] = { {0, 0, 0, 1, 0}, {1, 1, 1, 1, 0}, {1, 1, 1, 0, 0} };
    int i, j, n = 2, m = 5;
    InitializeGateArray(andGate, m, 1, &ANDOperation);
    InitializeGateArray(orGate, m, 0, &OROperation);
    InitializeGateArray(xorGate, m, 0, &XOROperation);
    for (i = 0; i < n; i++)
    {
        RunGateGroupOperation(andGate, data[i], m);
        RunGateGroupOperation(orGate, data[i], m);
        RunGateGroupOperation(xorGate, data[i], m);
    }

    for (j = 0; j < m; j++)
    {
        answer[0][j] = andGate[j].value;
        answer[1][j] = orGate[j].value;
        answer[2][j] = xorGate[j].value;
    }

    // PrintGateAnswer("AND", andGate, m);
    // PrintGateAnswer("OR ", orGate, m);
    // PrintGateAnswer("XOR", xorGate, m);

    return AssertInteger2DArrayEquals(except, answer, 3, 5);
}
int TestCase2()
{
    Gate andGate[SIZE];
    Gate orGate[SIZE];
    Gate xorGate[SIZE];
    int data[SIZE][SIZE] = { {0, 1, 0, 0, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0} };
    int answer[SIZE][SIZE];
    int except[SIZE][SIZE] = { {0, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 1, 1, 0} };
    int i, j, n = 4, m = 7;
    InitializeGateArray(andGate, m, 1, &ANDOperation);
    InitializeGateArray(orGate, m, 0, &OROperation);
    InitializeGateArray(xorGate, m, 0, &XOROperation);
    for (i = 0; i < n; i++)
    {
        RunGateGroupOperation(andGate, data[i], m);
        RunGateGroupOperation(orGate, data[i], m);
        RunGateGroupOperation(xorGate, data[i], m);
    }

    for (j = 0; j < m; j++)
    {
        answer[0][j] = andGate[j].value;
        answer[1][j] = orGate[j].value;
        answer[2][j] = xorGate[j].value;
    }

    return AssertInteger2DArrayEquals(except, answer, 3, m);
}
// Test Region 
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif