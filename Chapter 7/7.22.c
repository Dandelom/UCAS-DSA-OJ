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
    int vernum, edgenum;
    struct
    {
        int verdex;
        Node *first;
    }v[MAXNUM];
}Graph;

int visited[MAXNUM];

int SearchPath(Graph *g, int cur, int vj);

int main()
{
    Graph *g=(Graph *)malloc(sizeof(Graph));
    for(int i=0; i<MAXNUM; i++)
    {
        g->v[i].verdex=i;
        g->v[i].first=NULL;
    }
    scanf("%d", &g->vernum);
    g->edgenum=0;
    int curin, curout;
    while(scanf("%d-%d", &curout, &curin))
    {
        g->edgenum++;
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
        if(c == '\n') break;
    }
    int vi, vj;
    scanf("%d,%d", &vi, &vj);
    int res=SearchPath(g, vi, vj);
    if(res == 0) printf("no");
    else if(res == 1) printf("yes");
    return 0;
}

int SearchPath(Graph *g, int cur, int vj)
{
    if(visited[cur]) return 0;
    visited[cur]=1;
    if(g->v[cur].verdex == vj) return 1;
    int res=0;
    Node *p=g->v[cur].first;
    while(p)
    {
        int next=p->vindex;
        res|=SearchPath(g, next, vj);
        if(res) break;
        p=p->next;
    }
    return res;
}