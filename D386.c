#include <stdio.h>
#define MAX 10001
/*���D����:���إ߽�ƪ�A�A�θհ��k�إߥX�@�i0~10000���ŦXn*n+n+41�O��ƪ���*/
/*�̫��X�����p���I�~�t + 1e-7 (�[�W�@�ӶW�p�ȼƦr�A�ϥL�i�H�쥿�T���� ex123.4999999+0.00000001>>123.5)*/ 
int prime[MAX],pr[MAX];
int count[MAX]={0};
int main()
{
	int i;
	for(i=3;i<=MAX;i+=2)
	{
		pr[i]=i;
	}
	for(i=3;i*i<=MAX;i+=2)
	{
		if(pr[i]==0)
		continue;
		
		int k=2;
		while(i*k<=MAX)
		{
			pr[i*k]=0;
			k++;
		}
	}
	int k=1;
	prime[0]=2;
	for(i=3;i<=MAX;i+=2)
	{
		if(pr[i]!=0)
		{
			prime[k++]=pr[i];
		}
	}
	/*for(i=0;i<k;i++)
	{
		printf("%d ",prime[i]);
	}*/
	int a,b;
	for(i=0;i<=10000;i++)
		{
			int num=i*i+i+41,f=1;
			int j;
			//printf("%d\n",num);
			for(j=0;j<k&&prime[j]*prime[j]<=num;j++)
			{
				if(num%prime[j]==0)
				{
					f=0;
					//printf("%d\n",i);
					break;
				}
			}
			if(f==1)
			{
				count[i]=1;
			}
		}
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		int sumPr=0;
		for(i=a;i<=b;i++)
		{
			sumPr+=count[i];
		}
		double ans = (double)sumPr/(b-a+1)*100;
		printf("%.2lf\n",ans+1e-7);
	}
	return 0;
}
