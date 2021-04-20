#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a , int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void QuickSort(int array[] , int left , int right)
{
    int pivot, i, j;

    if(left >= right)
        return;

    pivot = array[left];

    i = left + 1;
    j = right;

    while (1)
    {
        while(i <= right && pivot >= array[i]) //向右尋找比pivot大的元素 (找到跳出)
            i++;
        while(j > left && pivot <= array[j]) //向左尋找比pivot小的元素 (找到跳出)
            j--;

        if(i >= j) //右邊的元素都比左邊大 即跳出
            break;

        swap(&array[i], &array[j]); //否則交換
    }
    swap(&array[left], &array[j]);

    QuickSort(array, left, j - 1);
    QuickSort(array, j + 1, right);

    return;
}
int main()
{
    int array[10] = {3, 2, 3, 6, 4, 7, 9, 1, 9, 8};
    int n = 10 , i;

    for (i = 0; i < n;i++)
        printf("%d ", array[i]);

    printf("\n");

    QuickSort(array, 0, n - 1);

    for (i = 0; i < n;i++)
        printf("%d ", array[i]);
    system("pause");
    return 0;
}