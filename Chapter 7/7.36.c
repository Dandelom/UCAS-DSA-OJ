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
        int verdex;
        Node *first;
    }v[MAXNUM];
}Graph;

int maxlen=-1;

void getLongestPath(Graph *g, int curver, int curlen);

int main()
{
    Graph *g=(Graph *)malloc(sizeof(Graph));
    for(int i=0; i<MAXNUM; i++)
    {
        g->v[i].verdex=i;
        g->v[i].first=NULL;
    }
    scanf("%d", &g->vernum);
    int curin, curout;
    while(scanf("%d-%d", &curout, &curin))
    {
        Node *new=(Node *)malloc(sizeof(Node));
        new->next=NULL;
        new->vindex=curin;
        if(!g->v[curout].first) g->v[curout].first=new;
        else
        {
            Node *p=g->v[curout].first;
            while(p->next) p=p->next;
            p->next=new;
        }
        char c=getchar();
        if(c != ',') break;
    }
    for(int i=1; i<=g->vernum; i++)
    {
        getLongestPath(g, i, 0);
        printf("%d", maxlen);
        maxlen=-1;
        if(i != g->vernum) putchar(',');
    }
    return 0;
}

void getLongestPath(Graph *g, int curver, int curlen)
{
    Node *p=g->v[curver].first;
    if(!p)
    {
        if(curlen > maxlen) maxlen=curlen;
        return;
    }
    while(p)
    {
        getLongestPath(g, p->vindex, curlen+1);
        p=p->next;
    }
    return;
}