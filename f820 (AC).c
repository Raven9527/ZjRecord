#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void InputTerrian(int terrian[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &terrian[i]);
    }
}
void InputLandPosition(int *land)
{
    scanf("%d", land);
}
int GetFinalPosition(int terrian[], int n, int land)
{
    land = land - 1;
    int nextDir = 1;
    if (land == 0)
        nextDir = 1;
    else if (land == n - 1)
        nextDir = -1;
    else if (terrian[land] - terrian[land + 1] >= terrian[land] - terrian[land - 1])
        nextDir = 1;
    else if (terrian[land] - terrian[land - 1] >= terrian[land] - terrian[land + 1])
        nextDir = -1;

    while (land >= 0 && land <= n - 1 && terrian[land] >= terrian[land + nextDir])
    {
        land += nextDir;
    }
    return land + 1;
}
void PrintAns(int finalPos)
{
    printf("%d", finalPos);
}
int main()
{
    int n, land = 0;
    int terrian[36];
    scanf("%d", &n);
    InputTerrian(terrian, n);
    InputLandPosition(&land);
    int finalPos = GetFinalPosition(terrian, n, land);
    PrintAns(finalPos);
    // system("pause");
    return 0;
}