#include <stdio.h>
#include <string.h>
int main()
{
	int state;
	int i , j , n;
	int x[1001];
	for(i = 2 ; i <= 1000 ; i++)
	{
		int sum = 0;
		for(j = 1 ; j < i ; j++)
		{
			if(i % j == 0)
			{
				sum += j;
			}
		}
		if(sum == i)
		{
			x[i] = 1;
		}
		else if(sum > i)
		{
			x[i] = 2;
		}
		else if(sum < i)
		{
			x[i] = 3;
		}
	}
	scanf("%d",&state);
	while(state--)
	{
		scanf("%d",&n);
		if(x[n] == 1)
			printf("perfect\n");
		else if(x[n] == 2)
			printf("abundant\n");
		else if(x[n] == 3)
			printf("deficient\n");
	}
	return 0;
 } 
