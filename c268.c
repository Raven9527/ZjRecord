#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int stage;
    scanf("%d", &stage);
    while(stage--)
    {
        int n, i, k;
        scanf("%d", &n);
        int max[3] = {0, 0, 0};
        int jj = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &k);
            jj += k;
            if(k > max[0])
            {
                max[2] = max[1];
                max[1] = max[0];
                max[0] = k;
            }
            else if(k > max[1])
            {
                max[2] = max[1];
                max[1] = k;
            }
            else if(k > max[2])
            {
                max[2] = k;
            }
        }
        if(stage == 0)
            printf("%d", jj);
        if(max[1] + max[2] > max[0])
            printf("YES\n");
        else
            printf("NO\n");
    }
    //system("pause");
    return 0;
}