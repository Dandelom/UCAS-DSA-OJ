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

int visited[MAXNUM];

int SearchPath(Graph *g, int cur, int des, int len, int limit);

int main()
{
    Graph *g=(Graph *)malloc(sizeof(Graph));
    for(int i=0; i<MAXNUM; i++)
    {
        g->v[i].verdex=i;
        g->v[i].first=NULL;
    }
    int n, k;
    scanf("%d,%d", &n, &k);
    int vi, vj;
    scanf(" %d,%d", &vi, &vj);
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
    if(SearchPath(g, vi, vj, 0, k)) printf("yes");
    else printf("no");
    return 0;
}

int SearchPath(Graph *g, int cur, int des, int len, int limit)
{
    if(len > limit || visited[cur]) return 0;
    if(len == limit && cur == des) return 1;
    visited[cur]=1;
    Node *p=g->v[cur].first;
    int res=0;
    while(p)
    {
        if(!visited[p->vindex])
        {
            res=SearchPath(g, p->vindex, des, len+1, limit);
            if(res) break;
        }
        p=p->next;
    }
    return res;
}