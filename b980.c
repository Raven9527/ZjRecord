#include <stdio.h>
#include <string.h>
int redbou[10001] = {0};
int main()
{
	int inpn;
	int knowkotoba = 0;
	int redbouNum = 0;
	int LastnIsNotKotoba = 0;
	while(scanf("%d",&inpn)!=EOF)
	{
		if(inpn == -1)
		{
			// sort
			int k = 10000;
			int i = 0;
			int sum = 0;
			while(knowkotoba > 0 && k >= 0)
			{
				while(redbou[k] > 0 && knowkotoba > 0)
				{
					knowkotoba--;
					redbou[k]--;
					sum += k;
				}
				k--;
			}
			printf("%d\n",sum);
			//
			memset(redbou , 0 , sizeof(redbou));
			knowkotoba = 0;
			redbouNum = 0;
			LastnIsNotKotoba = 0;
		}
		else
		{
			if(!LastnIsNotKotoba)
			{
				LastnIsNotKotoba = 1;
				knowkotoba = inpn;
			}
			else if(LastnIsNotKotoba)
			{
				redbou[inpn]++;
			}
		}
	}
	return 0;
} 
