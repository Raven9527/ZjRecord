#include <stdio.h>
#include <string.h>
int ConvertToMin(int hr, int min)
{
	return hr * 60 + min;
}
int ConvertToUnitHr(int min)
{
	return (min / 60) % 24;
}
int ConvertToUnitMin(int min)
{
	return (min % 60);
}
int main()
{
	int T;
	int bus[30] = {0};
	int start_hr, start_min;
	int min;
	int bus_s = 0;
	scanf("%d", &T);
	scanf("%d %d", &start_hr, &start_min);
	bus[bus_s++] = ConvertToMin(start_hr, start_min);
	while(T--)
	{
		scanf("%d", &min);
		bus[bus_s] = bus[bus_s - 1] + min;
		bus_s++;
	}
	
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		int a_hr = ConvertToUnitHr(bus[n]);
		int a_min = ConvertToUnitMin(bus[n]);
		if (a_hr < 10 && a_min < 10)
			printf("0%d:0%d\n", a_hr, a_min);
		else if (a_hr >= 10 && a_min < 10)
			printf("%d:0%d\n", a_hr, a_min);
		else if (a_hr < 10 && a_min >= 10)
			printf("0%d:%d\n", a_hr, a_min);
		else
			printf("%d:%d\n", a_hr, a_min);
	}
	return 0;
}
