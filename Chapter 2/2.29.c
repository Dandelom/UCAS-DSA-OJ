#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    char data;
    struct Lnode *next;
} Lnode, *Linkedlist;

int main()
{
    Linkedlist list_a;
    list_a=(Lnode*)malloc(sizeof(Lnode));
    list_a->next=NULL;
    Lnode *tail_a=list_a;
    char c;
    while((c=getchar()) && c!='\n')
    {
        if(c==',') continue;
        Lnode *p;
        p=(Lnode*)malloc(sizeof(Lnode));
        p->data=c;
        p->next=NULL;
        tail_a->next=p;
        tail_a=p;
    }
    Linkedlist list_b;
    list_b=(Lnode*)malloc(sizeof(Lnode));
    list_b->next=NULL;
    Lnode *tail_b=list_b;
    while((c=getchar()) && c!='\n')
    {
        if(c==',') continue;
        Lnode *p;
        p=(Lnode*)malloc(sizeof(Lnode));
        p->data=c;
        p->next=NULL;
        tail_b->next=p;
        tail_b=p;
    }
    Linkedlist list_c;
    list_c=(Lnode*)malloc(sizeof(Lnode));
    list_c->next=NULL;
    Lnode *tail_c=list_c;
    while((c=getchar()) && c!='\n')
    {
        if(c==',') continue;
        Lnode *p;
        p=(Lnode*)malloc(sizeof(Lnode));
        p->data=c;
        p->next=NULL;
        tail_c->next=p;
        tail_c=p;
    }
    Lnode *pin_a=list_a;
    while(pin_a->next!=NULL)
    {
        char temp=pin_a->next->data;
        int flagb=0, flagc=0;
        Lnode *pin_b=list_b, *pin_c=list_c;
        while(pin_b->next!=NULL)
        {
            if(pin_b->next->data==temp)
            {
                flagb=1;
                break;
            }
            pin_b=pin_b->next;
        }
        if(flagb==0)
        {
            pin_a=pin_a->next;
            continue;
        }
        while(pin_c->next!=NULL)
        {
            if(pin_c->next->data==temp)
            {
                flagc=1;
                break;
            }
            pin_c=pin_c->next;
        }
        if(flagc==1)
        {
            Lnode *ptemp=pin_a->next;
            pin_a->next=ptemp->next;
            free(ptemp);
            continue;
        }
        pin_a=pin_a->next;
    }
    while(list_a->next!=NULL)
    {
        printf("%c", list_a->next->data);
        if(list_a->next->next!=NULL) printf(",");
        list_a=list_a->next;
    }
    return 0;
}