#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
    struct Node *pre;
}Node;

typedef struct
{
    Node *head;
    Node *rear;
}String;

int main()
{
    String s;
    s.head=(Node *)malloc(sizeof(Node));
    s.head->data='\0';
    s.head->next=NULL;
    s.head->pre=NULL;
    s.rear=s.head;
    char c;
    while((c=getchar()) && c != '\n' && c != EOF)
    {
        Node *newNode;
        newNode=(Node *)malloc(sizeof(Node));
        newNode->data=c;
        s.rear->next=newNode;
        newNode->pre=s.rear;
        newNode->next=NULL;
        s.rear=newNode;
    }
    while(s.rear != s.head)
    {
        putchar(s.rear->data);
        s.rear=s.rear->pre;
    }
    return 0;
}