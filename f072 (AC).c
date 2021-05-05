#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InputData(int land[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &land[i]);
    }
}
void DeleteLand(int land[], int n)
{
    int i;
    // 刪除前面
    for (i = 0; i < n; i++)
    {
        if (land[i] == 1)
            break;
        land[i] = 1;
    }

    // 刪除後面
    for (i = n - 1; i >= 0; i--)
    {
        if (land[i] == 1)
            break;
        land[i] = 1;
    }

    // 害蟲
    for (i = 0; i < n; i++)
    {
        if (land[i] == 9)
        {
            if (i > 0 && land[i - 1] == 0)
            {
                land[i - 1] = 8;
            }
            if (i < n - 1 && land[i + 1] == 0)
            {
                land[i + 1] = 8;
            }
        }
    }

    // for (i = 0; i < n; i++)
    //     printf("%d ", land[i]);
    // printf("\n");
}
int GetFlowerLand(int land[], int n)
{
    int sum = 0, i;
    for (i = 0; i < n; i++)
    {
        if (land[i] == 0)
            sum++;
    }
    return sum;
}
void PrintAns(int ans)
{
    printf("%d", ans);
}
int main()
{
    int n;
    int land[30];
    scanf("%d", &n);
    InputData(land, n);
    DeleteLand(land, n);
    PrintAns(GetFlowerLand(land, n));
    // system("pause");
    return 0;
}