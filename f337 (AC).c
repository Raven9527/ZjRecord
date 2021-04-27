#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Process(int people, int pizza)
{
	pizza *= 8;
	if (people * 2 > pizza)
	{
		return 1;
	}
	else if (people * 2 <= pizza && people * 3 >= pizza)
	{
		return 2;
	}
	else if (people * 3 < pizza)
	{
		return 3;
	}
}
void PrintAns(int range)
{
	if (range == 1)
	{
		printf("Not enough\n");
	}
	else if (range == 2)
	{
		printf("Yes\n");
	}
	else if (range == 3)
	{
		printf("Too much\n");
	}
}
int main()
{
	int people, pizza;
	scanf("%d %d", &people, &pizza);
	PrintAns(Process(people, pizza));
	return 0;
} 
