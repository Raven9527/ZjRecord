#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Product_s
{
    int Value;
    int Index;
}Product;
void SetProduct(Product *p, int v, int i)
{
    p->Value = v;
    p->Index = i;
}
void Swap(Product *a, Product *b)
{
    Product temp;
    SetProduct(&temp, a->Value, a->Index);
    SetProduct(a, b->Value, b->Index);
    SetProduct(b, temp.Value, temp.Index);
}
void InputProductValue(Product product[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &product[i].Value);
    }
}
void InputProductIndex(Product product[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &product[i].Index);
    }
}
void Process(Product product[], int n)
{
    int spaceCount = 0;
    int i;
    Product *max = NULL;
    Product *min = NULL;
    for (i = 0; i < n; i++)
    {
        if (product[i].Index == -1)
        {
            spaceCount++;
            if (max != NULL && min != NULL)
            {
                Swap(max, min);
                max = NULL;
                min = NULL;
            }
        }

        if (spaceCount >= 1 && product[i].Index != -1)
        {
            if (max == NULL || product[i].Value > max->Value)
            {
                max = &product[i];
            }

            if (min == NULL || product[i].Value < min->Value)
            {
                min = &product[i];
            }
        }
    }
}
void PrintAns(Product product[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", product[i].Index);
    }
}
int main()
{
    int n;
    Product product[105];
    scanf("%d", &n);
    InputProductValue(product, n);
    InputProductIndex(product, n);
    Process(product, n);
    PrintAns(product, n);
    // system("pause");
    return 0;
}