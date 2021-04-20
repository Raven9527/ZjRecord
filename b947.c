#include <stdio.h>
#include <string.h>
char n1[20] , n2[20];
typedef struct 
{
	char name[20];
	int trick;
}person;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		person p1; // p1 = {n1 , 0}?
		person p2;
		int s , v1 , v2;
		// intielf
		scanf("%s %s",p1.name,p2.name);
		p1.trick = 0;
		p2.trick = 0;
		// end
		int i;
		for(i = 1 ; i <= n ; i++)
		{
			scanf("%d %d %d",&s , &v1 , &v2);
		
			if(v1 > v2)
			{
				p1.trick += s;
			}
			else if(v1 < v2)
			{
				p2.trick += s;
			}
		}
		if(p1.trick > p2.trick)
			printf("%s\n",p1.name);
			
		else if(p1.trick < p2.trick)
			printf("%s\n",p2.name);
			
		else if(p1.trick == p2.trick)
			printf("Tie\n");
	}
	return 0;
 } 
