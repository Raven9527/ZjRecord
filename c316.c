#include <stdio.h>
#include <math.h>
int main()
{
	int a , b , i , j , n;
	struct point
	{
		int x,y;
	};
	typedef struct point p;
	p pt[1001];
	scanf("%d",&n);
	
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d %d",&pt[i].x , &pt[i].y);
	}
	
	double maxdistance = -2147483647;
	int pi = 2147483647 , pj = 2147483647;
	for(i = 0 ; i < n ; i++)
	{
		for(j = i + 1 ; j < n ; j++)
		{
			double d = sqrt(((pt[i].x - pt[j].x) * (pt[i].x - pt[j].x)) + ((pt[i].y - pt[j].y) * (pt[i].y - pt[j].y)));  
			//printf("d = %lf\n" , d);
			if(d > maxdistance)
			{
				pi = i;
				pj = j;
				maxdistance = d;
			}
		}
	}
	printf("%d %d",pi , pj);
	return 0;
}
