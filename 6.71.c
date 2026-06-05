#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100

typedef struct TNode
{
    char data;
    struct TNode *child, *sibling;
}TNode;

void pre_order(TNode *t, int depth);

int main()
{
    char newdata;
    int newchild, newsibling;
    TNode *t[MAXNUM];
    for(int i=0; i<MAXNUM; i++)
    {
        t[i]=(TNode *)malloc(sizeof(TNode));
        t[i]->data='\0';
        t[i]->child=NULL;
        t[i]->sibling=NULL;
    }
    int num=0;
    while(scanf(" %c %d %d", &newdata, &newchild, &newsibling) == 3)
    {
        num++;
        t[num]->data=newdata;
        if(newchild != -1) t[num]->child=t[newchild];
        if(newsibling != -1) t[num]->sibling=t[newsibling];
    }
    pre_order(t[1], 0);
    return 0;
}

void pre_order(TNode *t, int depth)
{
    if(!t) return;
    for(int i=0; i<depth; i++) putchar('-');
    putchar(t->data);
    putchar('\n');
    for(TNode *pin=t->child; pin != NULL; pin=pin->sibling) pre_order(pin, depth+1);
}