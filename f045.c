#include <stdio.h> 
#include <string.h>
char inp[15];
int bucket[15];
int GetIDNumber(char inp[], int size)
{
	int num = 0;
	num = (inp[size - 3] - 48) * 100 + (inp[size - 2] - 48) * 10 + (inp[size - 1] - 48);
	return num;
}
int GetPow2()
{
	int sum = 0;
	int count = 0;
	int index = 9;
	while(count < 2 && index > 0)
	{
		if (bucket[index] > 0)
		{
			sum += (index * index);
			bucket[index]--;
			count++;
		}
		else
		{
			index--;
		}
	}
	return sum;
}
int main()
{
	memset(bucket, 0, sizeof(bucket));
	scanf("%s", inp);
	int s = strlen(inp);
	int i;
	for (i = 0; i < s; i++)
	{
		bucket[inp[i] - 48]++;
	}
	
	int idNumber = GetIDNumber(inp, s);
	int sqrt = GetPow2();
	//printf("id: %d\n", idNumber);
	//printf("Sqrt: %d\n", sqrt);
	if (idNumber == sqrt)
	{
		printf("Good Morning!\n");
	}
	else
	{
		printf("SPY!");
	}
	return 0;
}
