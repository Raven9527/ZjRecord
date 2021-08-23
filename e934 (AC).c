#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_FLAG 0
#define PAUSE_FLAG 0

#if TEST_FLAG
#include "TestFunctionLibrary/TestFunctionLibrary.c"
void TestProgram();
#endif

void MainProgram();
char* ConvertDNAToRNA(char[]);
char GetDNAConvertRNAChar(char);

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
    char data[1024];
    scanf("%s", data);
    char *converted = ConvertDNAToRNA(data);
    printf("%s\n", converted);
    free(converted);
}

char* ConvertDNAToRNA(char dna[])
{
    int size = strlen(dna);
    int i;
    char *rna = (char*)malloc(sizeof(char) * size + 1);

    for (i = 0; i < size; i++)
    {
        rna[i] = GetDNAConvertRNAChar(dna[i]);
    }

    rna[i] = '\0';
    return rna;
}

char GetDNAConvertRNAChar(char dnaChar)
{
    if (dnaChar == 'T')
        return 'A';
    else if (dnaChar == 'A')
        return 'U';
    else if (dnaChar == 'G')
        return 'C';
    else if (dnaChar == 'C')
        return 'G';
    return '.';
}

#if TEST_FLAG
// Test Region 
int TestCase1()
{
    char testData[] = "TAGGAC";
    char except[] = "AUCCUG";
    char *convert = ConvertDNAToRNA(testData);
    int flag = AssertStringEqual(except, convert);
    free(convert);
    return flag;
}
int TestCase2()
{
    char testData[] = "ATCGATCGATCGATCGATCG";
    char except[] = "UAGCUAGCUAGCUAGCUAGC";
    char *convert = ConvertDNAToRNA(testData);
    int flag = AssertStringEqual(except, convert);
    free(convert);
    return flag;
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