#include <stdio.h>
#include <stdlib.h>
int main()
{
	int s1,s2,T,k;
	while(scanf("%d %d %d %d",&s1,&s2,&T,&k)!=EOF)
	{
		int flag = 0;
		int i;
		int head = 0 , tail = k;
		while(head <= tail)
		{
			int easy = (head + tail) / 2;
			int totalSorce = s1 * easy + (s2 * (k - easy));
			if(totalSorce == T)
			{
				if(!(easy == 0 || k - easy == 0))
				{
					flag = 1;
					printf("%d %d\n",easy , k - easy);
				}
				break;
			}
			else if(totalSorce > T)
			{
				head = easy + 1;
			}
			else if(totalSorce < T)
			{
				tail = easy - 1;
			}
			/*printf("head = %d , tail = %d\n",head , tail);
			system("pause");*/
		}
		if(!flag)
			printf("impossible\n");
	}
	return 0;
}
