#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode;

BiTNode *create_tree_PI(int len);
void insert_node(BiTNode *node, char data, int len);
void print_post_order(BiTNode *t);

char pre_order[MAXLEN];
char in_order[MAXLEN];

int main()
{
    char c;
    int len=0;
    while((c=getchar()) && c != '\n') pre_order[len++]=c;
    for(int i=0; i<len; i++) in_order[i]=getchar();
    BiTNode *t=create_tree_PI(len);
    print_post_order(t);
    return 0;
}

BiTNode *create_tree_PI(int len)
{
    BiTNode *t=(BiTNode *)malloc(sizeof(BiTNode));
    t->data=pre_order[0];
    t->lchild=NULL;
    t->rchild=NULL;
    for(int i=1; i<len; i++) insert_node(t, pre_order[i], len);
    return t;
}

void insert_node(BiTNode *node, char data, int len)
{
    int pos0, pos1;
    for(int i=0; i<len; i++)
    {
        if(in_order[i] == node->data) pos0=i;
        if(in_order[i] == data) pos1=i;
    }
    BiTNode *newnode=(BiTNode *)malloc(sizeof(BiTNode));
    newnode->data=data;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    if(pos0-pos1 > 0) // left
    {
        if(!node->lchild)
        {
            node->lchild=newnode;
            return;
        }
        else insert_node(node->lchild, data, len);
    }
    else // right
    {
        if(!node->rchild)
        {
            node->rchild=newnode;
            return;
        }
        else insert_node(node->rchild, data, len);
    }
}

void print_post_order(BiTNode *node)
{
    if(!node) return;
    print_post_order(node->lchild);
    print_post_order(node->rchild);
    putchar(node->data);
    return;
}