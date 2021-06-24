#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ReverseString(char master[], int size, char store[])
{
    char temp[1024];
    strcpy(temp, master);
    int i, t = 0;
    for (i = size - 1; i >= 0; i--)
    {
        master[t++] = temp[i];
    }
    strcpy(store, temp);
    return store;
}

int main()
{
    char master[] = "123456789";
    char store[] = "111";
    printf("%s\n", ReverseString(master, 9, store));
    system("pause");
    return 0;
}