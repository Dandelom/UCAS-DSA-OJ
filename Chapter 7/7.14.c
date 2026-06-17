#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

typedef struct node
{
    int vindex;
    struct node *next;
}Node;

typedef struct
{
    int vexnum, edgenum, kind;
    struct
    {
        int verdex;
        Node *first;
    }v[MAXNUM];
}Graph;

int main()
{
    Graph *g=(Graph *)malloc(sizeof(Graph));
    for(int i=0; i<MAXNUM; i++)
    {
        g->v[i].verdex=-1;
        g->v[i].first=NULL;
    }
    scanf("%d,%d", &g->vexnum, &g->edgenum);
    g->kind=1;
    for(int i=0; i<g->edgenum; i++)
    {
        int curout, curin;
        scanf("%d-%d", &curout, &curin);
        if(i != g->edgenum-1) getchar();
        Node *new=(Node *)malloc(sizeof(Node));
        new->next=NULL;
        new->vindex=curin;
        g->v[curin].verdex=curin;
        if(!g->v[curout].first)
        {
            g->v[curout].verdex=curout;
            g->v[curout].first=new;
            continue;
        }
        Node *p=g->v[curout].first;
        while(p->next) p=p->next;
        p->next=new;
    }
    int count=g->vexnum;
    int i=0;
    while(count)
    {
        if(g->v[i].verdex != -1)
        {
            printf("%d", g->v[i].verdex);
            count--;
            Node *p=g->v[i].first;
            if(p)
            {
                putchar(' ');
                int outnum=0, maxindex=-1;
                int bucket[MAXNUM];
                for(int i=0; i<MAXNUM; i++) bucket[i]=-1;
                while(p)
                {
                    outnum++;
                    bucket[p->vindex]=p->vindex;
                    if(p->vindex > maxindex) maxindex=p->vindex;
                    p=p->next;
                }
                for(int i=maxindex; i>=0; i--)
                {
                    if(bucket[i] != -1)
                    {
                        printf("%d", bucket[i]);
                        outnum--;
                        if(outnum) putchar(',');
                    }
                }
            }
            if(count) putchar('\n');
        }
        i++;
    }
    return 0;
}