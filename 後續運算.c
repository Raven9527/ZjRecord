#include <stdio.h>
#include <string.h>
char oup[10001];
int Numst[10001]; 
int main()
{
	while(gets(oup)!=NULL)
	{
		int i,s2=strlen(oup);
		int sum=0;
		int Ntop=-1;//<-總是指向最上方 
		for(i=0;i<s2;i++)
		{
			if(oup[i]>='0' && oup[i]<='9')
			{
				sum*=10;
				sum+=oup[i]-48;
				if(oup[i+1]==' ')
				{
					Ntop++;
					Numst[Ntop]=sum;
					sum=0; 
				}
			}
			else if(oup[i]=='+')
			{
				Numst[Ntop-1] = Numst[Ntop] + Numst[Ntop-1];
				Ntop--;
			}
			else if(oup[i]=='-')
			{
				Numst[Ntop-1] = Numst[Ntop] - Numst[Ntop-1];
				Ntop--;
			}else if(oup[i]=='*')
			{
				Numst[Ntop-1] = Numst[Ntop] * Numst[Ntop-1];
				Ntop--;
			}
			else if(oup[i]=='/')
			{
				Numst[Ntop-1] = Numst[Ntop] / Numst[Ntop-1];
				Ntop--;
			}
		}
		printf("%d\n",Numst[0]);
	}
	return 0;
} 
