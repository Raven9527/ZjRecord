#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InputTestData(char test[])
{
    scanf("%s", test);
}
int IsDataCorrect(char test[], char ans, int A_index, int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        if (test[i] == ans)
        {
            if (A_index == i)
                return 2;
            else
                return 1;
        }
    }
    return 0;
}
void ProcessCompare(char ans[], char test[], int s, int *A, int *B)
{
    int a = 0, b = 0, i;
    for (i = 0; i < s; i++)
    {
        int compare = IsDataCorrect(test, ans[i], i, s);
        if (compare == 2)
            a++;
        else if (compare == 1)
            b++;
    }
    *A = a;
    *B = b;
}
void PrintGuess(int a, int b)
{
    printf("%dA%dB\n", a, b);
}
int main()
{
    char inp[15];
    int n;
    scanf("%s %d", inp, &n);
    while(n--)
    {
        char test[15];
        int a = 0, b = 0, s = strlen(inp);
        InputTestData(test);
        ProcessCompare(inp, test, s, &a, &b);
        PrintGuess(a, b);
    }
    return 0;
}