#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
    int data;
    int parent;
}TNode;

void merge(int case1, int case2, TNode **node);
int find(int case1, int case2, TNode **node);

int main()
{
    int T;
    scanf("%d", &T);
    for(int ii=0; ii<T; ii++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        TNode *node[2*n+1];
        for(int i=0; i<2*n+1; i++)
        {
            node[i]=(TNode *)malloc(sizeof(TNode));
            node[i]->data=i;
            node[i]->parent=-1;
        }
        char c;
        int case1, case2;
        for(int i=0; i<m; i++)
        {
            scanf(" %c %d %d", &c, &case1, &case2);
            if(c == 'D')
            {
                merge(case1, case2+n, node);
                merge(case2, case1+n, node);
            }
            if(c == 'A')
            {
                if(find(case1, case2, node) || find(case2, case1, node))
                {
                    printf("是同一个团伙所为\n");
                }
                else if(find(case1, case2+n, node) || find(case2, case1+n, node))
                {
                    printf("不是同一个团伙所为\n");
                }
                else printf("不确定\n");
            }
        }
    }
    return 0;
}

void merge(int case1, int case2, TNode **node)
{
    int curnode=case2;
    while(curnode != -1)
    {
        int nextnode=node[curnode]->parent;
        node[curnode]->parent=case1;
        curnode=nextnode;
    }
    return;
}

int find(int case1, int case2, TNode **node)
{
    if(node[case1]->parent == case2 || node[case2]->parent == case1) return 1;
    else return 0;
}