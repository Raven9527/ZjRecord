#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 55

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Video_s
{
    char name[20];
    int viewers;
    int length;
    int watchTime;
    int r;
    double priority;
}Video;

int cmp(const void *a, const void *b)
{
    Video *c = (Video *)a;
    Video *d = (Video *)b;
    if (c->priority >= d->priority)
        return -1;
    else
        return 1;
}

void MainProgram();
void InputVideoGroupData(Video[], int); // 輸入影片資料群
void ProcessComputeVideoGroupPriority(Video[], int); // 處裡計算所有影片群的優先度
double ComputeVideoPriority(Video*); // 計算影片優先度
void Sort(Video[], int); // 排序
void PrintVideoGroup(Video[], int); // 輸出

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
    Video videos[SIZE];
    int n;
    scanf("%d", &n);
    InputVideoGroupData(videos, n);
    ProcessComputeVideoGroupPriority(videos, n);
    Sort(videos, n);
    PrintVideoGroup(videos, n);
}

void InputVideoGroupData(Video videos[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d %d %d", &(videos[i].name), &(videos[i].viewers), &(videos[i]).length, &(videos[i].watchTime), &(videos[i].r));
    }
}

void ProcessComputeVideoGroupPriority(Video video[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        video[i].priority = ComputeVideoPriority(&video[i]);
    }
}

void Sort(Video video[], int n)
{
    qsort(video, n, sizeof(video[0]), cmp);
}

double ComputeVideoPriority(Video *video)
{
    return video->viewers * ((double)video->watchTime / (double)video->length) * video->r;
}

void PrintVideoGroup(Video videos[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s\n", videos[i].name);
    }
}

#if TEST_FLAG
// Test Region
int TestCase1()
{
    Video videos[SIZE] = {{ "A-Fu", 1000, 4, 4, 9, 0.0 }, { "HowHow", 100, 5, 4, 10, 0.0 }, { "Married", 1000, 8, 7, 9, 0.0 }};
    int i, n = 3;    
    ProcessComputeVideoGroupPriority(videos, n);
    Sort(videos, n);
    char v0[] = "A-Fu";
    char v1[] = "Married";
    char v2[] = "HowHow";
    int count = 0;
    count += AssertStringEqual(v0, videos[0].name);
    count += AssertStringEqual(v1, videos[1].name);
    count += AssertStringEqual(v2, videos[2].name);
    return count == 3;
}
int TestCase2()
{
    Video videos[SIZE] = {{ "Mina", 500, 10, 7, 10, 0.0 }, { "TT", 400, 5, 4, 7, 0.0 }, { "CheerUp", 420, 3, 2, 6, 0.0 }, { "Twice", 900, 3, 2, 5, 0.0 }};
    int i, n = 4;    
    ProcessComputeVideoGroupPriority(videos, n);
    Sort(videos, n);
    int count = 0;
    char v0[] = "Mina";
    char v1[] = "Twice";
    char v2[] = "TT";
    char v3[] = "CheerUp";
    count += AssertStringEqual(v0, videos[0].name);
    count += AssertStringEqual(v1, videos[1].name);
    count += AssertStringEqual(v2, videos[2].name);
    count += AssertStringEqual(v3, videos[3].name);
    return count == 4;
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