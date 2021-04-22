#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int GetPow2(int n)
{
	return n * n;
}
int GetEndPoint(int n, int d)
{
	return GetPow2(n) - d / 2;
}
void ProcessMove(int sec, int *tx, int *ty)
{
	int x, y;
	int s = sqrt(sec);
	if (sqrt(sec) != (double)s)
	{
		s += 1;
	}
		
	int d = GetPow2(s) - GetPow2(s - 1);
	
	// ���k�W
	if (s % 2 == 0)
	{
		int p = GetEndPoint(s, d);
		if (sec == p) // �A���I�W 
		{
			x = s;
			y = s;
		}
		else if (sec > p) // �b�k�� 
		{
			x = s;
			y = s - (sec - p);
		}
		else if (sec < p) // �b�U�� 
		{
			x = s - (p - sec);
			y = s;
		}
	}
	// �����U 
	else
	{
		int p = GetEndPoint(s, d);
		if (sec == p) // �A���I�W 
		{
			x = s;
			y = s;
		}
		else if (sec > p) // �b�U�� 
		{
			x = s - (sec - p);
			y = s;
		}
		else if (sec < p) // �b�k��
		{
			x = s;
			y = s - (p - sec);
		}
	}
	*tx = x;
	*ty = y;
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		int x, y;
		ProcessMove(n, &x, &y);
		printf("%d %d\n", x, y);
	}
	return 0;
}
