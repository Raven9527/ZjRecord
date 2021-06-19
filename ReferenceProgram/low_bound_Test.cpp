#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
	int arr[5] = {4 , 8 , 12 , 16 , 20};
	int k = lower_bound(arr , arr + 5 , 6) - arr;
	printf("%d\n",k);
	return 0;	
}
