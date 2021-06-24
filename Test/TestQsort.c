#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct CountableChar_s
{
    char c;
    int count;
}CountableChar;

// 懶人包 → 小到大
int cmp(const void *a, const void *b)
{
   return ( *(int*)a - *(int*)b );
}

// return 1: a 在 b後面
// reutnr -1: a 在 b前面
// return 0: 無關
int cmp(const void *a, const void *b)
{
    CountableChar *c = (CountableChar *)a;
    CountableChar *d = (CountableChar *)b;
    return d->count - c->count;
    // if (c->count != d->count)
    //     return c->count < d->count;
    // else
    //     return c->c > d->c;
}

void Sort(CountableChar charArray[])
{
    int n = 100;
    qsort(charArray, n, sizeof(charArray[0]), cmp);
}