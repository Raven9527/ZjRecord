#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Input(char inp[])
{
    scanf("%s", inp);
}
int DeterminePalindrome(char inp[])
{
    int size = strlen(inp), i;
    if (size % 2 != 0)
        return 0;
    
    for (i = 0; i < size / 2; i++)
    {
        if (inp[i] != inp[size - i - 1])
            return 0;
    }
    return 1;
}
void PrintAns(int flag, char inp[])
{
    if (flag == 0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        int size = strlen(inp), i;
        for (i = 0; i < size / 2; i++)
        {
            printf("%c", inp[i]);
        }
    }
}
int main()
{
    char inp[1024];
    Input(inp);
    int isPalindrome = DeterminePalindrome(inp);
    PrintAns(isPalindrome, inp);
    //system("pause");
    return 0;
}