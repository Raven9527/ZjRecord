#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int numArray[1000005];
void Input(int n, unsigned long long int *s)
{
	int i;
	for (i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		numArray[i] = k;
		(*s) += k;
	}
}
unsigned long long int Process(int n, unsigned long long int s)
{
	int i;
	s = s * s;
	for (i = 0; i < n; i++)
	{
		s -= (numArray[i] * numArray[i]);
	}
	s /= 2;
	return s;
}
void PrintAns(unsigned long long int ans)
{
	printf("%lld\n", ans);
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		unsigned long long int s = 0;
		Input(n, &s);
		unsigned long long int ans = Process(n, s);
		PrintAns(ans);
	}
	return 0;
}
