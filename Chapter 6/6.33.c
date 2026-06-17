#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, BiTree;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

int Bisearch(BiTree *t, int num);

int main()
{
    BiTree *t;
    t=(BiTNode *)malloc(sizeof(BiTNode));
    scanf("%d", &t->data);
    t->lchild=NULL;
    t->rchild=NULL;
    int num;
    LNode *l;
    l=(LNode *)malloc(sizeof(LNode));
    l->data=t->data;
    l->next=NULL;
    LNode *pin=l;
    for(num=0; num>=0; num++)
    {
        int temp_data;
        scanf("%d", &temp_data);
        if(temp_data == t->data) break;
        LNode *newNode;
        newNode=(LNode *)malloc(sizeof(LNode));
        newNode->data=temp_data;
        newNode->next=NULL;
        pin->next=newNode;
        pin=newNode;
    }
    // printf("%d\n", num);
    BiTNode *node[num];
    node[0]=t;
    pin=l->next;
    for(int i=1; i<num; i++)
    {
        node[i]=(BiTNode *)malloc(sizeof(BiTNode));
        node[i]->data=i+1;
        node[i]->lchild=NULL;
        node[i]->rchild=NULL;
    }
    for(int i=0; i<num; i++)
    {
        if(pin->data) node[i]->lchild=node[pin->data-1];
        pin=pin->next;
    }
    for(int i=0; i<num; i++)
    {
        int temp_data;
        scanf("%d", &temp_data);
        if(temp_data) node[i]->rchild=node[temp_data-1];
    }
    int u, v;
    scanf("%d%d", &u, &v);
    if(u == v) printf("0");
    else printf("%d", Bisearch(node[v-1], u));
    return 0;
}

int Bisearch(BiTree *t, int num)
{
    if(t == NULL) return 0;
    if(t->data == num) return 1;
    return (Bisearch(t->lchild, num) | Bisearch(t->rchild, num));
}