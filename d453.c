/* BFS��@�̵u�Z��*/ 
#include <stdio.h>
#include <string.h>
#define MAX 102
int tail=1,head=0;
char map[MAX][MAX];  //�a�� 
int v[MAX][MAX]; //�O�����L���I
char inp[MAX];
int stage;
int n,m;
int FirstX,FirstY;
int EndX,EndY;

struct Point
{
	int X,Y,step;
};

struct Point que[MAX*MAX];

int init()
{
	memset(map,'1',sizeof(map));
	memset(v,0,sizeof(v));
	memset(inp,0,sizeof(inp));
	tail=1,head=0;
	return ;
}
int main()
{
	int n;
	scanf("%d",&stage);
	while(stage--)
	{
		init();
		int f=0;
		scanf("%d %d %d %d %d %d",&n,&m,&FirstX,&FirstY,&EndX,&EndY);
		que[head].X = FirstX;
		que[head].Y = FirstY;
		que[head].step = 1;
		v[FirstX][FirstY]=1;
		int i,j;
		/*input*/
		for(i=1;i<=n;i++)
		{
			scanf("%s",inp);
			for(j=1;j<=m;j++)
			{
				map[i][j]=inp[j-1];
			}
		}
		/*End_input*/
		/*BFS--�Q�άW�C*/ 
		while(head!=tail)
		{
			int LocationX=que[head].X,LocationY=que[head].Y;
			if(LocationX == EndX && LocationY == EndY)
			{
				/*if(f>que[head].step)
				{
					f=que[head].step;
				}*/
				printf("%d\n",que[head].step);
				f=1;
				break;
			}
			
			if(map[LocationX+1][LocationY]=='0' && v[LocationX+1][LocationY]==0)//�W 
			{
				v[LocationX+1][LocationY]=1;
				que[tail].X = que[head].X+1;
				que[tail].Y = que[head].Y;
				que[tail].step = que[head].step +1;
				tail++;
			}
			if(map[LocationX-1][LocationY]=='0' && v[LocationX-1][LocationY]==0)//�U
			{
				v[LocationX-1][LocationY]=1;
				que[tail].X = que[head].X-1;
				que[tail].Y = que[head].Y;
				que[tail].step = que[head].step +1;
				tail++;
			}
			if(map[LocationX][LocationY-1]=='0' && v[LocationX][LocationY-1]==0)//�� 
			{
				v[LocationX][LocationY-1]=1;
				que[tail].X = que[head].X;
				que[tail].Y = que[head].Y-1;
				que[tail].step = que[head].step +1;
				tail++;
			}
			if(map[LocationX][LocationY+1]=='0' && v[LocationX][LocationY+1]==0)//�k 
			{
				v[LocationX][LocationY+1]=1;
				que[tail].X = que[head].X;
				que[tail].Y = que[head].Y+1;
				que[tail].step = que[head].step +1;
				tail++;
			}
			head++;
		}
		
		if(f==0)
		printf("0\n");
		/*test*/
		/*for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%d",v[i][j]);
			}
			printf("\n");
		}*/
		
		/*for(i=0;i<=n+1;i++)
		{
			printf("%s\n",map);
		}*/
	}	
	return 0;
}
