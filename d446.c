#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int ans[500001];
int cmp(const void *s1 , const void *s2)
{
	return *(int*)s1 -*(int*)s2;
}
int main()
{
	int n=2147483647;
	//while(scanf("%d",&n)!=EOF)
	//{
		int i,ansk=0;
		memset(ans,0,sizeof(ans));
		for(i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				if(n/i==i)
				{
					ans[ansk++]=i;
				}
				else
				{
					ans[ansk++]=i;
					ans[ansk++]=n/i;
				}
			}
		}
		//qsort(ans,ansk,sizeof(int),cmp);
		for(i=0;i<ansk;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
		printf("%d",clock());
//	}
	return 0;
 } 
