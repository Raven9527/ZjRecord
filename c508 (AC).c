#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100005
int numArray[MAX];
int cmp(const void *n1, const void *n2)
{
	return (*(int *)n1 - *(int *)n2);
}
void InputNumberArray(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &numArray[i]);
	}
}
void PrintAns(int n, int mode)
{
	if (mode == 1)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			printf("%d ", numArray[i]);
		}
	}
	else
	{
		int i;
		int tempRecord = -1; 
		for (i = n - 1; i >= 0; i--)
		{
			if (tempRecord != numArray[i])
			{
				printf("%d ", numArray[i]);
				tempRecord = numArray[i];
			}
		}
	}
	printf("\n");
} 
int main()
{
	int n;
	scanf("%d", &n);
	InputNumberArray(n);
	qsort(numArray, n, sizeof(int), cmp);
	PrintAns(n, 1);
	PrintAns(n, 2);
	return 0;
} 
