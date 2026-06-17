#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    int left;
    int right;
}TreeNode;

TreeNode tree[20005];
int has_parent[20005] = {0};
int prev_val;
int first = 1;

int is_bst(int root)
{
    if (root == -1) return 1;
    if (!is_bst(tree[root].left)) return 0;
    if (!first && tree[root].val <= prev_val) return 0;
    first = 0;
    prev_val = tree[root].val;
    return is_bst(tree[root].right);
}

int main()
{
    int val, left, right;
    int n = 0;
    while (scanf("%d %d %d", &val, &left, &right) == 3)
    {
        tree[n].val = val;
        tree[n].left = left;
        tree[n].right = right;
        if (left != -1) has_parent[left] = 1;
        if (right != -1) has_parent[right] = 1;
        n++;
    }
    if (n == 0)
    {
        printf("1\n");
        return 0;
    }
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (!has_parent[i])
        {
            root = i;
            break;
        }
    }
    if (is_bst(root)) printf("1\n");
    else printf("0\n");
    return 0;
}