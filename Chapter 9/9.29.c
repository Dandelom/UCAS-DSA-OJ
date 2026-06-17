#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int key;
    struct Node *next;
}Node;

int main()
{
    char line1[10000];
    if (!fgets(line1, sizeof(line1), stdin)) return 0;
    
    Node *h = NULL;
    Node *tail = NULL;
    
    char *token = strtok(line1, " \t\r\n");
    while (token != NULL)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->key = atoi(token);
        new_node->next = NULL;
        if (!h)
        {
            h = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        token = strtok(NULL, " \t\r\n");
    }
    if (tail)
    {
        tail->next = h;
    }
    
    Node *t = h;
    
    char line2[10000];
    if (!fgets(line2, sizeof(line2), stdin)) return 0;
    
    token = strtok(line2, " \t\r\n");
    int first = 1;
    while (token != NULL)
    {
        int K = atoi(token);
        int found = 0;
        if (t)
        {
            if (t->key == K)
            {
                found = 1;
            }
            else if (K < t->key)
            {
                Node *p = h;
                while (p != t && p->key < K)
                {
                    p = p->next;
                }
                if (p->key == K)
                {
                    found = 1;
                    t = p;
                }
            }
            else
            {
                Node *p = t->next;
                while (p != h && p->key < K)
                {
                    p = p->next;
                }
                if (p != h && p->key == K)
                {
                    found = 1;
                    t = p;
                }
            }
        }
        if (!first) putchar(' ');
        printf("%d", found);
        first = 0;
        token = strtok(NULL, " \t\r\n");
    }
    printf("\n");
    
    return 0;
}