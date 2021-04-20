/*
阿旺老師很喜歡在課堂上點同學回答問題，他規定每堂課只能有三位同學請假。老師因為記憶力不好，常常忘記哪些同學請假，所以我們要幫他印一份簡單明瞭的名條，讓他能直接看著這份名條點同學回答問題。 阿旺老師點名喜歡從最後一個座號開始點，所以這份名條必須將有出席同學的座號由後往前印出來。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InputStudentID(int studentCount[], int n)
{
    int i, k;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        studentCount[k]++;
    }
}

void PrintAns(int studentCount[], int n)
{
    int i;
    for (i = n; i >= 1; i--)
    {
        if (studentCount[i] == 0)
        {
            printf("No. %d\n", i);
        }
    }
}

int main()
{
    int n;
    int studentCount[25];
    int leakStudentCount[25];
    memset(studentCount, 0, sizeof(studentCount));
    memset(leakStudentCount, 0, sizeof(leakStudentCount));

    scanf("%d", &n);
    InputStudentID(studentCount, 3);
    PrintAns(studentCount, n);
    //system("pause");
    return 0;
}