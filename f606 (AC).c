#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 55

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Plan_s
{
    int serverOfCity[SIZE];
}Plan;
typedef struct Map_s
{
    int map[SIZE][SIZE];
    int row;
    int col;
}Map;
void MainProgram();
void InputDataMap(Map*); // 輸入流量Map
void InputPlans(Plan[], int, int); // 輸入方案群
int GetMinCostOfAllPlan(Map*, Plan[], int); // 從所有方案中計算最小花費
int GetPlanCost(Map*, Plan*); // 計算方案的花費
int GetCityCost(int[], int, int); // 計算城市傳送到各個城市的花費
int ComputeDataCost(int, int, int); // 計算流量的花費 (起點, 終點, 流量大小)
int GetMin(int, int); // 得到最小
void SetServerOnCity(Map*, int[], int, int); // 放置伺服器在城市上 (城市對城市的流量Map, 該伺服器的流量Array, 該伺服器編號, 放置的城市編號)

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
    int serverCount, cityCount, planCount;
    scanf("%d %d %d", &serverCount, &cityCount, &planCount);
    Map dataMap = { {0}, serverCount, cityCount};
    Plan plans[SIZE];
    InputDataMap(&dataMap);
    InputPlans(plans, planCount, serverCount);
    printf("%d", GetMinCostOfAllPlan(&dataMap, plans, planCount));
}

void InputDataMap(Map *dataMap)
{
    int i, j;
    for (i = 0; i < dataMap->row; i++)
    {
        for (j = 0; j < dataMap->col; j++)
        {
            scanf("%d", &(dataMap->map[i][j]));
        }
    }
}

void InputPlans(Plan plans[], int planCount, int serverCount)
{
    int i, j;
    for (i = 0; i < planCount; i++)
    {
        for (j = 0; j < serverCount; j++)
        {
            scanf("%d", &plans[i].serverOfCity[j]);
        }
    }
}

int GetMinCostOfAllPlan(Map *data, Plan plans[], int planCount)
{
    int i, j;
    int minCost = 2147483647;
    for (i = 0; i < planCount; i++)
    {
        minCost = GetMin(minCost, GetPlanCost(data, &plans[i]));
    }
    return minCost;
}

int GetPlanCost(Map *data, Plan *plan)
{
    int i, j, k;
    int cost = 0, planCount = data->row, cityCount = data->col;
    Map cityDataMap = { {0}, data->row, data->col};
    for (k = 0; k < planCount; k++)
    {
        SetServerOnCity(&cityDataMap, data->map[k], k, plan->serverOfCity[k]);
    }
    // for (i = 0; i < cityCount; i++)
    // {
    //     for (j = 0; j < cityCount; j++)
    //     {
    //         printf("%d ", cityDataMap.map[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("End Line--\n\n");
    for (k = 0; k < cityCount; k++)
    {
        cost += GetCityCost(cityDataMap.map[k], cityCount, k);
    }
    return cost;
}

int GetCityCost(int data[], int cityCount, int currentCity)
{
    int cityIndex;
    int cost = 0;
    for (cityIndex = 0; cityIndex < cityCount; cityIndex++)
    {
        cost += ComputeDataCost(currentCity, cityIndex, data[cityIndex]);
    }
    return cost;
}

int ComputeDataCost(int start, int goal, int data)
{
    if (start == goal)
        return data;
    else if (data <= 1000)
        return data * 3;
    else
        return 1000 * 3 + ((data - 1000) * 2);
}

int GetMin(int a, int b)
{
    return a <= b ? a : b;
}

void SetServerOnCity(Map *cityDataMap, int serverData[], int server, int city)
{
    int count = cityDataMap->col;
    int i;
    for (i = 0; i < count; i++)
    {
        cityDataMap->map[city][i] += serverData[i];
    }
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    Map data = { {{30, 23, 23}, {5, 25, 3}}, 2, 3 };
    Plan plan[SIZE] = { {0, 0}, {0, 1}, {0, 2} };
    int ans = GetMinCostOfAllPlan(&data, plan, 3);
    printf("ans = %d\n", ans);
    return AssertIntegerEquals(217, ans);
}
int TestCase2()
{
    Map data = { { {500, 400, 800, 200}, {500, 400, 100, 600}, {450, 420, 800, 790} }, 3, 4 };
    Plan plan[SIZE] = { {0, 0, 0, }, {0, 1, 2}, {0, 2, 2}, {2, 1, 2}, {1, 1, 1} };
    int ans = GetMinCostOfAllPlan(&data, plan, 5);
    printf("ans = %d\n", ans);
    return AssertIntegerEquals(13470, ans);
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