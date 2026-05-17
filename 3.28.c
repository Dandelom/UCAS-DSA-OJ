#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
typedef struct
{
    Node *rear;
}LinkedQueue;

int main()
{
    LinkedQueue q;
    q.rear=(Node *)malloc(sizeof(Node));
    q.rear->next=q.rear;
    q.rear->data=0;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int num;
        scanf("%d", &num);
        Node *qtemp;
        qtemp=(Node *)malloc(sizeof(Node));
        qtemp->data=num;
        qtemp->next=q.rear->next;
        q.rear->next=qtemp;
        q.rear=qtemp;
        getchar();
    }
    Node *pin=q.rear->next;
    for(int i=0; i<n-1; i++)
    {
        printf("%d,", pin->next->data);
        pin=pin->next;
    }
    printf("%d", pin->next->data);
    return 0;
}