#include <stdio.h>
#include <string.h>
int Compare(char inp[], char str[], int inp_s, int str_s)
{
	int i, j;
	for (i = 0; i < inp_s; i++)
	{
		int flag = 1;
		for (j = 0; j < str_s; j++)
		{
			if (inp[i + j] != str[j])
			{
				flag = 0;
				break;
			}
		}
		
		if (flag == 1)
		{
			return i;
		}
	}
}
int main()
{
	char inp[100];
	char str[100];
	char ans[100];
	memset(ans, '\0', sizeof(ans));
	scanf("%s", inp);
	scanf("%s", str);
	int inp_s = strlen(inp);
	int str_s = strlen(str);
	int i, j;
	// Reverse Str
	for (i = 0; i < inp_s; i++)
	{
		ans[i] = inp[inp_s - i - 1];
	}
	int index = Compare(inp, str, inp_s, str_s);
	//printf("index: %d\n", index);
	int reverse_index = inp_s - index - 1;
	//printf("reverse index: %d\n", reverse_index);
	for (i = str_s - 1; i >= 0; i--)
	{
		ans[reverse_index--] = str[i];
	}
	printf("%s", ans);
	return 0;
}
