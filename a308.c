#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ConvertSmall(char inp[])
{
    int k = 0;
    while(inp[k])
    {
        if(inp[k] >= 'A' && inp[k] <= 'Z')
            inp[k] += 32;
        k++;
    }
    return k;
}
int main()
{
    char inp1[11], inp2[1000001];
    memset(inp1, '\0', sizeof(inp1));
    memset(inp2, '\0', sizeof(inp2));
    gets(inp1);
    gets(inp2);
    puts(inp1);
    //printf("%s.%s", inp1, inp2);
    int s1 = ConvertSmall(inp1);
    int s2 = ConvertSmall(inp2);
    inp2[s2++] = ' ';
    int k = 0;
    int Index1 = 0;
    int Index2 = 0;
    int first = 0;
    int sum = 0;
    //printf("s1 = %d  , s2 = %d\n", s1, s2);
    while(inp2[k])
    {
        if(inp2[k] == ' ')
        {
            if(Index1 == s1 && Index2 == s1) //get
            {
                if(first == 0)
                    first = k;
                sum++;
            }
            //printf("Stext = %d\n", Index2);
            Index1 = 0;
            Index2 = 0;
        }
        else
            Index2++;
        if(inp2[k] == inp1[Index1])
        {
            Index1++;
        }
        else
        {
            Index1 = 0;
        }
        k++;
    }
    if(first)
        printf("%d %d\n", sum, first - s1);
    else
        printf("-1\n");
    //system("pause");
    return 0;
}