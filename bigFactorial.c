#include <stdio.h>
#include <string.h> 
int ans[10000];
int sum[1001];
int main()
{
	int n;
	memset(ans,0,sizeof(ans));
	memset(sum,0,sizeof(sum));
	ans[0]=1;
	int i,j;
	int ak=0;
	for(i=1;i<=1000;i++)
	{
		for(j=0;j<=ak;j++)
		{
			ans[j]=ans[j]*i;
		}
		for(j=0;j<=ak;j++)
		{
			if(ans[ak]>=10)
			{
				ak++;
			}
			if(ans[j]>=10)
			{
				ans[j+1]+=ans[j]/10;
				ans[j]%=10;
			}
		}
		for(j=0;j<=ak;j++)
		{
			sum[i]+=ans[j];
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",sum[n]);
	}
	return 0;
 }
