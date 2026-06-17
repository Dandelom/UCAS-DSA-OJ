#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild, *parent;
}BiTNode, BiTree;

BiTNode *create_tree_pre(BiTNode *parent);
BiTNode *search_tree(BiTNode *t, char obj);
BiTNode *co_parent(BiTNode *p, BiTNode *q);

int num;

int main()
{
    BiTree *t;
    t=create_tree_pre(NULL);
    char p, q;
    getchar();
    p=getchar();
    getchar();
    q=getchar();
    BiTNode *pp=search_tree(t, p);
    BiTNode *pq=search_tree(t, q);
    BiTNode *ancestor=co_parent(pp, pq);
    printf("%c", ancestor->data);
    return 0;
}

BiTNode *create_tree_pre(BiTNode *parent)
{
    char c;
    c=getchar();
    if(c == '^') return NULL;
    BiTNode *t;
    t=(BiTNode *)malloc(sizeof(BiTNode));
    num++;
    t->data=c;
    t->parent=parent;
    t->lchild=create_tree_pre(t);
    t->rchild=create_tree_pre(t);
    return t;
}

BiTNode *search_tree(BiTNode *t, char obj)
{
    if(t == NULL) return NULL;
    if(t->data == obj) return t;
    BiTNode *re=search_tree(t->lchild, obj);
    if(re) return re;
    re=search_tree(t->rchild, obj);
    if(re) return re;
    return NULL;
}

BiTNode *co_parent(BiTNode *p, BiTNode *q)
{
    if(p->parent == NULL) return p;
    if(q->parent == NULL) return q;
    if(p->parent == q)
    {
        if(q->parent) return q->parent;
        else return q;
    }
    if(q->parent == p)
    {
        if(p->parent) return p->parent;
        else return p;
    }
    BiTNode *curnode=p->parent;
    while(curnode->parent)
    {
        if(search_tree(curnode, q->data) == NULL) curnode=curnode->parent;
        else break;
    }
    return curnode;
}