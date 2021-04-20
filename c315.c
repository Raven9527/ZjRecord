#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int x = 0 , y = 0;
	while(n--){
		int a , b;
		scanf("%d %d",&a , &b);
		if(a == 0){
			y += b;
		}
		else if(a == 1){
			x += b;
		}
		else if(a == 2){
			y -= b;
		}
		else if(a == 3){
			x -= b;
		}
	}
	printf("%d %d\n", x , y);
	return 0;
}
