#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    int tag; // brackets?
    int number;
    struct BiTNode *lchild, *rchild, *parent;
}BiTNode, BiTree;

typedef struct Stack
{
    int top;
    BiTNode* *base;
}Stack;

int num;
int brackets_lmap[4][4]=
{
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {1, 1, 0, 0}
};

int brackets_rmap[4][4]=
{
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 1, 0}
};

BiTNode *create_tree_pre(BiTNode *parent);
void print_in_order(BiTree *t);
int is_operator(BiTNode *node);
void push(Stack *s, BiTNode *node);
void pop(Stack *s);

int main()
{
    BiTree *t;
    t=create_tree_pre(NULL);
    print_in_order(t);
    return 0;
}

BiTNode *create_tree_pre(BiTNode *parent)
{
    char c;
    c=getchar();
    if(c == '#') return NULL;
    BiTNode *t;
    t=(BiTNode *)malloc(sizeof(BiTNode));
    t->data=c;
    t->parent=parent;
    t->tag=0;
    t->number=num;
    num++;
    t->lchild=create_tree_pre(t);
    t->rchild=create_tree_pre(t);
    return t;
}

void print_in_order(BiTNode *node)
{
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->top=0;
    s->base=(BiTNode **)malloc(sizeof(BiTNode*)*num);
    int visited[num];
    for(int i=0; i<num; i++) visited[i]=0;
    push(s, node);
    while(s->top)
    {
        BiTNode *cur=s->base[s->top-1];
        if(is_operator(cur) == -1)
        {
            pop(s);
            putchar(cur->data);
        }
        else
        {
            if(visited[cur->number] == 0)
            {
                if(cur->tag) putchar('(');
                visited[cur->number]=1;
                push(s, cur->lchild);
                cur->lchild->tag=brackets_lmap[is_operator(cur)][is_operator(cur->lchild)];
            }
            else if(visited[cur->number] == 1)
            {
                visited[cur->number]=2;
                putchar(cur->data);
                push(s, cur->rchild);
                cur->rchild->tag=brackets_rmap[is_operator(cur)][is_operator(cur->rchild)];
            }
            else if(visited[cur->number] == 2)
            {
                if(cur->tag) putchar(')');
                pop(s);
            }
        }
    }
}

int is_operator(BiTNode *node)
{
    if(node->data == '+') return 0;
    else if(node->data == '-') return 1;
    else if(node->data == '*') return 2;
    else if(node->data == '/') return 3;
    else return -1;
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