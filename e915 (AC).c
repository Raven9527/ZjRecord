#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 100005

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Customer_s
{
    int angry;
    int waitTime;
}Customer;
void MainProgram();
void InputCustomers(Customer[], int);
void Sort(Customer[], int);
long long int ComputeAngryValue(Customer[], int);
int cmp(const void *a, const void *b);


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
    Customer customer[SIZE];
    int n;
    scanf("%d", &n);
    InputCustomers(customer, n);
    Sort(customer, n);
    printf("%lld\n", ComputeAngryValue(customer, n));
}

void InputCustomers(Customer customers[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d %d", &customers[i].angry, &customers[i].waitTime);
    }
}

void Sort(Customer customers[], int size)
{
    qsort(customers, size, sizeof(customers[0]), cmp);
}

long long int ComputeAngryValue(Customer customers[], int size)
{
    long long int currentWaitTime = 0;
    long long int angryValue = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        currentWaitTime += customers[i].waitTime;
        angryValue += customers[i].angry * currentWaitTime;
    }
    return angryValue;
}

int cmp(const void *a, const void *b)
{
    Customer *c = (Customer *)a;
    Customer *d = (Customer *)b;

    return (c->waitTime * d->angry - c->angry * d->waitTime);
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    Customer customer[SIZE] = { {1, 1}, {3, 1}, {7, 1} };
    int n = 3;
    int except = 16;
    Sort(customer, n);
    return AssertIntegerEquals(except, ComputeAngryValue(customer, n));
}
int TestCase2()
{
    Customer customer[SIZE] = { {5, 1}, {8, 10}, {9, 100} };
    int n = 3;
    int except = 1092;
    Sort(customer, n);
    return AssertIntegerEquals(except, ComputeAngryValue(customer, n));
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