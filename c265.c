#include <stdio.h>
#include <string.h>
int main()
{
	int n , q;
	int x[100001];
	while(scanf("%d %d",&n , &q) != EOF)
	{
		int i;
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&x[i]);
		} 
		while(q--)
		{
			scanf("%d",&n);
			if(n == 2)
			{
				int a , b , c;
				scanf("%d %d %d",&a,&b,&c);
				int sum = 0;
				for(i = a - 1 ; i <= b - 1 ; i++)
				{
					sum += x[i];
				}
				if(sum % c == 0)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else if(n == 1)
			{
				int Index , num;
				scanf("%d %d",&Index , &num);
				x[Index - 1] = num;
			}
		}
	}
	return 0;
}
