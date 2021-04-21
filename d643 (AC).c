#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100005
char inp[MAX];
char *words[MAX];
int cmp(const void *s1, const void *s2)
{
    //return strcmp(*(char**)s1, *(char**)s2);
    printf("%s %s\n", *(char**)s1, *(char**)s2);
    return strcmp(*(char**)s1, *(char**)s2);
}
// 計算字串長度
int GetStrlen(char *inp)
{
    int size = 0;
    for (size = 0; inp[size] != '\0'; size++);
    return size;
}
// 主要處理
void ProcessMerge(int f, int maxf, int *flag, char inp[])
{
    int i, k;
    int count = 0;
    char output[MAX];
    int outputIndex = 0;
    int index = 0;
    for (i = 0; i < maxf; i++)
    {
        words[i] = &inp[f * i];
        count++;
    }
    qsort(words, maxf, sizeof(*words), cmp);
    // for (i = 0; i < maxf; i++)
    // {
    //     printf("%s\n", words[i]);
    // }
    // printf("\n");
    // system("pause");
    for (i = 0; i < maxf; i++)
    {
        for (k = 0; k < f; k++)
        {
            output[outputIndex++] = (words[i][k]);
        }
    }
    output[outputIndex++] = '\0';
    if (strcmp(inp, output) != 0)
    {
        puts(output);
        *flag = 1;
    }
}
int main()
{
    gets(inp);
    int size = GetStrlen(inp);
    int factorSize = 0;
    int flag = 0;
    int i;
    for (i = 1; i < size; i++)
    {
        if (size % i == 0)
        {
            ProcessMerge(i, size / i, &flag, inp);
        }
    }
    if (flag == 0)
        printf("bomb!\n");
    // system("pause");
    return 0;
}