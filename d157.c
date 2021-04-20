#include <stdio.h>
#include <string.h>
int main()
{
	char izayoi[200] , hong[200] , knowledge[200];
	char inp[200];
	int izayoi_win = 0 , hong_win = 0 , knowledge_win = 0;
	memset(inp , '\0' , sizeof(inp));
	int stage = 1;
	enum fight
	{
		paper,
		scissors,
		stone,
		win
	};
	enum fight sakuya;
	enum fight meiling;
	enum fight pachi;
	while(gets(inp) != NULL)
	{
		memset(izayoi , '\0' , sizeof(izayoi));
		memset(hong , '\0' , sizeof(hong));
		memset(knowledge , '\0' , sizeof(knowledge));
		
		if(strcmp(inp , "Game Over") == 0)
		{
			printf("�Q���]�`�pĹ�F%d������\n",izayoi_win);
			printf("�����a�`�pĹ�F%d������\n",hong_win);
			printf("������P�չp�V�`�pĹ�F%d������\n",knowledge_win);
		}
		else if(strcmp(inp , "End") == 0)
		{
			if((izayoi_win >= hong_win && izayoi_win > knowledge_win) || (izayoi_win > hong_win && izayoi_win >= knowledge_win) )
				printf("���W�ȵ{\n");
			else
				printf("�~�򰵮a��\n");
			break;
		}
		else
		{
			inp[strlen(inp)] = ',';
			inp[strlen(inp) + 1] = '\0';
			int i , s = strlen(inp) , k = 0;
			int j = 0;
			for(i = 0 ; i < s ; i++)
			{
				if(inp[i] != ',')
				{
					if(k == 0)
					{
						izayoi[j++] = inp[i];
					}
					else if(k == 1)
					{
						hong[j++] = inp[i];
					}
					else if(k == 2)
					{
						knowledge[j++] = inp[i];
					}
				}
				else
				{
					k++;
					j = 0;
				}
			}
			
			
			if(strcmp(izayoi , "Paper") == 0)
				sakuya = paper;
			else if(strcmp(izayoi , "Scissors") == 0)
				sakuya = scissors;
			else if(strcmp(izayoi , "Stone") == 0)
				sakuya = stone;
			else
				sakuya = win;
			
			if(strcmp(hong , "Paper") == 0)
				meiling = paper;
			else if(strcmp(hong , "Scissors") == 0)
				meiling = scissors;
			else if(strcmp(hong , "Stone") == 0)
				meiling = stone;
			else
				meiling = win;
			
			if(strcmp(knowledge , "Paper") == 0)
				pachi = paper;
			else if(strcmp(knowledge , "Scissors") == 0)
				pachi = scissors;
			else if(strcmp(knowledge , "Stone") == 0)
				pachi = stone;
			else
				pachi = win;
				
			//printf("izayoi = %s\nmeiling = %s\nknowledge = %s\n",izayoi ,hong , knowledge);
			if(sakuya == win || (sakuya == stone && meiling == scissors && pachi == scissors) || (sakuya == scissors && meiling == paper && pachi == paper) || ((sakuya == paper && meiling == stone && pachi == stone)))
			{
				printf("�Q���]Ĺ�F��%d��������\n" , stage);
				izayoi_win++;
			}
			else if((sakuya == stone && meiling == paper && pachi == paper) || (sakuya == paper && meiling == scissors && pachi == scissors) || ((sakuya == scissors && meiling == stone && pachi == stone)))
			{
				printf("�Q���]��F��%d��������\n" , stage);
				hong_win++;
				knowledge_win++;
			}
			
			if(meiling == win || (meiling == stone && sakuya == scissors && pachi == scissors) || (meiling == scissors && sakuya == paper && pachi == paper) || ((meiling == paper && sakuya == stone && pachi == stone)))
			{
				printf("�����aĹ�F��%d��������\n" , stage);
				hong_win++;
			}
			else if((meiling == stone && sakuya == paper && pachi == paper) || (meiling == paper && sakuya == scissors && pachi == scissors) || ((meiling == scissors && sakuya == stone && pachi == stone)))
			{
				printf("�����a��F��%d��������\n" , stage);
				izayoi_win++;
				knowledge_win++;
			}
				
			if(pachi == win || (pachi == stone && meiling == scissors && sakuya == scissors) || (pachi == scissors && meiling == paper && sakuya == paper) || ((pachi == paper && meiling == stone && sakuya == stone)))
			{
				printf("������P�չp�VĹ�F��%d��������\n" , stage);
				knowledge_win++;
			}
			else if((pachi == stone && meiling == paper && sakuya == paper) || (pachi == paper && meiling == scissors && sakuya == scissors) || ((pachi == scissors && meiling == stone && sakuya == stone)))
			{
				printf("������P�չp�V��F��%d��������\n" , stage);
				hong_win++;
				izayoi_win++;
			}
			
			if((sakuya == stone && meiling == stone && pachi == stone) || (sakuya == scissors && meiling == scissors && pachi == scissors) || ((sakuya == paper && meiling == paper && pachi == paper)))
				printf("��%d�������ӭt\n",stage);
			if((sakuya == paper && meiling == scissors && pachi == stone) || (sakuya == paper && meiling == stone && pachi == scissors))
				printf("��%d�������ӭt\n",stage);
			if((sakuya == stone && meiling == paper && pachi == scissors) || (sakuya == stone && meiling == scissors && pachi == paper)) 
				printf("��%d�������ӭt\n",stage);
			if((sakuya == scissors && meiling == stone && pachi == paper) || (sakuya == scissors && meiling == paper && pachi == stone)) 
				printf("��%d�������ӭt\n",stage);
		}
		stage++;
		memset(inp , '\0' , sizeof(inp));
	}
	
	return 0;
 } 
