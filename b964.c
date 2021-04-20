#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a1 , const void *a2)
{
	return *(int*)a1 - *(int*)a2;
}
int main()
{
	int n;
	int s[100];
	int stage = 0;
	while(scanf("%d",&n)!=EOF)
	{
		if(stage)
			printf("\n");
		memset(s , 0 , sizeof(s));
		int min = 2147483647 , max = -2147483647;
		int i;
		int sum = 0;
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&s[i]);
			sum += s[i];
			if(s[i] < 60 && s[i] > max)
				max = s[i];
			if(s[i] >= 60 && s[i] < min)
				min = s[i];
		}
		qsort(s , n , sizeof(int) , cmp);
		for(i = 0 ; i < n ; i++)
		{
			printf("%d",s[i]);
			if(i != n - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
		if(max == -2147483647)
			printf("best case\n");
		else
			printf("%d\n",max);
		if(min == 2147483647)
			printf("worst case");
		else
			printf("%d",min);
		stage++;
	}
	return 0;
 } 
