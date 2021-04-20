#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char inp[1000005];
int main()
{
    scanf("%s", inp);
    int s = strlen(inp) - 1;
    int k = inp[s] - 48;
    if (s % 2 && k != 0)
        printf("-%d\n", k);
    else
        printf("%d\n", k);
    return 0;
}