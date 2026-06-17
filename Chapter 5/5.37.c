#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEAD 0
#define TAIL 1

typedef enum{ATOM, LIST} ElemTag;
typedef struct GLNode
{
    ElemTag tag;
    union
    {
        char atom;
        struct
        {
            struct GLNode *hp, *tp;
        }ptr;
    };
}*GList, GLNode;

GList createList(char s[], int len);
GList delete(GList l, char c);
void printList(GList l, int type);

int main()
{
    GList l;
    char s[10000];
    char c;
    int len=0;
    while((c=getchar()) && c != ' ') s[len++]=c;
    s[len]='\0';
    l=createList(s, len); 
    c=getchar();
    // printList(l, HEAD);
    // putchar('\n');
    l=delete(l, c);
    printList(l, HEAD);
    return 0;
}

GList createList(char s[], int len)
{
    if(strcmp(s, "()") == 0) return NULL;
    GList newList=(GList)malloc(sizeof(GLNode));
    newList->tag=LIST;
    int pos=0, bracketStack=0;
    for(pos=1; pos<len-1; pos++) // skip outer brackets
    {
        if(s[pos] == '(') bracketStack++;
        if(s[pos] == ')') bracketStack--;
        if(s[pos] == ',' && bracketStack == 0) break;
    }
    int lenHead=pos-1, lenTail=len-pos-2;
    if(lenTail == -1) lenTail=0;
    lenTail+=2; // add outer brackets
    char head[lenHead+1], tail[lenTail+1];
    int i;
    for(i=1; i<pos; i++) head[i-1]=s[i];
    head[lenHead]='\0';
    tail[0]='(';
    for(i=pos+1; i<len; i++) tail[i-pos]=s[i];
    tail[lenTail-1]=')';
    tail[lenTail]='\0';
    // puts(head);
    // puts(tail);
    if(lenHead == 1)
    {
        GList newAtom=(GList)malloc(sizeof(GLNode));
        newAtom->tag=ATOM;
        newAtom->atom=head[0];
        newList->ptr.hp=newAtom;
    }
    else newList->ptr.hp=createList(head, lenHead);
    newList->ptr.tp=createList(tail, lenTail);
    return newList;
}

GList delete(GList l, char c)
{
    if(l == NULL) return NULL;
    if(l->tag == ATOM)
    {
        if(l->atom == c)
        {
            free(l);
            return NULL;
        }
        return l;
    }
    l->ptr.hp=delete(l->ptr.hp, c);
    l->ptr.tp=delete(l->ptr.tp, c);
    if(l->ptr.hp == NULL)
    {
        if(l->ptr.tp == NULL)
        {
            free(l);
            return NULL;
        }
        else // 上提而非平移
        {
            GList temp=l->ptr.tp;
            free(l);
            return temp;
        }
    }
    return l;
}

void printList(GList l, int type)
{
    if(l == NULL)
    {
        printf("-1");
        return;
    }
    if(l->tag == ATOM) putchar(l->atom);
    if(l->tag == LIST)
    {
        if(type == HEAD) putchar('(');
        printList(l->ptr.hp, HEAD);
        if(l->ptr.tp != NULL)
        {
            putchar(',');
            printList(l->ptr.tp, TAIL);
        }
        if(type == HEAD) putchar(')');
    }
    return;
}