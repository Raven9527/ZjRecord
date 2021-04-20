#include <stdio.h>
#include <string.h>
int lastvectorpos[100001];
int lastvectorans[100001];
int main()
{
	int n1 = 1,n2 = 1;
	int vectornum = 0;
	while(1)
	{
		scanf("%d:%d",&n1 ,&n2);
		if(n1 == 0 && n2 == 0)
			break;
		
		lastvectorpos[vectornum] = n1;
		lastvectorans[vectornum] = n2;
		vectornum++;
	}
	n1 = n2 = 1;
	int i , sum = 0;
	while(1)
	{
		scanf("%d:%d",&n1 ,&n2);
		if(n1 == 0 && n2 == 0)
			break;
		for(i = 0 ; i < vectornum ; i++)
		{
			if(n1 == lastvectorpos[i])
			{
				sum += lastvectorans[i] * n2;
				break;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}
