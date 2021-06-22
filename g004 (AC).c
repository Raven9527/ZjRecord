#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define MAP_SIZE 12

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Map_s
{
    int row, col;
    int map[MAP_SIZE][MAP_SIZE];
}Map;
void MainProgram();
void InputMap(Map*);
void CalculateMapPoptlarity(Map*); // 計算Map的熱門值
int GetMapPointPopularity(Map*, int, int); // 得到Map中指定的點的熱門度
int GetMapAreaCount(Map*, int, int); // 得到Map中指定的點的相鄰區域數
int GetMapAreaPopularitySum(Map*, int, int); // 得到Map中指定的點的相鄰區域熱門度總合
int IsMapPointNull(Map*, int, int); // Map中指定的點是不是空的 (超出邊界 or 新商店
void RefreshMap(Map*); // Map重新整理
void PrintMap(Map*); // 輸出Map

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
    CalculateMapPoptlarity(&map);
    PrintMap(&map);
}

void InputMap(Map *map)
{
    int row, col, k, i, j;
    scanf("%d %d", &row, &col);
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &k);
            map->map[i][j] = k;
        }
    }
    map->row = row;
    map->col = col;
}

// 計算Map的熱門值:
// foreach 整個map，遇到0 → 計算該區域的熱門值，並變成負數 (負數代表該商店是新商店)
// 跑完整張圖後，將負數的值變成正數
void CalculateMapPoptlarity(Map *map)
{
    int i, j;
    for (i = 0; i < map->row; i++)
    {
        for (j = 0; j < map->col; j++)
        {
            if (map->map[i][j] == 0)
            {
                map->map[i][j] = -GetMapAreaPopularitySum(map, i, j);
            }
        }
    }

    RefreshMap(map);
}

int GetMapPointPopularity(Map *map, int r, int c)
{
    int pop = map->map[r][c];
    return (pop >= 0) ? pop : -pop;
}

int GetMapAreaCount(Map *map, int r, int c)
{
    int count = 0;
    count += IsMapPointNull(map, r, c - 1) ? 0 : 1;
    count += IsMapPointNull(map, r, c + 1) ? 0 : 1;
    count += IsMapPointNull(map, r - 1, c) ? 0 : 1;
    count += IsMapPointNull(map, r + 1, c) ? 0 : 1;

    if (count == 0)
        return 1;
    return count;
}

int GetMapAreaPopularitySum(Map *map, int r, int c)
{
    int count = GetMapAreaCount(map, r, c);
    int sum = 0;
    sum += (IsMapPointNull(map, r - 1, c) ? 0 : map->map[r - 1][c]);
    sum += (IsMapPointNull(map, r + 1, c) ? 0 : map->map[r + 1][c]);
    sum += (IsMapPointNull(map, r, c - 1) ? 0 : map->map[r][c - 1]);
    sum += (IsMapPointNull(map, r, c + 1) ? 0 : map->map[r][c + 1]);
    return sum / count;
}

int IsMapPointNull(Map *map, int r, int c)
{
    if (r < 0 || c < 0 || r >= map->row || c >= map->col)
        return 1;
    else if (map->map[r][c] <= 0)
        return 1;
    else
        return 0;
}

void RefreshMap(Map *map)
{
    int i, j;
    for (i = 0; i < map->row; i++)
    {
        for (j = 0; j < map->col; j++)
        {
            map->map[i][j] = GetMapPointPopularity(map, i, j);
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
int Compare2DArrayEquals(int except[MAP_SIZE][MAP_SIZE], int eRow, int eCol, int acitve[MAP_SIZE][MAP_SIZE], int aRow, int aCol)
{
    if (eRow != aRow || eCol != aCol)
        return 0;
    
    int i, j;
    for (i = 0; i < eRow; i++)
    {
        if (AssertIntegerArrayEquals(except[i], eCol, acitve[i], aCol) == 0)
            return 0;
    }
    return 1;
}
int TestCase(Map input, Map except)
{
    CalculateMapPoptlarity(&input);
    //PrintMap(&input);
    return Compare2DArrayEquals(input.map, input.row, input.col, except.map, except.row, except.col);
}
// Test Region 
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    Map testData1 = {3, 3, { {2, 0, 6}, {6, 8, 4}, {2, 2, 6} }};
    Map exceptData1 = {3, 3, { {2, 5, 6}, {6, 8, 4}, {2, 2, 6} }};

    Map testData2 = {3, 4, { {0, 1, 3, 9}, {0, 12, 14, 79}, {1, 123, 12, 12} }};
    Map exceptData2 = {3, 4, { {1, 1, 3, 9}, {6, 12, 14, 79}, {1, 123, 12, 12} } };

    Map testData3 = {5, 5, { {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {5, 9, 5, 5, 9}, {9, 6, 5, 5, 9} }};
    Map exceptData3 = {5, 5, { {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 5, 5, 5, 9}, {5, 9, 5, 5, 9}, {9, 6, 5, 5, 9} }};
    
    failCount += OutputTest(1, TestCase(testData1, exceptData1));
    failCount += OutputTest(2, TestCase(testData2, exceptData2));
    failCount += OutputTest(3, TestCase(testData3, exceptData3));
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif