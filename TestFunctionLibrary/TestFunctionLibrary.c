int OutputTest(int outputCase, int flag)
{
    if (flag)
        printf("case %d: pass\n", outputCase);
    else
        printf("case %d: fail\n", outputCase);
    return !flag;
}

// 比對是True
int AssertTrue(int flag)
{
    if (flag)
        return 1;
    else
        return 0;
}

// 比對兩個整數相等
int AssertIntegerEquals(int except, int active)
{
    if (except == active)
        return 1;
    else
        return 0;
}

// 比對兩個long long int 相等
int AssertLongLongIntegerEquals(long long except, long long active)
{
    if (except == active)
        return 1;
    else
        return 0;
}

// 比對 int array 相等
int AssertIntegerArrayEquals(int except[], int eSize, int acitve[], int aSize)
{
    if (eSize != aSize)
        return 0;

    int i;
    for (i = 0; i < eSize; i++)
    {
        if (AssertIntegerEquals(except[i], acitve[i]) == 0)
            return 0;
    }
    return 1;
}

// 比對 二維 int array相等
// int AssertInteger2DArrayEquals(int except[3][3], int eRow, int eCol, int acitve[3][3], int aRow, int aCol)
// {
//     if (eRow != aRow || eCol != aCol)
//         return 0;
    
//     int i, j;
//     for (i = 0; i < eRow; i++)
//     {
//         for (j = 0; j < eCol; j++)
//             if (AssertIntegerEquals(except[i][j], acitve[i][j]) == 0)
//                 return 0;
//     }
//     return 1;
// }

// int AssertInteger2DArrayEquals(int except[MAP_SIZE][MAP_SIZE], int active[MAP_SIZE][MAP_SIZE], int r, int c)
// {
//     int i, j;
//     for (i = 0; i < r; i++)
//     {
//         for (j = 0; j < c; j++)
//         {
//             if (except[i][j] != active[i][j])
//                 return 0;
//         }
//     }
//     return 1;
// }

int AssertStringEqual(char *except, char *active)
{
    return (strcmp(except, active) == 0);
}

// int AssertStringArrayEquals(char except[SIZE][SIZE], char acitve[SIZE][SIZE], int eRow, int eCol)
// {
//         int i, j;
//     for (i = 0; i < eRow; i++)
//     {
//         for (j = 0; j < eCol; j++)
//             if (AssertIntegerEquals(except[i][j], acitve[i][j]) == 0)
//                 return 0;
//     }
//     return 1;
// }

void PrintIntegerArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}