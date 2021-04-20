#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10005
void InputMessage(int messageList[], int size, int *baseNumber)
{
    int i;
    int number;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &number);
        messageList[i] = number;
        //printf("message: %d \n", messageList[i]);
    }
    (*baseNumber) = number;
}

// 搜尋Index 以及 回傳隨機數字總額
int FindIndexAndGetSum(int messageList[], int size, int baseNumber)
{
    int i;
    int sum = 0;
    //printf("baseNumber: %d\n", baseNumber);
    for (i = 0; i < size; i++)
    {
        if (((i + 1) % baseNumber) == 1)
        {
            sum += messageList[i];
            //printf("index: %d\n", i);
        }
    }
    return sum;
}

// 得到最後中獎得Index
int GetFinalIndex(int size, int sumNumber)
{
    return sumNumber % size;
}

void PrintAns(int messageList[], int size, int index)
{
    index = index - 1;
    if (index == -1)
    {
        printf("%d %d\n", size - 1 + 1, messageList[size - 1]);
    }
    else
    {
        printf("%d %d\n", index + 1, messageList[index]);
    }
}

int main()
{
    int messageList[SIZE];
    int n;
    int baseNumber;
    scanf("%d", &n);
    InputMessage(messageList, n, &baseNumber);
    int sum = FindIndexAndGetSum(messageList, n, baseNumber);
    int finalIndex = GetFinalIndex(n, sum);
    PrintAns(messageList, n, finalIndex);
    //system("pause");
    return 0;
}