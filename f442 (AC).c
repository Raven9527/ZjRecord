#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void InputChicken(int chicken[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &chicken[i]);
    }
}
void ProcessEagleCatchChicken(int chicken[], int chickenSize, int *eagleIndex)
{
    int catchIndex = 0, i;
    scanf("%d", &catchIndex);
    for (i = 0; i < chickenSize; i++)
    {
        if (chicken[i] == catchIndex)
        {
            Swap(eagleIndex, &chicken[i]);
            return;
        }
    }
}
void PrintAns(int chicken[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", chicken[i]);
    }
}
int main()
{
    int n, e, T;
    int chicken[10005];
    scanf("%d", &n); // input chicken count
    InputChicken(chicken, n);
    scanf("%d", &e); // input eagle index
    scanf("%d", &T); // T turn

    while(T--)
    {
        ProcessEagleCatchChicken(chicken, n, &e);
    }

    PrintAns(chicken, n);
    // system("pause");
    return 0;
}