#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char inp[10000001];
int num_array[100005];
char opr[100005];
int main()
{
    scanf("%s", inp);
    int len = strlen(inp);
    inp[len++] = '+';
    int k = 0, num = 0, kindex = 0, index = 0;
    for (k = 0; inp[k]; k++)
    {
        if (inp[k] >= '0' && inp[k] <= '9')
        {
            num *= 10;
            num += inp[k] - 48;
        }
        else
        {
            num_array[index++] = num;
            opr[kindex++] = inp[k];
            num = 0;
        }
    }

    for (k = 0; k < kindex - 1; k++)
    {
        if(opr[k] == '*')
        {
            num_array[k + 1] = num_array[k] * num_array[k + 1];
            num_array[k + 1] %= 10000;
            num_array[k] = 0;
        }
    }
    int sum = 0;
    for (k = 0; k < index; k++)
    {
        sum += num_array[k];
        sum %= 10000;
    }
    printf("%d\n", sum);
    //system("pause");
    return 0;
}