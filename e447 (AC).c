#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100005
int IsEmpty(int top, int tail)
{
    if (top == tail)
        return 1;
    return 0;
}
void Push(int queue[], int *top, int *tail, int number)
{
    queue[(*tail)] = number;
    (*tail)++;
}
void Pop(int queue[], int *top, int *tail)
{
    if (!IsEmpty(*top, *tail))
    {
        (*top)++;
    }
}
void PrintElement(int queue[], int *top, int *tail)
{
    if (IsEmpty(*top, *tail))
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",queue[*top]);
    }
}
void ProcessCommand(int command, int queue[], int *top, int *tail)
{
    if (command == 1)
    {
        int k;
        scanf("%d", &k);
        Push(queue, top, tail, k);
    }
    else if (command == 2)
    {
        PrintElement(queue, top, tail);
    }
    else if (command == 3)
    {
        Pop(queue, top, tail);
    }
}
void InputCommand(int *command)
{
    scanf("%d", command);
}
int main()
{
    int queue[SIZE];
    int top = 0, tail = 0;
    memset(queue, 0, sizeof(queue));
    int T;
    int command;
    scanf("%d", &T);
    while(T--)
    {
        InputCommand(&command);
        ProcessCommand(command, queue, &top, &tail);
    }
    //system("pause");
    return 0;
}