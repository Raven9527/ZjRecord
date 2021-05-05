#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void InputMap(int map[20][20], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}
int CheckPoint(int map[20][20], int r, int c, int i, int j)
{
    if (i >= 0 && i < r && j >= 0 && j < c)
        return map[i][j];
    return 0;
}
int CheckAroundHaveDetector(int map[20][20], int r, int c, int x, int y)
{
    if (CheckPoint(map, r, c, x - 1, y - 1) == 5)
        return 5;
    else if (CheckPoint(map, r, c, x - 1, y) == 5)
        return 5;
    else if (CheckPoint(map, r, c, x - 1, y + 1) == 5)
        return 5;

    else if (CheckPoint(map, r, c, x, y - 1) == 5)
        return 5;
    else if (CheckPoint(map, r, c, x, y + 1) == 5)
        return 5;

    else if (CheckPoint(map, r, c, x + 1, y - 1) == 5)
        return 5;
    else if (CheckPoint(map, r, c, x + 1, y) == 5)
        return 5;
    else if (CheckPoint(map, r, c, x + 1, y + 1) == 5)
        return 5;
    return 0;
}
void SetAroundBoom(int map[20][20], int r, int c, int x, int y)
{
    if (CheckPoint(map, r, c, x - 1, y - 1) == 1)
        map[x - 1][y - 1] = 2;
    if (CheckPoint(map, r, c, x - 1, y) == 1)
        map[x - 1][y] = 2;
    if (CheckPoint(map, r, c, x - 1, y + 1) == 1)
        map[x - 1][y + 1] = 2;

    if (CheckPoint(map, r, c, x, y - 1) == 1)
        map[x][y - 1] = 2;
    if (CheckPoint(map, r, c, x, y + 1) == 1)
        map[x][y + 1] = 2;

    if (CheckPoint(map, r, c, x + 1, y - 1) == 1)
        map[x + 1][y - 1] = 2;
    if (CheckPoint(map, r, c, x + 1, y) == 1)
        map[x + 1][y] = 2;
    if (CheckPoint(map, r, c, x + 1, y + 1) == 1)
        map[x + 1][y + 1] = 2;
}
void ProcessDetectBoom(int map[20][20], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (map[i][j] == 5 && CheckAroundHaveDetector(map, r, c, i, j) != 5)
            {
                SetAroundBoom(map, r, c, i, j);
            }
        }
    }
}
int GetDetectedBoomAndNoneDetectBoom(int map[20][20], int r, int c, int *detected, int *noneDetected)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (map[i][j] == 1)
            {
                (*noneDetected)++;
            }
            else if (map[i][j] == 2)
            {
                (*detected)++;
            }
        }
    }
}
void PrintAns(int detected, int noneDetected)
{
    printf("%d %d\n", detected, noneDetected);
}
int main()
{
    int r, c;
    int map[20][20];
    int detected = 0, noneDetected = 0;
    scanf("%d %d", &r, &c);
    InputMap(map, r, c);
    ProcessDetectBoom(map, r, c);
    GetDetectedBoomAndNoneDetectBoom(map, r, c, &detected, &noneDetected);
    PrintAns(detected, noneDetected);
    // system("pause");
    return 0;
}