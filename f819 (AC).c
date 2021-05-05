#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct book_s
{
    int Index;
    int BorrowDay;
}Book;
int cmp(const void *s1, const void *s2)
{
    return *(int *)s1 - *(int *)s2;
}
void InputBookData(Book books[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &books[i].Index, &books[i].BorrowDay);
        
    }
}
// return fine
int ProcessBookOverdue(Book books[], int n, int overdueBookIndex[], int *overdueBooksSize)
{
    int i;
    int fine = 0;
    for (i = 0; i < n; i++)
    {
        if (books[i].BorrowDay > 100)
        {
            fine += (books[i].BorrowDay - 100) * 5;
            overdueBookIndex[(*overdueBooksSize)++] = books[i].Index;
        }
    }
    qsort(overdueBookIndex, *overdueBooksSize, sizeof(int), cmp);
    return fine;
}
void PrintAns(int overdueBookIndex[], int overdueBooksSize, int fine)
{
    int i;
    for (i = 0; i < overdueBooksSize; i++)
    {
        printf("%d ", overdueBookIndex[i]);
    }
    printf("\n");
    printf("%d", fine);
}
int main()
{
    int n;
    Book books[2048];
    int overdueBookIndex[2048];
    int overdueBooksSize = 0;
    int fine = 0;
    scanf("%d", &n);
    InputBookData(books, n);
    fine = ProcessBookOverdue(books, n, overdueBookIndex, &overdueBooksSize);
    PrintAns(overdueBookIndex, overdueBooksSize, fine);
    //system("pause");
    return 0;
}