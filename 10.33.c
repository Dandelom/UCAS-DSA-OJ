#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void SelectionSort(Node *head)
{
    Node *p=head;
    while(p)
    {
        Node *minnode=p;
        Node *q=p->next;
        while(q)
        {
            if(q->data < minnode->data)
            {
                minnode=q;
            }
            q=q->next;
        }
        if(minnode != p)
        {
            int temp=p->data;
            p->data=minnode->data;
            minnode->data=temp;
        }
        p=p->next;
    }
}

int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    int val;
    while(scanf("%d", &val) == 1)
    {
        Node *newnode=(Node *)malloc(sizeof(Node));
        newnode->data=val;
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
    SelectionSort(head);
    Node *curr=head;
    int dotflag=0;
    while(curr)
    {
        if(dotflag) putchar(' ');
        printf("%d", curr->data);
        if(!dotflag) dotflag=1;
        curr=curr->next;
    }
    printf("\n");
    return 0;
}