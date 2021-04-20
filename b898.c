#include <stdio.h>
#include <string.h>
void CmpString(char a[] , char b[] , int n , char ans[])
{
	int i;
	//memset(ans , '\0' , sizeof(ans));
	for(i = 0 ; i < n ; i++)
	{
		if(a[i] > b[i])
		{
			strcpy(ans , a);
			return;
		}
		else if(a[i] < b[i])
		{
			strcpy(ans , b);
			return;
		}
	}
}
void addInFirstZero(char a[] , int max , int s)
{
	int i;
	char temp[100001];
	memset(temp , '\0' , sizeof(temp));
	for(i = 0 ; i < max - s ; i++)
	{
		temp[i] = '0';
	}
	int j = 0;
	for(i = max - s ; i < max ; i++)
		temp[i] = a[j++];
	//printf("temp %s\n",temp);
	strcpy(a , temp);
}
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{	
		char inp[4][100003];
		while(n--)
		{
			char ans[100001];
			memset(ans, '\0' , sizeof(ans));
			memset(inp[0] , '\0' , sizeof(inp[0]));
			scanf("%s %s %s",inp[0] , inp[1] , inp[2]);
			int s1 = strlen(inp[0]), s2  = strlen(inp[1]) , s3  = strlen(inp[2]);
			int max = -1;
			if(s1 > max)
				max = s1;
			if(s2 > max)
				max = s2;
			if(s3 > max)
				max = s3;
			//printf("max %d\ns1 %d\n" , max,s1);
			
			//printf("inp0 = %s\ninp1 = %s\ninp2 = %s\n\n",inp[0] , inp[1] , inp[2]);
			//printf("s1 = %d\ns2 = %d\ns3 = %d\n",s1,s2,s3);
			addInFirstZero(inp[0] , max , s1);
			addInFirstZero(inp[1] , max , s2);
			addInFirstZero(inp[2] , max , s3);
			
			CmpString(inp[0] , inp[1] , max , ans);
			//printf("ans = %s\n",ans);
			CmpString(ans , inp[2] , max , ans);
			//printf("%s\n%s\n%s\n",inp[0],inp[1],inp[2]);
			printf("%s\n",ans);
		}
	}
	return 0;
} 
