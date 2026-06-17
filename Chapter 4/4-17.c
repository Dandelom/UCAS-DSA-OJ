#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char ch;
    struct Node *next;
} Node, *String;

int lens, lent, lenv;
char* getString(int *relen);
void getNextVal(char t[], int nextVal[]);
int KMP(char s[], char t[], int nextVal[]);

int main()
{
    char *s, *t, *v;
    s=getString(&lens);
    t=getString(&lent);
    v=getString(&lenv);
    // puts(s);
    // puts(t);
    // puts(v);
    // printf("%d %d %d\n", lens, lent, lenv);
    int nextVal[lent];
    getNextVal(t, nextVal);
    int pos=KMP(s, t, nextVal);
    // printf("%d\n", pos);
    if(pos == -1)
        for(int i=0; i<lens; i++) putchar(s[i]);
    else
    {
        for(int i=0; i<pos; i++) putchar(s[i]);
        for(int i=0; i<lenv; i++) putchar(v[i]);
        for(int i=pos+lent; i<lens; i++) putchar(s[i]);
    }
    return 0;
}

char* getString(int *relen)
{
    String str=(String)malloc(sizeof(Node));
    str->next=NULL;
    str->ch='\0';
    String tail=str;
    char c;
    int len=0;
    while((c=getchar()) && c != ' ' && c != '\n' && c != EOF)
    {
        Node *newNode=(Node *)malloc(sizeof(Node));
        newNode->ch=c;
        newNode->next=NULL;
        tail->next=newNode;
        tail=newNode;
        len++;
    }
    char *s=(char *)malloc(sizeof(char)*(len+1));
    Node *pin=str->next;
    for(int i=0; i<len; i++)
    {
        Node *temp=pin;
        s[i]=temp->ch;
        pin=pin->next;
        free(temp);
    }
    free(str);
    s[len]='\0';
    *relen=len;
    return s;
}

void getNextVal(char t[], int nextVal[])
{
    int i=0, j=-1;
    nextVal[0]=-1;
    while(i < lent)
    {
        if(j == -1 || t[i] == t[j])
        {
            i++;
            j++;
            if(t[i] == t[j]) nextVal[i]=nextVal[j];
            else nextVal[i]=j;
        }
        else j=nextVal[j];
    }
    return;
}

int KMP(char s[], char t[], int nextVal[])
{
    int i=0, j=0;
    while(i < lens)
    {
        if(j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else j=nextVal[j];
        if(j == lent) return i-lent;
    }
    return -1;
}