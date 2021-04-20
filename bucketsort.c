#include <stdio.h>
int main()
{
	int bucket[10]={0};
	int i;
	int n=5;
	int max=0;
	for(i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		bucket[k]++;
		if(k>=max)
			max = k;
	}
	for(i=0;i<=max;i++)
	{
		while(bucket[i]>0)
		{
			printf("%d ",i);
			bucket[i]--;
		}
	}
	printf("\n");
	return 0;
 } 
