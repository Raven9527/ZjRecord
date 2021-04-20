#include <stdio.h>
int main()
{
	char a,b,c,d;
	scanf("%c%c%c%c",&a,&b,&c,&d);
	int n;
	char ga,gb,gc,gd;
	char inp[5];
	scanf("%d",&n);
	while(n--)
	{
		int suma = 0 , sumb = 0;
		scanf("%s",inp);
		ga = inp[0];
		gb = inp[1];
		gc = inp[2];
		gd = inp[3];
		if(a == ga)
		{
			suma++;
		}
		else if(a == gb || a == gc || a == gd)
		{
			sumb++;
		}
		
		if(b == gb)
		{
			suma++;
		}
		else if(b == ga || b == gc || b == gd)
		{
			sumb++;
		}
		
		if(c == gc)
		{
			suma++;
		}
		else if(c == ga || c == gb || c == gd)
		{
			sumb++;
		}
		
		if(d == gd)
		{
			suma++;
		}
		else if(d == ga || d == gb || d == gc)
		{
			sumb++;
		}
		printf("%dA%dB\n",suma,sumb);
	}
	return 0;
 } 
