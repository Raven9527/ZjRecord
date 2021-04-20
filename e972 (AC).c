#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void Input(double *budget, double *cost, char *goal)
{
    scanf("%lf", budget);
    scanf("%lf %c", cost, goal);
}
// 回傳匯率
double GetExchangeRate(char country)
{
    if (country == 'T')
    {
        return 1.0;
    }
    else if (country == 'U')
    {
        return 30.9;
    }
    else if (country == 'J')
    {
        return 0.28;
    }
    else if (country == 'E')
    {
        return 34.5;
    }
    return 1.0;
}
// 預算轉換成目的地的數字
void ConvertBudgetWithRate(double *budget, char country)
{
    *budget = (*budget) / GetExchangeRate(country);
}
// 回傳預算-cost
double ComputeRealBudget(double budget, double cost)
{
    budget = budget - cost;
    budget = ((int)(budget * 100 + 0.5)) / 100.0;
    if (budget < 0.05 && budget >= 0.00)
    {
        budget = 0.00;
    }
    return budget;
}
void PrintAns(double budget, char country)
{
    if (budget < 0)
    {
        printf("No Money");
    }
    else
    {
        printf("%c %.2lf", country, budget);
    }
}
int main()
{
    double budget;
    double cost;
    char goal;
    Input(&budget, &cost, &goal);
    ConvertBudgetWithRate(&budget, goal);
    budget = ComputeRealBudget(budget, cost);
    PrintAns(budget, goal);
    //system("pause");
    return 0;
}