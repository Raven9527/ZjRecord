#include <stdio.h>
#include <string.h>
/*先比較二字串大小，再進行相減*/ 
char inp1[10001],inp2[10001];
char Sub1[10001],Sub2[10001];
int ans[10001];
int Flag=0; // 0 = a >= b , 1 = b > a
int CmpInp(int len1 , int len2) 
{
	if(len1>len2)
	{
		Flag = 0;
	}
	else if(len1 == len2)
	{
		int i;
		for(i=0;i<len1;i++)
		{
			if(inp1[i]>inp2[i])
			{
				Flag = 0;
				break;
			}
			else if(inp1[i]<inp2[i])
			{
				Flag = 1;
				break;
			}
		}
	}
	else if(len1<len2)
	{
		Flag = 1;
	}
	
	updataInp(Flag , len1 , len2);
}
int updataInp(int f)
{
	int i;
	if(f==0)
	{
		strcpy(Sub1,inp1);
		strcpy(Sub2,inp2);
	}
	else
	{
		strcpy(Sub1,inp2);
		strcpy(Sub2,inp1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s %s",inp1,inp2);
		memset(ans,0,sizeof(ans));
		Flag=0;
		/*Cmp*/
		CmpInp(strlen(inp1),strlen(inp2)); 
		/*EndCmp*/
		//printf("inp = %s %s\nSub = %s %s\n",inp1,inp2,Sub1,Sub2);
		int AnsCount=0;
		int i,j,InpLen1 = strlen(Sub1) , InpLen2 = strlen(Sub2);
		/*Sub*/
		for(i=InpLen1-1 , j=InpLen2-1 ; i >= 0 ; i-- , j--)
		{
			int a = Sub1[i] - 48 , b = Sub2[j]-48;
			if(j<0)  //a>b
			{
				b = 0;
			}
			ans[AnsCount++] =  a - b;
		}
		
		for(i=0;i<AnsCount;i++)
		{
			if(ans[i]<0)
			{
				ans[i+1]--;
				ans[i]+=10;
			}
		}
		if(Flag==1)
		printf("-");
		AnsCount--;
		while(ans[AnsCount]==0)
		{
			if(AnsCount==0)
			break;
			AnsCount--;
		}
		for(i=AnsCount;i>=0;i--)
		{
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}

