#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 22
int main()
{
    char a[MAX] , inp[MAX];
    memset(inp, '\0', sizeof(inp));
    while (gets(inp) != NULL)
    {
        memset(a, '\0', sizeof(a));
        int a_len = 0 , inp_len = 0;
        int i = 0, j;
        unsigned long long n = 0;
        
        while(inp[inp_len])
        {
            n *= 10;
            n += inp[inp_len] - 48;
            inp_len++;
        }

        if(n <= 85993459)
        {
            printf("%llu\n", n * n * 25);
            continue;
        }

        int ans[MAX];
        char str[MAX];
        memset(str, '\0', sizeof(str));
        memset(ans, 0, sizeof(ans));

        
        // str re
        while(a_len < inp_len)
        {
            a[a_len] = inp[inp_len - a_len - 1];
            a_len++;
        }
        // end

        for(i = a_len - 1; i >= 0 ; i--)
		{
			for(j = a_len - 1 ; j >= 0 ; j--)
			{
                int n1 = a[i] ? a[i] - 48 : 0;
                int n2 = a[j] ? a[j] - 48 : 0;
                ans[i + j] += n1 * n2 * 25;
            }
		}
        for(i = 0 ; i < MAX ; i++)
		{
			if(ans[i] >= 10)
			{
				ans[i + 1] += ans[i] / 10;
				ans[i] %= 10;
            }
		}
        int k = 0;
        for (i = MAX - 1; i >= 0; i--)
        {
            if(ans[i])
                break;
        }
        for (j = i; j >= 0; j--)
            str[k++] = ans[j] + 48;
        printf("%s\n", str);
        memset(inp, '\0', sizeof(inp));
    }
    return 0;
}