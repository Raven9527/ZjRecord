#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char c , lastc = '.';
    int sum = 0;
    while (scanf("%c", &c) != EOF)
    {
        int k = 0;
        if(c == ' ' || c == '.' || c == '!' || c == '?' || c == ',' || c == '\n')
        {
            if((lastc >= 'A' && lastc <= 'Z') || (lastc >= 'a' && lastc <= 'z') || (lastc >= '0' && lastc <= '9'))
            {
                sum++;
            }
        }
        lastc = c;
    }
    printf("%d\n", sum);
    //system("pause");
    return 0;
}
