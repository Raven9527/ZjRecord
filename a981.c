#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int inp[31] , n;
int cmp(const void *s1 , const void *s2)
{
	return (*(int *)s2 - *(int *)s1);
}
int ddiv(int k , int total , int nowsum) //k ¬°²ÄIndex
{
	if(k >= n)
	{
		return ;
	}
	nowsum += inp[k];
	if(nowsum > total)
	{
		return 0;
	}
	if(nowsum == total)
	{
		printf("%d ",inp[k]);
		return 1;
	}
	if(ddiv(k + 1 , total , nowsum))
	{
		printf("%d ",inp[k]);
		return 1;
	}
}
int main()
{
	int m;
	while(scanf("%d %d",&n , &m)!=EOF)
	{
		memset(inp , 0 , sizeof(inp));
		int i;
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&inp[i]);
		}
		//sort
		qsort(inp , n , sizeof(int) , cmp);
		
		for(i = 0 ; i < n ; i++)
		{
			ddiv(i , m , 0);
		}
	}
	return 0;
}
