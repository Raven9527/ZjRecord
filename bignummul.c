#include <stdio.h>
#include <string.h>
int a[100];
int b[100];
int ans[100];
char inpa[100];
char inpb[100];
int main()
{
	while(scanf("%s %s",inpa,inpb)!=EOF)
	{
		int i,j,ak = 0;
		int ai , bi;
		for(i = 0 ; i < strlen(inpa) ; i++)
			a[i] = inpa[i] + 48;
		ai = i;
		for(i = 0 ; i < strlen(inpb) ; i++)
			b[i] = inpb[i] + 48;
		bi = i;
		
		for(i = 0; i < ai ; i++)
		{
			for(j = 0 ; j < bi ; j++)
			{
				ans[ak] = a[i] * b[j];
			}
		}
	}
	return 0;
} 
