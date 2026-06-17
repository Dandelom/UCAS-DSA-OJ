#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    char data;
    struct Lnode *next;
} Lnode, *Linkedlist;

int main()
{
    Linkedlist list;
    list=(Lnode*)malloc(sizeof(Lnode));
    list->next=NULL;
    Lnode *tail=list;
    char c;
    while((c=getchar()) && c!='\n')
    {
        if(c==',') continue;
        Lnode *p;
        p=(Lnode*)malloc(sizeof(Lnode));
        p->data=c;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
    Lnode *plast, *pcur, *pnext;
    plast=NULL;
    pcur=list->next;
    pnext=pcur->next;
    while(pnext!=NULL)
    {
        pcur->next=plast;
        plast=pcur;
        pcur=pnext;
        pnext=pnext->next;
    }
    pcur->next=plast;
    list->next=pcur;
    while(list->next!=NULL)
    {
        printf("%c", list->next->data);
        if(list->next->next!=NULL) printf(",");
        list=list->next;
    }
    return 0;
}