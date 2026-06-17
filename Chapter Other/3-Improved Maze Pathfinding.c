#include <stdio.h>
#include <stdlib.h>

typedef struct Coordinate
{
    int x, y;
}Coor;

typedef struct Trace
{
    Coor cur;
    int last;
}Trace;

int len=0;

void BFS(Coor dept, Coor dest, Coor *path, int x, int y, char map[x+1][y+1]);

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    getchar();
    char map[x+1][y+1];
    Coor entr, exit, key;
    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=y; j++)
        {
            map[i][j]=getchar();
            if(map[i][j] == 'R')
            {
                entr.x=i;
                entr.y=j;
            }
            else if(map[i][j] == 'C')
            {
                exit.x=i;
                exit.y=j;
            }
            else if(map[i][j] == 'Y')
            {
                key.x=i;
                key.y=j;
            }
        }
        getchar();
    }
    Coor path[x*y+1];
    BFS(entr, key, path, x, y, map);
    for(int i=len-1; i>=0; i--)
    {
        printf("%d %d\n", path[i].x, path[i].y);
    }
    len=0;
    BFS(key, exit, path, x, y, map);
    for(int i=len-2; i>=0; i--)
    {
        printf("%d %d\n", path[i].x, path[i].y);
    }
    return 0;
}

void BFS(Coor dept, Coor dest, Coor *path, int x, int y, char map[x+1][y+1])
{
    char newmap[x+1][y+1];
    for(int i=1; i<=x; i++)
        for(int j=1; j<=y; j++)
            newmap[i][j]=map[i][j];
    newmap[dest.x][dest.y]='0';
    Trace t[x*y+1];
    int top=0, bottom=0;
    t[top].cur=dept;
    t[top].last=-1;
    top++;
    while(top != bottom)
    {
        Coor curpoint=t[bottom].cur;
        newmap[curpoint.x][curpoint.y]='2';
        if(curpoint.x == dest.x && curpoint.y == dest.y)
        {
            Trace back=t[bottom];
            while(1)
            {
                path[len++]=back.cur;
                if(back.last == -1) break;
                back=t[back.last];
            }
            break;
        }
        if(curpoint.x-1 >= 1 && newmap[curpoint.x-1][curpoint.y] == '0')
        {
            Coor newpoint;
            newpoint.x=curpoint.x-1;
            newpoint.y=curpoint.y;
            t[top].cur=newpoint;
            t[top].last=bottom;
            top++;
        }
        if(curpoint.y-1 >= 1 && newmap[curpoint.x][curpoint.y-1] == '0')
        {
            Coor newpoint;
            newpoint.x=curpoint.x;
            newpoint.y=curpoint.y-1;
            t[top].cur=newpoint;
            t[top].last=bottom;
            top++;
        }
        if(curpoint.x+1 <= x && newmap[curpoint.x+1][curpoint.y] == '0')
        {
            Coor newpoint;
            newpoint.x=curpoint.x+1;
            newpoint.y=curpoint.y;
            t[top].cur=newpoint;
            t[top].last=bottom;
            top++;
        }
        if(curpoint.y+1 <= y && newmap[curpoint.x][curpoint.y+1] == '0')
        {
            Coor newpoint;
            newpoint.x=curpoint.x;
            newpoint.y=curpoint.y+1;
            t[top].cur=newpoint;
            t[top].last=bottom;
            top++;
        }
        bottom++;
    }
    return;
}