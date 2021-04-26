#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Input(int quiz[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &quiz[i]);
    }
}
int ComputeScore(int ans[], int quiz[], int size, int scoreOfQuiz)
{
    int i;
    int totalScore = 0;
    for (i = 0; i < size; i++)
    {
        if (ans[i] == quiz[i])
            totalScore += scoreOfQuiz;
    }
    return totalScore;
}
void PrintFinalAns(int score)
{
    printf("%d\n", score);
}
int main()
{
    int n, s, T;
    int quiz[25];
    int ans[25];
    scanf("%d %d", &n, &s);
    Input(ans, n);
    scanf("%d", &T);
    while(T--)
    {
        Input(quiz, n);
        int score = ComputeScore(ans, quiz, n, s);
        PrintFinalAns(score);
    }
    // system("pause");
    return 0;
}