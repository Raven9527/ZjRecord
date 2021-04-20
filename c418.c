#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i , j , k;
	for(i = 1 ; i <= n ; i++)
	{
		for(k = n - i - 1 ; k >= 0 ; k--)
		{
			printf("_");
		}
		for(j = 1 ; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		for(k = n - i - 1 ; k >= 0 ; k--)
		{
			printf("_");
		}
		printf("\n");
	}
	return 0;
}
