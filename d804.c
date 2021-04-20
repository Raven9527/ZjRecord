#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *s1 , const void *s2)
{
	return *(int *)s2 - *(int *)s1;
}
int inp[100010];
int main()
{
	int n,sum;
	while(scanf("%d %d",&n,&sum)!=EOF)
	{
		int i;
		memset(inp,0,sizeof(inp));
		for(i=0;i<n;i++)
		{
			scanf("%d",&inp[i]);
		}
		qsort(inp,n,sizeof(int),cmp);
		i=0;
		int total=0;
		while(total<sum)
		{
			total+=inp[i];
			i++;
		}
		if(total<sum)
			printf("OAQ\n");
		else
			printf("%d\n",i);
	}
	return 0;
} 
