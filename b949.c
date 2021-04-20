#include <stdio.h>
#include <string.h>
#define MAX 21
int main()
{
	unsigned long long int n;
	while(scanf("%llu",&n)!=EOF)
	{
		if(n <= 858993459)
		{
			n *= 5;
			printf("%llu\n",n*n);
			continue;
		}
		n *= 5;
		int a[MAX] = {0} , ans[MAX] = {0};
		//memset(a , 0 , sizeof(a));
		//memset(ans , 0 , sizeof(ans));
		int ak = 0;
		while(n > 0)
		{
			a[ak++] = n % 10;
			n /= 10;
		}
		int i , j;
		for(i = 0 ; i < MAX ; i++)
		{
			for(j = 0 ; j < MAX ; j++)
			{
				ans[i + j] += a[i] * a[j];
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
		int flag = 0;
		for(i = MAX ; i >= 0 ; i--)
		{
			if(ans[i])
				flag = 1;
			if(flag)
				printf("%d",ans[i]); 
		}
		printf("\n");
	}
	return 0;
}
