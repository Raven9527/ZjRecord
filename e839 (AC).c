#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define STRING_SIZE 20
#define FOOD_SIZE 55

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Food_s
{
    char name[STRING_SIZE];
    char foodType[STRING_SIZE];
}Food;
void MainProgram();
void InputFoodGroup(Food[], int); // 輸入
void Sort(Food[], int); // 排序Food陣列 (根據name)
void FindBelongTypeFoods(Food[], int, Food*[], int*, char[]); // 尋找屬於這個Type的所有食物
int IsFoodBelongType(Food*, char[]); // 該食物是否屬於這個Type
int cmp(const void*, const void*); // 比較器
void PrintFoods(Food*[], int); // 輸出

// Main Region
int main()
{
    #if TEST_FLAG
        TestProgram();
    #else
        MainProgram();
    #endif

    #if PAUSE_FLAG
        system("pause");
    #endif

    return 0;
}

void MainProgram()
{
    Food foods[FOOD_SIZE];
    Food *foodTypeGroup[FOOD_SIZE];
    int size;
    int foodTypeGroupSize = 0;
    char searchType[STRING_SIZE];
    scanf("%d", &size);
    InputFoodGroup(foods, size);
    scanf("%s", searchType);
    Sort(foods, size);
    FindBelongTypeFoods(foods, size, foodTypeGroup, &foodTypeGroupSize, searchType);
    PrintFoods(foodTypeGroup, foodTypeGroupSize);
}

int cmp(const void *a, const void *b)
{
    Food *c = (Food *)a;
    Food *d = (Food *)b;
    return strcmp(c->name, d->name);
}

void InputFoodGroup(Food foods[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s %s", foods[i].name, foods[i].foodType);
    }
}

void FindBelongTypeFoods(Food foods[], int size, Food *targetFoodGroup[], int *foodTypeGroupSize, char searchType[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (IsFoodBelongType(&foods[i], searchType))
        {
            targetFoodGroup[(*foodTypeGroupSize)++] = &foods[i];
        }
    }
}

int IsFoodBelongType(Food *food, char cmpType[])
{
    return strcmp(food->foodType, cmpType) == 0;
}

void Sort(Food foods[], int n)
{
    qsort(foods, n, sizeof(foods[0]), cmp);
}

void PrintFoods(Food *foods[], int size)
{
    if (size == 0)
    {
        printf("No\n");
        return;
    }
    
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%s\n", foods[i]->name);
    }
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    Food foods[] = { {"apple", "fruit"}, {"milk", "drink"} };
    Food *foodTypeGroup[FOOD_SIZE];
    int size = 2;
    int foodTypeGroupSize = 0;
    char search[] = "grains";
    Sort(foods, size);
    FindBelongTypeFoods(foods, size, foodTypeGroup, &foodTypeGroupSize, search);
    return AssertIntegerEquals(0, foodTypeGroupSize);
}
int TestCase2()
{
    Food foods[] = { {"pork", "meat"}, {"tea", "drink"}, {"fish", "meat"}, {"rice", "grains"}, {"beef", "meat"} };
    Food *foodTypeGroup[FOOD_SIZE];
    int size = 5;
    int foodTypeGroupSize = 0;
    char search[] = "meat";
    Sort(foods, size);
    FindBelongTypeFoods(foods, size, foodTypeGroup, &foodTypeGroupSize, search);
    return AssertIntegerEquals(3, foodTypeGroupSize) && AssertStringEqual("beef", foodTypeGroup[0]->name)
            && AssertStringEqual("fish", foodTypeGroup[1]->name)
            && AssertStringEqual("pork", foodTypeGroup[2]->name);
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());
    failCount += OutputTest(caseCount++, TestCase2());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif