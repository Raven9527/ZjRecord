#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct lotto_s
{
    int Number;
    int Price;
}Lotto;
void InputLuckyNumber(int luckyNumber[])
{
    scanf("%d %d %d", &luckyNumber[0], &luckyNumber[1], &luckyNumber[2]);
}
void InputLottoNumber(Lotto lotto[])
{
    scanf("%d %d %d %d %d", &lotto[0].Number, &lotto[1].Number, &lotto[2].Number, &lotto[3].Number, &lotto[4].Number);
}
void InputLottoPrice(Lotto lotto[])
{
    scanf("%d %d %d %d %d", &lotto[0].Price, &lotto[1].Price, &lotto[2].Price, &lotto[3].Price, &lotto[4].Price);
}
int GetWinLottoPrice(Lotto lotto[], int luckyNumber)
{
    int i;
    int price = 0;
    for (i = 0; i < 5; i++)
    {
        if (lotto[i].Number == luckyNumber)
        {
            price += lotto[i].Price;
        }
    }

    return price;
}
int ComputeFinalPrice(Lotto lotto[], int luckyNumber[])
{
    int i;
    int price = 0;
    for (i = 0; i < 2; i++)
    {
        price += GetWinLottoPrice(lotto, luckyNumber[i]);
    }

    int winLottoPrice = GetWinLottoPrice(lotto, luckyNumber[2]);
    if (winLottoPrice != 0)
        price = (price - winLottoPrice >= 0) ? (price - winLottoPrice) : 0;
    else
        price *= 2;
    return price;
}
void PrintAns(int price)
{
    printf("%d\n", price);
}
int main()
{
    int luckyNumber[3];
    Lotto lotto[5];
    InputLuckyNumber(luckyNumber);
    InputLottoNumber(lotto);
    InputLottoPrice(lotto);
    PrintAns(ComputeFinalPrice(lotto, luckyNumber));
    //system("pause");
    return 0;
}