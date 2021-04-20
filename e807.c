#include <stdio.h>
#include <string.h>
int main()
{
	// j - index = 4, store total rain on day
	// i - index = 7, store total rain on time zone
	double rainMap[10][10]; 
	int i, j;
	// input
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%lf", &rainMap[i][j]);
		}		
	}
	
	/*for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%10lf", rainMap[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");*/
	// process
	// Step1: process max day
	for (i = 0; i < 7; i++)
	{
		double r = 0;
		for (j = 0; j < 4; j++)
		{
			r += rainMap[i][j];
		}
		rainMap[i][5] = r;
	}
	// Step2: process max time zone
	for (i = 0; i < 4; i++)
	{
		double r = 0;
		for (j = 0; j < 7; j++)
		{
			r += rainMap[j][i];
		}
		rainMap[7][i] = r;
	}
	// Get Max Day
	int day = 1;
	double max = -1;
	for (i = 0; i < 7; i++)
	{
		if (rainMap[i][5] > max)
		{
			day = i + 1;
			max = rainMap[i][5];
		}
	}
	// Get Max Time Zone
	int timeZone = 1;
	max = -1;
	for (i = 0; i < 4; i++)
	{
		if (rainMap[7][i] > max)
		{
			timeZone = i + 1;
			max = rainMap[7][i];
		}
	}
	
	/*for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%10lf", rainMap[i][j]);
		}
		printf("\n");
	}*/
	
	printf("%d\n", day);
	if (timeZone == 1)
		printf("morning\n");
	if (timeZone == 2)
		printf("afternoon\n");
	if (timeZone == 3)
		printf("night\n");
	if (timeZone == 4)
		printf("early morning\n");
	return 0;
}
