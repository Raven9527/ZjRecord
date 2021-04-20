#include <stdio.h>
#include <string.h>
int main()
{
	char inp[10001];
	char q;
	double oddsum = 0 , evensum = 0;
	while(scanf("%s%c" , inp , &q) != EOF)
	{
		int f;
		double num;
		sscanf(inp , "%d:%lf" , &f , &num);
		//printf("f = %d , num = %lf\n",f , num);
		if(f % 2 == 0)
		{
			evensum += num;
		}
		else 
		{
			oddsum += num;
		}
		if(q == '\n' || q == '\0')
		{
			printf("%g\n",oddsum - evensum);
			evensum = oddsum = 0;
		}
	}
	return 0;
}
