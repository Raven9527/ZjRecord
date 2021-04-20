#include <stdio.h>
#include <string.h>
int map[802][802];

void dfs(int k ,int n)
{
	int i,j;
	for(i=k;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(map[i][j]==1)
			{
				dfs(j,n);
			}
		}
		return;
	}
}
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int i;
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			map[a][b] = 1;
		}
		dfs(1,n);
	}
	return 0;
} 
