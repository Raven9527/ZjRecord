#include <stdio.h>
#include <string.h>
#include <math.h>
char inp[500];
char code[20]="0123456789ABCDEF";
int ans[500];
int sum=0;
int DtoH()
{
	int i,s=strlen(inp);
	int ak=0;
	memset(ans,0,sizeof(ans));
	for(i=0;i<s;i++)
	{
		sum*=10;
		sum += (inp[i]-48);
	}
	//printf("sum=%d\n",sum);
	while(sum>0)
	{
		ans[ak]=sum%16;
		sum/=16;
		ak++;
	}
	printf("0x");
	for(i=ak-1;i>=0;i--)
	{
		printf("%c",code[ans[i]]);
	}
	printf("\n");
}
int HtoD()
{
	int i,s=strlen(inp);
	int m;
	for(i=s-1,m=0;i>=2;i--,m++)
	{
		int num = inp[i];
		if(num>=65&&num<=70)
		{
			num-=55;
		}
		else
		{
			num-=48;
		}
		sum += num * pow(16,m);
	}
	printf("%d\n",sum);
}
int main()
{
	while(scanf("%s",inp)!=EOF)
	{
		sum=0;
		if(inp[0]=='-')
		{
			break;
		}
		else if(inp[0]=='0' && inp[1]=='x')
		{
			HtoD();
		}
		else
		{
			DtoH();
		}
	}
	return 0;
}
