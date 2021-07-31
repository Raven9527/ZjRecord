// rewrite by zj e797
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 1

typedef struct Gate_s
{
    int value;
    void (*AND)(struct Gate_s*, int);
    void (*OR)(struct Gate_s*, int);
    void (*XOR)(struct Gate_s*, int);
}Gate;

void MainProgram();
void ANDOperation(Gate*, int); // AND 操作
void OROperation(Gate*, int); // OR 操作
void XOROperation(Gate*, int); // XOR 操作

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
    Gate gate = {1, &ANDOperation, &OROperation, &XOROperation};
    gate.AND(&gate, 1);
    printf("%d\n", gate.value);
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
    gate->value = !(gate->value);
}