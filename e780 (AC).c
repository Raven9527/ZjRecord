#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void InputCommand(char inp[])
{
    scanf("%s", inp);
}

void ProcessCommand(char inp[], int *x, int *count)
{
    if (inp[0] == 'L')
    {
        (*x)--;
    }
    else if (inp[0] == 'R')
    {
        (*x)++;
    }
    else if (inp[0] == 'G')
    {
        int tr;
        scanf("%d", &tr);
        if (tr == (*x))
        {
            (*count)++;
        }
    }
}

int main()
{
    char inp[10];
    int T;
    int xPosition = 0;
    int count = 0;
    scanf("%d", &T);
    while(T--)
    {
        InputCommand(inp);
        ProcessCommand(inp, &xPosition, &count);
    }
    printf("%d\n", count);
    //system("pause");
    return 0;
}