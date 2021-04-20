#include <stdio.h>
#include <math.h>
int main() 
{
	long long int kernelX , kernelY;
	long long int kingdomX , kingdomY;
	long long int r;
	while(scanf("%lld %lld %lld %lld %lld",&kernelX , &kernelY , &kingdomX , &kingdomY , &r)!=EOF)
	{
		double distance = sqrt((((kernelX - kingdomX) * (kernelX - kingdomX))) + (((kernelY - kingdomY) * (kernelY - kingdomY))));
		if(distance > (double)r)
			printf("alive\n");
		else
			printf("die\n");
	}
	return 0;
}
