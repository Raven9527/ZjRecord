#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define MAP_SIZE 105

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
typedef struct Map_s
{
    int row;
    int col;
    int map[MAP_SIZE][MAP_SIZE];
}Map;
void InputMap(Map*); // 輸入
int GetMapValue(Map*, int, int); // 得到 Map指定的值 (超出邊界回傳0)
int IsValueDiffent(int, int); // 比較兩個值是否不相等
int IsFlagEliminate(Map*, int, int); // 這個Falg是不是要被淘汰了
int GetEliminatePeopleCount(Map*); // 回傳淘汰的總人數

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
    printf("%d\n", GetEliminatePeopleCount(&map));
}

void InputMap(Map *map)
{
    scanf("%d %d", &(map->row), &(map->col));
    int i, j;
    for (i = 0; i < map->row; i++)
    {
        for (j = 0; j < map->col; j++)
        {
            scanf("%d", &(map->map[i][j]));
        }
    }
}

int IsValueDiffent(int currentValue, int mapValue)
{
    return (mapValue == 0 || currentValue != mapValue);
}

int GetMapValue(Map *map, int r, int c)
{
    if (r < 0 && c < 0 && r >= map->row && c >= map->col)
        return 0;
    return map->map[r][c];
}

int IsFlagEliminate(Map *map, int i, int j)
{
    int currentValue = map->map[i][j];
    int flag1 = IsValueDiffent(currentValue, GetMapValue(map, i - 1, j - 1)) && IsValueDiffent(currentValue, GetMapValue(map, i - 1, j + 1));
    int flag2 = IsValueDiffent(currentValue, GetMapValue(map, i + 1, j - 1)) && IsValueDiffent(currentValue, GetMapValue(map, i + 1, j + 1));
    int flag3 = IsValueDiffent(currentValue, GetMapValue(map, i, j - 1)) && IsValueDiffent(currentValue, GetMapValue(map, i, j + 1));
    int flag4 = IsValueDiffent(currentValue, GetMapValue(map, i + 1, j)) && IsValueDiffent(currentValue, GetMapValue(map, i - 1, j));
    return flag1 && flag2 && flag3 && flag4;
}

int GetEliminatePeopleCount(Map *map)
{
    int sum = 0;
    int i, j;
    for (i = 0; i < map->row; i++)
    {
        for (j = 0; j < map->col; j++)
        {
            int currentValue = map->map[i][j];
            if (IsValueDiffent(currentValue, GetMapValue(map, i - 1, j - 1)) && IsValueDiffent(currentValue, GetMapValue(map, i - 1, j + 1)) && 
                IsValueDiffent(currentValue, GetMapValue(map, i + 1, j - 1)) && IsValueDiffent(currentValue, GetMapValue(map, i + 1, j + 1)) &&
                IsValueDiffent(currentValue, GetMapValue(map, i, j - 1)) && IsValueDiffent(currentValue, GetMapValue(map, i, j + 1)) &&
                IsValueDiffent(currentValue, GetMapValue(map, i + 1, j)) && IsValueDiffent(currentValue, GetMapValue(map, i - 1, j)))
            {
                sum ++;
            }
        }
    }
    return sum;
}

#if TEST_FLAG
int TestFlagEliminate()
{
    // Map map1 = {3, 3, { {2, 2, 2}, {2, 2, 2}, {2, 2, 2} } };
    // int sum1 = GetEliminatePeopleCount(&map1);
    // printf("%d\n", sum1);
    // if (AssertIntegerEquals(0, sum1) == 0)
    //     return 0;
    
    Map map2 = {3, 3, { {2, 2, 2}, {2, 1, 2}, {2, 2, 2} } };
    if (IsFlagEliminate(&map2, 1, 1) == 0)
        return 0;

    Map map3 = {3, 3, { {1, 2, 2}, {2, 2, 2}, {2, 2, 2} } };
    if (IsFlagEliminate(&map3, 0, 0) == 0)
        return 0;
    
    Map map4 = {3, 3, { {2, 1, 2}, {2, 2, 2}, {2, 2, 2} } };
    if (IsFlagEliminate(&map4, 0, 1) == 0)
        return 0;

    Map map5 = {3, 3, { {2, 2, 1}, {2, 2, 2}, {2, 2, 2} } };
    if (IsFlagEliminate(&map5, 0, 2) == 0)
        return 0;

    Map map6 = {3, 3, { {2, 2, 2}, {1, 2, 2}, {2, 2, 2} } };
    if (IsFlagEliminate(&map6, 1, 0) == 0)
        return 0;

    Map map7 = {3, 3, { {2, 2, 2}, {2, 2, 1}, {2, 2, 2} } };
    if (IsFlagEliminate(&map7, 1, 2) == 0)
        return 0;

    Map map8 = {3, 3, { {2, 2, 2}, {2, 2, 2}, {1, 2, 2} } };
    if (IsFlagEliminate(&map8, 2, 0) == 0)
        return 0;

    Map map9 = {3, 3, { {2, 2, 2}, {2, 2, 2}, {2, 1, 2} } };
    if (IsFlagEliminate(&map9, 2, 1) == 0)
        return 0;

    Map map10 = {3, 3, { {2, 2, 2}, {2, 2, 2}, {2, 2, 1} } };
    if (IsFlagEliminate(&map10, 2, 2) == 0)
        return 0;

    return 1;
}
int TestCase2()
{
    Map map = {3, 4, { {2, 2, 2, 2}, {2, 1, 2, 1}, {2, 2, 2, 2} } };
    int sum = GetEliminatePeopleCount(&map);
    return AssertIntegerEquals(2, sum);
}
int TestCase3()
{
    Map map = {8, 8, { {2, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 2, 2, 2, 1, 1}, {1, 2, 2, 2, 1, 2, 1, 1}, {1, 2, 2, 2, 2, 2, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 2, 1, 1, 1, 2, 1}, {1, 1, 1, 1, 1, 2, 1, 1}, {2, 1, 1, 1, 1, 1, 1, 1} } };
    int sum = GetEliminatePeopleCount(&map);
    return AssertIntegerEquals(4, sum);
}
int TestCase4()
{
    Map map = {2, 7, { {2, 1, 2, 1, 2, 1, 2}, {1, 2, 1, 2, 1, 2, 1} } };
    int sum = GetEliminatePeopleCount(&map);
    return AssertIntegerEquals(0, sum);
}
// Test Region 
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestFlagEliminate());
    failCount += OutputTest(caseCount++, TestCase2());
    failCount += OutputTest(caseCount++, TestCase3());
    failCount += OutputTest(caseCount++, TestCase4());
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif