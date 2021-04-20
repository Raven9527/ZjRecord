#include <stdio.h>
#include <string.h>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int t = b - a;
	if (t < 0)
		t += 100;
	printf("%d", t);
	return 0;
}
