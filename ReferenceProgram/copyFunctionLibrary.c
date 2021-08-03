// 回傳兩者之間的最大值
int GetMax(int a, int b)
{
    return a >= b ? a : b;
}

// 回傳兩者之間的最小值
int GetMin(int a, int b)
{
    return a <= b ? a : b;
}

// 輸出二維陣列
void PrintMap(int map[SIZE][SIZE], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}