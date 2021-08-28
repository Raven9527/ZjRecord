#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[32][100];
    int inputSize = 0, i;
    while(scanf(" %s ", input[inputSize]) != EOF)
        inputSize++;
        
    for (i = 0; i < inputSize; i++)
    {
        if (i != inputSize - 1)
            printf("%s little, ", input[i]);
        else
            printf("%s little Indians\n", input[i]);
    }
    //system("pause");
    return 0;
}