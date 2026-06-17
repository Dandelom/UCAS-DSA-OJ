#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node* Merge(Node *l1, Node *l2)
{
    Node dummy;
    Node *tail=&dummy;
    dummy.next=NULL;
    while(l1 && l2)
    {
        if(l1->data <= l2->data)
        {
            tail->next=l1;
            l1=l1->next;
        }
        else
        {
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    if(l1) tail->next=l1;
    else tail->next=l2;
    return dummy.next;
}

int main()
{
    int n;
    if(scanf("%d", &n) != 1 || n <= 0) return 0;
    Node *head=NULL;
    Node *tail=NULL;
    for(int i=0; i<n; i++)
    {
        Node *newnode=(Node *)malloc(sizeof(Node));
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        if(!head)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
    if(!head) return 0;
    Node **queue=(Node **)malloc(sizeof(Node *)*(2*n+5));
    int front=0;
    int rear=0;
    Node *curr=head;
    Node *segstart=head;
    while(curr && curr->next)
    {
        if(curr->data > curr->next->data)
        {
            Node *nextstart=curr->next;
            curr->next=NULL;
            queue[rear++]=segstart;
            segstart=nextstart;
            curr=nextstart;
        }
        else curr=curr->next;
    }
    if(segstart) queue[rear++]=segstart;
    while(rear-front > 1)
    {
        Node *l1=queue[front++];
        Node *l2=queue[front++];
        Node *merged=Merge(l1, l2);
        queue[rear++]=merged;
    }
    Node *finalhead=queue[front];
    curr=finalhead;
    int first=1;
    while(curr)
    {
        if(!first) printf(" ");
        printf("%d", curr->data);
        first=0;
        curr=curr->next;
    }
    printf("\n");
    return 0;
}