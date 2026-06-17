#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode
{
    struct TrieNode *children[26];
    int is_end;
} TrieNode;

TrieNode* create_node()
{
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->is_end = 0;
    for (int i = 0; i < 26; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, const char *key)
{
    TrieNode *curr = root;
    for (int i = 0; key[i] != '\0'; i++)
    {
        int index = key[i] - 'a';
        if (!curr->children[index])
        {
            curr->children[index] = create_node();
        }
        curr = curr->children[index];
    }
    curr->is_end = 1;
}

int search(TrieNode *root, const char *key)
{
    TrieNode *curr = root;
    for (int i = 0; key[i] != '\0'; i++)
    {
        int index = key[i] - 'a';
        if (!curr->children[index])
        {
            return 0;
        }
        curr = curr->children[index];
    }
    return curr->is_end;
}

int has_children(TrieNode *node)
{
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i]) return 1;
    }
    return 0;
}

TrieNode* delete_node(TrieNode *node, const char *key, int depth)
{
    if (!node) return NULL;
    if (key[depth] == '\0')
    {
        node->is_end = 0;
    }
    else
    {
        int index = key[depth] - 'a';
        node->children[index] = delete_node(node->children[index], key, depth + 1);
    }
    if (!node->is_end && !has_children(node))
    {
        free(node);
        return NULL;
    }
    return node;
}

int main()
{
    TrieNode *root = create_node();
    int op;
    char key[1005];
    while (scanf("%d %s", &op, key) == 2)
    {
        if (op == 1)
        {
            insert(root, key);
        }
        else if (op == 2)
        {
            if (key[0] != '\0')
            {
                int index = key[0] - 'a';
                root->children[index] = delete_node(root->children[index], key, 1);
            }
        }
        else if (op == 3)
        {
            if (search(root, key))
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
        }
    }
    return 0;
}