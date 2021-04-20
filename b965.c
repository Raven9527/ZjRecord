#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1001
int printMap(int map[MAX][MAX] , int r, int c)
{
	int i,j;
	for(i = 0 ; i < r; i++)
	{
		for(j = 0 ; j < c ; j++)
		{
			printf("%d",map[i][j]);
			if(j != c - 1)
				printf(" ");
		}
		printf("\n");
	}
}
int copymap(int map[MAX][MAX] , int map2[MAX][MAX] , int r , int c) //±NMAP2½Æ»s¨ìMAP1 
{
	int i , j;
	memset(map , 0 , sizeof(map));
	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < c ; j++)
		{
			map[i][j] = map2[i][j];
		}
	}
}
int right(int map[MAX][MAX] , int *r , int *c) 
{
	int i , j;
	int map2[MAX][MAX];
	memset(map2 , 0 , sizeof(map2));
	for(i = 0 ; i < *r ; i++)
	{
		for(j = 0 ; j < *c ; j++)
		{
			map2[*c - j - 1][i] = map[i][j];
		}
	}
	int k;
	k = *r;
	*r = *c;
	*c = k;
	memset(map , 0 , sizeof(map));
	copymap(map , map2 , *r , *c);
}
int Updown(int map[MAX][MAX] , int r , int c)
{
	int i , j;
	int map2[MAX][MAX];
	memset(map2 , 0 , sizeof(map2));
	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < c ; j++)
		{
			map2[r - i - 1][j] = map[i][j];
		}
	}
	memset(map , 0 , sizeof(map));
	copymap(map , map2 , r , c);
} 
int main()
{
	int r , c , m;
	int map[MAX][MAX];
	int d[MAX];
	while(scanf("%d %d %d",&r,&c,&m)!=EOF)
	{
		int i , j;
		for(i = 0 ; i  < r ; i++)
		{
			for(j = 0 ; j < c ; j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		//printMap(map , r , c);
		//printMap(map , r , c); 
		//printf("\n");
		for(i = 0 ; i < m; i++)
		{
			scanf("%d",&d[i]);
		}
		i = m - 1;
		while(i >= 0)
		{
			if(d[i] == 0)
			{
				right(map , &r , &c);
			}
			else
			{
				Updown(map , r , c);
			}
			i--;
		}
		printf("%d %d\n", r , c);
		printMap(map , r , c); 
	}
	return 0;
}
