#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char inpkey[105] , inpstr[1005];
    int dekey[105] = {0};
    scanf("%s %s", inpkey, inpstr);
    int k = 0 , index = 0;
    while(inpkey[k])
    {
        if(inpkey[k] >= 'A' && inpkey[k] <= 'Z')
        {
            dekey[k] = inpkey[k] - 65;
        }
        else if(inpkey[k] >= 'a' && inpkey[k] <= 'z')
        {
            dekey[k] = inpkey[k] - 97;
        }
        k++;
    }

    while(inpstr[index])
    {
        if(inpstr[index] >= 'A' && inpstr[index] <= 'Z')
        {
            if(inpstr[index] - dekey[index % k] < 65)
                inpstr[index] += 26;
        }
        else if(inpstr[index] >= 'a' && inpstr[index] <= 'z')
        {
            if(inpstr[index] - dekey[index % k] < 97)
                inpstr[index] += 26;
        }
        printf("%c", inpstr[index] - dekey[index % k]);
        index++;
    }
    printf("\n");
    //system("pause");
    return 0;
}