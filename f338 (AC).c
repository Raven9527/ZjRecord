#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif
typedef struct Point_s
{
    int x;
    int y;
}Point;
typedef struct Archer_s
{
    Point point;
    int level;
    int r;
}Archer;
typedef struct Sun_s
{
    Point point;
    int level;
}Sun;

void MainProgram();
void InputArcherInfo(Archer*); // 輸入射手資訊
void InputSunInfo(Sun*); // 輸入太陽資訊
int IsArcherShotSun(Archer*, Sun*); // 射手可以射下太陽
int ComputePointDistance(Point, Point); // 計算兩點的距離

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
    int i, n, fallSun = 0;
    Archer archer;
    Sun sun;
    InputArcherInfo(&archer);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        InputSunInfo(&sun);
        fallSun += IsArcherShotSun(&archer, &sun);
    }
    printf("%d\n", fallSun);
}

void InputArcherInfo(Archer *archer)
{
    scanf("%d %d %d %d", &(archer->point.x), &(archer->point.y), &(archer->level), &(archer->r));
}

void InputSunInfo(Sun *sun)
{
    scanf("%d %d %d", &(sun->point.x), &(sun->point.y), &(sun->level));
}

int IsArcherShotSun(Archer *archer, Sun *sun)
{
    if (sun->level > archer->level)
        return 0;
    return ComputePointDistance(archer->point, sun->point) <= (archer->r * archer->r);
}

int ComputePointDistance(Point p1, Point p2)
{
    return ((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y));
}

#if TEST_FLAG
// Test Region
int TestCase1()
{
    Archer archer = { {0, 0}, 2, 1000 };
    Sun sun1 = { {500, 0 }, 4 };
    int ans = 0;
    ans += IsArcherShotSun(&archer, &sun1);
    AssertIntegerEquals(0, ans);
}
int TestCase2()
{
    Archer archer = { {10, 10}, 5, 50 };
    Sun sun1 = { {20, 10 }, 1 };
    Sun sun2 = { {-100, 50 }, 2 };
    Sun sun3 = { {0, 0}, 3 };
    int ans = 0;
    ans += IsArcherShotSun(&archer, &sun1);
    ans += IsArcherShotSun(&archer, &sun2);
    ans += IsArcherShotSun(&archer, &sun3);
    AssertIntegerEquals(2, ans);
}
int TestCase3()
{
    Archer archer = { {100, 60}, 1, 100 };
    Sun sun1 = { {100, 100 }, 1 };
    Sun sun2 = { {500, 60 }, 1 };
    Sun sun3 = { {50, -20 }, 1 };
    Sun sun4 = { {200, 60 }, 1 };
    Sun sun5 = { {120, 70 }, 3 };
    int ans = 0;
    ans += IsArcherShotSun(&archer, &sun1);
    ans += IsArcherShotSun(&archer, &sun2);
    ans += IsArcherShotSun(&archer, &sun3);
    ans += IsArcherShotSun(&archer, &sun4);
    ans += IsArcherShotSun(&archer, &sun5);
    AssertIntegerEquals(3, ans);
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