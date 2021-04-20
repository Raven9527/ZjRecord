#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 712
int main()
{
    int subMatches[MAX + MAX] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int i, j, n;
    scanf("%d", &n);
    n -= 4;
    int ans = 0;

    for (i = 10; i < MAX + MAX; i++)
    {
        subMatches[i] = subMatches[i / 10] + subMatches[i % 10];
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            int k = n;
            if (k - subMatches[i] - subMatches[j] - subMatches[i + j] == 0)
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}
