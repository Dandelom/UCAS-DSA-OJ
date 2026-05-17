#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
}Node;

typedef struct
{
    Node *head;
    Node *rear;
}String;

int main()
{
    String s;
    s.head=(Node *)malloc(sizeof(Node));
    s.head->data='\0';
    s.head->next=NULL;
    s.rear=s.head;
    char c;
    while((c=getchar()) && c != ' ' && c != '\n')
    {
        Node *newNode;
        newNode=(Node *)malloc(sizeof(Node));
        newNode->data=c;
        newNode->next=NULL;
        s.rear->next=newNode;
        s.rear=newNode;
    }
    String t;
    t.head=(Node *)malloc(sizeof(Node));
    t.head->data='\0';
    t.head->next=NULL;
    t.rear=t.head;
    while((c=getchar()) && c != EOF && c != '\n')
    {
        Node *newNode;
        newNode=(Node *)malloc(sizeof(Node));
        newNode->data=c;
        newNode->next=NULL;
        t.rear->next=newNode;
        t.rear=newNode;
    }
    Node *sh=s.head->next;
    Node *th=t.head->next;
    while(sh != NULL && th != NULL)
    {
        int diff=sh->data-th->data;
        if(diff > 0)
        {
            printf("1");
            return 0;
        }
        else if(diff < 0)
        {
            printf("-1");
            return 0;
        }
        sh=sh->next;
        th=th->next;
    }
    if(sh == NULL && th == NULL) printf("0");
    else if(sh != NULL) printf("1");
    else printf("-1");
    return 0;
}