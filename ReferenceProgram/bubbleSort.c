#include <stdio.h>
#define MAX 999
int main()
{
	int a[MAX],n;
	while(scanf("%d",&n)!=EOF)
	{
		int i , j , k;
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
		}
		for(i = 0 ; i < n - 1 ; i++) //�̫�@���洫���Ѩ�Ӥ����N���A���@�洫�Y��������
		{
			for(j = 0 ; j < n - 1 - i; j++) //�C������̤j����������̫�@�Ӧ�m�A�G�̫�@�Ӥ������ݤ��
			{
				if(a[j] > a[j + 1])
				{
					k = a[j];
					a[j] = a[j + 1];
					a[j + 1] = k;
				}
			}
		}
		for(i = 0 ; i < n ; i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
 } 
