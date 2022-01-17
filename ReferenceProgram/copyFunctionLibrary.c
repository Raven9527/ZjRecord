#define SIZE 100
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

// 最大公因數
int gcd(int a,int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// 篩質數表
void CreatePrimeTable(int table[], int size)
{
    int i, j;
    for (i = 3; i <= size; i += 2)
    {
        table[i] = 1;
    }

    for (i = 3; i <= size; i += 2)
    {
        for (j = 2; i * j <= size; j++)
            table[i * j] = 0;
    }
}

// 線性質數表
void CreatePrimeArray(int table[], int tableSize, int primeArray[], int *primeArraySize)
{
    primeArray[0] = 2;
    *primeArraySize = 1;

    int i;
    for (i = 3; i <= tableSize; i += 2)
    {
        if (table[i])
            primeArray[(*primeArraySize)++] = i;
    }
}

// 四捨五入
// int RoundInt(double k, int step)
// {
//     int i, count = 1;
//     for (i = 0; i < step; i++)
//         count *= 10;
//     return (int)( ( (k * count) + 0.5) / count );
// }

// 四捨五入
int RoundInt(double k)
{
    return (int)( ( k + 0.5 ) );
}

int Abs(int n)
{
    return (n > 0) ? n : -n;
}