#include <stdio.h>
#include <string.h>
int flag = 0 , maxNoteNum = 0 , NowNoteNum;
int dfs(int map[81][81] , int v[81][81], int Nownote , int lastnote)
{
	int i;
	
	if(flag)
		return;
	if(NowNoteNum > maxNoteNum)
	{
		maxNoteNum = NowNoteNum;
	}
	for(i = 0 ; i < 81 ; i++)
	{
		if(i == lastnote)
			continue;
		if(map[Nownote][i] == 1)
		{
			//printf("i = %d , j = %d , notenum = %d ,lastNote = %d\n",Nownote , i , NowNoteNum , lastnote);
			if(v[Nownote][i] == 1)
			{
				//printf("\ni = %d , j = %d\n\n" , Nownote , i);
				flag = 1;
				return;
			}
			else //v = 0
			{
				//printf("i = %d , j = %d , notenum = %d ,lastNote = %d\n",Nownote , i , NowNoteNum , lastnote);
				v[Nownote][i] = 1;
				v[i][Nownote] = 1;
				NowNoteNum++;
				dfs(map , v , i , Nownote);
				//NowNoteNum--;
				//v[Nownote][i] = 0;
			}
		}
	}
}
int main()
{
	int stage;
	scanf("%d " , &stage);
	while(stage--)
	{
		char inp[1000];
		memset(inp , '\0' , sizeof(inp));
		gets(inp);
		int k = 0;
		int map[81][81] , v[81][81];
		memset(map , 0 , sizeof(map));
		memset(v , 0 , sizeof(v));
		int t1 = 0 , t2 = 0;
		int NumNote = 0;
		inp[strlen(inp)] = ' ';
		while(inp[k])
		{
			if(inp[k] == ',')
			{
				t1 = t2;
				t2 = 0;
			}
			else if(inp[k] == ' ')
			{
				if(t1 == 0)
				{
					k++;
					continue;
				}
				map[t1][t2] = 1;
				map[t2][t1] = 1;
				//printf("t12 = %d %d\n" , t1 , t2);
				NumNote++;
				t1 = t2 = 0;
			}
			else
			{
				t2 *= 10;
				t2 += inp[k] - 48;
			}
			k++;
		}
		int i , j , q = 0;
		for(i = 0 ; i < 81 && q == 0; i++)
		{
			for(j = 0 ; j < 81 ; j++)
			{
				if(map[i][j])
				{
					dfs(map , v , i , 0);
					q = 1;
					break;	
				}
			}
		}
		//printf("max = %d\n" , maxNoteNum);
		//printf("flag = %d\n", flag);
		if(flag || maxNoteNum != NumNote)
		{
			printf("F\n");
		}
		else
		{
			printf("T\n");
		}
		flag = 0;
		maxNoteNum = 0;
		NowNoteNum = 0;
	}
	return 0;
}
