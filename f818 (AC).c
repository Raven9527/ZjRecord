#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct lion_s
{
    int height;
    int weight;
}Lion;
int GetLionScore(Lion lion)
{
    return lion.height * lion.weight;
}
void InputLionData(Lion lions[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &lions[i].height);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &lions[i].weight);
    }
}
Lion* FindMinLion(Lion lions[], int n)
{
    Lion *minLion = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        if (minLion == NULL)
        {
            minLion = &lions[i];
        }
        else if (GetLionScore(*minLion) > GetLionScore(lions[i]))
        {
            minLion = &lions[i];
        }
    }
    return minLion;
}
void PrintMinLion(Lion *lion)
{
    printf("%d %d\n", lion->height, lion->weight);
}
int main()
{
    int n;
    Lion lions[2021];
    scanf("%d", &n);
    InputLionData(lions, n);
    PrintMinLion(FindMinLion(lions, n));
    // system("pause");
    return 0;
}