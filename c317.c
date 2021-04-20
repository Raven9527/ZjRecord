#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x , a , b;
		scanf("%d %d %d",&x ,&a ,&b);
		int i , j;
		int min = 2147483647;
		for(i = 0 ; i <= x / a + 1 ; i++)
		{
			for(j = 0 ; j <= x / b + 1 ; j++)
			{
				if(i * a + j * b == x)
				{
					if(min > i + j)
					{
						min = i + j;
					}
				}
			}
		}
		if(min == 2147483647)
			printf("-1\n");
		else
			printf("%d\n",min);
	}
	return 0;
}
