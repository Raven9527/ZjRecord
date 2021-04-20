#include <stdio.h>
#include <string.h>
#define MAX 23
//MAX 位數 11
int print(int *x)
{
	int i;
	for(i = 0 ; i < MAX ; i++)
	{
		printf("%d ",x[i]);
	}
	printf("\n");
}
int AddnumberToArray(int *k , long long int num)
{
	int i , Index = 0;
	for(i = 0 ; i < MAX ; i++)
		k[i] = 0;
	while(num > 0)
	{
		k[Index++] = num % 10;
		num /= 10;
	}
}
int ArraySort(int s1[] , int s2[] , int s3[])
{
	int i;
	int temp[MAX];
	memset(temp , 0 , sizeof(temp));
	short int flag = 0; // 1為最長 
	for(i = MAX - 1 ; i >= 0 ; i--)
	{
		if(s1[i] > s2[i])
		{
			CopyNumToArray(temp , s1);
			flag = 1;
			break;
		}
		else if(s1[i] < s2[i])
		{
			CopyNumToArray(temp , s2);
			flag = 2;
			break;
		}
	}
	if(flag == 0)
	{
		flag = 2;
		CopyNumToArray(temp , s2);
	}
	for(i = MAX - 1 ; i >= 0 ; i--)
	{
		if(temp[i] > s3[i])
		{
			break;
		}
		else if(temp[i] < s3[i])
		{
			flag = 3;
			break;
		}
	}
	return flag;
}
int CmpArray(int *s1 , int *s2 , int *s3)
{
	int i;
	int sk[MAX];
	bignumeradd(s1 , s2 , s1);
	for(i = MAX - 1 ; i >= 0 ; i--) //兩邊平方大於第三邊 
	{
		if(s1[i] > s3[i])
		{
			printf("acute triangle\n");
			return;
		}
		else if(s1[i] < s3[i])
		{
			printf("obtuse triangle\n"); //兩邊平方小於第三邊 
			return;
		}
	}
	printf("right triangle\n");
}
int CopyNumToArray(int *a , int *b)
{
	int i;
	for(i = 0 ; i < MAX ; i++)
	{
		a[i] = b[i];
	}
}
int bignumermut(int *a , int *b , int *ans)
{
	int i , j;
	int temp[MAX];
	memset(temp , 0 , sizeof(temp));
	for(i = 0 ; i < MAX ; i++)
	{
		for(j = 0 ; j < MAX ; j++)
		{
			temp[j + i] += a[i] * b[j];
		}
 	}
 	
 	for(i = 0 ; i < MAX ; i++)
 	{
 		if(temp[i] >= 10)
 		{
 			temp[i + 1] += temp[i] / 10;
 			temp[i] %= 10;
		}
	}
	CopyNumToArray(ans , temp);
}
int bignumeradd(int *a , int *b , int *ans)
{
	int i;
	int temp[MAX];
	memset(temp , 0 , sizeof(temp));
	for(i = 0 ; i < MAX ; i++)
	{
		temp[i] += a[i] + b[i];
 	}
 	
 	for(i = 0 ; i < MAX ; i++)
 	{
 		if(temp[i] >= 10)
 		{
 			temp[i + 1] += temp[i] / 10;
 			temp[i] %= 10;
		}
	}
	CopyNumToArray(ans , temp);
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long int a,b,c;
		scanf("%lld %lld %lld",&a , &b , &c);
		int s1[MAX] , s2[MAX] , s3[MAX];
		AddnumberToArray(s1 , a);
		AddnumberToArray(s2 , b);
		AddnumberToArray(s3 , c);
		 
		bignumermut(s1 , s1 , s1);
		bignumermut(s2 , s2 , s2);
		bignumermut(s3 , s3 , s3);
		int f1;
		f1 = ArraySort(s1 , s2 , s3);
		if(f1 == 1)
		{
			CmpArray(s2 , s3 , s1);
		}
		else if(f1 == 2)
		{
			CmpArray(s1 , s3 , s2);
		}
		else if(f1 == 3)
		{
			CmpArray(s1 , s2 , s3);
		}
	}
	return 0;
}
