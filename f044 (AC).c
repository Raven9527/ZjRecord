#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int GetSplitNumber(int n, int t)
{
	return t * 2 + n;
}
int GCD(int a, int b)
{
	int gcd = 1;
	int i;
	for (i = 1; i <= b; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			gcd = i;
		}
	}
	return gcd;
}
void Process(int n, int t, int *day)
{
	if (t == 0)
	{
		*day = 0;
		return;
	}
	int gcd = GCD(n, t);
	n /= gcd;
	t /= gcd;
	
	int smileCount = 0;
	int dayCount = 0;
	(*day) = log2(t + n);
}
void PrintAns(int day)
{
	printf("%d\n", day);
}
int main()
{
	int n, t;
	int day = 0;
	scanf("%d %d", &n, &t);
	Process(n, t, &day);
	PrintAns(day);
	return 0;
}
