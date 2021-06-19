#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#define max 46341
int p[max],prime[max];
int t;
int Era();
int process();
int process2();
int main()
{
    int n = 10000000; // repeat do_somenting() n times
	int i;
	int t1 = clock();
	process2();
	int t2 = clock();
	printf("do_something() %d times took %lf seconds\n(measurement granularity: %d of a second)\n" , n , (double)(t2-t1)/CLOCKS_PER_SEC , CLOCKS_PER_SEC);
    //printf("%d\n",sum);
    system("pause");
    return 0;
}
int Era()
{
	int i,k,j,n;
	for(i=3;i<=max;i=i+2)
	{
		p[i]=i;
	}
	for(i=3;i*i<=max;i=i+2)
	{
		if(p[i]==0)
		{
			continue;
		}
		k=i;
		while(k<=max)
		{
			k=k+2;
			if(k%i==0)
			{
				p[k]=0;
			}
		}
	}
	prime[0]=2;
	t = 0;
	for(k=3,t=1;k<=max;k=k+2)
	{
		if(p[k]!=0)
		prime[t++]=p[k];
	}
}
int process()
{
	Era();
	int k,n,j,f;
	n = 2147483647;
	for(k=0,f=1;k<t&&prime[k]*prime[k]<=n;k++)
	{
		if(n%prime[k]==0)
		{
			f=0;
			break;
		}
	}
	if(f==1)
	printf("借计\n");
	else
	printf("獶借计\n");
}
int process2()
{
	int i,x,sum=0;
	x = 2147483647;
	for(i=2;i<x;i++)
	{
		if (x%i==0)
		sum=sum+i;
	}
    if (sum==0)
    printf("借计\n");
    else printf("獶借计\n");
	 
	sum=0;
}
