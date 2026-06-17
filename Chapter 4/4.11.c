#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
    int num;
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
    s.head->num=-1;
    s.head->next=NULL;
    s.rear=s.head;
    char c;
    while((c=getchar()) && c != ' ' && c != '\n')
    {
        Node *newNode;
        newNode=(Node *)malloc(sizeof(Node));
        newNode->data=c;
        newNode->num=s.rear->num+1;
        newNode->next=NULL;
        s.rear->next=newNode;
        s.rear=newNode;
    }
    String t;
    t.head=(Node *)malloc(sizeof(Node));
    t.head->data='\0';
    t.head->num=-1;
    t.head->next=NULL;
    t.rear=t.head;
    while((c=getchar()) && c != EOF && c != '\n')
    {
        Node *newNode;
        newNode=(Node *)malloc(sizeof(Node));
        newNode->data=c;
        newNode->num=t.rear->num+1;
        newNode->next=NULL;
        t.rear->next=newNode;
        t.rear=newNode;
    }
    String r;
    r.head=(Node *)malloc(sizeof(Node));
    r.head->data='\0';
    r.head->num=-1;
    r.head->next=NULL;
    r.rear=r.head;
    Node *sh=s.head->next;
    for(int i=0; sh != NULL; i++)
    {
        // printf("%c %d\n", sh->data, i);
        Node *rh=r.head->next;
        int flag=1;
        while(rh != NULL)
        {
            if(rh->data == sh->data)
            {
                flag=0;
                break;
            }
            rh=rh->next;
        }
        if(flag == 0)
        {
            sh=sh->next;
            continue;
        }
        Node *th=t.head->next;
        while(th != NULL)
        {
            if(th->data == sh->data)
            {
                flag=0;
                break;
            }
            th=th->next;
        }
        if(flag == 0)
        {
            sh=sh->next;
            continue;
        }
        Node *newNode;
        newNode=(Node *)malloc(sizeof(Node));
        newNode->data=sh->data;
        newNode->next=NULL;
        newNode->num=i;
        r.rear->next=newNode;
        r.rear=newNode;
        sh=sh->next;
    }
    if(r.head == r.rear) printf("-1");
    else
    {
        Node *rh=r.head->next;
        while(rh != NULL)
        {
            putchar(rh->data);
            rh=rh->next;
        }
        putchar(' ');
        rh=r.head->next;
        while(rh != NULL)
        {
            printf("%d", rh->num);
            rh=rh->next;
        }
    }
    return 0;
}