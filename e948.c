#include <string.h>
#include <stdio.h>
double Compute(int m, int a, int h, int w)
{
	if (m == 0) // female
	{
		double a1 = (9.6 * ((double)w));
		double a2 = (1.8 * ((double)h));
		double a3 = (4.7 * ((double)a));
		//printf("%lf %lf %lf\n", a1, a2, a3);
		return a1 + a2 - a3 + 655;
	}
	else // male
	{
		double a1 = (13.7 * ((double)w));
		double a2 = (5.0 * ((double)h));
		double a3 = (6.8 * ((double)a));
		//printf("%lf %lf %lf\n", a1, a2, a3);
		return a1 + a2 - a3 + 66;
	}
}
int main()
{
	int T; 
	scanf("%d", &T);
	while(T--)
	{
		int g, a, h, w;
		scanf("%d %d %d %d", &g, &a, &h, &w);
		double ans = Compute(g, a, h, w);
		printf("%.2lf\n", ans);
	}
	return 0;
}
