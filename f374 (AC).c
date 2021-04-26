#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ProcessGroup(int n, char inp[], int group[], int *groupNumber)
{
    int s = strlen(inp), i, k = 0;
    for (i = s - 1, k = 0; i >= 0; i--, k++)
    {
        group[k / n] += (inp[i] - 48);
    }

    if (s % n == 0)
    {
        *groupNumber = (s / n);
    }
    else
    {
        *groupNumber = (s / n) + 1;
    }
}
void PrintAns(int group[], int groupNumber)
{
    int i, max = -1;
    int groupIndex = 0;
    for (i = 0; i < groupNumber; i++)
    {
        if (group[i] >= max)
        {
            groupIndex = i + 1;
            max = group[i];
        }
    }
    printf("%d %d\n", groupIndex, max);
}
int main()
{
    int n;
    char inp[15];
    int group[15];
    int groupNumber = 0;
    memset(group, 0, sizeof(group));
    scanf("%d %s", &n, inp);
    ProcessGroup(n, inp, group, &groupNumber);
    PrintAns(group, groupNumber);
    //system("pause");
    return 0;
}