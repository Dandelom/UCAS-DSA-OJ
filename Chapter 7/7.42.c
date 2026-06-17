#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000
#define MAXINT 2147483647

typedef struct Node
{
    int vindex;
    int weight;
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

void Dijkstra(Graph *g, int source, int distance[]);

int main()
{
    Graph *g=(Graph *)malloc(sizeof(Graph));
    for(int i=0; i<MAXNUM; i++)
    {
        g->v[i].verdex=i;
        g->v[i].first=NULL;
    }
    int n, source;
    scanf("%d %d", &n, &source);
    g->vernum=n;
    int curin, curout, weight;
    while(scanf("%d-%d %d", &curout, &curin, &weight) == 3)
    {
        Node *new=(Node *)malloc(sizeof(Node));
        new->next=NULL;
        new->vindex=curin;
        new->weight=weight;
        Node *p=g->v[curout].first;
        if(!g->v[curout].first) g->v[curout].first=new;
        else
        {
            while(p->next) p=p->next;
            p->next=new;
        }
    }
    int distance[n+1];
    for(int i=0; i<=n; i++) distance[i]=MAXINT;
    Dijkstra(g, source, distance);
    int dotflag=0;
    for(int i=1; i<=n; i++)
    {
        if(i == source) continue;
        if(dotflag) putchar(',');
        printf("%d", distance[i]);
        if(!dotflag) dotflag=1;
    }
    return 0;
}

void Dijkstra(Graph *g, int source, int distance[])
{
    int n=g->vernum;
    int completed[n+1];
    for(int i=0; i<=n; i++) completed[i]=0;
    distance[source]=0;
    completed[source]=1;
    int curver=source;
    for(int i=0; i<n-1; i++)
    {
        Node *p=g->v[curver].first;
        while(p)
        {
            if(distance[curver]+p->weight < distance[p->vindex])
                distance[p->vindex]=distance[curver]+p->weight;
            p=p->next;
        }
        int mindist=MAXINT, nextver=0;
        for(int i=1; i<=n; i++)
        {
            if(distance[i] < mindist && !completed[i])
            {
                mindist=distance[i];
                nextver=i;
            }
        } 
        curver=nextver;
        completed[nextver]=1;
    }
    return;
}