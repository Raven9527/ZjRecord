#include <string.h>
#include <stdio.h>
int main()
{
	char str[105];
	scanf("%s", &str);
	int s = strlen(str);
	int i;
	for (i = s - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
	return 0;
}
