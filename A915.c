#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*\ Sakuya / \ Sakuya / \ Sakuya / \ Sakuya / \ Sakuya / \ Sakuya / */
long long int x[1001];
long long int y[1001];
long long int sort[1001];

int cmp(const void *s1 , const void *s2)
{
	return *(long long int *)s1 - *(long long int *)s2; 
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(sort,0,sizeof(sort));
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%llu %llu",&x[i],&y[i]);
			sort[i]=x[i]*100000 + y[i];
		}
		qsort(sort,n,sizeof(long long int),cmp);
		
		for(i=0;i<n;i++)
		{
			x[i]=sort[i]/100000;
			y[i]=sort[i]%100000;
			printf("%llu %llu\n",x[i],y[i]);
		}
		
	}
	return 0;
}

