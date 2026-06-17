#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *pre;
    struct Node *next;
}Node;

typedef struct
{
    Node *head;
    Node *rear;
    int size;
}Queue;

int main()
{
    Queue q;
    q.head=(Node *)malloc(sizeof(Node));
    q.head->data=0;
    q.head->next=NULL;
    q.head->pre=NULL;
    q.rear=q.head;
    q.size=0;
    char c;
    while((c=getchar()) && c != EOF)
    {
        if(c == '\n') continue;
        if(c == '@')
        {
            Node *pfree=q.head;
            int flag=1;
            q.head=q.head->next;
            for(int i=0; i<q.size/2; i++)
            {
                if(q.head->data != q.rear->data) flag=0;
                q.head=q.head->next;
                q.rear=q.rear->pre;
            }
            printf("%d\n", flag);
            Node *temp;
            while(pfree != NULL)
            {
                temp=pfree->next;
                free(pfree);
                pfree=temp;
            }
            q.head=(Node *)malloc(sizeof(Node));
            q.head->data=0;
            q.head->next=NULL;
            q.head->pre=NULL;
            q.rear=q.head;
            q.size=0;
            continue;
        }
        q.size++;
        Node *newNode;
        newNode=(Node *)malloc(sizeof(Node));
        newNode->data=c;
        newNode->pre=q.rear;
        newNode->next=NULL;
        q.rear->next=newNode;
        q.rear=newNode;
    }
    return 0;
}