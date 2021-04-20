#include <string.h>
#include <stdio.h>
#define MAX 1005
void Input(int poly[MAX])
{
	int n;
	scanf("%d", &n);
	int k;
	for (k = 0; k < n; k++)
	{
		int a, c;
		scanf("%d %d", &a, &c);
		poly[a] += c;
	}
}

void PrintAns(int poly[MAX])
{
	int i;
	int flag = 1;
	for (i = MAX - 1; i >= 0; i--)
	{
		if (poly[i] != 0)
		{
			printf("%d:%d\n", i, poly[i]);
			flag = 0;
		}
	}
	
	if (flag == 1)
		printf("NULL!\n");
}
int main()
{
	int poly[MAX];
	memset(poly, 0, sizeof(poly));
	Input(poly);
	Input(poly);
	PrintAns(poly);
	return 0;
}
