#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, *Linkedlist;

int main()
{
    Linkedlist va;
    va=(Lnode*)malloc((sizeof(Lnode)));
    va->next=NULL;
    va->data=0;
    Lnode *last;
    last=va;
    int temp;
    while((scanf("%d", &temp)))
    {
        char c;
        Lnode *p;
        p=(Lnode*)malloc(sizeof(Lnode));
        p->data=temp;
        last->next=p;
        p->next=NULL;
        last=p;
        c=getchar();
        if(c=='\n') break;
    }
    Lnode *p;
    p=(Lnode*)malloc(sizeof(Lnode));
    scanf("%d", &temp);
    p->data=temp;
    p->next=NULL;
    Lnode *find;
    find=va;
    while(find->next!=NULL)
    {
        if(find->next->data>=temp)
        {
            p->next=find->next;
            find->next=p;
            break;
        }
        find=find->next;
    }
    if(find->next==NULL) find->next=p;
    while(va->next!=NULL)
    {
        va=va->next;
        printf("%d ", va->data);
    }
    return 0;
}