#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    Node dummy;
    dummy.next = NULL;
    Node *tail = &dummy;

    for (int i = 0; i < n; i++) {
        int val;
        if (scanf("%d", &val) == 1) {
            Node *newnode = (Node *)malloc(sizeof(Node));
            newnode->data = val;
            newnode->next = NULL;
            tail->next = newnode;
            tail = newnode;
        }
    }

    Node *head = dummy.next;
    Node sorted_dummy;
    sorted_dummy.next = NULL;
    Node *curr = head;

    while (curr) {
        Node *next_node = curr->next;
        Node *prev = &sorted_dummy;
        while (prev->next && prev->next->data < curr->data) {
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
        curr = next_node;
    }

    Node *p = sorted_dummy.next;
    int dotflag = 0;
    while (p) {
        if (dotflag) putchar(' ');
        printf("%d", p->data);
        dotflag = 1;
        Node *temp = p;
        p = p->next;
        free(temp);
    }
    printf("\n");

    return 0;
}