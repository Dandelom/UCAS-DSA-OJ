#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, BiTree;

int create_tree_LR(BiTNode **node);
void print_in_order(BiTNode *t);

int main()
{
    BiTNode *p[MAXNUM], *x[MAXNUM];
    p[0]=NULL;
    x[0]=NULL;
    for(int i=1; i<MAXNUM; i++)
    {
        p[i]=(BiTNode *)malloc(sizeof(BiTNode));
        p[i]->data=i;
        p[i]->lchild=NULL;
        p[i]->rchild=NULL;
        x[i]=(BiTNode *)malloc(sizeof(BiTNode));
        x[i]->data=i;
        x[i]->lchild=NULL;
        x[i]->rchild=NULL;
    }
    int p_offset, x_offset;
    p_offset=create_tree_LR(p);
    int pos;
    scanf("%d", &pos);
    x_offset=create_tree_LR(x);
    for(int i=1; i<MAXNUM; i++)
    {
        p[i]->data+=p_offset;
        x[i]->data+=x_offset;
    }
    x[1]->rchild=p[pos]->lchild;
    p[pos]->lchild=x[1];
    print_in_order(p[1]);
    return 0;
}

int create_tree_LR(BiTNode **node)
{
    int flag, num=0;
    scanf("%d", &flag);
    int offset=flag-1;
    int tempnum;
    while((scanf("%d", &tempnum)) && tempnum != flag)
    {
        num++;
        if(tempnum == 0)  node[num]->lchild=NULL;
        else node[num]->lchild=node[tempnum-offset];
    }
    for(int i=1; i<=num; i++)
    {
        scanf("%d", &tempnum);
        if(tempnum == 0)  node[num]->rchild=NULL;
        else node[i]->rchild=node[tempnum-offset];
    }
    return offset;
}

void print_in_order(BiTNode *t)
{
    if(t == NULL) return;
    print_in_order(t->lchild);
    printf("%d ", t->data);
    print_in_order(t->rchild);
}