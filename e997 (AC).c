#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void SetNameTable(char inp[], char nameTable[55][55], int *count)
{
    int i, iSize = 0, size = strlen(inp);

    for (i = 0; i < size; i++)
    {
        if (inp[i] != ' ')
        {
            nameTable[(*count)][iSize++] = inp[i];
        }
        else
        {
            nameTable[(*count)][iSize++] = '\0';
            (*count)++;
            iSize = 0;
        }
    }
}

void TestPrintNameTable(char nameTable[55][55], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("%s\n", nameTable[i]);
    }
    printf("count: %d\n", count);
}

void PrintAns(char nameTable[55][55], int count, int index)
{
    printf("%s", nameTable[count - index]);
}

int main()
{
    char nameTable[55][55];
    int count = 0, index = 0;
    char inp[3000];
    memset(nameTable, '\0', sizeof(nameTable));
    gets(inp);
    inp[strlen(inp)] = ' ';
    SetNameTable(inp, nameTable, &count);
    //TestPrintNameTable(nameTable, count);
    scanf("%d", &index);
    PrintAns(nameTable, count, index);
    //system("pause");
    return 0;
}