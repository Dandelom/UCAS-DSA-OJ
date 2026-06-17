#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, BiTree;

int create_tree_LR(BiTNode **node);
// void exchange(BiTNode *t);

int main()
{
    BiTNode *node[MAXNUM];
    node[0]=NULL;
    for(int i=1; i<MAXNUM; i++)
    {
        node[i]=(BiTNode *)malloc(sizeof(BiTNode));
        node[i]->data=i;
        node[i]->lchild=NULL;
        node[i]->rchild=NULL;
    }
    int num;
    num=create_tree_LR(node);
    // for(int i=1; i<=num; i++)
    // {
    //     printf("%d ", node[i]->data);
    //     if(node[i]->lchild) printf("%d ", node[i]->lchild->data);
    //     else printf("-1 ");
    //     if(node[i]->rchild) printf("%d ", node[i]->rchild->data);
    //     else printf("-1 ");
    //     putchar('\n');
    // }
    printf("1");
    for(int i=1; i<=num; i++)
    {
        putchar(' ');
        if(node[i]->rchild) printf("%d", node[i]->rchild->data);
        else printf("0");
    }
    printf("\n1");
    for(int i=1; i<=num; i++)
    {
        putchar(' ');
        if(node[i]->lchild) printf("%d", node[i]->lchild->data);
        else printf("0");
    }
    return 0;
}

int create_tree_LR(BiTNode **node)
{
    int flag, num=0;
    scanf("%d", &flag);
    int tempnum;
    while((scanf("%d", &tempnum)) && tempnum != flag)
    {
        num++;
        node[num]->lchild=node[tempnum];
    }
    for(int i=1; i<=num; i++)
    {
        scanf("%d", &tempnum);
        node[i]->rchild=node[tempnum];
    }
    return num;
}