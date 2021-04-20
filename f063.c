#include <stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	int mmax = 0;
	int first = 1;
	while (T--)
	{
		int n, i;
		scanf("%d", &n);
		int min = 0;
		int k;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &k);
			if (i == 0 || k < min)
				min = k;
		}
		
		if (first == 1 || min > mmax)
		{
			first = 0;
			mmax = min;
		}
	}
	printf("%d", mmax);
	return 0;
}
