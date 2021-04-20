#include <stdio.h>
#include <string.h>
int map[102][102];
int n;
int f=1;
int odd=0;
int checkrow(int k)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=map[i][k];
	}
	if(sum%2!=0)
		f=0;
	else
		odd++;
	return ;
}

int checkelse(int k)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=map[k][i];
	}
	if(sum%2!=0)
		f=0;
	else
		odd++;
	return ;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		f=1;
		odd=0;
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			checkrow(i); //檢查直的 
			checkelse(i); //檢查橫的 
		}
		if(f==1)
		{
			printf("OK\n");
		}
		else
		{
			if(odd>=2)
			{
				printf("Corrupt\n");
			}
			else
			{
				printf("Change bit (%d,%d)",i,j);
			}
		}
	}
	return 0;
}
