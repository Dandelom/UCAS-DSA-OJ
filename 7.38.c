#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

typedef struct Node
{
    int vindex;
    struct Node *next;
}Node;

typedef struct
{
    int vernum;
    struct
    {
        char verdex;
        Node *first;
    }v[MAXNUM];
}Graph;

int top=0;

void printGraph(Graph *g, int curver, char stack[]);

int main()
{
    Graph *g=(Graph *)malloc(sizeof(Graph));
    for(int i=0; i<MAXNUM; i++)
    {
        g->v[i].verdex='\0';
        g->v[i].first=NULL;
    }
    int n;
    scanf("%d", &n);
    g->vernum=n;
    getchar();
    int i=0;
    while(i != n)
    {
        char c=getchar();
        g->v[i].verdex=c;
        while((c=getchar()) && c != '\n')
        {
            Node *new=(Node *)malloc(sizeof(Node));
            new->next=NULL;
            scanf("%d", &new->vindex);
            Node *p=g->v[i].first;
            if(!p) g->v[i].first=new;
            else
            {
                while(p->next) p=p->next;
                p->next=new;
            }
        }
        i++;
    }
    char stack[n+1];
    printGraph(g, 0, stack);
    while(top) putchar(stack[--top]);
    return 0;
}

void printGraph(Graph *g, int curver, char stack[])
{
    Node *p=g->v[curver].first;
    stack[top++]=g->v[curver].verdex;
    while(p)
    {
        printGraph(g, p->vindex, stack);
        p=p->next;
    }
    return;
}