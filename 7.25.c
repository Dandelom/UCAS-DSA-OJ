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
    int temp;
    int n=g->vernum;
    int s[n*n];
    for(int i=0; i<n*n; i++) s[i]=0;
    int count=1;
    scanf("%d", &s[0]);
    while((scanf("%d", &temp)) && temp) s[count++]=temp;
    int fst[n+1], lst[n+1];
    for(int i=1; i<=n; i++) scanf("%d", &fst[i]);
    scanf("%d", &temp);
    for(int i=1; i<=n; i++) scanf("%d", &lst[i]);
    for(int i=1; i<=n; i++)
    {
        if(fst[i] > lst[i]) continue;
        for(int j=fst[i]; j<lst[i]; j++)
        {
            Node *new=(Node *)malloc(sizeof(Node));
            new->next=NULL;
            new->vindex=s[j];
            if(!g->v[i].first) g->v[i].first=new;
            else
            {
                Node *p=g->v[i].first;
                while(p->next) p=p->next;
                p->next=new;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<MAXNUM; j++) visited[j]=0;
        if(SearchPath(g, i, i))
        {
            printf("yes");
            return 0;
        }
    }
    printf("no");
    return 0;
}

int SearchPath(Graph *g, int cur, int vj)
{
    if(g->v[cur].verdex == vj && visited[cur]) return 1;
    if(visited[cur]) return 0;
    visited[cur]=1;
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