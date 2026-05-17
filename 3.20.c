#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
    int x;
    int y;
} Point;

typedef struct Stack
{
    int top;
    Point *base;
    int stacksize;
} Stack;

Stack stack;
Stack *s=&stack;

void push(Point p);
Point pop();
void dye(int m, int n, int map[m][n]);
void initStack(int len);

int main()
{
    int m, n, x, y, dir;
    scanf("%d%d%d%d%d", &m, &n, &x, &y, &dir);
    int map[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &map[i][j]);
    initStack(m*n);
    Point p={x, y};
    push(p);
    map[x][y]=2;
    dye(m, n, map);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d", map[i][j]);
        }
        if(i != m-1) printf("\n");
    }
    return 0;
}

void initStack(int len)
{
    s->base=(Point *)malloc(sizeof(Point)*len);
    s->top=0;
    s->stacksize=len;
    return;
}

void push(Point p)
{
    s->base[s->top++]=p;
    return;
}

Point pop()
{
    return s->base[--s->top];
}

void dye(int m, int n, int map[m][n])
{
    while(s->top != 0)
    {
        Point p=pop();
        // printf("%d %d\n", p.x, p.y);
        if(p.x != 0 && map[p.x-1][p.y] == 1) // 上
        {
            map[p.x-1][p.y]=2;
            Point p_push={p.x-1, p.y};
            push(p_push);
        }
        if(p.x != m-1 && map[p.x+1][p.y] == 1) // 下
        {
            map[p.x+1][p.y]=2;
            Point p_push={p.x+1, p.y};
            push(p_push);
        }
        if(p.y != 0 && map[p.x][p.y-1] == 1) // 左
        {
            map[p.x][p.y-1]=2;
            Point p_push={p.x, p.y-1};
            push(p_push);
        }
        if(p.y != n-1 && map[p.x][p.y+1] == 1) // 右
        {
            map[p.x][p.y+1]=2;
            Point p_push={p.x, p.y+1};
            push(p_push);
        }
    }
    return;
}