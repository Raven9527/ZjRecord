// 根據 time 決定要輸出哪筆，要在時間尾數9接近0時送出Code for test，sleep防止輸出太快馬上到下一個判斷 (延遲判斷)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define PAUSE_FLAG 0
void PrintAns(int index)
{
    if (index == 1)
        printf("Hello, World!");
    else if (index == 2)
        printf("hello, world");
    else if (index == 3)
        printf("Halo, word!!!");
    else if (index == 4)
        printf("世界，您好！");
    else if (index == 5)
        printf("https://zerojudge.tw/ShowProblem?problemid=a001");
    else
        printf("miss: %d\n", index);

    sleep(1);
}
int main()
{
    time_t t = 0;
    time(&t);
    long int currentTime = (t % 60) % 10;
    PrintAns(currentTime + 1);
    if (PAUSE_FLAG)
        system("pause");
    return 0;
}