#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int data[5][5] = { {0, -1, 1, 1, -1},
                       {1, 0, -1, 1, -1},
                       {-1, 1, 0, -1, 1},
                       {-1, -1, 1, 0, 1},
                       {1, 1, -1, -1, 0}
                     };
    int n, na, nb, a = 0, b = 0;
    int i, j;
    int a_array[201], b_array[201];
    scanf("%d %d %d", &n, &na, &nb);

    for (i = 0; i < na; i++)
        scanf("%d", &a_array[i]);

    for (i = 0; i < nb; i++)
        scanf("%d", &b_array[i]);

    for (i = 0; i < n; i++)
    {
        int k = data[a_array[i % na]][b_array[i % nb]];
        if(k == 1)
            a++;
        else if(k == -1)
            b++;
    }
    printf("%d %d\n", a, b);
    system("pause");
    return 0;
}