#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
}BSTNode;

BSTNode* insert(BSTNode *t, int key)
{
    if (!t)
    {
        BSTNode *p = (BSTNode *)malloc(sizeof(BSTNode));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if (key < t->data)
    {
        t->lchild = insert(t->lchild, key);
    }
    else if (key > t->data)
    {
        t->rchild = insert(t->rchild, key);
    }
    return t;
}

void print_nodes(BSTNode *t, int x, int *first)
{
    if (!t) return;
    print_nodes(t->rchild, x, first);
    if (t->data >= x)
    {
        if (!(*first)) printf(" ");
        printf("%d", t->data);
        *first = 0;
        print_nodes(t->lchild, x, first);
    }
}

int main()
{
    char line[100000];
    if (!fgets(line, sizeof(line), stdin)) return 0;
    
    BSTNode *root = NULL;
    char *token = strtok(line, " \t\r\n");
    while (token != NULL)
    {
        int val = atoi(token);
        root = insert(root, val);
        token = strtok(NULL, " \t\r\n");
    }
    
    int x;
    if (scanf("%d", &x) != 1) return 0;
    
    int first = 1;
    print_nodes(root, x, &first);
    printf("\n");
    
    return 0;
}