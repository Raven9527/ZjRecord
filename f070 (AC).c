#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct number_rs
{
    int Number;
    int Remaining;
}RNumber;
void InputData(RNumber rNumber[3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        scanf("%d %d", &rNumber[i].Number, &rNumber[i].Remaining);
    }
}
int GetRemainingSolution(int number, int div, int r)
{
    int count = 1;
    while(number * count % div != r)
    {
        count++;
    }
    return number * count;
}
int GetMinAns(RNumber rNumber[3])
{
    int a = GetRemainingSolution(rNumber[1].Number * rNumber[2].Number, rNumber[0].Number, rNumber[0].Remaining);
    int b = GetRemainingSolution(rNumber[0].Number * rNumber[2].Number, rNumber[1].Number, rNumber[1].Remaining);
    int c = GetRemainingSolution(rNumber[0].Number * rNumber[1].Number, rNumber[2].Number, rNumber[2].Remaining);

    int m = rNumber[0].Number * rNumber[1].Number * rNumber[2].Number;
    int x = a + b + c;
    return x % m;
}
void PrintAns(int ans)
{
    printf("%d", ans);
}
int main()
{
    RNumber rNumber[3];
    InputData(rNumber);
    PrintAns(GetMinAns(rNumber));
    // system("pause");
    return 0;
}