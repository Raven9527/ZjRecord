#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int sum=1;
		int count=1;
		while(sum>0)
		{
			sum*=10;
			sum+=1;
			sum=sum%n;
			count++;
		}
		if(n==1)
		printf("1\n");
		else
		printf("%d\n",count);
	}
	return 0;
 } 
