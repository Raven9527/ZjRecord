#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10001
typedef struct
{
    int first, end;
}Ln;
Ln line[MAX];
int cmp(const void *a , const void *b)
{
    Ln *c = (Ln *)a;
    Ln *d = (Ln *)b;
    if (c->first == d->first)
        return c->end > d->end;
    return c->first > d->first;
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

        qsort(line, n, sizeof(line[0]), cmp);

        int line_left = line[0].first, line_right = line[0].end;
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

        printf("%d\n", line_right - line_left - SubSum);

    }
    return 0;
}