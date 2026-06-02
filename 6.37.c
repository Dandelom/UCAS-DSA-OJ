#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

typedef struct BiTNode
{
    int number;
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, BiTree;

typedef struct Stack
{
    int top;
    BiTNode* *base;
    int size;
}Stack;

void pre_order(BiTNode *t, int num);
void push(Stack *s, BiTNode *node);
void pop(Stack *s);

int main()
{
    BiTNode *node[MAXNUM];
    int num=0;
    char newdata;
    int lnum, rnum;
    for(int i=0; i<MAXNUM; i++) node[i]=NULL;
    while(scanf(" %c %d %d", &newdata, &lnum, &rnum) == 3)
    {
        num++;
        if(!node[num]) node[num]=(BiTNode *)malloc(sizeof(BiTNode));
        node[num]->data=newdata;
        node[num]->number=num;
        if(lnum == -1) node[num]->lchild=NULL;
        else
        {
            if(!node[lnum]) node[lnum]=(BiTNode *)malloc(sizeof(BiTNode));
            node[num]->lchild=node[lnum];
        }
        if(rnum == -1) node[num]->rchild=NULL;
        else
        {
            if(!node[rnum]) node[rnum]=(BiTNode *)malloc(sizeof(BiTNode));
            node[num]->rchild=node[rnum];
        }
    }
    // for(int i=0; i<num; i++) printf("%c ", node[i]->data);
    pre_order(node[1], num);
    return 0;
}

void pre_order(BiTNode *t, int num)
{
    Stack s;
    s.base=(BiTNode **)malloc(sizeof(BiTNode*)*num);
    s.size=num;
    s.top=0;
    push(&s, t);
    putchar(t->data);
    int visited[num+1];
    for(int i=1; i<num+1; i++) visited[i]=0;
    while(s.top)
    {
        BiTNode *cur_node=s.base[s.top-1];
        if(!visited[cur_node->number])
        {
            if(cur_node->lchild)
            {
                putchar(' ');
                putchar(cur_node->lchild->data);
                push(&s, cur_node->lchild);
            }
            visited[cur_node->number]=1;
        }
        else
        {
            pop(&s);
            if(cur_node->rchild)
            {
                putchar(' ');
                putchar(cur_node->rchild->data);
                push(&s, cur_node->rchild);
            }
        }
    }
    return;
}

void push(Stack *s, BiTNode *node)
{
    s->base[s->top++]=node;
    return;
}

void pop(Stack *s)
{
    s->top--;
    return;
}