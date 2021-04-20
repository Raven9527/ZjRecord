#include <stdio.h>
char inp[150];
int main()
{
	while(scanf("%s",inp)!=EOF)
	{
		int i,s=strlen(inp);
		if(inp[0]=='0' && inp[1]=='\0')
			break;
		int sum=0;
		for(i=0;i<s;i++)
		{
			sum*=10;
			sum+=inp[i]-48;
			sum%=17;
		}
		if(sum==0)
		printf("1\n");
		else
		printf("0\n");
	}
	return 0;
}
