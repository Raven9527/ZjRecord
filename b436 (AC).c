#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 267
typedef struct pixel_s
{
    int r, g, b;
} pixel;
pixel map[MAX][MAX];
pixel newMap[MAX][MAX];
int w, h;
int BangAbs(int k)
{
    return k >= 0 ? k : -k;
}
int BangRound(double k)
{
    int r = k * 10;
    if (r % 10 >= 5)
        r += 10;
    return r / 10;
}
void testPrint(int array[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
}
int GetColor(int i, int j, char color)
{
    if(color == 'r')
        return map[i][j].r;
    if(color == 'g')
        return map[i][j].g;
    if(color == 'b')
        return map[i][j].b;
}
int GetMaskValue(int i, int j, char color)
{
    if(i < 0 && j < 0)
        return GetColor(0, 0, color);
    else if(i < 0 && j >= 0 && j < w)
        return GetColor(0, j, color);
    else if(i < 0 && j >= w)
        return GetColor(0, w - 1, color);
    else if(i >= 0 && i < h && j < 0)
        return GetColor(i, 0, color);
    else if(i >= 0 && i < h && j >= w)
        return GetColor(i, w - 1, color);
    else if(i >= h && j < 0)
        return GetColor(h - 1, 0, color);
    else if (i >= h && j >= 0 && j < w)
        return GetColor(h - 1, j, color);
    else if (i >= h && j >= w)
        return GetColor(h - 1, w - 1, color);
    else
        return GetColor(i, j, color);
}
void CreateMask(int mask[3][3], int i, int j, char color)
{
    mask[0][0] = GetMaskValue(i - 1, j - 1, color);
    mask[0][1] = GetMaskValue(i - 1, j, color);
    mask[0][2] = GetMaskValue(i - 1, j + 1, color);
    
    mask[1][0] = GetMaskValue(i, j - 1, color);
    mask[1][1] = GetMaskValue(i, j, color);
    mask[1][2] = GetMaskValue(i, j + 1, color);

    mask[2][0] = GetMaskValue(i + 1, j - 1, color);
    mask[2][1] = GetMaskValue(i + 1, j, color);
    mask[2][2] = GetMaskValue(i + 1, j + 1, color);
}
int ComputeNewColorValue(int mask[3][3], int dv[3][3])
{
    int i, j;
    int sum = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum += (mask[i][j] * dv[i][j]);
        }
    }
    return sum;
}
int GetNewColor(int i, int j, char color, int Straight[3][3], int Horizontal[3][3])
{
    int mask[3][3];
    CreateMask(mask, i, j, color);
    // testPrint(mask);
    int ns = (ComputeNewColorValue(mask, Straight));
    int nh = (ComputeNewColorValue(mask, Horizontal));
    int newColor = BangAbs(ns) + BangAbs(nh);
    return BangRound((double)newColor / 8.0);
}
int main()
{
    int i, j;
    int Straight[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int Horizontal[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    scanf("%d %d", &w, &h);
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
            scanf("%d %d %d", &map[i][j].r, &map[i][j].g, &map[i][j].b);
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            newMap[i][j].r = GetNewColor(i, j, 'r', Straight, Horizontal);
            newMap[i][j].g = GetNewColor(i, j, 'g', Straight, Horizontal);
            newMap[i][j].b = GetNewColor(i, j, 'b', Straight, Horizontal);
        }
    }

    printf("%d %d\n", w, h);
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
            printf("%d %d %d ", newMap[i][j].r, newMap[i][j].g, newMap[i][j].b);
        printf("\n");
    }

    // system("pause");
    return 0;
}
