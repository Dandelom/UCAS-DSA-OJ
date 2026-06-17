#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

typedef struct
{
    int vexnum;
    int A[MAXNUM][MAXNUM];
}Graph;

void DeleteArc(Graph *g, int v, int w);
void InsertArc(Graph *g, int v, int w);
void DeleteVex(Graph *g, int v);
void InsertVex(Graph *g, int v);

int main()
{
    Graph *g=(Graph *)malloc(sizeof(Graph));
    int num;
    scanf("%d", &num);
    g->vexnum=num;
    for(int i=0; i<num; i++)
        for(int j=0; j<num; j++)
            scanf("%d", &g->A[i][j]);
    char op[2];
    while(scanf(" %c%c", &op[0], &op[1]) == 2)
    {
        if(op[0] == 'D' && op[1] == 'A')
        {
            int v, w;
            scanf("%d %d", &v, &w);
            DeleteArc(g, v, w);
        }
        else if(op[0] == 'I' && op[1] == 'A')
        {
            int v, w;
            scanf("%d %d", &v, &w);
            InsertArc(g, v, w);
        }
        else if(op[0] == 'D' && op[1] == 'V')
        {
            int v;
            scanf("%d", &v);
            DeleteVex(g, v);
        }
        else if(op[0] == 'I' && op[1] == 'V')
        {
            int v;
            scanf("%d", &v);
            InsertVex(g, v);
        }
    }
    for(int i=0; i<g->vexnum; i++)
    {
        for(int j=0; j<g->vexnum; j++)
        {
            printf("%d", g->A[i][j]);
            if(j != g->vexnum-1) putchar(' ');
        }
        if(i != g->vexnum-1) putchar('\n');
    }
    return 0;
}

void DeleteArc(Graph *g, int v, int w)
{
    g->A[v][w]=0;
    g->A[w][v]=0;
    return;
}

void InsertArc(Graph *g, int v, int w)
{
    g->A[v][w]=1;
    g->A[w][v]=1;
    return;
}

void DeleteVex(Graph *g, int v)
{
    for(int i=0; i<v; i++)
        for(int j=v+1; j<g->vexnum; j++)
            g->A[i][j-1]=g->A[i][j];
    for(int i=v+1; i<g->vexnum; i++)
        for(int j=0; j<v; j++)
            g->A[i-1][j]=g->A[i][j];
    for(int i=v+1; i<g->vexnum; i++)
        for(int j=v+1; j<g->vexnum; j++)
            g->A[i-1][j-1]=g->A[i][j];
    g->vexnum--;
    return;
}

void InsertVex(Graph *g, int v)
{
    for(int i=0; i<v; i++)
        for(int j=g->vexnum; j>v; j--)
            g->A[i][j]=g->A[i][j-1];
    for(int i=g->vexnum; i>v; i--)
        for(int j=0; j<v; j++)
            g->A[i][j]=g->A[i-1][j];
    for(int i=g->vexnum; i>v; i--)
        for(int j=g->vexnum; j>v; j--)
            g->A[i][j]=g->A[i-1][j-1];
    g->vexnum++;
    for(int i=0; i<g->vexnum; i++) g->A[i][v]=0;
    for(int j=0; j<g->vexnum; j++) g->A[v][j]=0;
    return;
}