#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

typedef struct BiTNode
{
    int number;
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, BiTree;

typedef struct QNode
{
    int number;
    struct QNode *next;
}QNode;

typedef struct Queue
{
    QNode *front, *rear;
}Queue;

void push(Queue *q, BiTNode *node);
void pop(Queue *q);

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
    // for(int i=1; i<=num; i++) printf("%c ", node[i]->data);
    Queue *q=(Queue *)malloc(sizeof(Queue));
    QNode *head=(QNode *)malloc(sizeof(QNode));
    head->next=NULL;
    head->number=0;
    q->front=head;
    q->rear=head;
    push(q, node[1]);
    num--;
    while(num>0)
    {
        BiTNode *curnode=node[q->front->next->number];
        if(!curnode->lchild && num>0)
        {
            printf("No");
            return 0;
        }
        push(q, curnode->lchild);
        num--;
        if(!curnode->rchild && num>0)
        {
            printf("No");
            return 0;
        }
        push(q, curnode->rchild);
        num--;
        pop(q);
    }
    printf("Yes");
    return 0;
}

void push(Queue *q, BiTNode *node)
{
    if(!node) return;
    QNode *newnode=(QNode *)malloc(sizeof(QNode));
    newnode->number=node->number;
    newnode->next=NULL;
    q->rear->next=newnode;
    q->rear=newnode;
    return;
}

void pop(Queue *q)
{
    if(!q->front->next) return;
    QNode *pf=q->front;
    q->front=q->front->next;
    q->front->number=0;
    free(pf);
}