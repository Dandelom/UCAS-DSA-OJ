#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linkedlist;

int main()
{
    Linkedlist list;
    list=(Lnode*)malloc(sizeof(Lnode));
    list->next=NULL;
    Lnode* tail=list;
    int num=0;
    char c;
    while(scanf("%d", &num))
    {
        Lnode *p;
        p=(Lnode*)malloc(sizeof(Lnode));
        p->data=num;
        p->next=NULL;
        tail->next=p;
        tail=p;
        c=getchar();
        if(c=='\n') break;
    }
    int mink, maxk;
    scanf("%d%d", &mink, &maxk);
    Lnode *pin=list;
    while(pin->next!=NULL)
    {
        if(pin->next->data>mink && pin->next->data<maxk)
        {
            while(pin->next!=NULL && pin->next->data>mink && pin->next->data<maxk)
            {
                Lnode *ptemp=pin->next;
                pin->next=ptemp->next;
                free(ptemp);
                if(pin->next==NULL) break;
            }
            break;
        }
        pin=pin->next;
    }
    while(list->next!=NULL)
    {
        printf("%d ", list->next->data);
        list=list->next;
    }
    return 0;
}