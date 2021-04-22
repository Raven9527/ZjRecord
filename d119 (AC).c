#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50005
const int coins[10] = {1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
unsigned long long int dp[15][MAX];
void CreateDPTable()
{
    int i, j;
    // initialize
    for (i = 0; i <= 10; i++)
    {
        dp[i][0] = 1;
    }
    for (i = 0; i < MAX; i++)
    {
        dp[0][i] = 0;
    }

    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j < MAX; j++)
        {
            if (j - coins[i - 1] >= 0) // 裝得進去
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else // 不裝進去
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for (i = 1; i <= 10; i++)
    // {
    //     for (j = 1; j <= 10; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

}
unsigned long long int GetCombinationNumber(int money)
{
    return dp[10][money] - 1;
}
int ConvertInputToNumber(char inp[])
{
    int s = strlen(inp);
    int i;
    int num = 0;
    int sum = 0;
    for (i = 0; i <= s; i++)
    {
        if (inp[i] == ' ' || inp[i] == '\0')
        {
            sum += num;
            num = 0;
        }
        else
        {
            num *= 10;
            num += inp[i] - 48;
        }
    }
    return sum;
}
int main()
{
    CreateDPTable();
    char inp[1024];
    while(gets(inp) != NULL)
    {
        if (inp[0] == '0' && inp[1] == '\0')
            break;
        int money = ConvertInputToNumber(inp);
        printf("%llu\n", GetCombinationNumber(money));
    }
    return 0;
}