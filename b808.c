#include <stdio.h>
#define MAX 20000000
short int prime[MAX];
int main()
{
	int i;
	for(i = 3 ; i < MAX ; i+=2)
	{
		prime[i] = 1;
	}
	
	for(i = 3 ;i < MAX ; i+=2)
	{
		if(prime[i] == 0)
		continue;
		int k = 2 ;
		while(i * k < MAX)
		{
			prime[i * k] = 0;
			k++;
		}
	}
	//prime[1] = 1;
	prime[2] = 1;
	
	long long int c;
	while(scanf("%lld",&c)!=EOF)
	{
		if(c == 0)
			break;
		/*if(c == 1)
		{
			print("1 1\n");
			continue;
		}*/
		int ans = 1;
		printf("%lld ",c);
		c = c*4 - 3;
		long long int maxc = MAX > c ? c : MAX;
		for(i = 3 ; i <= maxc ; i+=2)
		{
			int tmp = 0;
			if(prime[i] == 0)
				continue;
			while(c % i == 0)
			{
				c /= i;
				tmp++;
			}
			if(tmp > 0){
				tmp++;
				ans = ans * tmp;
			}
		}
		if(c > 1)
			ans *= 2;
		printf("%d\n",ans);
	}
	return 0;
}
