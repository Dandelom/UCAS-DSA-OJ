#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, BiTree;

void pre_order(int order[], BiTree *t);
void in_order(int order[], BiTree *t);
void post_order(int order[], BiTree *t);
int currentnum;

int main()
{
    int num;
    scanf("%d", &num);
    BiTNode *node[num+1];
    int is_root[num+1];
    node[0]=NULL;
    is_root[0]=0;
    for(int i=1; i<num+1; i++)
    {
        is_root[i]=1;
        node[i]=(BiTNode *)malloc(sizeof(BiTNode));
        node[i]->data=i;
        node[i]->lchild=NULL;
        node[i]->rchild=NULL;
    }
    for(int i=0; i<num; i++)
    {
        int nodenum, child, sibling;
        scanf("%d%d%d", &nodenum, &child, &sibling);
        is_root[child]=0;
        is_root[sibling]=0;
        node[nodenum]->lchild=node[child];
        node[nodenum]->rchild=node[sibling];
    }
    int temproot=1;
    for(int i=2; i<num+1; i++) // merge trees
    {
        if(is_root[i] == 1)
        {
            node[temproot]->rchild=node[i];
            temproot=i;
        }
    }
    BiTree *t=node[1];
    int order[num];
    currentnum=0;
    pre_order(order, t);
    printf("1 ");
    for(int i=1; i<num+1; i++)
    {
        if(node[i]->lchild != NULL) printf("%d", node[i]->lchild->data);
        else
        {
            for(int j=0; j<num; j++)
            {
                if(order[j] == i)
                {
                    if(j == 0) printf("0");
                    else printf("%d", order[j-1]);
                    break;
                }
            }
        }
        if(i != num) putchar(' ');
    }
    putchar('\n');
    printf("1 ");
    for(int i=1; i<num+1; i++)
    {
        if(node[i]->rchild != NULL) printf("%d", node[i]->rchild->data);
        else printf("0");
        if(i != num) putchar(' ');
    }
    putchar('\n');
    currentnum=0;
    in_order(order, t);
    printf("1 ");
    for(int i=1; i<num+1; i++)
    {
        if(node[i]->lchild != NULL) printf("%d", node[i]->lchild->data);
        else
        {
            for(int j=0; j<num; j++)
            {
                if(order[j] == i)
                {
                    if(j == 0) printf("0");
                    else printf("%d", order[j-1]);
                    break;
                }
            }
        }
        if(i != num) putchar(' ');
    }
    putchar('\n');
    printf("1 ");
    for(int i=1; i<num+1; i++)
    {
        if(node[i]->rchild != NULL) printf("%d", node[i]->rchild->data);
        else
        {
            for(int j=0; j<num; j++)
            {
                if(order[j] == i)
                {
                    if(j == num-1) printf("0");
                    else printf("%d", order[j+1]);
                    break;
                }
            }
        }
        if(i != num) putchar(' ');
    }
    putchar('\n');
    currentnum=0;
    post_order(order, t);
    // for(int i=0; i<num; i++) printf("%d ", order[i]);
    // putchar('\n');
    printf("1 ");
    for(int i=1; i<num+1; i++)
    {
        if(node[i]->lchild != NULL) printf("%d", node[i]->lchild->data);
        else printf("0");
        if(i != num) putchar(' ');
    }
    putchar('\n');
    printf("1 ");
    for(int i=1; i<num+1; i++)
    {
        if(node[i]->rchild != NULL) printf("%d", node[i]->rchild->data);
        else
        {
            for(int j=0; j<num; j++)
            {
                if(order[j] == i)
                {
                    if(j == num-1) printf("0");
                    else printf("%d", order[j+1]);
                    break;
                }
            }
        }
        if(i != num) putchar(' ');
    }
    return 0;
}

void pre_order(int order[], BiTree *t)
{
    if(t == NULL) return;
    order[currentnum++]=t->data;
    pre_order(order, t->lchild);
    pre_order(order, t->rchild);
    return;
}

void in_order(int order[], BiTree *t)
{
    if(t == NULL) return;
    in_order(order, t->lchild);
    order[currentnum++]=t->data;
    in_order(order, t->rchild);
    return;
}

void post_order(int order[], BiTree *t)
{
    if(t == NULL) return;
    post_order(order, t->lchild);
    post_order(order, t->rchild);
    order[currentnum++]=t->data;
    return;
}