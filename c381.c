#include <stdio.h>
char ans[60000002];
int main()
{
	int n,m;
	char inp[102];
	while(scanf("%d %d",&n , &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		int i;
		int ak = 0;
		for(i = 0 ; i < n ; i++)
		{
			scanf("%s",inp);
			int k = 0;
			while(inp[k] != '\0')
			{
				ans[ak++] = inp[k++];
			}
		}
		int k;
		//printf("%s",ans);
		for(i = 0 ; i < m ; i++)
		{
			scanf("%d",&k);
			printf("%c",ans[k - 1]);
		}
		printf("\n");
		memset(ans , '\0' , sizeof(ans));
	}
	return 0;
}
