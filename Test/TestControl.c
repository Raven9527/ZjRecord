#define TEST_FLAG 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#if TEST_FLAG
#include "TestFunction.c"
#endif

int main()
{
    printf("%d", Get100());
    system("pause");
    return 0;
}