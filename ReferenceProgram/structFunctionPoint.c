// zj e797
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 1
#define PAUSE_FLAG 1
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
void RunGateOperation(Gate*, int); // 執行gate 操作
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
    Gate andGate[SIZE] = {{1, &ANDOperation}};
    Gate orGate[SIZE] = {{0, &OROperation}};
    Gate xorGate[SIZE] = {{0, &XOROperation}};

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
        scanf("%d", &data[n]);
    }
}

void RunGateOperation(Gate *gate, int v)
{
    gate->OPT(gate, v);
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
        for (j = 0; j < m; j++)
        {
            RunGateOperation(&andGate[j], data[i][j]);
            RunGateOperation(&orGate[j], data[i][j]);
            RunGateOperation(&xorGate[j], data[i][j]);
        }
    }

    for (j = 0; j < m; j++)
    {
        answer[0][j] = andGate[i].value;
        answer[1][j] = orGate[i].value;
        answer[2][j] = xorGate[i].value;
    }

    PrintGateAnswer("AND", andGate, m);
    PrintGateAnswer("OR ", orGate, m);
    PrintGateAnswer("XOR", xorGate, m);

    return AssertInteger2DArrayEquals(except, answer, 3, 5);
}
int TestCase2()
{
    Gate andGate[SIZE] = {{1, &ANDOperation}};
    Gate orGate[SIZE] = {{0, &OROperation}};
    Gate xorGate[SIZE] = {{0, &XOROperation}};
    int data[SIZE][SIZE] = { {0, 1, 0, 0, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0} };
    int answer[SIZE][SIZE];
    int except[SIZE][SIZE] = { {0, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 1, 1, 0} };

    int i, j, n = 4, m = 7;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            RunGateOperation(&andGate[j], data[i][j]);
            RunGateOperation(&orGate[j], data[i][j]);
            RunGateOperation(&xorGate[j], data[i][j]);
        }
    }

    for (j = 0; j < m; j++)
    {
        answer[0][j] = andGate[i].value;
        answer[1][j] = orGate[i].value;
        answer[2][j] = xorGate[i].value;
    }

    return AssertInteger2DArrayEquals(except, answer, n, m);
}
// Test Region 
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());
    //failCount += OutputTest(caseCount++, TestCase2());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif