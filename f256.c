#include <string.h>
#include <stdio.h>
char bang[10];
int main()
{
	int total_sorce = 0;
	int total_point = 0;
	while (gets(bang) != '\0')
	{
		int s = 0;
		int mode = 0;
		int current_sorce = 0;
		while (bang[s] != '\0')
		{
			if (bang[s] == ' ')
			{
				mode = 1;	
			}
			else if (mode == 0)
			{
				current_sorce *= 10;
				current_sorce += bang[s] - 48;
			}
			else if (mode == 1)
			{
				int delta = bang[s] - 48;
				total_sorce += current_sorce * delta;
				total_point += delta;
			}
			s++;
		}
		
		//memset(bang, '\0', sizeof(bang));
	}
	
	int ts = total_sorce / total_point;
	//printf("%d\n", ts);
	if (ts < 60)
	{
		puts("YEEEEEE!!!");
	}
	else
	{
		puts("Oh wow! You pass it!\n");
		printf("%d", ts);
	}
	return 0;
}
