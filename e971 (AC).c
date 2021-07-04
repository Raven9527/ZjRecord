#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define MAP_SIZE 120

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
typedef struct Map_s
{
    int row, col;
    int map[MAP_SIZE][MAP_SIZE];
}Map;
void InputMap(Map*);
void DrawMap(Map*);
void DrawLine(Map*, int, int, int);
void PrintMap(Map*);

// Main Region
int main()
{
    #if TEST_FLAG
        TestProgram();
    #else
        MainProgram();
    #endif

    #if PAUSE_FLAG
        system("pause");
    #endif

    return 0;
}

void MainProgram()
{
    Map map;
    InputMap(&map);
    DrawMap(&map);
    PrintMap(&map);
}

void InputMap(Map *map)
{
    int i, j;
    scanf("%d %d", &(map->row), &(map->col));
    for (i = 0; i < map->row; i++)
    {
        for (j = 0; j < map->col; j++)
        {
            scanf("%d", &(map->map[i][j]));
        }
    }
}

void DrawLine(Map *map, int rIndex, int startPoint, int endPoint)
{
    int j;
    for (j = startPoint; j < endPoint; j++)
    {
        map->map[rIndex][j] = 1;
    }
}

void DrawMap(Map *map)
{
    int i, j;
    for (i = 0; i < map->row; i++)
    {
        int drawPoint = -1;
        for (j = 0; j < map->col; j++)
        {
            if (map->map[i][j] == 1)
            {
                if (drawPoint == -1)
                    drawPoint = j;
                else
                {
                    DrawLine(map, i, drawPoint, j);
                    drawPoint = -1;
                }
            }
        }
    }
}

void PrintMap(Map *map)
{
    int i, j;
    for (i = 0; i < map->row; i++)
    {
        for (j = 0; j < map->col; j++)
        {
            printf("%d ", map->map[i][j]);
        }
        printf("\n");
    }
}

#if TEST_FLAG
int AssertInteger2DArrayEquals(int except[MAP_SIZE][MAP_SIZE], int active[MAP_SIZE][MAP_SIZE], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (except[i][j] != active[i][j])
                return 0;
        }
    }
    return 1;
}

// Test Region
int TestCase1()
{
    Map map = { 3, 4, { {0, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 0, 0} } };
    int except[MAP_SIZE][MAP_SIZE] = { {0, 1, 0, 0}, {1, 1, 1, 1}, {0, 1, 0, 0} };
    DrawMap(&map);
    return AssertInteger2DArrayEquals(except, map.map, map.row, map.col);
}
int TestCase2()
{
    Map map = { 4, 7, { {0, 1, 1, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0} } };
    int except[MAP_SIZE][MAP_SIZE] = { {0, 1, 1, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 1}, {1, 1, 1, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0} };
    DrawMap(&map);
    return AssertInteger2DArrayEquals(except, map.map, map.row, map.col);
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif