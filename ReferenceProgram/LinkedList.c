#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void InsertNode(int data)
{
    struct node *NewNode;
    struct node *NowNode;
    NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = data;
    NewNode->next = NULL;
    if(head == NULL)
    {
        head = NewNode;
    }
    else
    {
        NowNode = head;
        while(NowNode != NULL)
        {
            if (NowNode->next == NULL)
            {
                NowNode->next = NewNode;
                break;
            }
            NowNode = NowNode->next;
        }
    }
}
void RemoveNode(int data)
{
    struct node *NowNode;
    struct node *NextNode;

    if(head == NULL)
        return;

    if (head->data == data)
    {
        NowNode = head->next;
        head = head->next;
        free(NowNode);
        return;
    }

    NowNode = head;
    NextNode = head->next;

    while(NextNode != NULL)
    {
        //printf("NextNodeData = %d\n", NextNode->data);
        if (NextNode->data == data)
        {
            NowNode->next = NextNode->next;
            free(NextNode);
            break;
        }
        NowNode = NowNode->next;
        NextNode = NextNode->next;
    }
}
int main()
{
    int i;
    int TotalElement = 0;
    head = NULL;
    int move = 0;
    while (scanf("%d", &move) != EOF)
    {
        int num;
        scanf("%d", &num);
        if(move == 0)
        {
            InsertNode(num);
        }
        else
        {
            RemoveNode(num);
        }
        struct node *Visitnode;
        Visitnode = head;
        while(Visitnode != NULL)
        {
            printf("%d ", Visitnode->data);
            Visitnode = Visitnode->next;
        }
        printf("\n");
    }
    return 0;
}