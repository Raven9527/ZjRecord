#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		unsigned long long int factorialN = 1;
		unsigned long long int i;
		for(i = 1 ; i <= n ; i++)
		{
			factorialN *= i;
			while(factorialN % 10 == 0)
				factorialN /= 10;
			factorialN %= 100000;
			//printf("%lld , %lld\n",i , factorialN);
		}
		printf("%5lld -> %lld\n", n , factorialN % 10);
	}
	return 0;
}
