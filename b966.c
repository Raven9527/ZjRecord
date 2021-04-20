#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10001
typedef struct
{
    int first, end;
}Line;
Line line[MAX];
void swap(int l , int r)
{
    int temp = line[l].first , temp2 = line[l].end;
    line[l].first = line[r].first;
    line[l].end = line[r].end;
    line[r].first = temp;
    line[r].end = temp2;
    return;
}
void QuickSort(int left , int right)
{
    if(left >= right)
        return;

    int pivot, pivotEnd, l, r;
    pivot = line[left].first;
    pivotEnd = line[left].end;
    l = left + 1;
    r = right;
    while(1)
    {
        while (l <= right && pivot >= line[l].first)
        {
            if(pivot > line[l].first)
                l++;
            if(pivot == line[l].first)
            {
                if(pivotEnd > line[l].end)
                {
                    l++;
                }
                break;
            }
        }

        while (r >= left && pivot <= line[r].first)
        {
            if(pivot < line[r].first)
                r--;
            if(pivot == line[r].first)
            {
                if(pivotEnd < line[r].end)
                {
                    r--;
                }
                break;
            }
        }

        if(l >= r)
            break;
        swap(l, r);
    }
    swap(left, r);

    QuickSort(left, r - 1);
    QuickSort(r + 1, right);
    return;
}
int main()
{
    int n, i;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            line[i].first = line[i].end = 0;

        for (i = 0; i < n;i++)
            scanf("%d %d", &line[i].first, &line[i].end);

        QuickSort(0, n - 1);

        /*printf("\n");
        */for (i = 0; i < n;i++)
        {
            printf("%d %d\n", line[i].first, line[i].end);
        }
        /*system("pause");*/

        /*int line_left = line[0].first, line_right = line[0].end;
        int SubSum = 0;

        for (i = 1; i < n;i++)
        {
            if(line[i].first <= line_right)
            {
                if (line[i].end > line_right)
                    line_right = line[i].end;
            }
            else
            {
                SubSum += line[i].first - line_right;
                line_right = line[i].end;
            }
        }

        printf("%d\n", line_right - line_left - SubSum);*/
        //system("pause");
    }
    return 0;
}