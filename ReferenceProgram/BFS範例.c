#include <stdio.h>
#include <string.h>
#define MAXS 102
int tail = 1 , head = 0 , idx[MAXS][MAXS];
char map[MAXS][MAXS];
typedef struct PT
{
	int x , y , step;
}Point;
Point que[MAXS * MAXS];

int breadthFirstSearch(int);
int main()
{
	int n , k , result;
	char inp[MAXS];
	scanf("%d" , &n);
	
	for(k = 0 ; k < n ; k++)
	{
		scanf("%s" , &inp);
		strcpy(map[k] , inp);
	}
	
	que[head].x = 1;
	que[head].y = 1;
	que[head].step = 1;
	idx[1][1] = 1;
	
	result = breadthFirstSearch(n - 2);
	if(result < 0)
	{
		printf("No solution!\n");
	}
	else
	{
		printf("%d\n" , result);
	}
	
	return 0;
}

int breadthFirstSearch(int goal)
{
	while(head != tail)
	{
		if(que[head].x == goal && que[head].y == goal)
		{
			return que[head].step;
		}
		
		if(map[que[head].x][que[head].y + 1] == '.' && idx[que[head].x][que[head].y + 1] == 0)
		{
			idx[que[head].x][que[head].y + 1] = 1;
			que[tail].x = que[head].x;
			que[tail].y = que[head].y + 1;
			que[tail].step = que[head].step + 1;
			
			tail++;
		}
		if(map[que[head].x + 1][que[head].y] == '.' && idx[que[head].x + 1][que[head].y] == 0)
		{
			idx[que[head].x + 1][que[head].y] = 1;
			que[tail].x = que[head].x + 1;
			que[tail].y = que[head].y;
			que[tail].step = que[head].step + 1;
			
			tail++;
		}
		if(map[que[head].x][que[head].y - 1] == '.' && idx[que[head].x][que[head].y - 1] == 0)
		{
			idx[que[head].x][que[head].y - 1] = 1;
			que[tail].x = que[head].x;
			que[tail].y = que[head].y - 1;
			que[tail].step = que[head].step + 1;
			
			tail++;
		}
		if(map[que[head].x - 1][que[head].y] == '.' && idx[que[head].x - 1][que[head].y] == 0)
		{
			idx[que[head].x - 1][que[head].y] = 1;
			que[tail].x = que[head].x - 1;
			que[tail].y = que[head].y;
			que[tail].step = que[head].step + 1;
			
			tail++;
		}
		
		head++;
		
		int k;
		/*for(k = head ; k < tail ; k++)
		{
			printf("(%d %d), " , que[k].x , que[k].y);
		}
		printf("\nhead:%d tail:%d\n" , head , tail);*/
	}
	
	return -1;
}

