#include <stdio.h>
long long int r(int n, int k)
{
	k = k * (n%10);
	if(n/10 == 0)
		return k;
	return r(n/10 , k);
}
int main() 
{
	long long int n;
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",r(n, 1));
	}
	return 0;
}
