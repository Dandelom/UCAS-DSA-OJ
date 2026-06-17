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
    int num;
    scanf("%d", &num); // first 0
    int flag=-1;
    while(flag != 1)
    {
        int temp_data;
        scanf("%d", &temp_data);
        if(temp_data == 0) flag++;
        num++;
    }
    num--;
    BiTNode *node[num];
    for(int i=0; i<num; i++)
    {
        node[i]=(BiTNode *)malloc(sizeof(BiTNode));
        node[i]->data=i+1;
        node[i]->lchild=NULL;
        node[i]->rchild=NULL;
    }
    for(int i=0; i<num; i++)
    {
        int temp_data;
        scanf("%d", &temp_data);
        if(temp_data) node[i]->lchild=node[temp_data-1];
    }
    scanf("%d", &flag);
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