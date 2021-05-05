#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct meal_s
{
    char Name[30];
    int Price;
}Meal;
void InputComboMeal(Meal combo[], Meal *totals[], int *size)
{
    int index;
    scanf("%d", &index);
    totals[(*size)++] = &combo[index - 1];
}
void InputCarteMeal(Meal carte[], Meal *totals[], int *size)
{
    int index;
    scanf("%d", &index);
    totals[(*size)++] = &carte[index - 1];
}
void PrintFinalData(Meal *totals[], int size)
{
    int i;
    int price = 0;
    for (i = 0; i < size; i++)
    {
        printf("%s %d\n", totals[i]->Name, totals[i]->Price);
        price += totals[i]->Price;
    }
    printf("Total: %d\n", price);
}
void InitializeComboMealName(Meal combo[5])
{
    strcpy(combo[0].Name, "Medium Wac");
    combo[0].Price = 4;
    strcpy(combo[1].Name, "WChicken Nugget");
    combo[1].Price = 8;
    strcpy(combo[2].Name, "Geez Burger");
    combo[2].Price = 7;
    strcpy(combo[3].Name, "ButtMilk Crispy Chicken");
    combo[3].Price = 6;
    strcpy(combo[4].Name, "Plastic Toy");
    combo[4].Price = 3;
}
void InitializeCarteMealName(Meal carte[4])
{
    strcpy(carte[0].Name, "German Fries");
    carte[0].Price = 2;
    strcpy(carte[1].Name, "Durian Slices");
    carte[1].Price = 3;
    strcpy(carte[2].Name, "WcFurry");
    carte[2].Price = 5;
    strcpy(carte[3].Name, "Chocolate Sunday");
    carte[3].Price = 7;
}
int main()
{
    // Meal carte[4] = {
    //     [0] = {.Price = 2},
    //     [1] = {.Price = 3}
    // }

    Meal combo[10];
    Meal carte[10];
    InitializeComboMealName(combo);
    InitializeCarteMealName(carte);
    int order;
    Meal *totals[10000];
    int size = 0;
    while (scanf("%d", &order) != EOF)
    {
        if (order == 0)
        {
            PrintFinalData(totals, size);
            break;
        }
        else if (order == 1)
        {
            InputComboMeal(combo, totals, &size);
        }
        else if (order == 2)
        {
            InputCarteMeal(carte, totals, &size);
        }
    }
    // system("pause");
    return 0;
}