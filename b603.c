#include <stdio.h>
#include <string.h>
int gcd(int a,int b)
{
	if(a%b==0)
	return b;
	else
	return gcd(b,a%b);
}
int main()
{
	long long int x1,x2,y1,y2;
	while(scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2)!=EOF)
	{
		long long int a,b;
		a=y2-y1;//¤À¤l
		b=(x2-x1)*(x2-x1);//¤À¥À
		//printf("%lld %lld\n",a*x1*x1,b*y2);
		long long int k = gcd(a,b);
		a=a/k;
		b=b/k;
		printf("%lldy = %lldx^2 + %lldx + %lld\n",b,a,a*-x1*2,a*x1*x1+b*y1);
	}
	return 0;
 } 
