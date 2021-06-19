#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../f925 (AC).h"

int main()
{
    if (strcmp(JudgementCIA(6, 12), "Yes") == 0)
        printf("pass\n");
    else
        printf("fail\n");
    system("pause");
    return 0;
}