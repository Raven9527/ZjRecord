#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char inp1[105], inp2[105];
    char translation[105];
    char temp[2][27] = {{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}, {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}};
    int ps[26] = {0};
    scanf("%s %s %s", inp1, inp2, translation);
    int k = 0, flag = 1;
    
    for (k = 0; inp1[k]; k++)
    {
        if(ps[inp1[k] - 65] == 0)
            ps[inp1[k] - 65] = inp2[k];
        else if(ps[inp1[k] - 65] != inp2[k])
            flag = 0;
        
        temp[0][inp1[k] - 65] = '.';
        temp[1][inp2[k] - 65] = '.';
    }

    for (k = 0; k < 26; k++)
    {
        if(temp[0][k] != '.' || temp[1][k] != '.')
            flag = 0;
    }
    //printf("flag = %d\n", flag);
    if(flag)
    {
        int len = strlen(translation);
        for (k = 0; k < len; k++)
        {
            printf("%c", ps[translation[k] - 65]);
        }
        printf("\n");
    }
    else
    {
        printf("Failed\n");
    }
    //system("pause");
    return 0;
}