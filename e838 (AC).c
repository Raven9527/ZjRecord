#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 105

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Map_s
{
    char map[SIZE][SIZE];
    int size;
}Map;
void MainProgram();
void InputMap(Map*); // 輸入
void InitializeMap(Map*, int); // 初始化Map
void FillBoomMap(Map*, Map*); // 填上會爆炸的地方
void CrossBoom(int, int, Map*); // 讓Map的炸彈十字爆炸
void PrintMap(Map*); // 輸出
int IsPointBomb(Map*, int, int); // 這個點是不是炸彈

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
    Map testDataMap;
    Map safeMap;
    InputMap(&testDataMap);
    InitializeMap(&safeMap, testDataMap.size);
    FillBoomMap(&testDataMap, &safeMap);
    PrintMap(&safeMap);
}

void InputMap(Map *map)
{
    int i;
    scanf("%d", &(map->size));
    for (i = 0; i < map->size; i++)
    {
        scanf("%s", (map->map[i]));
    }
}

void InitializeMap(Map *map, int size)
{
    int i, j;
    map->size = size;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            map->map[i][j] = '0';
        }
    }
}

void FillBoomMap(Map *dataMap, Map *safeMap)
{
    int i, j;
    for (i = 0; i < dataMap->size; i++)
    {
        for (j = 0; j < dataMap->size; j++)
        {
            if (IsPointBomb(dataMap, i, j))
            {
                CrossBoom(i, j, safeMap);
            }
        }
    }
}
void CrossBoom(int r, int c, Map *map)
{
    int i;
    for (i = 0; i < map->size; i++)
    {
        map->map[r][i] = '*';
        map->map[i][c] = '*';
    }
}

int IsPointBomb(Map *map, int r, int c)
{
    return (map->map[r][c] == '*');
}

void PrintMap(Map *map)
{
    int i;
    for (i = 0; i < map->size; i++)
        printf("%s\n", map->map[i]);
}

#if TEST_FLAG
// Test Region
int AssertStringArrayEquals(char except[SIZE][SIZE], char acitve[SIZE][SIZE], int eRow, int eCol)
{
        int i, j;
    for (i = 0; i < eRow; i++)
    {
        for (j = 0; j < eCol; j++)
            if (AssertIntegerEquals(except[i][j], acitve[i][j]) == 0)
                return 0;
    }
    return 1;
}
int TestCase1()
{
    Map dataMap = { { {'0', '0', '0', '0'}, {'0', '*', '0', '0'}, {'0', '0', '0', '0'}, {'0', '0', '0', '0'} }, 4 };
    Map ansMap;
    char except[SIZE][SIZE] = { "0*00", "****", "0*00", "0*00" };
    InitializeMap(&ansMap, 4);
    FillBoomMap(&dataMap, &ansMap);
    return AssertStringArrayEquals(except, ansMap.map, ansMap.size, ansMap.size);
}
int TestCase2()
{
    Map dataMap;
    Map ansMap;
    char except[SIZE][SIZE] = { "*******", "****000", "*******", "*******", "****000", "*******", "****000" };
    InitializeMap(&dataMap, 7);
    InitializeMap(&ansMap, 7);
    dataMap.map[0][1] = '*';
    dataMap.map[2][3] = '*';
    dataMap.map[3][0] = '*';
    dataMap.map[3][2] = '*';
    dataMap.map[3][3] = '*';
    dataMap.map[5][1] = '*';
    FillBoomMap(&dataMap, &ansMap);
    return AssertStringArrayEquals(except, ansMap.map, ansMap.size, ansMap.size);
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