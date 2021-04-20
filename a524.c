#include <stdio.h>
#include <string.h>
int a[10];
int b[10];
int f[10];
int dfs(int n, int k)
{
	int i;
	if(n==k)
	{
		for(i=0;i<k;i++)
		{
			printf("%d",b[i]);
		}
		printf("\n");
		return ;
	}
	for(i=0;i<k;i++)
	{
		if(f[i]==1)
		continue;
		b[n]=a[i];
		f[i]=1;
		dfs(n+1,k);
		f[i]=0;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		int i;
		for(i=0;i<n;i++)
		{
			a[i]=n-i;
		}
		dfs(0,n);
	}
	return 0;
}
