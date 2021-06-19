#include <stdio.h>
#define MAX 999
int main()
{
	int a[MAX],n;
	while(scanf("%d",&n)!=EOF)
	{
		int i , j , k;
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
		}
		for(i = 0 ; i < n - 1 ; i++) //程Ωユ传ゲ逞ㄢじ传ユ传场传Ч
		{
			for(j = 0 ; j < n - 1 - i; j++) //–Ω常р程じ传程竚珿程じぃ惠ゑ耕
			{
				if(a[j] > a[j + 1])
				{
					k = a[j];
					a[j] = a[j + 1];
					a[j + 1] = k;
				}
			}
		}
		for(i = 0 ; i < n ; i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
 } 
