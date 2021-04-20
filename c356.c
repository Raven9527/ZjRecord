#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    int k = 0, Index = 0;
    char ch;
    while(1)
    {
        if(k >= n*n)
        	break;
        ch = getchar();
        if(k == Index)
        {
        	putchar(ch);
        	Index += n + 1;
		}
        k+=n;
        k++;
    }
    return 0;
}
