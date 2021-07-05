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
typedef struct ClassRoom_s
{
    int row;
    int col;
    int seat[MAP_SIZE][MAP_SIZE];
}ClassRoom;
void Input(ClassRoom*, int*); // 輸入
void InitializeClassRoom(ClassRoom*); // 初始化座位
void DaiFongChui(ClassRoom*, int); // 座位大風吹
void SeatMoveRight(ClassRoom*); // 座位右移
void SeatMoveBack(ClassRoom*); // 座位左移
void PrintAns(ClassRoom*);

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
    ClassRoom classRoom;
    int week;
    Input(&classRoom, &week);
    InitializeClassRoom(&classRoom);
    DaiFongChui(&classRoom, week);
    PrintAns(&classRoom);
}

void Input(ClassRoom *classRoom, int *w)
{
    int r, c, week;
    scanf("%d %d %d", &r, &c, &week);
    classRoom->row = r;
    classRoom->col = c;
    *w = week;
}

void InitializeClassRoom(ClassRoom *classRoom)
{
    int count = 1;
    int i, j;
    for (i = 0; i < classRoom->row; i++)
    {
        for (j = 0; j < classRoom->col; j++)
        {
            classRoom->seat[i][j] = count++;
        }
    }
}

void DaiFongChui(ClassRoom *classRoom, int week)
{
    int i;
    int right = 0, back = 0;
    // 2 > 1 0
    // 3 > 1 1
    // 4 > 2 1
    // 5 > 2 2
    right = (week / 2) % classRoom->col;
    back = ((week - 1) / 2) % classRoom->row;

    for (i = 0; i < right; i++)
        SeatMoveRight(classRoom);
    
    for (i = 0; i < back; i++)
        SeatMoveBack(classRoom);
}

void SeatMoveRight(ClassRoom *classRoom)
{
    int i, j;
    for (i = 0; i < classRoom->row; i++)
    {
        int last = classRoom->seat[i][classRoom->col - 1];
        for (j = classRoom->col - 1; j > 0; j--)
        {
            classRoom->seat[i][j] = classRoom->seat[i][j - 1];
        }
        classRoom->seat[i][0] = last;
    }
}

void SeatMoveBack(ClassRoom *classRoom)
{
    int i, j;
    for (j = 0; j < classRoom->col; j++)
    {
        int last = classRoom->seat[classRoom->row - 1][j];
        for (i = classRoom->row - 1; i > 0; i--)
        {
            classRoom->seat[i][j] = classRoom->seat[i - 1][j];
        }
        classRoom->seat[0][j] = last;
    }
}

void PrintAns(ClassRoom *classRoom)
{
    int i, j;
    for (i = 0; i < classRoom->row; i++)
    {
        for (j = 0; j < classRoom->col; j++)
        {
            printf("%d ", classRoom->seat[i][j]);
        }
        printf("\n");
    }

}

#if TEST_FLAG
void Print(int print[MAP_SIZE][MAP_SIZE], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", print[i][j]);
        }
        printf("\n");
    }
}
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
int TestSeatMoveRight()
{
    int except[MAP_SIZE][MAP_SIZE] = { {4, 1, 2, 3}, {8, 5, 6, 7} };
    ClassRoom classRoom = {2, 4};
    InitializeClassRoom(&classRoom);
    SeatMoveRight(&classRoom);
    Print(classRoom.seat, 2, 4);
    return AssertInteger2DArrayEquals(except, classRoom.seat, 2, 4);
}

int TestSeatMoveBack()
{
    int except[MAP_SIZE][MAP_SIZE] = { {5, 6, 7, 8}, {1, 2, 3, 4} };
    ClassRoom classRoom = {2, 4};
    InitializeClassRoom(&classRoom);
    SeatMoveBack(&classRoom);
    Print(classRoom.seat, 2, 4);
    return AssertInteger2DArrayEquals(except, classRoom.seat, 2, 4);
}

int TestCase3()
{
    int except[MAP_SIZE][MAP_SIZE] = { {1, 2, 3, 4}, {5, 6, 7, 8} };
    ClassRoom classRoom = {2, 4};
    InitializeClassRoom(&classRoom);
    DaiFongChui(&classRoom, 1);
    return AssertInteger2DArrayEquals(except, classRoom.seat, 2, 4);
}

int TestCase4()
{
    int except[MAP_SIZE][MAP_SIZE] = { {19, 20, 16, 17, 18}, {4, 5, 1, 2, 3}, {9, 10, 6, 7, 8}, {14, 15, 11, 12, 13} };
    ClassRoom classRoom = {4, 5};
    InitializeClassRoom(&classRoom);
    DaiFongChui(&classRoom, 4);
    Print(classRoom.seat, 4, 5);
    return AssertInteger2DArrayEquals(except, classRoom.seat, 4, 5);
}

int TestCase5()
{
    int except[MAP_SIZE][MAP_SIZE] = { {2, 3, 1} };
    ClassRoom classRoom = {1, 3};
    InitializeClassRoom(&classRoom);
    DaiFongChui(&classRoom, 11);
    return AssertInteger2DArrayEquals(except, classRoom.seat, 1, 3);
}
// Test Region 
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestSeatMoveRight());
    failCount += OutputTest(caseCount++, TestSeatMoveBack());
    failCount += OutputTest(caseCount++, TestCase3());
    failCount += OutputTest(caseCount++, TestCase4());
    failCount += OutputTest(caseCount++, TestCase5());
    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif