#include <stdio.h>
#include <string.h>
int main()
{
	char inp[2500];
	while(gets(inp)!=NULL){
		int MaxSpace = 0 , NumSpace = 0;
		int strLen = strlen(inp);
		int i;
		for(i = 0 ; i < strLen ; i++){
			if(inp[i] == ' '){
				NumSpace ++ ;
			}
			else{
				MaxSpace = (NumSpace > MaxSpace) ? NumSpace : MaxSpace;
				NumSpace = 0; 
			}
		}
		int ans = 0 , k = 1;
		while(MaxSpace > k){
			k *= 2;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
 } 
