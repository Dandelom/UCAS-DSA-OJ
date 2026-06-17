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
    int num=0, flag=0;
    scanf("%d", &num);
    list->data=num;
    list->next=NULL;
    Lnode *last=list;
    char c;
    c=getchar();
    if(c!='\n')
    {
        while(scanf("%d", &num))
        {
            Lnode *p;
            p=(Lnode*)malloc(sizeof(Lnode));
            p->data=num;
            p->next=NULL;
            last->next=p;
            last=p;
            c=getchar();
            if(c=='\n') break;
        }
    }
    else flag=1;
    int i;
    scanf("%d", &i);
    if(i==0 && flag==1)
    {
        printf("NULL");
        return 0;
    }
    else if(i==0 && flag==0)
    {
        Lnode *p;
        p=list;
        list=list->next;
        free(p);
    }
    else
    {
        Lnode *p;
        p=list;
        for(int j=0; j<i-1; j++)
            p=p->next;
        Lnode *pn;
        pn=p->next;
        p->next=pn->next;
        free(pn);
    }
    while(list->next!=NULL)
    {
        printf("%d ", list->data);
        list=list->next;
    }
    printf("%d", list->data);
    return 0;
}