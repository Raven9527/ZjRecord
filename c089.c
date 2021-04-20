#include <stdio.h>
#include <string.h> 
#include <math.h>
char inp[100];
int ThisNumIn;
int ToNumOut;
int Output[100];
char code[16]={"0123456789ABCDEF"};
int main()
{
	while(scanf("%s %d %d",inp,&ThisNumIn,&ToNumOut)!=EOF)
	{
		memset(Output,0,sizeof(Output));
		int i,InpLen=strlen(inp),m;
		int sum=0;
		for(i=InpLen-1,m=0;i>=0;i--,m++)
		{
			int SubNum=inp[i];
			if(SubNum==32)
			{
				SubNum=0;
			} 
			else if(SubNum>=65&&SubNum<=70)
			{
				SubNum-=55;
			}
			else
			{
				SubNum-=48;
			}
			sum += SubNum * pow(ThisNumIn,m);
			//printf("s=%d\n",SubNum);
		}
		//printf("%d\n",sum);
		m=0;
		while(sum>0)
		{
			Output[m]=sum%ToNumOut;
			sum/=ToNumOut;
			//printf("%d\n",Output[m]); 
			m++;
		}
		if(m>7)
		{
			printf("  ERROR");	
		} 
		else
		{
			for(i=0;i<7-m;i++)
			{
				printf(" ");
			}
			for(i=m-1;i>=0;i--)
			{
				printf("%c",code[Output[i]]);
			}
		 } 
		printf("\n");
	}
	return 0;
} 
