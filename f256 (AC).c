#pragma GCC optimize("Ofast")
#include <stdio.h>
#define MAX 131267
char GetChar()
{
	static char buffer[MAX];
	static int bufferCount = MAX << 1;
	static char *start = buffer, *end = buffer;
	
	if (start == end)
	{
		if (bufferCount < MAX)
			return EOF;
			
		bufferCount = fread(buffer, 1, MAX, stdin);
		start = buffer;
		end = buffer + bufferCount;
	}
	return *(start++);
}
int main()
{
	int total_sorce = 0;
	int total_point = 0;
	int mode = 0;
	int current_sorce = 0;
	
	int k = 0;
	char c;
	while((c = GetChar()) != EOF)
	{
		if (c == '\n')
		{
			mode = 0;
		    current_sorce = 0;
		}
		else if (c == ' ')
		{
			if (mode == 0)
				mode = 1;
			else
				mode = 0;	
		}
		else if (mode == 0)
		{
			current_sorce *= 10;
			current_sorce += c - 48;
		}
		else if (mode == 1)
		{
			int delta = c - 48;
			total_sorce += current_sorce * delta;
			total_point += delta;
		}
	}
	
	int ts = total_sorce / total_point;
	if (ts < 60)
	{
		puts("YEEEEEE!!!");
	}
	else
	{
		puts("Oh wow! You pass it!");
		if (ts == 100)
		{
			puts("100");
		}
		else
		{
			printf("%d\n", ts);
		}
	}
	return 0;
}
