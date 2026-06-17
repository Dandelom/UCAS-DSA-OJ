#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linkedlist;

int main()
{
    Linkedlist ha, hb;
    ha=(Lnode*)malloc(sizeof(Lnode));
    hb=(Lnode*)malloc(sizeof(Lnode));
    ha->next=NULL;
    hb->next=NULL;
    Lnode *tail_a=ha, *tail_b=hb;
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i=0; i<m; i++)
    {
        Lnode *p;
        p=(Lnode*)malloc(sizeof(Lnode));
        int temp=0;
        scanf("%d", &temp);
        p->data=temp;
        p->next=NULL;
        tail_a->next=p;
        tail_a=p;
    }
    for(int i=0; i<n; i++)
    {
        Lnode *p;
        p=(Lnode*)malloc(sizeof(Lnode));
        int temp=0;
        scanf("%d", &temp);
        p->data=temp;
        p->next=NULL;
        tail_b->next=p;
        tail_b=p;
    }
    tail_b->next=ha->next;
    while(hb->next!=NULL)
    {
        printf("%d ", hb->next->data);
        hb=hb->next;
    }
    return 0;
}