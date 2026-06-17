#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int addr;
    struct Node *next;
}Node;

Node *head[32] = {NULL};

void insert_sorted(int k, int addr)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->addr = addr;
    new_node->next = NULL;
    if (!head[k] || head[k]->addr > addr)
    {
        new_node->next = head[k];
        head[k] = new_node;
        return;
    }
    Node *curr = head[k];
    while (curr->next && curr->next->addr < addr)
    {
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
}

int remove_from_list(int k, int buddy)
{
    if (!head[k]) return 0;
    if (head[k]->addr == buddy)
    {
        Node *temp = head[k];
        head[k] = head[k]->next;
        free(temp);
        return 1;
    }
    Node *curr = head[k];
    while (curr->next && curr->next->addr != buddy)
    {
        curr = curr->next;
    }
    if (curr->next)
    {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
        return 1;
    }
    return 0;
}

void buddy_free(int k, int addr)
{
    int buddy = addr ^ (1 << k);
    if (remove_from_list(k, buddy))
    {
        int parent_addr = (addr < buddy) ? addr : buddy;
        buddy_free(k + 1, parent_addr);
    }
    else
    {
        insert_sorted(k, addr);
    }
}

int main()
{
    char line[4096];
    int part = 1;
    while (fgets(line, sizeof(line), stdin))
    {
        int is_blank = 1;
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r')
            {
                is_blank = 0;
                break;
            }
        }
        if (is_blank)
        {
            part = 2;
            continue;
        }
        if (part == 1)
        {
            int k;
            int offset = 0;
            int bytes_read;
            if (sscanf(line + offset, "%d%n", &k, &bytes_read) == 1)
            {
                offset += bytes_read;
                int addr;
                while (sscanf(line + offset, "%d%n", &addr, &bytes_read) == 1)
                {
                    offset += bytes_read;
                    insert_sorted(k, addr);
                }
            }
        }
        else
        {
            int k, addr;
            if (sscanf(line, "%d %d", &k, &addr) == 2)
            {
                buddy_free(k, addr);
            }
        }
    }
    for (int i = 0; i < 32; i++)
    {
        if (head[i])
        {
            printf("%d", i);
            Node *curr = head[i];
            while (curr)
            {
                printf(" %d", curr->addr);
                curr = curr->next;
            }
            printf("\n");
        }
    }
    return 0;
}