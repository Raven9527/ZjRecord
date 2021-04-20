#include <stdio.h>
#include <string.h>
int CmpString(char x[])
{
	if(strcmp(x , "yee") == 0)
		return 0;
	else if(strcmp(x , "eye") == 0)
		return 1;
	else if(strcmp(x , "eey") == 0)
		return 2;
	else if(strcmp(x , "eee") == 0)
	return 1;
	else if(strcmp(x , "yey") == 0)
	return 4;
	else if(strcmp(x , "yye") == 0)
	return 3;
	else if(strcmp(x , "eyy") == 0)
	return 5;
		
}
int main()
{
	char inp[100001];
	scanf("%s",inp);
	{
		int k = 0;
		while(inp[k])
		{
			int i;
			char temp[4];
			memset(temp , '\0' , sizeof(temp));
			for(i = 0 ; i < 3 ; i++)
			{
				temp[i] = inp[k + i];
			}
			int sum += CmpString(temp);
			k += 3;
		}
	}
	return 0;
}
