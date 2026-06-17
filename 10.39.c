#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

int main()
{
    int temp;
    Node *arr=NULL;
    Node *p=arr;
    while(scanf("%d", &temp) == 1)
    {
        Node *new=(Node *)malloc(sizeof(Node));
        new->data=temp;
        new->next=NULL;
        if(!arr)
        {
            arr=new;
            p=arr;
        }
        else
        {
            p->next=new;
            p=new;
        }
        char c;
        c=getchar();
        if(c == '\n') break;
    }
    p=arr;
    while(scanf("%d", &temp) == 1)
    {
        Node *new=(Node *)malloc(sizeof(Node));
        new->data=temp;
        new->next=NULL;
        while(p)
        {
            if(!p->next)
            {
                p->next=new;
                p=new;
                break;
            }
            else if(p->data >= temp)
            {
                new->next=arr;
                arr=new;
                p=new;
                break;
            }
            else if(p->data <= temp && p->next->data >= temp)
            {
                new->next=p->next;
                p->next=new;
                p=new;
                break;
            }
            else p=p->next;
        }
    }
    p=arr;
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    return 0;
}