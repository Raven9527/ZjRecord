#include <stdio.h>
int main()
{
	int a , b;
	char k;
	while(scanf("%d %c %d" , &a , &k , &b)!=EOF)
	{
		if(k == '+')
		{
			printf("%d\n",a + b);
		}
		else if(k == '-')
		{
			printf("%d\n",a - b);
		}
		else if(k == '*')
		{
			printf("%d\n",a * b);
		}
		else if(k == '/')
		{
			printf("%d\n",a / b);
		}
	}
	return 0;
 } 
