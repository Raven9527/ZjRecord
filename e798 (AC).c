#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 24

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Map_s
{
    int map[SIZE][SIZE];
    int size;
}Map;
void MainProgram();
void InputDataMap(Map*);
void CreateMaxPoolingMatrix(Map*, Map*); // 創建最大池化矩陣 (要創建的矩陣, 資料矩陣)
void PrintMap(Map*); // 輸出Map
int GetAreaMax(int[2][2]); // 得到2*2矩形中的最大值
int GetMax(int, int); // 回傳兩者之間的最大值

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
    Map dataMap;
    Map maxPollingMap;
    InputDataMap(&dataMap);
    CreateMaxPoolingMatrix(&maxPollingMap, &dataMap);
    PrintMap(&maxPollingMap);
}

void InputDataMap(Map *map)
{
    scanf("%d", &(map->size));
    int i, j;
    for (i = 0; i < map->size; i++)
    {
        for (j = 0; j < map->size; j++)
        {
            scanf("%d", &(map->map[i][j]));
        }
    }
}

void CreateMaxPoolingMatrix(Map *maxPolling, Map *dataMap)
{
    maxPolling->size = dataMap->size / 2;
    int tempMap[2][2] = {0};
    int i, j;
    for (i = 0; i < maxPolling->size; i++)
    {
        for (j = 0; j < maxPolling->size; j++)
        {
            tempMap[0][0] = dataMap->map[i * 2][j * 2];
            tempMap[0][1] = dataMap->map[i * 2][j * 2 + 1];
            tempMap[1][0] = dataMap->map[i * 2 + 1][j * 2];
            tempMap[1][1] = dataMap->map[i * 2 + 1][j * 2 + 1];
            maxPolling->map[i][j] = GetAreaMax(tempMap);
        }
    }
}

void PrintMap(Map *map)
{
    int i, j;
    for (i = 0; i < map->size; i++)
    {
        for (j = 0; j < map->size; j++)
        {
            printf("%d ", map->map[i][j]);
        }
        printf("\n");
    }
}

int GetAreaMax(int map[2][2])
{
    return GetMax( GetMax(map[0][0], map[0][1]), GetMax(map[1][0], map[1][1]) );
}

int GetMax(int a, int b)
{
    return a >= b ? a : b;
}

#if TEST_FLAG
// Test Region
int AssertInteger2DArrayEquals(int except[SIZE][SIZE], int active[SIZE][SIZE], int r, int c)
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
int TestCase1()
{
    Map dataMap = {{ {12, 20, 30, 0}, {8, 12, 2, 0}, {34, 70, 37, 4}, {112, 100, 25, 12} }, 4};
    Map ansMap;
    int except[SIZE][SIZE] = { {20, 30}, {112, 37} };
    CreateMaxPoolingMatrix(&ansMap, &dataMap);
    return AssertInteger2DArrayEquals(except, ansMap.map, 2, 2);
}
int TestCase2()
{
    Map dataMap = {{ {10, 2, 0, 12, 1, 3}, {21, 0, 13, 2, 2, 0}, {0, 0, 0, 10, 0, 0}, {19, 2, 0, 13, 61, 1}, {0, 1, 32, 3, 0, 2}, {9, 2, 0, 31, 11, 0} }, 6};
    Map ansMap;
    int except[SIZE][SIZE] = { {21, 13, 3}, {19, 13, 61}, {9, 32, 11} };
    CreateMaxPoolingMatrix(&ansMap, &dataMap);
    return AssertInteger2DArrayEquals(except, ansMap.map, 3, 3);
}
int TestCase3()
{
    Map dataMap = {{ {-2147483648, -1, 2, 3}, {-5, -6, 2147483647, -543}, {6, 7, 8, 9}, {9, 8, 7, 6} }, 4};
    Map ansMap;
    int except[SIZE][SIZE] = { {-1, 2147483647}, {9, 9} };
    CreateMaxPoolingMatrix(&ansMap, &dataMap);
    return AssertInteger2DArrayEquals(except, ansMap.map, 2, 2);
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());
    failCount += OutputTest(caseCount++, TestCase3());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif