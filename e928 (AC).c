#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0
#define SIZE 214

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

typedef struct Term_s
{
    int power;
    int coefficient;
}Term;
typedef struct Polynomial_s
{
    int powerSize;
    Term term[SIZE];
}Polynomial;
void MainProgram();
void InputPolynomial(Polynomial*); // 輸入
Term TermMultiply(Term*, Term*); // 項數相乘
Polynomial* PolynomialMultiply(Polynomial*, Polynomial*); // 多項式相乘
void PrintPolynomial(Polynomial*); // 輸出

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
    Polynomial p1, p2;
    InputPolynomial(&p1);
    InputPolynomial(&p2);
    Polynomial *ansPolynoial = PolynomialMultiply(&p1, &p2);
    PrintPolynomial(ansPolynoial);
    free(ansPolynoial);
}

void InputPolynomial(Polynomial *polynomial)
{
    int n, coff;
    scanf("%d", &n);
    polynomial->powerSize = n;
    while (n >= 0)
    {
        scanf("%d", &coff);
        polynomial->term[n].coefficient = coff;
        polynomial->term[n].power = n;
        n--;
    }
}

Term TermMultiply(Term *term1, Term *term2)
{
    Term term;
    term.power = term1->power + term2->power;
    term.coefficient = term1->coefficient * term2->coefficient;
    return term;
}

Polynomial* PolynomialMultiply(Polynomial *polynomial1, Polynomial *polynomial2)
{
    Polynomial *polynomial = (Polynomial*)malloc(sizeof(Polynomial));
    polynomial->powerSize = polynomial1->powerSize + polynomial2->powerSize;
    int i, j;
    for (i = 0; i <= polynomial->powerSize; i++)
    {
        polynomial->term[i].power = polynomial->powerSize - i;
        polynomial->term[i].coefficient = 0;
    }

    for (i = 0; i <= polynomial1->powerSize; i++)
    {
        for (j = 0; j <= polynomial2->powerSize; j++)
        {
            Term newTerm = TermMultiply(&polynomial1->term[i], &polynomial2->term[j]);
            polynomial->term[polynomial->powerSize - newTerm.power].coefficient += newTerm.coefficient;
        }
    }
    return polynomial;
}

void PrintPolynomial(Polynomial *polynomial)
{
    int i;
    printf("%d\n", polynomial->powerSize);
    for (i = 0; i <= polynomial->powerSize; i++)
    {
        printf("%d ", polynomial->term[i].coefficient);
    }
    printf("\n");
}

#if TEST_FLAG
// Test Region
int TestCase1()
{
    Polynomial p1 = {2, { {2, 1}, {1, 2}, {0, 0} } };
    Polynomial p2 = {3, { {3, 2}, {2, 0}, {1, 3}, {0, 1} } };;
    int except[] = { 2, 4, 3, 7, 2, 0 };
    Polynomial *ans = PolynomialMultiply(&p1, &p2);
    int i;
    PrintPolynomial(ans);
    for (i = 0; i < ans->powerSize; i++)
    {
        if (AssertIntegerEquals(except[i], ans->term[i].coefficient) == 0)
            return 0;
    }
    return 1;
}
void TestProgram()
{
    int caseCount = 1;
    int failCount = 0;

    failCount += OutputTest(caseCount++, TestCase1());

    printf(failCount == 0 ? "All Pass!\n" : "Some Case Fail!\n");
}
#endif