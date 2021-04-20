#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#define MAX 10000
int p[MAX] , pr[1005];
int main()
{
    int n, i, j;
    int k = 1;
    srand(5);
    double t1 = clock();
    memset(p, 1, sizeof(p));

    for (i = 3; k <= 1005; i += 2)
    {
        if(p[i] != 0)
            pr[k++] = i;
        
        for (j = 2; i * j <= MAX; j++)
        {
            p[i * j] = 0;
        }
    }
	pr[0] = 2;

    int sum = 1;
    int stage = 0;
    int f[5] = {31,5,6,7,9};
    while (stage < 5)
    {
    	t1 = clock();
        for (i = 0; i < f[stage]; i++)
        {
        	sum *= pr[stage];
        	sum %= 76543;
        }
        stage++;
    }
    printf("%d\n",sum);
    printf("%lf\n",t1);
    return 0;
}

int kkk()
{
	int n = 10000000; // repeat do_somenting() n times
	int i;
	int t1 = clock();
	for (i = 0; i<n; i++)
	{
		n = n;
	}
	int t2 = clock();
	//printf("do_something() %d times took %lf seconds\n(measurement granularity: %d of a second)\n" , n , (double)(t2-t1)/CLOCKS_PER_SEC , CLOCKS_PER_SEC);
	
