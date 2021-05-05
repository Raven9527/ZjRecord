#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct position_s
{
    int x;
    int y;
}Point;
void InputMap(char map[12][12], int n, int m)
{
    int i, j;
    char inp[50];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            char k;
            scanf("%c", &k);
            if (k == '\n' || k == ' ')
            {
                j--;
                continue;
            }
            map[i][j] = k;
        }
    }
}
int SearchTarget(char map[12][12], char target, int n, int m, Point *p)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (map[i][j] == target)
            {
                p->x = i;
                p->y = j;
                //printf("Find!\n");
                return 1;
            }
        }
    }
    return 0;
}
void ProcessMap(char map[12][12], int n, int m, int targetCount, int *CanComplete, Point path[], int *pathSize)
{
    int searchCount = 0;
    int i;
    for (i = 'a'; i <= 'z'; i++)
    {
        if (SearchTarget(map, i, n, m, &path[(*pathSize)]))
        {
            searchCount++;
            (*pathSize)++;
        }
    }

    if (searchCount >= targetCount)
    {
        (*CanComplete) = 1;
    }
}
void PrintAns(Point path[], int pathSize, int CanComplete, int targetCount)
{
    if (CanComplete)
    {
        int i;
        for (i = 0; i < pathSize && i < targetCount; i++)
        {
            printf("%d %d\n", path[i].x, path[i].y);
        }
    }
    else
    {
        printf("Mission fail.\n");
    }
}
void PrintMap(char map[12][12], int n, int m)
{
    int i, j;
    printf("Print: \n");
    for (i = 0; i < n ; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    char map[12][12];
    int targetCount, CanComplete = 0;
    int m, n;
    Point path[30];
    int pathSize = 0;
    scanf("%d %d", &n, &m);
    scanf("%d", &targetCount);
    InputMap(map, n, m);
    //PrintMap(map, n, m);
    ProcessMap(map, n, m, targetCount, &CanComplete, path, &pathSize);
    PrintAns(path, pathSize, CanComplete, targetCount);
    // system("pause");
    return 0;
}