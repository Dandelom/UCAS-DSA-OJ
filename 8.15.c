#include <stdio.h>
#include <stdlib.h>

typedef struct SpaceNode
{
    int tag;
    int addr;
    int size;
    struct SpaceNode *next;
}SpaceNode;

int main()
{
    int lowbound, highbound, block_size;
    if(scanf("%d %d %d", &lowbound, &highbound, &block_size) != 3) return 0;
    int num_blocks = (highbound - lowbound) / block_size;
    int *tags = (int *)malloc(sizeof(int) * num_blocks);
    for(int i=0; i<num_blocks; i++)
    {
        scanf("%d", &tags[i]);
    }
    SpaceNode *head = NULL;
    SpaceNode *tail = NULL;
    int in_free = 0;
    int start_addr = 0;
    int current_size = 0;
    for(int i=0; i<num_blocks; i++)
    {
        if(tags[i] == 0)
        {
            if(!in_free)
            {
                start_addr = lowbound + i * block_size;
                current_size = block_size;
                in_free = 1;
            }
            else
            {
                current_size += block_size;
            }
        }
        else
        {
            if(in_free)
            {
                SpaceNode *new_node = (SpaceNode *)malloc(sizeof(SpaceNode));
                new_node->tag = 0;
                new_node->addr = start_addr;
                new_node->size = current_size;
                new_node->next = NULL;
                if(!head)
                {
                    head = new_node;
                    tail = new_node;
                }
                else
                {
                    tail->next = new_node;
                    tail = new_node;
                }
                in_free = 0;
            }
        }
    }
    if(in_free)
    {
        SpaceNode *new_node = (SpaceNode *)malloc(sizeof(SpaceNode));
        new_node->tag = 0;
        new_node->addr = start_addr;
        new_node->size = current_size;
        new_node->next = NULL;
        if(!head)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
    if(!head)
    {
        printf("0 0 0\n");
    }
    else
    {
        SpaceNode *curr = head;
        while(curr)
        {
            printf("%d %d %d\n", curr->tag, curr->addr, curr->size);
            curr = curr->next;
        }
    }
    free(tags);
    return 0;
}