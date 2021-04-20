#include <string.h>
#include <stdio.h>
#define MAX_SIZE 1299710
int map[MAX_SIZE];
int prime[100005];
int size = 0;
// Create Prime Table
void Create()
{
	int i, j, k;
	memset(map, 1, sizeof(map));
	for (i = 4; i <= MAX_SIZE; i += 2)
		map[i] = 0;
	for (i = 3; i * i <= MAX_SIZE; i += 2)
	{
		for (j = 2; i * j <= MAX_SIZE; j++)
		{
			map[i * j] = 0;
		}
	}
	prime[size++] = 2;
	for (i = 3; i <= MAX_SIZE; i += 2)
	{
		if (map[i] > 0)
			prime[size++] = i;
	}
	
	/*for (i = 0; i < 10; i++)
	{
		printf("bang: %d\n", map[i]);
	}*/
}

void DebugPrint()
{
	int i;
	for (i = 0 ; i < 10; i++)
	{
		printf("%d ", prime[i]);
	}
}

// Binary Search, Return Index, prime[index] < Number
int BinarySearch(int number)
{
	int l = 0;
	int r = size;
	int mid = (l + r) / 2;
	while(mid < r)
	{
		//printf("mid: %d\n", prime[mid]);
		if (prime[mid] < number && prime[mid + 1] > number)
		{
			return mid;
		}
		else if (prime[mid] > number)
		{
			r = mid - 1;
		}
		else if (prime[mid] < number)
		{
			l = mid + 1;
		}
		
		mid = (l + r) / 2;
	}
}

int main()
{
	Create();
	//DebugPrint();
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		if (map[n] != 0)
			printf("0\n");
		else
		{
			int index = BinarySearch(n);
			printf("%d\n", prime[index + 1] - prime[index]);
		}
	}
	return 0;
}
