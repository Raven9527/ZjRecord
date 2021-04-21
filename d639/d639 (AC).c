#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void TestPrint(int A[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
void CopyMatrix(int a[3][3], int b[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
// 3*3矩陣乘法 (結果存為a)
void MatrixMulti(int a[3][3], int b[3][3])
{
    int i, j, k;
    int map[3][3] = {0};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int temp = 0;
            for (k = 0; k < 3; k++)
            {
                temp += a[i][k] * b[k][j];
                map[i][j] = temp % 10007;
            }
        }
    }

    CopyMatrix(a, map);
}
// 矩陣快速冪
void FastMatrixPow(int count, int p[3][3], int MatrixA[3][3], int stackMap[3][3])
{
    int binary[40] = {0};
    int i, bSize = 0;
    while(count > 0)
    {
        binary[bSize++] = count % 2;
        count /= 2;
    }

    for (i = 0; i < bSize; i++)
    {
        if (binary[i] == 1)
        {
            MatrixMulti(p, stackMap);
        }
        MatrixMulti(stackMap, stackMap);
    }
}
void PrintAns(int ans[3][3], int n)
{
    if (n <= 3)
    {
        printf("1\n");
    }
    else
    {
        printf("%d\n", ans[0][0]);
    }
}
int main()
{
    // 原始A
    int MatrixA[3][3] = { {1, 1, 1},
                          {1, 0, 0},
                          {0, 1, 0}};
    // 單位矩陣，最後算成A^n
    int p[3][3] =  { {1, 0, 0},
                    {0, 1, 0},
                    {0, 0, 1}};
    // For 快速冪 平方堆疊
    int stackMap[3][3] =  { {1, 1, 1},
                            {1, 0, 0},
                            {0, 1, 0}};
    /* base = 1 方便運算補成 3*3矩陣
              1
              1
    */
    int base[3][3] = { {1, 0, 0}, {1, 0 ,0}, {1, 0, 0} };
    int n;
    scanf("%d", &n);
    FastMatrixPow(n - 3, p, MatrixA, stackMap); // 快速冪算出A^n
    // TestPrint(p);
    MatrixMulti(p, base); // A^n * base -> 結果傳回給p作為答案
    // TestPrint(p);
    PrintAns(p, n); //  輸出答案
    //TestPrint(p);
    //system("pause");
    return 0;
}